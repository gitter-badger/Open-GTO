//
// Created:	 05.09.06
// Aurthor:	Iain Gilbert
//
/*
	������������� ZiGGi
*/

#if defined _gtoutils_included
  #endinput
#endif

#define _gtoutils_included
#pragma library gtoutils

#define MODE_INFO_VERSION 1
#define MODE_INFO_NAME    2

enum CoordInfo {
	Float:Coord_X,
	Float:Coord_Y,
	Float:Coord_Z
}

new nullstr[MAX_STRING];

#define GivePVarInt(%1,%2,%3) SetPVarInt(%1,%2, GetPVarInt(%1,%2)+%3)
#define set(%0,%1) strmid(%0,%1, 0, 160, MAX_STRING + 32)
#define IS_IN_RANGE(%0,%1,%2) (((%0) - ((%1) + cellmin)) < (((%2) + 1) - ((%1) + cellmin)))

// �������������� ������� '���' mxINI
#define ini_fileRemove	fremove
#define ini_fileExist	fexist

// �� �������
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))

#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

// strcmp empty string fix
stock strcmpEx(const string1[], const string2[], bool:ignorecase=false, length=cellmax)
{
	if (string1[0])
	{
		if (string2[0])
		{
			return strcmp(string1, string2, ignorecase, length);
		}
		else
		{
			// Positive as st1 is greater (strcmp spec).
			return 1;
		}
	}
	else
	{
		if (string2[0])
		{
			// Negative as str2 is greater.
			return -1;
		}
		else
		{
			// The strings are the same (empty).
			return 0;
		}
	}
}
#define strcmp strcmpEx

stock timestamp_to_format_date(unix_timestamp)
{
	new year, month, day, hour, minute, second;
	timestamp_to_date(unix_timestamp, year, month, day, hour, minute, second);

	new string[MAX_STRING];
	format(string, sizeof(string), "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
	return string;
}

stock PlayerPlaySoundOnPlayer(playerid, soundid)
{
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	return PlayerPlaySound(playerid, soundid, pos[0], pos[1], pos[2]);
}

stock PlaySoundForPlayersInRange(soundid, Float:range, Float:x, Float:y, Float:z)
{
	foreach (new i : Player) {
	    if (IsPlayerInRangeOfPoint(i, range, x, y, z)) {
		    PlayerPlaySound(i, soundid, x, y, z);
	    }
	}
}

stock FormatPosition(position)
{
	new string[MAX_STRING];
	switch (position)
	{
		case 1: set(string, "1st!");
		case 2: set(string, "2nd!");
		case 3: set(string, "3rd!");
		default: format(string, sizeof(string), "%dth", position);
	}
	return string;
}

stock strcharsplit(const string[], &index, seperator=' ')
{
	new result[20], i = 0;
	if (index != 0 && string[index] != '\0') index++;
	while (string[index] && string[index] != seperator && string[index] != '\r' && string[index] != '\n')
	{
		result[i++] = string[index++];
	}
	return result;
}

stock mathrandom(min, max)
{
	return (random(max - min + 1) + min);
}

stock NameCharCheck(string[MAX_PLAYER_NAME+1])
{
	if (!strcmp(string, "Unknown", true) || IsNumeric(string)) return 0;
	for (new i = strlen(string)-1; i >= 0; i--)
	{
		switch (string[i])
		{
			case ALLOWED_NICK_SYMBOLS: continue;
			default: return 0;
		}
	}
	if (IsIpAddress(string))
	{
		return 0;
	}
	return 1;
}

stock PlayerCount()
{
	return Iter_Count(Player);
}

stock SetPlayerPosEx(playerid, Float:X, Float:Y, Float:Z, Float:Angle, Interior, World=0)
{
	SetPlayerInterior(playerid, Interior);
	SetPlayerFacingAngle(playerid, Angle);
	SetPlayerVirtualWorld(playerid, World);
	SetPlayerPos(playerid, X, Y, Z);
	SetCameraBehindPlayer(playerid);
}

stock pow(value, degree)
{
	new result = 1;
	while (degree--) {
		result *= value;
	}
	return result;
}

stock IsValidChars(string[])
{
	for (new i = 0; string[i] != '\0'; i++) {
		switch (string[i]) {
			case ALLOWED_STRING_SYMBOLS: {
				continue;
			}
			default: {
				return 0;
			}
		}
	}
	return 1;
}

stock IsNumeric(const string[])
{
	for (new i = 0; string[i] != '\0'; i++) {
		if (!IS_IN_RANGE(string[i], '0', '9')) {
			return 0;
		}
	}
	return 1;
}

stock IsIpAddress(string[])
{
	new
		octet,
		j = 100;

	for (new i = 0; string[i] != '\0'; i++) {
		if (j != 0 && IS_IN_RANGE(string[i], '0', '9')) {
			octet += (string[i] - '0') * j;
			j /= 10;
		} else if (string[i] == '.') {
			if (IS_IN_RANGE(octet, 0, 255)) {
				j = 100;
				octet = 0;
			} else {
				return 0;
			}
		} else {
			return 0;
		}
	}
	return 1;
}

stock GetVehicleSpeed(vehicleid)
{
	new Float:pos[3];
	GetVehicleVelocity(vehicleid, pos[0], pos[1], pos[2]);
	return floatround( floatsqroot(pos[0]*pos[0] + pos[1]*pos[1] + pos[2]*pos[2]) * 100 );
}

stock Float:GetDistanceBetweenPoints(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
	return VectorSize(x1-x2, y1-y2, z1-z2);
}

stock GetCoordsBefore(Float:x, Float:y, Float:a, Float:distance, &Float:res_x, &Float:res_y)
{
	res_x = x + (distance * floatsin(-a, degrees));
	res_y = y + (distance * floatcos(-a, degrees));
}

stock GetCoordsBeforePlayer(playerid, Float:distance, &Float:x, &Float:y)
{
	new Float:pos[4];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	GetPlayerFacingAngle(playerid, pos[3]);

	GetCoordsBefore(pos[0], pos[1], pos[3], distance, x, y);
}

stock GetVehicleCoordsBeforePlayer(&Float:x, &Float:y, &Float:z, &Float:a, playerid, modelid = -1)
{
	new Float:size[3];
	if (modelid != -1) {
		GetVehicleModelInfo(modelid, VEHICLE_MODEL_INFO_SIZE, size[0], size[1], size[2]);
	} else {
		size[0] = 1.5;
		size[2] = 1.0;
	}

	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);

	GetCoordsBefore(x, y, a, size[0] + 0.5, x, y);

	z -= size[2] * 0.25;

	a += 90.0;
	if (a > 360.0) {
		a -= 360.0;
	}
}


stock GenerateRandomString(result_str[], length, size = sizeof(result_str), alphabet[] = DEFAULT_ALPHABET, alphabet_size = sizeof(alphabet))
{
	result_str[0] = '\0';

	if (length > size) {
		length = size - 1;
	}
	
	if (length < 1) {
		return 0;
	}

	for (new i = 0; i < length; i++) {
		result_str[i] = alphabet[ random(alphabet_size) ];
	}

	return 1;
}

stock SendMessageToBesidePlayers(message[], Float:range, Float:x, Float:y, Float:z)
{
	foreach (new playerid : Player) {
		if (IsPlayerInRangeOfPoint(playerid, range, x, y, z)) {
			SendClientMessage(playerid, -1, message);
		}
	}
}

/*

	For UpdateVehicleDamageStatus

*/

stock decode_panels(panels,&flp,&frp,&rlp,&rrp,&windshield,&front_bumper,&rear_bumper)
{
	flp = panels >> 0 & 0xF;
	frp = panels >> 4 & 0xF;
	rlp = panels >> 8 & 0xF;
	rrp = panels >> 12 & 0xF;
	windshield = panels >> 16 & 0xF;
	front_bumper = panels >> 20 & 0xF;
	rear_bumper = panels >> 24 & 0xF;
}

stock decode_doors(doors,&driver_door,&passenger_door,&bonnet,&boot)
{
	bonnet = doors & 0x7;
	boot = doors >> 8 & 0x7;
	driver_door = doors >> 16 & 0x7;
	passenger_door = doors >> 24 & 0x7;
}

stock decode_lights(lights,&light1,&light2,&light3,&light4)
{
	light1 = lights >> 0 & 0x1;
	light2 = lights >> 1 & 0x1;
	light3 = lights >> 2 & 0x1;
	light4 = lights >> 3 & 0x1;
}

stock decode_tires(tires,&tyre1,&tyre2,&tyre3,&tyre4)
{
	tyre1 = tires >> 0 & 0x1;
	tyre2 = tires >> 1 & 0x1;
	tyre3 = tires >> 2 & 0x1;
	tyre4 = tires >> 3 & 0x1;
}

stock encode_panels(flp, frp, rlp, rrp, windshield, front_bumper, rear_bumper)
{
	return flp | (frp << 4) | (rlp << 8) | (rrp << 12) | (windshield << 16) | (front_bumper << 20) | (rear_bumper << 24);
}

stock encode_doors(bonnet, boot, driver_door, passenger_door, behind_driver_door, behind_passenger_door)
{
	#pragma unused behind_driver_door
	#pragma unused behind_passenger_door
	return bonnet | (boot << 8) | (driver_door << 16) | (passenger_door << 24);
}

stock encode_lights(light1, light2, light3, light4)
{
	return light1 | (light2 << 1) | (light3 << 2) | (light4 << 3);
}

stock encode_tires(tire1, tire2, tire3, tire4)
{
	return tire1 | (tire2 << 1) | (tire3 << 2) | (tire4 << 3);
}

stock encode_tires_bike(rear, front)
{
	return rear | (front << 1);
}

stock Chat_Clear(playerid)
{
	for (new i = 0; i < 20; i++) {
		SendClientMessage(playerid, -1, "");
	}
}

stock Chat_ClearAll()
{
	for (new i = 0; i < 20; i++) {
		SendClientMessageToAll(-1, "");
	}
}

stock StripNL(str[]) // by Y_Less
{
	new i = strlen(str);
	while (i-- && str[i] <= ' ') str[i] = '\0';
}

stock FixAscii(text[])
{
	for (new i = 0; text[i] != '\0'; i++) {
		text[i] &= 0xFF;
	}
}

stock InsertSpacesInString(string[], const size = sizeof(string), const between_pos = 3)
{
	for (new i = 1, length = strlen(string); i < length; i++) {
		if ((length - i) % between_pos == 0) {
			strins(string, " ", i, size);
			i++;
			length++;
		}
	}
}