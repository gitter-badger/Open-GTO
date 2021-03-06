/*

	About: vehicle user menu
	Author: ziggi
	
*/

#if defined _pl_vehicle_menu_included
  #endinput
#endif

#define _pl_vehicle_menu_included
#pragma library pl_vehicle_menu


DialogCreate:PlayerVehicleMenu(playerid)
{
	if (GetPlayerVehicleCount(playerid) == 0) {
		Dialog_MessageEx(playerid, Dialog:PlayerReturnMenu,
			_(PLAYER_MENU_VEHICLE_CAPTION),
			_(PLAYER_MENU_VEHICLE_NO_VEHICLES),
			_(PLAYER_MENU_VEHICLE_BUTTON_BACK), _(PLAYER_MENU_VEHICLE_BUTTON_CANCEL)
		);
		return 1;
	}

	new string[MAX_NAME * MAX_PLAYER_VEHICLES];

	for (new i = 0; i < MAX_PLAYER_VEHICLES; i++) {
		if (IsValidPlayerVehicleSlot(playerid, i)) {
			format(string, sizeof(string), "%s%s\n", string, GetVehicleName(PlayerVehicle[playerid][i][pv_Model]));
		}
	}

	Dialog_Open(playerid, Dialog:PlayerVehicleMenu, DIALOG_STYLE_LIST,
		_(PLAYER_MENU_VEHICLE_CAPTION),
		string,
		_(PLAYER_MENU_VEHICLE_BUTTON_NEXT), _(PLAYER_MENU_VEHICLE_BUTTON_BACK)
	);
	return 1;
}

DialogResponse:PlayerVehicleMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerMenu);
		return 1;
	}

	pl_veh_menu_SetItemID(playerid, listitem);
	Dialog_Show(playerid, Dialog:PlayerVehicleList);
	return 1;
}

DialogCreate:PlayerVehicleList(playerid)
{
	new veh_slot = pl_veh_menu_GetItemID(playerid);

	for (new i = 0; i < MAX_PLAYER_VEHICLES; i++) {
		if (!IsValidPlayerVehicleSlot(playerid, i)) {
			veh_slot++;
			continue;
		}
		if (i == veh_slot) {
			break;
		}
	}

	pl_veh_menu_SetVehicleSlot(playerid, veh_slot);

	new string[MAX_LANG_VALUE_STRING * 3];
	format(string, sizeof(string), _(PLAYER_MENU_VEHICLE_LIST), GetPlayerVehicleCostBySlot(playerid, veh_slot) / 2);
	
	Dialog_Open(playerid, Dialog:PlayerVehicleList, DIALOG_STYLE_LIST,
		_(PLAYER_MENU_VEHICLE_CAPTION),
		string,
		_(PLAYER_MENU_VEHICLE_BUTTON_SELECT), _(PLAYER_MENU_VEHICLE_BUTTON_BACK)
	);
}

DialogResponse:PlayerVehicleList(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerVehicleMenu);
		return 1;
	}

	switch (listitem) {
		// ����������� � ����
		case 0: {
			if (GetPlayerInterior(playerid) != 0) {
				Dialog_MessageEx(playerid, Dialog:PlayerVehicleReturnMenu,
					_(PLAYER_MENU_VEHICLE_CAPTION),
					_(PLAYER_MENU_VEHICLE_ERROR_INTERIOR),
					_(PLAYER_MENU_VEHICLE_BUTTON_BACK), _(PLAYER_MENU_VEHICLE_BUTTON_CANCEL)
				);
				return 0;
			}

			new slot = pl_veh_menu_GetVehicleSlot(playerid);
			new model = GetPlayerVehicleModelBySlot(playerid, slot);

			new Float:pos[4];
			GetVehicleCoordsBeforePlayer(pos[0], pos[1], pos[2], pos[3], playerid, model);

			CreatePlayerVehicle(playerid, slot, pos[0], pos[1], pos[2], pos[3]);
			return 1;
		}
		// �������
		case 1: {
			new slot = pl_veh_menu_GetVehicleSlot(playerid);
			
			GivePlayerMoney(playerid, GetPlayerVehicleCostBySlot(playerid, slot) / 2, 1);
			RemovePlayerVehicle(playerid, slot);
			
			Dialog_MessageEx(playerid, Dialog:PlayerVehicleReturnMenu,
				_(PLAYER_MENU_VEHICLE_CAPTION),
				_(PLAYER_MENU_VEHICLE_SELLED),
				_(PLAYER_MENU_VEHICLE_BUTTON_BACK), _(PLAYER_MENU_VEHICLE_BUTTON_CANCEL)
			);
			return 1;
		}
		// ����� ������
		case 2: {
			RemovePlayerVehicleComponents(playerid, pl_veh_menu_GetVehicleSlot(playerid));
	
			Dialog_MessageEx(playerid, Dialog:PlayerVehicleReturnMenu,
				_(PLAYER_MENU_VEHICLE_CAPTION),
				_(PLAYER_MENU_VEHICLE_TUNING_REMOVED),
				_(PLAYER_MENU_VEHICLE_BUTTON_BACK), _(PLAYER_MENU_VEHICLE_BUTTON_CANCEL)
			);
			return 1;
		}
	}

	pl_veh_menu_CleanMenuGarbage(playerid);
	return 1;
}

DialogResponse:PlayerVehicleReturnMenu(playerid, response, listitem, inputtext[])
{
	if (response) {
		Dialog_Show(playerid, Dialog:PlayerVehicleMenu);
	}
	return 1;
}

stock pl_veh_menu_GetItemID(playerid)
{
	return GetPVarInt(playerid, "pl_veh_menu_ItemID");
}

stock pl_veh_menu_SetItemID(playerid, itemid)
{
	SetPVarInt(playerid, "pl_veh_menu_ItemID", itemid);
}

stock pl_veh_menu_GetVehicleSlot(playerid)
{
	return GetPVarInt(playerid, "pl_veh_menu_VehicleSlot");
}

stock pl_veh_menu_SetVehicleSlot(playerid, itemid)
{
	SetPVarInt(playerid, "pl_veh_menu_VehicleSlot", itemid);
}

stock pl_veh_menu_CleanMenuGarbage(playerid)
{
	DeletePVar(playerid, "pl_veh_menu_VehicleSlot");
	DeletePVar(playerid, "pl_veh_menu_ItemID");
}
