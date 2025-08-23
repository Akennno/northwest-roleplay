Dialog:DL_LOGIN_PW(playerid, response, listitem, inputtext[])
{
    if(!response)
        return Kick(playerid);
    
    new len = strlen(inputtext);
    if(len >= 8 && len <= 32)
    {
        new
            loginAttemps,
            Task:task = task_new()
        ;

        new result = bcrypt_verify(playerid, "OnPasswordVerfying", inputtext, aData[playerid][aPassword], "d", _:task);
        if(!result)
        {
            task_set_error_ms(task, amx_err_exit, false);
            return false;
        }

        new valid = await task;
        if(valid)
        {
            LoadPlayerCharacter(playerid);
        }
        else
        {
            loginAttemps++;
            if(loginAttemps > 3)
            {
                InfoMessage(playerid, "Incorrect password for 3 times, you'll be kicked");
                DelayedKick(playerid);
            }

            WarningMessage(playerid, "Incorrect password! (%d/3)", loginAttemps);
            Dialog_Last(playerid);
        }
    }
    else 
    {
        ErrorMessage(playerid, "password must be between 8 and 32 characters");
        Dialog_Last(playerid);
    }
    return true;
}

Dialog:DL_REGISTER(playerid, response, listitem, inputtext[])
{
    if(!response)
        return Kick(playerid);

    new String:str = str_new(inputtext);
    if(str_match(str, PASS_REGEX))
    {
        new
            Task:task = task_new(),
            hash[BCRYPT_HASH_LENGTH + 1]
        ;

        bcrypt_hash(playerid, "OnPasswordHashing", inputtext, BCRYPT_COST, "d", _:task);
        task_await_arr(task, hash);

        await mysql_aquery_s(sql_Handle, str_format("INSERT INTO accounts (Account_Name, Account_Password) VALUES ('%s','%s')", aData[playerid][aName], hash));
        LoadPlayerCharacter(playerid);
    }
    else
    {
        ErrorMessage(playerid, "password must be between 8 and 32 characters and contain at least one symbol");
        Dialog_Last(playerid);
    }
    return true;
}