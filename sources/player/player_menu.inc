/*

	Created: 07.04.2011
	Author: ziggi
	
*/

#if defined _player_menu_included
  #endinput
#endif

#define _player_menu_included
#pragma library player_menu


DialogCreate:PlayerMenu(playerid)
{
	Dialog_Open(playerid, Dialog:PlayerMenu, DIALOG_STYLE_LIST,
		"���� ������",
		"���������� � ���������\n\
		�����\n\
		����� ������\n\
		��������\n\
		���������\n\
		��������� ������\n\
		����� ������\n\
		��� �������\n\
		��� ���������\n\
		������������� ������\n\
		���������\n\
		������",
		"��", "������"
	);
}

DialogResponse:PlayerMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		return 1;
	}

	switch (listitem) {
		// ���������� � ���������
		case 0: {
			new premium_status[MAX_NAME];
			if (Premium_GetPlayerStatus(playerid) == 1) {
				format(premium_status, sizeof(premium_status), "�� %s", Premium_GetPlayerDate(playerid));
			} else {
				set(premium_status, "���");
			}

			new Float:kill_on_death = 0.0;
			if (player_GetDeaths(playerid) != 0) {
				kill_on_death = float(player_GetKills(playerid)) / float(player_GetDeaths(playerid));
			}

			new fstylename[MAX_STRING];
			fights_GetStyleName(pl_fights_GetPlayerStyleUsed(playerid), fstylename);
			
			new gangname[MAX_NAME];
			gangname = player_GetGangName(playerid);
			if (strlen(gangname) == 0) {
				gangname = "���";
			}

			new string[1024];
			format(string, sizeof(string),
				"�������: %d, ����: %d/%d\n\
				\n\
				���� �����������: %s\n\
				����� � ����: %s\n\
				\n\
				�����: %s\n\
				\n\
				������: $%d, ������ � �����: $%d. ����� �����: $%d\n\
				\n\
				�������: %d, �������: %d (%.2f)\n\
				�����: %d\n\
				�����: %d\n\
				\n\
				����� ������: %s\n\
				������� ������: %s",
				GetPlayerLevel(playerid),
				GetPlayerXP(playerid), GetXPToLevel(GetPlayerLevel(playerid) + 1),
				timestamp_to_format_date( account_GetRegisterTime(playerid) ),
				account_GetPlayedTimeString(playerid),

				gangname,
				
				GetPlayerMoney(playerid), GetPlayerBankMoney(playerid), GetPlayerTotalMoney(playerid),
				
				player_GetKills(playerid), player_GetDeaths(playerid), kill_on_death,
				player_GetJailCount(playerid),
				player_GetMuteCount(playerid),
				
				fstylename,
				premium_status
			);

			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "���������� � ���������", string, "�����", "�����");
			return 1;
		}
		// �����
		case 1: {
			Dialog_Show(playerid, Dialog:GangMenu);
			return 1;
		}
		// ����� ������
		case 2: {
			Dialog_Show(playerid, Dialog:PlayerFights);
			return 1;
		}
		// ��������
		case 3: {
			Dialog_Show(playerid, Dialog:AnimLib);
			return 1;
		}
		// ���������
		case 4: {
			if (GetPVarInt(playerid, "teleports_Pause") == 1) {
				Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "���� ����������", "�� ������� �����������������, �����...", "�����", "�����");
				return 0;
			}
			Dialog_Show(playerid, Dialog:PlayerTeleportMenu);
			return 1;
		}
		// ��������� ������
		case 5: {
			ResetPlayerWeapons(playerid);
			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "��������� ������", "�� ����������� ���������� �� ����� ������.", "�����", "�����");
			return 1;
		}
		// ����� ������
		case 6: {
			Dialog_Show(playerid, Dialog:PlayerSpawnMenu);
			return 1;
		}
		// ��� �������
		case 7: {
			Dialog_Show(playerid, Dialog:BusinessPlayerOwned);
			return 1;
		}
		// ��� ���������
		case 8: {
			Dialog_Show(playerid, Dialog:PlayerVehicleMenu);
			return 1;
		}
		// ������������� ������
		case 9: {
			new idsa = 0,
				idsm = 0,
				admins[(MAX_PLAYER_NAME + 1 + 5) * 10],
				moders[(MAX_PLAYER_NAME + 1 + 5) * 10];
			
			foreach (new id : Player) {
				if (IsPlayerAdm(id)) {
					format(admins, sizeof(admins), "%s%s(%d)\n", admins, ReturnPlayerName(id), id);
					idsa++;
				} else if (IsPlayerMod(id)) {
					format(moders, sizeof(moders), "%s%s(%d)\n", moders, ReturnPlayerName(id), id);
					idsm++;
				}
			}

			new string[(MAX_PLAYER_NAME + 1 + 5) * 20 + 64];
			if (idsa == 0 && idsm == 0) {
				format(string, sizeof(string), _(NO_ADMINS));
			} else {
				if (idsa != 0) {
					format(string, sizeof(string), "�������������:\n%s\n", admins);
				}

				if (idsm != 0) {
					format(string, sizeof(string), "%s\n���������:\n%s\n", string, moders);
				}
			}

			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "������������� ������", string, "�����", "�����");
			return 1;
		}
		// ���������
		case 10: {
			Dialog_Show(playerid, Dialog:PlayerSettingsMenu);
			return 1;
		}
		// ������
		case 11: {
			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX,
				"���������� � ������",
				"{AFE7FF}�� ������� �������:\n\
				\n\
				\t{FFFFFF}Open - Grand Theft Online {AA3333}"VERSION_STRING"{FFFFFF}.\n\
				\n\
				\n\
				{00C0DD}������ {AFE7FF}Iain Gilbert\n\
				\n\
				{00C0DD}����������:{AFE7FF}\n\
							\tPeter Steenbergen\n\
							\tRobin Kikkert\n\
							\tAsturel\n\
							\tDmitry Frolov (FP)\n\
							\tOpen-GTO Team:\n\
							\t\t�������: ziggi\n\
							\t\t����������: GhostTT, heufix, Elbi\n\
				\n\
				{00C0DD}�������������: {AFE7FF}\n\
							\tMX_Master - mxINI, Chat-Guard.\n\
							\twups - Default map icons.\n\
							\tY_Less - foreach, fixes.\n\
							\tZeeX - zcmd.\n\
				\n\
				",
				"�����", "�����"
			);
			return 1;
		}
	}
	return 1;
}

DialogResponse:PlayerReturnMenu(playerid, response, listitem, inputtext[])
{
	if (response) {
		Dialog_Show(playerid, Dialog:PlayerMenu);
	}
	return 1;
}
