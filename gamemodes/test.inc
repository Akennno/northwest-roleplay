#include <open.mp>
#include <izcmd>
#include <sscanf2>
#include <omp_npcs>

main(){}

#define MAX_BOTS         10
enum e_BOT_DATA
{
    botID = INVALID_PLAYER_ID,
    botName[MAX_PLAYER_NAME + 1],
    botSkin,
    Float:botX,
    Float:botY,
    Float:botZ,
    Float:botHealth,
    Float:botArmour
};
new botData[MAX_BOTS][e_BOT_DATA];


public OnNPCCreate(npcid)
{

}


stock GetFreeBots()
{
    new slot = -1;
    for(new i ; i < MAX_BOTS; i++) {
        if(botData[i][botID] == INVALID_PLAYER_ID)  {
            slot = i;
            break;
        }
    }
    return slot;
}

#define IsValidBotID(%1)        (botData[%1][botID] != INVALID_PLAYER_ID)

cmd(ncreate, playerid, params[])
{
    new
        botName[MAX_PLAYER_NAME + 1],
        botSkin
    ;

    new free_bot = GetFreeBots();
    if(free_bot == -1)
        return SendClientMessage(playerid, -1, "No free bot slots available.");
    

    if(sscanf(params, "s[24]d", botName, botSkin))
        return SendClientMessage(playerid, -1, "[USAGE]: /ncreate [bot name] [bot skin].");
    
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);


    botData[free_bot][botID] = NPC_Create(botName);
    strcat(botData[free_bot][botName], botName);

    NPC_SetSkin(botData[free_bot][botID], botSkin);
    NPC_SetPos(botData[free_bot][botID], x + 1.0,y,z);

    SendClientMessage(playerid, -1, "Bot created successfully.");
    return NPC_Spawn(botData[free_bot][botID]);
}

cmd(nremove, playerid, params[])
{
    new botID;
    if(sscanf(params, "d", botID) != 1)
        return SendClientMessage(playerid, -1, "[USAGE]: /nremove [bot id].");
    
    if(IsValidBotID(botID))
    {
        botData[botID][botName][0] =  '\0';
        botData[botID][botSkin] = 0;

        botData[botID][botX] = 0.0;
        botData[botID][botY] = 0.0;
        botData[botID][botZ] = 0.0;
        botData[botID][botHealth] = 0.0;
        botData[botID][botArmour] = 0.0;

        NPC_Destroy(botData[botID][botID]);
        botData[botID][botID] = INVALID_PLAYER_ID;
        SendClientMessage(playerid, -1, "Bot removed successfully.");
    }
    return 1;
}

cmd(nmove, playerid, params[])
{
    new
        botid,
        Float:x,
        Float:y,
        Float:z
    ;

    GetPlayerPos(playerid, x,y,z);
    if(sscanf(params, "d", botid))
        return SendClientMessage(playerid, -1, "[USAGE]: /nmove [bot id].");
    
    if(IsValidBotID(botid))
    {
        NPC_MoveToPlayer(botid, playerid, .movespeed = 1.2);
    }
    return 1;
}