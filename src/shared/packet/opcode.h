#ifndef _OPCODE_H_
#define _OPCODE_H_

namespace srdgame
{
namespace opcode
{
/*
 * All the last member with number is the Max number but not must number
 * It means you can provide less info only for last member, without any warry
 * Only the one I have comment for you that you could not provide less data.
 *
 */
enum LoginResultFlag
{
// 0 = OK, 1 = Refect, 2 = Incorrect PWD, 3 = Block list, 4 = Not latest client, 5 = Account Expired, 6 = Banned, 7 = Server too busy, 8 = Account Limitition, 9 = Self Lock, 10 = Not permitted Group, 11 = Account erased, 12 = Hacking... 13 = Unknow for sure :-)
	LRF_OK = 0,
	LRF_RECT = 1,
	LRF_PASSWORD = 2,
	LRF_BLOCKED = 3,
	LRF_OUTDATA = 4,
	LRF_EXPIRED = 5,
	LRF_BANNED = 6,
	LRF_OVERLOAD = 7,
	LRF_ACC_LIMIT = 8,
	LRF_SELF_LOCK = 9,
	LRF_NO_PERMITTED = 10,
	LRF_ACC_ERASED = 11,
	LRF_R_U_HACKING = 12,
	LRF_UNKNOW_13 = 13,
};

// The param.Data are following below instruction if you have more than one sub param:
// This string include more than one item.  and they are sperated as below
// @sub param's index, L16 @ subparam's len, L16 @ sub param's context L(2) @ another param's index, L16
//
// Normally, you should put the smaller index before the maxer one.
//
// Below is the suggested sub params for specified opcode.
//
//
enum LoginParam
{
	LP_NAME = 0,
	LP_PASS = 1,
	LP_CRYPTO_TYPE = 3,
	// Define for yourself.
	ROLP_CLIENT_TYPE = 20,
	ROLP_VERSION = 21,
};


// OR  OR  OR  OR
// Save your own struct and for your prefer.


enum ExOpcode
{
	// ES_*** send out by server only
	// EC_*** send out by game client only.
	// Every item should marked with exactly number.
	//
	EC_NONE = 0, // For nopacket( :-) just the packet we won't handle it);
	EC_INIT = 1,
	ES_INIT = 2, // TODO:
	EC_VERSION = 5, // Provide client version.
	ES_VERSION = 6, // TODO:

	ES_DISCONNECT = 7,

	// For login
	EC_LOGIN = 10,
	ES_LOGIN = 11,
	EC_LOGOUT = 12,
	ES_LOGOUT = 13,
	EC_GET_LS_INFO = 14,
	ES_GET_LS_INFO = 15,
	EC_ADMIN_LOGIN = 18, 
	ES_ADMIN_LOGIN = 19, 

	// For server list not only for login.
	EC_SERVER_LIST = 20, 
	ES_SERVER_LIST = 21, 
	EC_ENTER_SERVER = 22,
	ES_ENTER_SERVER = 23,

	EC_CRYPTO_KEY = 40, // for key..
	ES_CRYPTO_KEY = 41, // 

	// Char server
	EC_LOGIN_TO_CHAR = 100,
	ES_LOGIN_TO_CHAR = 101,

	EC_SELECT_CHAR = 105,
	ES_SELECT_CHAR = 106,

	EC_CHAR_LIST = 110,
	ES_CHAR_LIST = 111,

	EC_CHAR_CREATE = 112,
	ES_CHAR_CREATE = 113,
	EC_CHAR_DELETE = 114,
	ES_CHAR_DELETE = 115,
	EC_CHAR_RENAME = 116,
	ES_CHAR_RENAME = 117,

	EC_CHAR_KEEP_ALIVE = 120,
	ES_CHAR_KEEP_ALIVE = 121,

	// Map server.
	EC_QUIT_GAME = 148,
	ES_QUIT_GAME = 149,
	EC_CONNECT_TO_MAP = 150,
	ES_CONNECT_TO_MAP = 151,

	EC_TICK_COUNT = 152,
	ES_TICK_COUNT = 153,

	EC_MAP_AUTH	= 154,
	ES_MAP_AUTH = 155,

	EC_LOAD_END_ACK = 156,
	ES_LOAD_END_ACK = 157,

	EC_MESSAGE = 160,
	ES_MESSAGE = 161,
	ES_PRIVATE_MSG = 162,
	ES_WIS_MESSAGE = 163,
	
	ES_LOOK_UPDATE = 164,

	ES_FRIEND_LIST = 170,
	ES_FRIEND_STATUS = 171,

	ES_EQUIP_ITEM_LIST = 174,
	ES_STACKABLE_ITEM_LIST = 175,
	ES_STORAGE_ITEM_LIST = 176,
	ES_GUILD_STORAGE_ITEM_LIST = 177,
	ES_CART_ITEM_LIST = 178,
	ES_ITEM_LIST = 179,

	EC_WALK_TO = 200,
	ES_WALK_TO = 201,
	ES_UNIT_MOVE = 203,
	EC_CHANGE_DIR = 204,
	ES_CHANGE_DIR = 205, // send to others.

	EC_EQUIP_ITEM = 230,
	ES_EQUIP_ITEM = 231,
	EC_UNEQUIP_ITEM = 232,
	ES_UNEQUIP_ITEM = 233,

	ES_ADD_ITEM = 241,

	ES_NEW_MOB = 251,
	ES_NEW_PLAYER = 253,

	ES_MOB_INFO = 255,
	ES_PLAYER_INFO = 257,

	ES_UNIT_ACTION = 301,
	ES_UNIT_DISAPPEAR = 303,

	EC_CLICK_NPC = 304,
	ES_CLICK_NPC_BUY_SELL = 305,
	ES_CLICK_NPC_ATTACK = 306,
	ES_CLICK_NPC_CASHSHOP = 307,
	EC_NPC_BUY_SELL_SELECT = 308,
	ES_NPC_SELLING_LIST = 309,
	ES_NPC_BUYING_LIST = 310,
	ES_ITEM_VALUES = 311,

	EC_GUILD_CHECK_MASTER = 400,
	ES_GUILD_CHECK_MASTER = 401,
	EC_GUILD_REQUEST_INFO = 402,
	ES_GUILD_REQUEST_INFO = 403,

	EC_REQUEST_CHAR_NAME = 410,
	ES_REQUEST_CHAR_NAME = 411, // to send 0x95
	ES_REQUEST_CHAR_NAME_EX = 421, // to send 0x195
};
}
}

#endif
