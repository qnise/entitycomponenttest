#pragma once
#include <map>

class GunBase 
{
public:
	GunBase() {};
	virtual ~GunBase() {};

	enum eGunStatsTypes
	{
		projectilesPerShot,
		magSize,
		damage,
		weakspotMultiplier,
		ROF,
		reloadTime,
		bulletSpread,
		bulletSpreadMultiplier,
		max_eGunStatsTypes //east wind all last!! 
	};

	
	std::map<int, float> getMap() { return mapBaseStats; };
	std::map<int, float> initBaseStats() 
	{
		for (int i = 0; i < max_eGunStatsTypes; i++)
		{
			mapBaseStats.emplace(i, 0);
		}
		mapBaseStats.emplace(max_eGunStatsTypes, 0);
		return mapBaseStats;
	}

private:
	std::map<int, float> mapBaseStats;
};