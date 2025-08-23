callback::OnPasswordVerfying(playerid, success, Task:task) 
{
    task_set_result(task, success);
    return true;
}

callback::OnPasswordHashing(playerid, Task:task)
{
    new hash[BCRYPT_HASH_LENGTH + 1];
    bcrypt_get_hash(hash);

    task_set_result_arr(task, hash);
    return true;
}

callback::OnGetPlayerData(playerid)
{
    cache_get_value_int(0, "Player_ID", pData[playerid][pID]);
    cache_get_value(0, "Player_Name", pData[playerid][pName]);
    cache_get_value_int(0, "Player_World", pData[playerid][pWorld]);
    cache_get_value_int(0, "Player_Interior", pData[playerid][pInterior]);
    cache_get_value_int(0, "Player_Skin", pData[playerid][pSkin]);

    cache_get_value_float(0, "Player_Health", pData[playerid][pHealth]);
    cache_get_value_float(0, "Player_Armour", pData[playerid][pArmour]);

    cache_get_value_float(0, "Player_PosX", pData[playerid][pPosX]);
    cache_get_value_float(0, "Player_PosY", pData[playerid][pPosY]);
    cache_get_value_float(0, "Player_PosZ", pData[playerid][pPosZ]);
    cache_get_value_float(0, "Player_Angle", pData[playerid][pAngle]);


    if(pData[playerid][pHealth] < 1) pData[playerid][pHealth] = 10; // karena system injured belum dibikin
 
    SetPlayerName(playerid, pData[playerid][pName]);
    // SetPlayerHealth(playerid, pData[playerid][pHealth]);
    SetPlayerArmour(playerid, pData[playerid][pArmour]);
    SetPlayerVirtualWorld(playerid, pData[playerid][pWorld]);
    SetPlayerInterior(playerid, pData[playerid][pInterior]);

    SetSpawnInfo(
        playerid, NO_TEAM, pData[playerid][pSkin], 
        pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ],
        pData[playerid][pAngle]
    );


    InfoMessage(playerid, "Server took %d ms to load your data", cache_get_query_exec_time(MILLISECONDS));
    SetPlayerColor(playerid, -1);
    return SpawnPlayer(playerid);
}