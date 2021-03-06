/*

	About: anti rcon hack
	Author:	ziggi

*/

#if defined _rconhack_included
	#endinput
#endif

#define _rconhack_included
#pragma library rconhack


/*
 * Vars
 */

static IsEnabled = ANTI_RCON_HACK_ENABLED;


/*
 * Config
 */

pt_rcon_LoadConfig(file_config)
{
	ini_getInteger(file_config, "Protection_Rcon_IsEnabled", IsEnabled);
}

pt_rcon_SaveConfig(file_config)
{
	ini_setInteger(file_config, "Protection_Rcon_IsEnabled", IsEnabled);
}


/*
 * For public
 */

pt_rcon_OnRconLoginAttempt(ip[], password[], success)
{
	if (!IsEnabled || success) {
		return 0;
	}

	new
		playerip[MAX_IP];

	foreach (new playerid : Player) {
		GetPVarString(playerid, "IP", playerip, sizeof(playerip));

		if (!strcmp(ip, playerip, false)) {
			Admin_SendProtectReport(playerid, _(PROTECTION_RCON), playerip, password);
			return 1;
		}
	}
	return 1;
}
