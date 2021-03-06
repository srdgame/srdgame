#ifndef LISTEN_SOCKET_H_
#define LISTEN_SOCKET_H_

#include "socketdefs.h"

namespace srdgame
{
class ListenSocket
{
public:
	virtual ~ListenSocket(){};
	virtual void on_accept() = 0;
	virtual SOCKET get_fd() = 0;
	virtual void close() = 0;
};
}
#endif
