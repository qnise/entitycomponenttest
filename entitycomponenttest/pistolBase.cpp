#include "pistolBase.h"

//initialize as base, edit specific charecteristics in {}
pistol::pistol() : mapPistolBaseStats(gunBase.getMap())
{
	mapPistolBaseStats[GunBase::eGunStatsTypes::bulletSpread] = 0;
	mapPistolBaseStats[GunBase::eGunStatsTypes::bulletSpreadMultiplier] = 1.1f;
};

pistol::~pistol()
{
};

std::map<int, float> pistol::getBaseStats()
{
	return mapPistolBaseStats;
};
