#define UNKNOWN_NPC_MOVE_TYPE                  (-1)
#define NPC_MOVE_TYPE_NONE                     (0)
#define NPC_MOVE_TYPE_WALK                     (1)
#define NPC_MOVE_TYPE_JOG                      (2)
#define NPC_MOVE_TYPE_SPRINT                   (3)
#define NPC_MOVE_TYPE_DRIVE                    (4)

#define NPC_ENTITY_CHECK_NONE                  (0)
#define NPC_ENTITY_CHECK_PLAYER                (1)
#define NPC_ENTITY_CHECK_NPC                   (2)
#define NPC_ENTITY_CHECK_ACTOR                 (4)
#define NPC_ENTITY_CHECK_VEHICLE               (8)
#define NPC_ENTITY_CHECK_OBJECT                (16)
#define NPC_ENTITY_CHECK_POBJECT_ORIG          (32)
#define NPC_ENTITY_CHECK_POBJECT_TARG          (64)
#define NPC_ENTITY_CHECK_MAP                   (128)
#define NPC_ENTITY_CHECK_ALL                   (255)


native NPC_Create(const name[]);
native NPC_Destroy(npcid);
native NPC_IsValid(npcid);
native NPC_Spawn(npcid);
native NPC_Respawn(npcid);
native NPC_SetPos(npcid, Float:x, Float:y, Float:z);
native NPC_GetPos(npcid, &Float:x, &Float:y, &Float:z);
native NPC_SetRot(npcid, Float:x, Float:y, Float:z);
native NPC_GetRot(npcid, &Float:x, &Float:y, &Float:z);
native NPC_SetFacingAngle(npcid, Float:angle);
native NPC_GetFacingAngle(npcid, &Float:angle);
native NPC_SetVirtualWorld(npcid, vw);
native NPC_GetVirtualWorld(npcid, &vw);
native NPC_Move(npcid, Float:x, Float:y, Float:z, moveType = NPC_MOVE_TYPE_JOG, Float:moveSpeed = -1.0, Float:stopRange = 0.2);
native NPC_MoveToPlayer(npcid, playerid, moveType = NPC_MOVE_TYPE_JOG, Float:moveSpeed = -1.0, Float:stopRange = 0.2, updateDelayMS = 500, autoRestart = false);
native NPC_StopMove(npcid);
native bool:NPC_IsMoving(npcid);
native NPC_SetSkin(npcid, model);
native NPC_IsStreamedIn(npcid, playerid);
native NPC_IsAnyStreamedIn(npcid);
native NPC_GetAll(npcs[], size = sizeof(npcs));
native NPC_SetInterior(npcid, interiorid);
native NPC_GetInterior(npcid);
native NPC_SetHealth(npcid, Float:health);
native Float:NPC_GetHealth(npcid);
native NPC_SetArmour(npcid, Float:armour);
native Float:NPC_GetArmour(npcid);
native NPC_ApplyAnimation(npcid, const animLib[], const animName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time, sync);
native NPC_SetWeapon(npcid, weapon);
native NPC_GetWeapon(npcid);
native NPC_SetAmmo(npcid, ammo);
native NPC_GetAmmo(npcid);
native NPC_SetKeys(npcid, upAndDown, leftAndRight, keys);
native NPC_GetKeys(npcid, &upAnddown, &leftandRight, &keys);
native NPC_MeleeAttack(npcid, time, bool:secondaryAttack = false);
native NPC_StopMeleeAttack(npcid);
native bool:NPC_IsMeleeAttacking(npcid);
native NPC_SetFightingStyle(npcid, style);
native NPC_GetFightingStyle(npcid);
native NPC_EnableReloading(npcid, bool:enable);
native bool:NPC_IsReloadEnabled(npcid);
native bool:NPC_IsReloading(npcid);
native NPC_EnableInfiniteAmmo(npcid, bool:enable);
native bool:NPC_IsInfiniteAmmoEnabled(npcid);
native NPC_GetWeaponState(npcid);
native NPC_SetAmmoInClip(npcid, ammo);
native NPC_GetAmmoInClip(npcid);
native NPC_Shoot(npcid, weapon, hitId, hitType, Float:endPointX, Float:endPointY, Float:endPointZ, Float:offsetX, Float:offsetY, Float:offsetZ, bool:isHit, checkInBetweenFlags = NPC_ENTITY_CHECK_ALL);
native bool:NPC_IsShooting(npcid);
native NPC_AimAt(npcid, Float:pointX, Float:pointY, Float:pointZ, bool:shoot, shootDelay, bool:updateAngle, Float:offsetFromX, Float:offsetFromY, Float:offsetFromZ, checkInBetweenFlags = NPC_ENTITY_CHECK_ALL);
native NPC_AimAtPlayer(npcid, playerid, bool:shoot, shootDelay, bool:updateAngle, Float:offsetX, Float:offsetY, Float:offsetZ, Float:offsetFromX, Float:offsetFromY, Float:offsetFromZ, checkInBetweenFlags = NPC_ENTITY_CHECK_ALL);
native NPC_StopAim(npcid);
native bool:NPC_IsAiming(npcid);
native bool:NPC_IsAimingAtPlayer(npcid, playerid);
native NPC_SetWeaponAccuracy(npcid, weaponid, Float:accuracy);
native Float:NPC_GetWeaponAccuracy(npcid, weaponid);
native NPC_EnterVehicle(npcid, vehicleid, seatid, moveType);
native NPC_ExitVehicle(npcid);
native NPC_PutInVehicle(npcid, vehicleid, seatid);
native NPC_RemoveFromVehicle(npcid);

// NPC Path System
native NPC_CreatePath();
native bool:NPC_DestroyPath(pathid);
native bool:NPC_DestroyAllPath();
native NPC_GetPathCount();
native bool:NPC_AddPointToPath(pathid, Float:x, Float:y, Float:z, Float:stopRange);
native bool:NPC_RemovePointFromPath(pathid, point_index);
native bool:NPC_ClearPath(pathid);
native NPC_GetPathPointCount(pathid);
native bool:NPC_GetPathPoint(pathid, point_index, &Float:x, &Float:y, &Float:z, &Float:stopRange);
native bool:NPC_SetPathCurrentIndex(pathid, index);
native NPC_GetPathCurrentIndex(pathid);
native bool:NPC_ResetPath(pathid);
native bool:NPC_IsValidPath(pathid);
native bool:NPC_PathHasNextPoint(pathid);
native bool:NPC_GetPathNextPoint(pathid, &Float:x, &Float:y, &Float:z, &Float:stopRange);
native bool:NPC_MoveByPath(npcid, pathid, moveType, moveSpeed = -1.0);


// Callbacks
forward OnNPCFinishMove(npcid);
forward OnNPCCreate(npcid);
forward OnNPCDestroy(npcid);
forward OnNPCSpawn(npcid);
forward OnNPCRespawn(npcid);
forward OnNPCWeaponStateChange(npcid, newState, oldState);
forward OnNPCTakeDamage(npcid, damagerid, Float:damage, WEAPON:weapon, bodypart);
forward OnNPCGiveDamage(npcid, damagedid, Float:damage, WEAPON:weapon, bodypart);
forward OnNPCDeath(npcid, killerid, reason);