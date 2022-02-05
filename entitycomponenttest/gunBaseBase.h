#pragma once
#include <map>
class GunBase
{
	public:
		enum eGunStatsTypes
		{
			projectilesPerShot, //0
			magSize,
			damage,
			weakspotMultiplier,
			ROF,
			reloadTime,
			bulletSpread,
			bulletSpreadMultiplier,
			max_eGunStatsTypes //east wind all last!! 
		};

		std::map<int, float> mapGunStats{
	{projectilesPerShot, iProjectilesPerShot},
	{magSize, iMagSize},
	{damage, iDamage},
	{weakspotMultiplier, fWeakspotMultiplier},
	{ROF, iROF},
	{reloadTime, fReloadTime},
	{bulletSpread, fBulletSpread},
	{bulletSpreadMultiplier, fBulletSpreadMultiplier}
		};

		std::map<int, float> getMap() { return mapGunStats; };

	private:
		int iProjectilesPerShot = 1,
					iMagSize = 8,
					iDamage = 2,
					iROF = 60; //rate of fire, rounds per min

		float fWeakspotMultiplier = 2.0f,
					fReloadTime = 4.0f,
					fBulletSpread = 10.0f,
					fBulletSpreadMultiplier = 1.1f;
	
};

GunBase gunBase;