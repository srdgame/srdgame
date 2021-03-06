#ifndef SHARE_H_
#define SHARE_H_
#include "defs.h"

#define TO_DC(x) size_t to_send_##x(char* buf, const Packet* packet)

namespace ro
{
size_t send_account(char* buf, const Packet* packet);
// 5: Your game's exe file is not the lastest version.
// 3: Reject by server.
//size_t to_send_0x006a(char* buf, const Packet* packet);
TO_DC(0x006a);
size_t send_6a_to_disconnect(char* buf, uint8 reason);
TO_DC(0x0283); // send out when user trying to connect to map.
TO_DC(0x0073); // map auth ok.
TO_DC(0x008e); // Send normal message to client.
TO_DC(0x017f); // send private message to client.
TO_DC(0x0097); // Wis message ????

TO_DC(0x01d7); // send the look update.
TO_DC(0x0201); // send friend list.
TO_DC(0x0206); // send friend status.

TO_DC(0x00a0); // send one item adding.
TO_DC(0x00a4); // send equip item list.
TO_DC(0x01ee); // send stackable item list.

TO_DC(0x0087); // send walk to xy ok.
TO_DC(0x007f); // send back tickcount;
TO_DC(0x0086); // send unit move.
TO_DC(0x00aa); // equip result.
TO_DC(0x00ac); // unequip result.

TO_DC(0x007c); // spawn new mob/npc.
TO_DC(0x0078); // mob/npc/ standing.
TO_DC(0x022b); // spawn new player.
TO_DC(0x022a); // player standing

TO_DC(0x008a); // Actions and Attack damage.

TO_DC(0x0080); // clear unit. disappear.

TO_DC(0x014e); // TO say whether the player is the master of Guild.

TO_DC(0x0095); // Send name.
TO_DC(0x0195); // Send name ex

TO_DC(0x018b); // ack for quit game.

TO_DC(0x009c); // tell others about one player's change dir. TODO:

TO_DC(0x00c4); // NpcBuySell.
TO_DC(0x00c6); // Npc selling items
TO_DC(0x00c7); // Send value of player's items
}

#endif
