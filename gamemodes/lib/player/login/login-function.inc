stock bool:IsAccountAlreadyLoggedIn(playerid)
{
    foreach(new i : Player) 
    {
        if(i == playerid || !IsPlayerSpawned(i)) 
            continue;
        
        if(strequal(ReturnPlayerName(playerid), ReturnPlayerName(i)))  
            return true;
    }
    return false;
}

stock GetPlayerAccount(playerid)
{
    if(IsAccountAlreadyLoggedIn(playerid)) 
    {
        ErrorMessage(playerid, "This account already on the server, you'll be kicked from server");
        DelayedKick(playerid);
    }

    strpack(aData[playerid][aName], ReturnPlayerName(playerid));

    await mysql_aquery_s(sql_Handle, str_format("SELECT Account_LoginType, Account_Password, Account_RawIp FROM accounts WHERE Account_Name = '%s'", aData[playerid][aName]));
    if(cache_num_rows())
    {
        cache_get_value(0, "Account_Password", aData[playerid][aPassword]);
        Dialog_Show(playerid, DL_LOGIN_PW, DIALOG_STYLE_INPUT, "Login session", "Plese input your password here!", "Login", "");
    }
    else
    {
        InfoMessage(playerid, "Unregistered Account!");
        Dialog_Show(playerid, DL_REGISTER, DIALOG_STYLE_INPUT, "Register session", "Create your account password", "Create", "Cancel");
    }
    return 1;
}