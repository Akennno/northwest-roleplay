/*
 * Author: Akennno
 * Version: N:1.0
*/
#define PP_SYNTAX
#define I_ZCMD_USE_DELAY
#define I_ZCMD_DEBUG

#include <open.mp>
#include <a_mysql>
#include <sscanf2>
#include <foreach>
#include <PawnPlus>
#include <pp-mysql>
#include <samp_bcrypt>
#include <strlib>
#include <easyDialog>

#include "lib\mysql.inc"
#include "lib\define.inc"
#include "lib\player\player-data.inc"
#include "lib\player\player-function.inc"

// login
#include "lib\player\player-character.inc"
#include "lib\player\login\login-function.inc"
#include "lib\player\login\login-dialog.inc"
#include "lib\player\login\login-callback.inc"



public OnGameModeInit()
{
    print(">-------------------------------------------<");
    print(">> Northwest Open.MP version "SV_VERSION"");
    print(">> Author: Akennno");
    print(">> Copyright (c) 2025, All rights reversed");
    print(">-------------------------------------------<");

    mysql_init();
    
    SendRconCommand("name %s", SV_NAME);
    SendRconCommand("language %s", SV_LANGUAGE);
    SendRconCommand("game.map %s", SV_MAP);
    SendRconCommand("game.mode %s", SV_VERSION);    

    return true;
}

public OnGameModeExit()
{
    foreach(new i : Player)
    {
        if(IsPlayerConnected(i) || IsPlayerSpawned(i)) 
        {
            SavePlayerData(i);
            Kick(i);
            print("[N:INFO] All online player has been kicked from server.");
        }
    }

    if(sql_Handle != MYSQL_INVALID_HANDLE) mysql_close(sql_Handle);
    return true;
}

public OnPlayerConnect(playerid)
{
    GetPlayerAccount(playerid);
    return true;
}

public OnPlayerSpawn(playerid)
{
    return true;
}

public OnPlayerDisconnect(playerid, reason)
{
    SavePlayerData(playerid);
    return true;
}

public OnPlayerText(playerid, text[])
{
    if(!IsPlayerSpawned(playerid))
    {
        ErrorMessage(playerid, "You can't use chat before you spawn.");
        return false;
    }

    new 
        fmt[180]
    ;
    format(fmt, sizeof fmt, "%s says: %s", ReturnRoleplayName(playerid), text);
    ProxDetector(playerid, 15.0, 0xF5F5F5FF, fmt);
    return false;
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
    return true;
}


main() {}