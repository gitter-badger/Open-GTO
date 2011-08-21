/*
	Author:	SLICK
	Created: 15.06.11
*/

new BanWeapons[MAX_WEAPONS] = {BAN_WEAPONS};

stock BanWeaponsLoadConfig()
{
	if(!ini_Exist(ConfigDB)) return 0;
	new file_bw = ini_Open(ConfigDB);
	new buffer[MAX_STRING];
    ini_Get(file_bw,"BanWeapons",buffer);
	SetBanWeaponsFromDBString(buffer);
	ini_Close(file_bw);
	return 1;
}

stock BanWeaponsSaveConfig()
{
	new file_bw = (!ini_Exist(ConfigDB)) ? ini_Create(ConfigDB) : ini_Open(ConfigDB);
	ini_Set(file_bw,"BanWeapons",CreateBanWeaponDBString());
	ini_Close(file_bw);
	return 1;
}

stock banweapons_OnGameModeInit()
{
	BanWeaponsLoadConfig();
	GameMSG("SERVER: (protections)BanWeapons module init");
	return 1;
}

// ������ ������, ������������ ������ ��������
stock SetBanWeaponsFromDBString(dbstring[])
{
	new idx;
	for(new i=0;i<MAX_WEAPONS;i++)
	{
		BanWeapons[i] = strval(strcharsplit(dbstring,idx,'/'));
	}
}
// ���������� ������ ��� ���������� ������������ ������
stock CreateBanWeaponDBString()
{
	new wepstr[MAX_STRING],temp[MAX_STRING];
	for(new i=0;i<MAX_WEAPONS;i++)
	{
		if(BanWeapons[i] == 0) break;
		valstr(temp,BanWeapons[i]);
		strins(wepstr,temp,strlen(wepstr));
		wepstr[strlen(wepstr)] = '/';
	}
	return wepstr;
}
//

stock banweapons_OnPlayerDeath(playerid, killerid, reason)
{
	#pragma unused playerid, reason
	new weapid = GetPlayerWeapon(killerid);
	for(new i=0; i<sizeof(BanWeapons); i++)
	{
		if(weapid == BanWeapons[i])
		{
			new str[MAX_STRING];
			ResetPlayerWeapons(killerid);
			GetWeaponName(BanWeapons[i], str, sizeof(str));
			format(str, sizeof(str), "������������� ������������ ������ ( %s )", str);
			KickPlayer(killerid,str);
			return 1;
		}
	}
	return 1;
}