	// Simple player camera functions
// by Akennno

#if defined _playercam_included 
    #endinput
#endif
#define _playercam_included

stock MovePlayerCamera(playerid, radius, Float:height = 1.5, bool:freeze = false)
{
    new 
        Float:x,
        Float:y,
        Float:z,
        Float:ang
    ;
    GetPlayerPos(playerid, x,y,z);
    GetPlayerFacingAngle(playerid, ang);

    if(freeze == true)
        TogglePlayerControllable(playerid, false);  

    SetPlayerCameraPos(
        playerid,
        x + (radius * floatsin(-ang, degrees)),
        y + (radius * floatcos(-ang, degrees)),
        z + height
    );
    SetPlayerCameraLookAt(playerid, x,y,z,CAMERA_MOVE);
    return true;
}

stock MovePlayerCameraXY(playerid, Float:movex, Float:movey)
{
    new
      Float:px, Float:py, Float:pz,
      Float:pa
    ;

    GetPlayerPos(playerid, px, py, pz);
    GetPlayerFacingAngle(playerid, pa);

    SetPlayerCameraPos(
        playerid,
        px + (movex * floatsin(pa, degrees)),
        py + (movey * floatcos(pa, degrees)),
        pz + 1.0
    );

    SetPlayerCameraLookAt(
        playerid,
        px,
        py,
        pz,
        CAMERA_MOVE
    );
    return 1;
}

stock SetPlayerCameraFront(playerid, Float:distance = 5.0, Float:height = 1.0)
{
    new
        Float:px, Float:py, Float:pz,
        Float:angle
    ;

    GetPlayerPos(playerid, px, py, pz);
    GetPlayerFacingAngle(playerid, angle);

    new 
        Float:camX = px + (distance * floatsin(-angle, degrees)),
        Float:camY = py + (distance * floatcos(-angle, degrees)),
        Float:camZ = pz + height
    ;

    SetPlayerCameraPos(playerid, camX, camY, camZ);
    SetPlayerCameraLookAt(playerid, px, py, pz, CAMERA_MOVE);
    return 1;
}