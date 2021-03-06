#ifndef LOGIN_SOCKET_H_
#define LOGIN_SOCKET_H_

#include "loginsocketbase.h"
#include "packetdefs.h"
#include "userinfo.h"
#include "rouser.h"
using ro::RoUser;
namespace srdgame
{
class LoginWorker;
struct Packet;

// Handle the communication with game clients.
class LoginSocket : public LoginSocketBase
{
	friend class LoginWorker;
	friend class LoginAuth;
public:
	LoginSocket();
	virtual ~LoginSocket();
	//virtual void on_rev();
	virtual void on_send();
	virtual void on_connect();
	virtual void on_close();

	UserInfoEx<RoUser>* _info;
public:
	// Worker will call this to response one packet.
	virtual void on_handle(Packet* packet);

protected:
};
}

#endif
