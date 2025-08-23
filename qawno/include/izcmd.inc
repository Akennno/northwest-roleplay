/*******************************************************************************************************************************
 Improved ZCMD (iZCMD)

 This include is just a re-make of the ZCMD Command Processor ( V0.3.1 31/10/2009) originnaly developed by Zeex.

 Version: 0.2.4.0 (August 21th 2025)

 GitHub Link: https://github.com/YashasSamaga/I-ZCMD

 Credits:
 Zeex for ZCMD (the very idea of making publics for each command was introduced by Zeex in ZCMD)
 Yashas
 Akennno
*******************************************************************************************************************************/

#if defined _I_ZCMD_INCLUDED
    #endinput
#endif
#define _I_ZCMD_INCLUDED
#define _I_ZCMD_VERSION		"0.2.4.0"

#if !defined I_ZCMD_DELAY_TIME
    #define I_ZCMD_DELAY_TIME 15000 
#endif

#if !defined I_ZCMD_MAX_GROUP
	#define I_ZCMD_MAX_GROUP 25
#endif

#if !defined I_ZCMD_GROUPS
	#define I_ZCMD_GROUPS 50
#endif

#if !defined I_ZCMD_GROUP_NAME
	#define I_ZCMD_GROUP_NAME 24
#endif

#define MAX_CLIENT_MSG_LENGTH 144
#define MAX_FUNC_NAME 64

#define COMMAND:%1(%2)          \
			forward cmd_%1(%2); \
			public cmd_%1(%2)

#define CMD:%1(%2) \
			COMMAND:%1(%2)

#define command(%1,%2,%3) \
			COMMAND:%1(%2, %3)

#define cmd(%1,%2,%3) \
			COMMAND:%1(%2, %3)
		
#if !defined isnull
        #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#if defined OnPlayerCommandReceived
	forward OnPlayerCommandReceived(playerid,cmdtext[]);
#endif

#if defined OnPlayerCommandPerformed
	forward OnPlayerCommandPerformed(playerid,cmdtext[], success);
#endif

#if defined OnPlayerCommandBlocked
	forward OnPlayerCommandBlocked(playerid, cmdtext[]);
#endif


#define izcmd_IsValidCommand(%0) ((%0[0] == '/') && (%0[1] != '\0'))

new pCmd_Delay[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
    pCmd_Delay[playerid] = 0;
    #if defined izcmd_OnPlayerConnect
        return izcmd_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if(!IsPlayerSpawned(playerid)) return 0;
    if(!izcmd_IsValidCommand(cmdtext)) return 0;
    if(isnull(cmdtext)) return 0;

    #if defined OnPlayerCommandReceived
        if(!OnPlayerCommandReceived(playerid, cmdtext)) return 1;
    #endif

    static funcname[MAX_FUNC_NAME + 4] = "cmd_";
    new length = strlen(cmdtext);
    
    new pos = 1;
    while(pos < length && cmdtext[pos] > ' ') pos++;
    
    new cmd_length = pos - 1;
    if(cmd_length > MAX_FUNC_NAME - 4) 
        cmd_length = MAX_FUNC_NAME - 4;
    
    #if defined IZCMD_CASE_SENSITIVE
        strmid(funcname[4], cmdtext[1], 0, cmd_length, MAX_FUNC_NAME - 4);
        funcname[cmd_length + 4] = '\0';
    #else
        for(new i = 0; i < cmd_length; i++)
        {
            new c = cmdtext[i + 1];
            funcname[i + 4] = ('A' <= c <= 'Z') ? (c | 0x20) : c;
        }
        funcname[cmd_length + 4] = '\0';
    #endif
    
    while(pos < length && cmdtext[pos] == ' ') pos++;
    
    new params[MAX_CLIENT_MSG_LENGTH] = "\1";
    if(pos < length && cmdtext[pos] != '\0')
    {
        new params_length = length - pos;
        if(params_length >= sizeof(params)) 
            params_length = sizeof(params) - 1;
        strmid(params, cmdtext, pos, length, params_length + 1);
    }
    
    new result = 0;
    new function_exists = (funcidx(funcname) != -1);
    
    if(function_exists)
    {
        #if defined I_ZCMD_USE_DELAY
            new time_remaining = GetTickCount() - pCmd_Delay[playerid];
            if(time_remaining < I_ZCMD_DELAY_TIME)
            {
                new d = (I_ZCMD_DELAY_TIME - time_remaining) / 1000;
                if(d <= 0 ) d = 0;

                return SendClientMessage(playerid, -1, "CMD: You must wait %d second(s) before using another command.", d);
            }
        #endif

        pCmd_Delay[playerid] = GetTickCount();
        result = CallLocalFunction(funcname, "is", playerid, params);
        
    }
    else
    {
        #if defined I_ZCMD_DEBUG
            printf("Command not found: %s", funcname);
        #endif
        result = 0;
    }
    
    #if defined OnPlayerCommandPerformed
        return OnPlayerCommandPerformed(playerid, cmdtext, result);
    #else
        return result;
    #endif
}

// ALS
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect izcmd_OnPlayerConnect

#if defined izcmd_OnPlayerConnect
    forward izcmd_OnPlayerConnect(playerid);
#endif