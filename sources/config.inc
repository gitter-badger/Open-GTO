/*
	
	About: defines and default settings
	Author: ziggi

*/

#if defined _config_included
	#endinput
#endif

#define _config_included
#pragma library config


/*
 * Core settings
 */

#pragma dynamic 13000

#define MAX_STRING  128
#define MAX_NAME    40
#define MAX_IP      16


/*
 * System settings
 */

//#define FS_USING // ���� �����������, �� ���������� ����� � ������ ������������� � FS (fixes, api)

#define MODE_NAME       "Open-GTO"
#define VERSION_MAJOR   2
#define VERSION_MINOR   0
#define VERSION_BUILD   0
#define VERSION_EXTRA   "-alpha"
#define VERSION_NAME    "New generation"

#define VERSION_STRING          "v2.0.0-alpha" // �� ����������� ���� ������ ����������: "v" #VERSION_MAJOR "." #VERSION_MINOR "." #VERSION_BUILD VERSION_EXTRA
#define GAMEMODE_TEXT           MODE_NAME " " VERSION_STRING
#define DATA_FILES_FORMAT       ".gto" // ����������(.txt ��� ������������ ������ �� ���� GNU/Linux �� �������������)
#define DATA_FILES_FOLDER       "open-gto/" // ������� � scriptfiles/, ��� �������� ����� Open-GTO

#define LANGUAGE_USE            "russian" // ������������ ����

#define USE_PLAYER_PED_ANIMS
#define USED_PLAYER_MARKERS     PLAYER_MARKERS_MODE_GLOBAL

#define PASSWORD_ENCRYPT_ENABLED // ���� �����������, �� ������ � ����� ������ ����� �����������
#define PASSWORD_SALT_LENGTH  12 // ����� ���� ��� ����
#define PASSWORD_HASH_LENGTH  64 // ����� ����

#define DEFAULT_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

#define SERVER_REAL_TIME            1 // ������� ����� ������������� �������� ������� �������
#define SERVER_REAL_TIME_OFFSET     0 // �������� ������� ������������ �������

#define MAX_QUESTS          255
#define MAX_FIGHTS          6 // ������������ ���������� ������ ������ (����� �� ������)

#define WORLD_SAVE_TIME     300000 // 1 ���, �� ��� ���-�� ���������� ����������� ���������� ����� ����(300000 - 5 �����)

#define LOG_PRINTING // ���� ����������, �� ������� ������� ��������� � ������� �������
// ����(��������� �� ���������) 1 ���, 0 ����
#define LOG_GAME_ENABLED    1 // ����������� ��������� ���������
#define LOG_DEBUG_ENABLED   1 // ����������� ���������� ���������
#define LOG_PLAYER_ENABLED  1 // ����������� �������� ������ � ���

#define KEY_USING      KEY_YES // ������ 'Y' - �������� �� �������� ��������(����, ������� ����������...), ������/�������
#define KEY_NAME       "Y"

// ����������� ������� � ���������
#define ALLOWED_STRING_SYMBOLS      'a'..'z','A'..'Z','0'..'9','_','[',']','=','(',')',' '
#define ALLOWED_STRING_SYMBOLS_STR  "'a'..'z','A'..'Z','0'..'9','_','[',']','=','(',')',' '"
#define ALLOWED_NICK_SYMBOLS        'a'..'z','A'..'Z','0'..'9','_','[',']','.','=','(',')'
#define ALLOWED_NICK_SYMBOLS_STR    "'a'..'z','A'..'Z','0'..'9','_','[',']','.','=','(',')'"

// ����������� ������(by wups, ��������������)
#define MAPICON_PAY_SPRAY
#define MAPICON_TUNE

#define MAX_PLAYER_LOGIN_ATTEMPT    3 // ������������ ���������� ������� �����

#define MIN_SEND_SYMBOLS  3 // ����������� ���-�� ������������ �������� � ��
#define MAX_SEND_SYMBOLS  100 // ������������ ���-�� ������������ �������� � ��

#define MIN_NAME_LEN      3
#define MAX_NAME_LEN      20

#define MIN_PASS_LEN      3
#define MAX_PASS_LEN      40


/*
 * Protection settings
 */

#define ANTI_HEALTH_HACK_ENABLED      1 // ������ �� ���� �� ��������

#define ANTI_HIGH_PING_ENABLED        1 // ������ �� �������� �����
#define MAXIMAL_PING                  500 // ����, ��� ������� ������

#define ANTI_IDLE_ENABLED             1 // ������ �� ��� �� ������ ��������
#define MAX_IDLE_TIME                 5 // ���-�� �����, ����� ������� ������

#define CHAT_GUARD_ENABLED            1 // ������ ����
#define ANTI_RCON_HACK_ENABLED        1 // ������ �� ������ rcon ������
#define ANTI_ARMOUR_HACK_ENABLED      1 // ������ �� ���� �� �����
#define ANTI_SPECIAL_ACTION_ENABLED   1 // ������ �� ��������� special action

#define ANTI_WEAPON_HACK_ENABLED      1 // ������ �� ���� �� ������ � �������
#define ANTI_WEAPON_HACK_DELAY_TIME   1000 // ����������� ����� ����������

#define ANTI_VEHICLE_TELEPORT_ENABLED 1 // ������ �� ������������ ����������
#define ANTI_VEHICLE_TELEPORT_DISTANCE 20.0

#define ANTI_SPEED_HACK_ENABLED	      0 // ������ �� speedhack, airbreak, ������������(���� ����������� ������ ������������, �������������� �������� ����)
#define ANTI_SPEED_HACK_CHECK_TIME    900 // ����� ������� ��� ������ �� ��������


/*
 * Gameplay settings
 */

// start player settings
#define PLAYER_START_LEVEL    1 // �������, ������� ����� ������ ����� �����������
#define PLAYER_START_MONEY    1500 // ���-�� ��������� �����
#define PLAYER_START_WEAPON   {WEAPON_COLT45, 200}
//#define PLAYER_START_SKIN     95 // ���� �� ��������� (���� ���������, �� ����� ����� �����������)

// player
#define MIN_HEALTH            35.0 // �����������(���������) ���-�� ��������
#define MAX_HEALTH            100.0 // ������������ ���-�� ��������
#define HEALTH_TARIF          3.0 // ������� ���������� ������������� �������� �� ���, �������: MIN_HEALTH + (GetPlayerLevel(playerid) * HEALTH_TARIF)
#define HEALTH_REGEN_TARIF    0.1 // ������� ���-�� ����������������� ��������, �������: (GetPlayerLevel(id) * HEALTH_REGEN_TARIF)

#define MAX_LEVEL             30 // ������������ ������� ������
#define XP_RATE               50 // ����������� ���������� ����� ��� ������, ������� (XP_RATE * (3 * level + 2) * (level - 1))

#define MAX_MONEY             999999999 // ������������ ���-�� �����, ������� ����� ����� �����

#define CHANGE_NICK_COST      100000 // ���-�� �����, ��������� ��� ����� ����
#define CHANGE_PASS_COST      5000 // ���-�� �����, ��������� ��� ����� ������

#define PLAYER_XP_PREMIUM_PROFIT  10 // ������� ������ �������� �� PLAYER_XP_PREMIUM_PROFIT ��������� ������ �����

#define MIN_REPORTS_FOR_JAIL  3 // ����������� ���������� �������� ��� ������� � ������
#define SKYDIVE_TIME          (5 * 60) // �����, ����� ������� ����� ����� ����� ������������ /skydive, � ��������
#define SYS_WEATHER_UPDATE    20 // �����, ����� ������� ��������� ��������� ������, � �������, ���� 0, �� ���������
#define TELEPORTS_PAUSE_TIME  300 // ����� ����� ����������������, ����� ������� ����� ��������� �����������������, � ��������

// on death
#define PLAYER_XP_KILL_TARIF            4 // �������� �� ���������� ����������� ����� ��� ��������, ��������� � ������� player_OnPlayerKill
#define PLAYER_XP_DEATH_MINUS_PROC      3 // ������� ��������� XP ��������� �� ��� ���������� �����
#define PLAYER_MONEY_DEATH_MINUS_PROC   20 // ������� ��������� ����� ���������

// admin
#define ADMIN_TELEPORT_ENABLED       1 // ��������-�� ������� ������������ ������������� �� ����� �� �����
#define ADMIN_TELEPORT_MIN_STATUS    STATUS_LEVEL_ADMIN // ����������� ������� ������� ��� ������������

// lottery
#define LOTTERY_ENABLED      1 // �������-�� ������ �������
#define LOTTERY_TIME         60 // ����� ���������, � ��������
#define LOTTERY_WIN_MONEY    200000 // ���������� ����� ���������� � �������
#define LOTTERY_TICKET_COST  5000 // ���� ����������� ������

// skins
#define SKINS_COST    0 // ���� ������� �����
#define SKINS_IGNORE  0, 74  // ������ ������������ ������
#define SKINS_MAXID   311
#define SKINS_MINID   1

// groundhold
#define GROUNDHOLD_ENABLED    1 // ����� ��������
#define GROUNDHOLD_HOLD_TIME  2 // �������� ������ ����� ��� ������ �� ����

// bank
#define BANK_PROFIT      2 // ������� ���������� ������� �� �������� � �����
#define BANK_PROFIT_PREMIUM  (BANK_PROFIT * 2) // ������� ���������� ������� �� �������� � ����� ��� ������� � �������
#define MAX_BANK_MONEY   1000000000 // ������������ ���������� �����, ������� ����� ������� � �����

// payday
#define PAYDAY_BASE_PAY  25 // PayDay ����� �� ������
#define PAYDAY_CUTOFF    (MAX_MONEY / 2) // ���-�� �����, ��� ������� ���������� �������� ������ �� PayDay
#define PAYDAY_PAYXP     200 // PayDay ����� �� ����

// weapon
#define WEAPON_SKILL_ENABLED  1 // �������� �������� ������ (���� ���������, �� ������ �� ���������)
#define WEAPON_SKILL_SPEED    10 // ���������� ��������� ������ �� ���� ��������
#define WEAPON_DROP_ENABLED   1 // �������� ��������� ������
#define WEAPON_DROP_TIME      10 // �����, ����� �������� �������� ������, �������� �� ������, � ��������
#define WEAPON_DROP_BULL      5 // ������� ��������� ���������� ������ ������� �� ������
#define MAX_DROPPED_WEAPONS   64 // ������������ ���������� ��������� ������ �������������(� ���� �������)
#define WEAPON_DRIVEBY_DISABLED WEAPON_COLT45, WEAPON_SILENCED, WEAPON_DEAGLE, WEAPON_SHOTGSPA

// house
#define MAX_PLAYER_HOUSES          3 // ���������� �����, ������� ����� ����� �����(����� ������� �� �������������)
#define HOUSE_UPGRADE_ARMOUR_COST  100000
#define HOUSE_UPGRADE_HEALTH_COST  100000
#define HOUSE_UPGRADE_USE_TIME     300 // ����� ����� ������� ����� ������������ ������� � ���� (� ��������)
//#define BUY_ALL_HOUSES // ��������� ��������� �������� ����� ����(���� ���������������� �� ����� ���� ������ ��������)

// business
#define MAX_PLAYER_BUSINESS  3 // ���������� ��������, ������� ����� ����� �����(����� ������� �� �������������)
#define MAX_BUSINESS_LEVEL   30 // ������������ ������� �������� �������
#define UPGRADE_TARIF        10 // ����� ����� �� ��������� ������, �������: (Businesses[id][Business_Upgrade]+1) * Businesses[id][Business_Value] * UPGRADE_TARIF
//#define BUY_ALL_BUSINESS // ��������� ��������� �������� ����� �������(���� ���������������� �� ����� ������� ������ ��������)
#define BUSINESS_UNLOGIN_SELL_DAYS  14 // ���������� ����, ����� ������� ������ ����� ������, ���� ����� �� ������ � ����

// other
#define MAX_GULPS            3 // ������������ ���������� ������� �� �������
#define MAX_COUNTDOWN        4 // ���-�� ������ ��� ������� ����� � ��
#define GPICKUP_RESPAWN_TIME 10 // ���-�� ������ ����� ������� ����� �������� �������� �����
/*
 * Vehicle settings
 */

#define PLAYER_VEHICLES_INCREASE_LEVELS  0, 15, 24, 30 // ������, ��� ���������� ������� ������������� ����. ��������� ������
#define VEHSHOP_CAR_CHANGE_TIME  3 // ���������� �����, ����� ������� ��������� � �������� ��������
#define VEHICLE_RESPAWN_TIME     600 // ����� �������� ���������� � �������� (86400 - ���� ����) 
#define OLD_ENGINE_DO // ��� � ��������� - ��������, ����� - ������(���� �����������)

// ��������� � VEHICLE_LIGHTS_ON_TIME � VEHICLE_LIGHTS_OFF_TIME �������� 0, ���� ������, ����� ���� ���������� � ����� �����
#define VEHICLE_LIGHTS_ON_TIME   16 // �����(�����), ����� ���� ���������� ����� ������������� ����������
#define VEHICLE_LIGHTS_OFF_TIME  7 // �����(�����), ����� ���� ���������� ����� ������������� �����������

#define VEHICLE_DAMAGE_ENABLE_TIRES // �������� ������������ ��� � ������� ����������
//#define VEHICLE_DAMAGE_ENABLE_DAMAGE // �������� ���� � ������� ����������

// ��������� � ������
#define VEHICLE_FUEL_ENABLED     1
#define VEHICLE_FUEL_TD_FONT     2 // ������������ id ������ � ����������
#define VEHICLE_FUEL_SPEED       2 // ���������� �������, ������������� �� 1 �������
#define VEHICLE_FUEL_TARIF       10 // ���� ������ ����� �������, � ��������


/*
 * Gang settings
 */

#define MAX_GANGS           MAX_PLAYERS // �������� ���� ������
#define MAX_GANG_SIZE       12 // ������������ ���-�� ����� � �����

#define MIN_GANG_NAME_LEN   3 // ����������� ����� ����� �����
#define MAX_GANG_NAME_LEN   40 // ������������ ����� ����� �����

#define MAX_GANG_MOTD_LEN   64 // ������������ ����� ���������� �����

#define GANG_CREATE_COST    500000 // ���-�� �����, ��������� �� �������� �����
#define GANG_COLOR_COST    20000 // ���-�� �����, ��������� �� ����� ����� �����

#define MAX_GANG_BANK       2000000000 // ������������ ���������� �����, ������� ����� ������� � ����� �����


/*
 * Mission settings
 */

// trucker
#define TRUCKER_ENABLED             1
#define TRUCKER_XP_RATE             100 // ����������� ����� �� �����
#define TRUCKER_MONEY_RATE          200
#define TRUCKER_TIME_GET_TRAILER    120 // ���-�� ������, �������� �� ����������� ���� � ������
#define TRUCKER_MISSION_TRY_COUNT   2 // ���-�� ���������� � ������������� ������ �� ��������
#define TRUCKER_MISSION_TIME        480 // ����� �������� �� ����������� ������
#define TRUCKER_PAUSE_MISSION_TIME  300 // ����� �������� ����� ��������, � ��������
#define TRUCKER_CAR_SPAWN_TIME      300
#define TRUCKER_BACK_CAR_TIME       60

// �������
#define SWAGUP_ENABLED      1 // �������� �� ������� ������
#define SWAGUP_MONEY_RATE   300 // ����������� ���������� ����� �� �������� �������
#define SWAGUP_XP_RATE      300 // ����������� ���������� ����� �� �������� �������
#define SWAGUP_PAUSE_TIME   480000

/*
 * Functions
 */

stock config_OnGameModeInit()
{
	SetGameModeText(GAMEMODE_TEXT);
#if defined USE_PLAYER_PED_ANIMS
	UsePlayerPedAnims();
#endif
	ShowPlayerMarkers(USED_PLAYER_MARKERS);
	ShowNameTags(1);
	ManualVehicleEngineAndLights();
	EnableStuntBonusForAll(0);
	
	new rcon_command[64];
	rcon_command = lang_GetLang();
	format(rcon_command, sizeof(rcon_command), "language %c%s", toupper(rcon_command[0]), rcon_command[1]);
	SendRconCommand(rcon_command);

	Log_Game("SERVER: Config module init");
	return 1;
}
