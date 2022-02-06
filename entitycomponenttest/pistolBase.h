#pragma once
#include "gunBase.h"

class pistol
{
	public:
		pistol();
		~pistol();

		std::map<int, float>getBaseStats();

	private:
		GunBase gunBase;
		std::map<int, float>mapPistolBaseStats;
};


