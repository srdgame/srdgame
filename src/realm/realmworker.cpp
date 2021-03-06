#include "realmworker.h"
#include "realmsocketbase.h"
#include "realmmgr.h"
#include "packetparser.h"

#include "log.h"
using namespace srdgame;

#ifdef _DEBUG_WORKER_
#define _LogDebug_ LogDebug
#else
#define _LogDebug_ //
#endif

RealmWorker::RealmWorker(RealmSocketBase* socket) : ThreadBase(), _running(true), _socket(socket)
{
}
RealmWorker::~RealmWorker()
{
	if (is_running())
	{
		shutdown();
	}
}

bool RealmWorker::run()
{
	_LogDebug_("RealmServer", "RealmWorker::run()!!!!!!!!!!!!!!!!!!!!!!!");
	
	// return true to delete this object.
	// return false run() will be called again.
	// process the data until empty.
	if (!_socket || !_running)
	{
		_LogDebug_("RealmServer", "Quiting Realm Worker thread");
		_socket->_worker_lock.lock();
		_socket->_worker = NULL;
		_socket->_worker_lock.unlock();
		return true;
	}

	if (_socket->_worker != this)
		return true;

	Packet p;
	if (!_socket->_packets.try_pop(p) || !_running)
	{
		_LogDebug_("RealmServer", "Realm Worker finished its job!!!");
		// no data, we will quit this.
		_socket->_worker_lock.lock();
		_socket->_worker = NULL;
		_socket->_worker_lock.unlock();
		return true;
	}

	handle(&p);
	
	return false;
}

void RealmWorker::shutdown()
{
	_running =false;
}
void RealmWorker::on_close()
{
}

bool RealmWorker::is_running()
{
	return _running;
}

void RealmWorker::handle(Packet* packet)
{
	_socket->on_handle(packet);
	PacketParser::free(*packet); // Free the space that we have done.
}

