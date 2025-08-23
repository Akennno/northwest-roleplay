#define callback::%1(%2)     \
        forward %1(%2); public %1(%2)


#define PASS_REGEX                  "^(?=.*[!@#\\$%\\^&\\*\\(\\)\\-_=+\\{\\};:,<.>\\/\\[\\]~`|])[a-zA-Z0-9!@#$%^&*()_+\\-={};:,.<>?\\[\\]~`|/]{8,32}$"
#define NAME_REGEX                  "^[A-Z][a-zA-Z]{2,22}_[A-Z][a-zA-Z]{0,20}$"

#define ErrorMessage(%1,%2)         SendClientMessage(%1, -1, "ERROR: "%2)
#define WarningMessage(%1,%2)       SendClientMessage(%1, -1, "WARNING: "%2)
#define InfoMessage(%1,%2)          SendClientMessage(%1, -1, "INFO: "%2)
#define SuccessMessage(%1,%2)       SendClientMessage(%1, -1, "SUCCESS: "%2)


#define SV_NAME                     "Northwest Roleplay"
#define SV_VERSION                  "N-1.0 Beta"
#define SV_MAP                      "San Andreas"
#define SV_LANGUAGE                 "EN/ID"
    
