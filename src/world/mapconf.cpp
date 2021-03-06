#include "mapconf.h"
#include <fstream>
#include "log.h"

using namespace srdgame;
using namespace std;

#ifndef MAP_DEBUG
#define MAP_DEBUG
#undef _LogDebug_
#undef LN
#endif

#undef MAP_DEBUG

#ifdef MAP_DEBUG
#define _LogDebug_ LogDebug
#else
#define _LogDebug_ //
#endif

#define LN "MAP"

MapConf::MapConf(const char* fn) : _fn(fn)
{
}

MapConf::~MapConf()
{
}

bool MapConf::load()
{
	fstream file(_fn.c_str());
	if (!file.good())
		return false;

	string buf;
	
	while (getline(file, buf))
	{
		if (buf.size() < 5)
			continue;
		if (buf[0] == '/' && buf[1] == '/')
			continue;

		_LogDebug_("MAP", "Loaded String: %s", buf.c_str());
		if (buf.find("map: ") != 0)
			continue;

		_maps.push_back(buf.substr(5));
	}
	file.close();
	return true;
}
