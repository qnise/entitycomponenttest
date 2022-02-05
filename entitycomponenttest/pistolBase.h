#pragma once
#include "gunBaseBase.h"

class pistol
{
	private:
	std::map<int, float>mapPistolBaseStats = gunBase.getMap();
	mapPistolBaseStats.at(GunBase::eGunStatsTypes::ROF) = 10;
};