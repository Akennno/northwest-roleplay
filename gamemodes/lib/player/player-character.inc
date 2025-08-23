#define MAX_PLAYER_CHARACTER                    3
#define MAX_REGISTRATION_STEP                   2

enum e_PLAYER_CHAR_DATA
{
    charExist,
    charName[MAX_PLAYER_NAME + 1],
    charLastLogin[32]
};
new 
    charData[MAX_PLAYERS][MAX_PLAYER_CHARACTER][e_PLAYER_CHAR_DATA],
    registStep[MAX_PLAYERS]
;


static void:GetPlayerCharacterList(playerid)
{
    await mysql_aquery_s(sql_Handle, str_format("SELECT Player_Name, Player_LastLogin FROM players WHERE Account_Name = '%s'", aData[playerid][aName]));
    new
        rows = cache_num_rows(),
        bool:null
    ;

    if(rows)
    {
        for(new i ; i < rows ; i++) 
        {
            charData[playerid][i][charExist] = 1;

            cache_get_value(i, "Player_Name", charData[playerid][i][charName]);
            cache_is_value_name_null(i, "Player_LastLogin", null);

            if(null) format(charData[playerid][i][charLastLogin], 32, "-");
            else cache_get_value(i, "Player_LastLogin", charData[playerid][i][charLastLogin]);
        }
    }    
}

stock LoadPlayerCharacter(playerid)
{
    new
        fmt[128]
    ;

    strcat(fmt, "#\tCharacter Name\tLast Login\n");
    GetPlayerCharacterList(playerid);

    for(new i; i < MAX_PLAYER_CHARACTER ; i++) 
    {
        if(charData[playerid][i][charExist]) {
            format(fmt, sizeof fmt, "%s%d\t%s\t%s\n", fmt, i + 1, charData[playerid][i][charName], charData[playerid][i][charLastLogin]);
        }
        else format(fmt, sizeof fmt, "%s-\tEmpty\t-\n", fmt);
    }

    Dialog_Show(playerid, DL_CHARACTERS, DIALOG_STYLE_TABLIST_HEADERS, "Character list(s)", fmt, "Select", "Cancel");
    return 1;
}

stock ShowDialogCreateCharacter(playerid)
{
    new 
        fmt[128]
    ;

    strcat(fmt, "Data\tValue\n");
    format(fmt, sizeof fmt, "%sCharacter Name\t%s\n", fmt, pData[playerid][pName]);
    format(fmt, sizeof fmt, "%sCharacter Skin\t%d\n", fmt, pData[playerid][pSkin]);
    
    strcat(fmt, ">> Confirm registration");
    Dialog_Show(playerid, DL_CREATE_CHARACTER, DIALOG_STYLE_TABLIST_HEADERS, "Create Character", fmt, "Fill", "Cancel");
    return 1;
}


Dialog:DL_CHARACTERS(playerid, response, listitem, inputtext[])
{
    if(!response)
        return Kick(playerid);
    
    if(charData[playerid][listitem][charExist]) 
    {
        mysql_tquery_s(
            sql_Handle,
            str_format("SELECT * FROM players WHERE Player_Name = '%s'", charData[playerid][listitem][charName]),
            "OnGetPlayerData",
            "d",
            playerid
        );
    }
    else
    {
        InfoMessage(playerid, "Create your character here");
        ShowDialogCreateCharacter(playerid);
    }
    return 1;
}



Dialog:DL_CREATE_CHARACTER(playerid, response, listitem, inputtext[])
{
    if(!response)
        return ShowDialogCreateCharacter(playerid);
    
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, DL_CHAR_NAME, DIALOG_STYLE_INPUT, "Character Name", "Create your character name here", "Create", "Cancel");
        case 1: Dialog_Show(playerid, DL_CHAR_SKIN, DIALOG_STYLE_INPUT, "Character Skin", "Create your character skin here", "Create", "Cancel");
        case 2: 
        {
            if(registStep[playerid] != MAX_REGISTRATION_STEP)
            {
                ErrorMessage(playerid, "You must fill all required data");
                return ShowDialogCreateCharacter(playerid);
            }

            await mysql_aquery_s(sql_Handle, str_format("INSERT INTO players (Account_Name, Player_Name, Player_Skin) VALUES ('%s', '%s', %d)", aData[playerid][aName], pData[playerid][pName], pData[playerid][pSkin]));

            pData[playerid][pID] = cache_insert_id();
            SetPlayerName(playerid, pData[playerid][pName]);
            SetSpawnInfo(
                playerid, NO_TEAM, pData[playerid][pSkin], 
                0.0, 0.0, 0.0,
                0.0
            );

            SetPlayerColor(playerid, -1);
            SpawnPlayer(playerid);
        }
    }
    return 1;
}

Dialog:DL_CHAR_NAME(playerid, response, listitem, inputtext[])
{
    if(!response)
        return ShowDialogCreateCharacter(playerid);
    

    new String:name = str_new(inputtext);
    if(!str_match(name, NAME_REGEX))
    {
        ErrorMessage(playerid, "Invalid player name");
        return ShowDialogCreateCharacter(playerid);
    }

    registStep[playerid]++;
    strpack(pData[playerid][pName], inputtext);
    return ShowDialogCreateCharacter(playerid);
}

Dialog:DL_CHAR_SKIN(playerid, response, listitem, inputtext[])
{
    if(!response)
        return ShowDialogCreateCharacter(playerid);
    
    new skin;
    if(sscanf(inputtext, "d", skin))
    {
        ErrorMessage(playerid, "This isn't a number");
        Dialog_Last(playerid);
    }

    pData[playerid][pSkin] = strval(inputtext);
    registStep[playerid]++;
    ShowDialogCreateCharacter(playerid);

    return 1;
}