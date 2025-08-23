stock ReturnPlayerName(playerid)
{
    new 
        tmp[MAX_PLAYER_NAME + 1]
    ;
    GetPlayerName(playerid, tmp);
    return tmp;
}

stock ReturnRoleplayName(playerid)
{
    return ret_strreplace(ReturnPlayerName(playerid), "_", " ");
}

stock DelayedKick(playerid, ticks = 500)
{
    wait_ticks(ticks);
    return Kick(playerid);
}

stock SavePlayerData(playerid)
{
    new
        Float:x,
        Float:y,
        Float:z,
        Float:ang,
        Float:h,
        Float:a
    ;

    GetPlayerPos(playerid, x,y,z);
    GetPlayerFacingAngle(playerid, ang);
    GetPlayerHealth(playerid, h);
    GetPlayerArmour(playerid, a);

    new query[512];
    mysql_format(
        sql_Handle,
        query,
        sizeof query,
        "UPDATE players SET Player_World=%d, Player_Interior=%d, Player_Skin=%d, \
        Player_Health=%f, Player_Armour=%f, \
        Player_PosX=%f, Player_PosY=%f, Player_PosZ=%f, \
        Player_Angle=%f, \
        Player_LastLogin = NOW() WHERE Player_ID=%d",
        GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), GetPlayerSkin(playerid),
        h, a, x, y, z, ang,
        pData[playerid][pID]
    );
    
    return mysql_pquery(sql_Handle, query) ? printf("Berhasil menyimpan data player \'%s\'", ReturnPlayerName(playerid)) : print("Gagal menyimpan data player");
}

//https://gist.github.com/ziggi/40edafde359776530f10d3218873fd02
stock ProxDetector(playerid, Float:max_range, color, const string[], Float:max_ratio = 1.6)
{
    if(!IsPlayerSpawned(playerid))
        return false;

	new
		Float:pos_x,
		Float:pos_y,
		Float:pos_z,
		Float:range,
		Float:range_ratio,
		Float:range_with_ratio,
		clr_r, clr_g, clr_b,
		Float:color_r, Float:color_g, Float:color_b
    ;
    
    GetPlayerPos(playerid, pos_x, pos_y, pos_z);

	color_r = float(color >> 24 & 0xFF);
	color_g = float(color >> 16 & 0xFF);
	color_b = float(color >> 8 & 0xFF);
	range_with_ratio = max_range * max_ratio;

	foreach (new i : Player) 
    {
        if(!IsPlayerSpawned(i) || !IsPlayerStreamedIn(i, playerid))
            continue;

		range = GetPlayerDistanceFromPoint(i, pos_x, pos_y, pos_z);
		if (range > max_range) {
			continue;
		}

		range_ratio = (range_with_ratio - range) / range_with_ratio;
		clr_r = floatround(range_ratio * color_r);
		clr_g = floatround(range_ratio * color_g);
		clr_b = floatround(range_ratio * color_b);

		SendClientMessage(i, (color & 0xFF) | (clr_b << 8) | (clr_g << 16) | (clr_r << 24), string);
	}

	SendClientMessage(playerid, color, string);
	return 1;
}