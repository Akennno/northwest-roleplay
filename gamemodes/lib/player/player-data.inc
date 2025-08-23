#define MAX_ACCOUNT_NAME            32
#define MAX_ACCOUNT_PASSWORD        32

enum e_PLAYER_DATA
{
    pID,
    pName[(MAX_PLAYER_NAME + 1) char],
    pWorld,
    pSkin,
    pInterior,
    pLastLogin[32],
    Float:pPosX,
    Float:pPosY,
    Float:pPosZ,
    Float:pAngle,
    Float:pHealth,
    Float:pArmour,


    // injured - death
    pInjured,
    pDeath,
    pInjuredTimer
};

enum e_ACCOUNT_DATA
{
    aName[MAX_ACCOUNT_NAME char],
    aPassword[BCRYPT_HASH_LENGTH + 1]
};


new
    pData[MAX_PLAYERS][e_PLAYER_DATA],
    aData[MAX_PLAYERS][e_ACCOUNT_DATA]
;