//
// Created: 05.09.06
// Aurthor: Iain Gilbert
//

#if defined _commands_included
#endinput
#endif

#define _commands_included
#pragma library commands

COMMAND:help(playerid, params[])
{
	SendClientMessage(playerid, COLOR_WHITE, lang_texts[15][2]);
	SendClientMessage(playerid, COLOR_LIGHTRED, lang_texts[15][3]);
	SendClientMessage(playerid, COLOR_WHITE, lang_texts[15][4]);
	SendClientMessage(playerid, COLOR_WHITE, lang_texts[15][5]);
	return 1;
}

COMMAND:info(playerid, params[])
{
	Dialog_Message(playerid, "����������", _m(ACCOUNT_DIALOG_INFORMATION_TEXT), "��");
	return 1;
}

COMMAND:commands(playerid, params[])
{
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][15]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][16]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][17]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][18]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][19]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][20]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][21]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][22]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][23]);
	SendClientMessage(playerid, COLOR_PURPLE, lang_texts[15][24]);
	return 1;
}

COMMAND:status(playerid, params[])
{
	SendClientMessage(playerid, COLOR_GREEN, lang_texts[15][35]);
	
	new Float:kill_on_death = 0.0;
	if (player_GetDeaths(playerid) != 0) {
		kill_on_death = float(player_GetKills(playerid)) / float(player_GetDeaths(playerid));
	}
	
	new string[MAX_STRING];

	switch ( player_GetStatus(playerid) )
	{
		case STATUS_LEVEL_MODER: set(string, lang_texts[12][87]);
		case STATUS_LEVEL_ADMIN: set(string, lang_texts[12][86]);
		case STATUS_LEVEL_RCON: set(string, lang_texts[12][94]);
		default: set(string, lang_texts[12][88]);
	}
	SendClientMessage(playerid, COLOR_LIGHTRED, string);

	format(string, sizeof(string), lang_texts[15][37], player_GetGangName(playerid));
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

	format(string, sizeof(string), lang_texts[15][38], GetPlayerLevel(playerid), GetPlayerXP(playerid), GetXPToLevel(GetPlayerLevel(playerid) + 1), GetPlayerMoney(playerid), GetPlayerBankMoney(playerid), GetPlayerTotalMoney(playerid));
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

	format(string, sizeof(string), lang_texts[15][39], player_GetKills(playerid), player_GetDeaths(playerid), kill_on_death, player_GetJailCount(playerid), player_GetMuteCount(playerid));
	SendClientMessage(playerid, COLOR_LIGHTRED, string);

	new fstylename[MAX_STRING];
	fights_GetStyleName(pl_fights_GetPlayerStyleUsed(playerid), fstylename);

	format(string, sizeof(string), "������������ ����� ������: %s", fstylename);
	SendClientMessage(playerid, COLOR_LIGHTRED, string);

	if (Premium_GetPlayerStatus(playerid) == 1) {
		format(string, sizeof(string), "� ��� ���� ������� ������, �������� ��: %s", Premium_GetPlayerDate(playerid));
	} else {
		format(string, sizeof(string), "� ��� ��� ������� �������, ��� ������������ ���������� � �������������");
	}
	SendClientMessage(playerid, COLOR_LIGHTRED, string);
	return 1;
}

COMMAND:version(playerid, params[])
{
	SendClientMessage(playerid, COLOR_MISC, lang_texts[15][74]);
	new string[MAX_STRING];
	format(string, sizeof(string), lang_texts[15][75], VERSION_STRING);
	SendClientMessage(playerid, COLOR_GREEN, string);
	SendClientMessage(playerid, COLOR_MISC, lang_texts[15][76]);
	SendClientMessage(playerid, COLOR_MISC, lang_texts[15][77]);
	return 1;
}

COMMAND:time(playerid, params[])
{
	new string[MAX_STRING],
		minute;
	
	gettime(_, minute);
	format(string, sizeof(string), "%02d:%02d", Time_GetCurrentHour(), minute);
	GameTextForPlayer(playerid, string, 2000, 1);

	new jail_time = player_GetJailTime(playerid);
	new mute_time = player_GetMuteTime(playerid);

	if (jail_time != -1 || mute_time != 0) {
		SendClientMessage(playerid, COLOR_LIGHTRED, lang_texts[15][29]);
	}

	if (jail_time != -1) {
		format(string, sizeof(string), lang_texts[13][56], (jail_time - gettime()) / 60 + 1);
		SendClientMessage(playerid, COLOR_LIGHTRED, string);
	}

	if (mute_time != 0) {
		format(string, sizeof(string), lang_texts[13][59], (mute_time - gettime()) / 60 + 1);
		SendClientMessage(playerid, COLOR_LIGHTRED, string);
	}
	
	PlayerPlaySound(playerid, 1085, 0, 0, 0);
	return 1;
}

COMMAND:skydive(playerid, params[])
{
	if (player_IsJailed(playerid) || GetPlayerInterior(playerid) != 0 || player_IsAtQuest(playerid)) {
		SendClientMessage(playerid, COLOR_WHITE, _(SKYDIVING_ERROR));
		return 1;
	}

	new string[MAX_STRING];
	new time_sky = player_GetSkydiveTime(playerid) - gettime();
	if (time_sky > 0) {
		new
			minutes = (time_sky / 60) % 60,
			seconds = time_sky % 60;

		format(string, sizeof(string),
			_(SKYDIVING_NEED_TIME),
			minutes, Declension_GetMinutes(minutes),
			seconds, Declension_GetSeconds(seconds)
		);

		SendClientMessage(playerid, COLOR_WHITE, string);
		return 1;
	}

	GivePlayerWeapon(playerid, 46, 1);
	PlayerPlaySound(playerid, 1057, 0, 0, 0);

	new Float:playerx, Float:playery, Float:playerz;
	GetPlayerPos(playerid, playerx, playery, playerz);
	SetPlayerPos(playerid, playerx, playery, playerz + 1200);
	
	player_SetSkydiveTime(playerid, gettime() + SKYDIVE_TIME);

	SendClientMessage(playerid, COLOR_WHITE, _(SKYDIVING_MSG));
	GameTextForPlayer(playerid, _(SKYDIVING_GAMETEXT), 4000, 5);
	
	format(string, sizeof(string), _(SKYDIVING_MSG_TO_ALL), ReturnPlayerName(playerid), playerid);
	SendClientMessageToAll(COLOR_GREY, string);
	return 1;
}
