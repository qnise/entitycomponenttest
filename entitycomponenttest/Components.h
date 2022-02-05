#pragma once
//component class just dump every component in here

class cComponent
{
public:
	enum eComponentTypes {
		base,
		barrel,
		grip,
		sight,
		stock,
		max_eComponentType //keep at end
	};

	int getComponentType();
	int getComponentUID();

	float math(float value1, char _operator, float value2)
	{
		switch (_operator)
		{

		}
	}

	//template <eGunStatsTypes gunStatType>
	//float modifyGunStat(char _operator, float value) //return end value
	//{
	//	switch (gunStatType)
	//	{
	//	case projectilesPerShot: //math(getGunROF(), _operator, value); return getGunROF; break;
	//	}
	//}

	//modifyGunStat<ROF>('*', 5.f);
private:
	int iComponentUID;

	int iROFModifier;
	int iProjectilesPerShotModifier;
	int iMagSizeModifier;
	int iDamageModifier;
	int iWeakspotMultiplierModifier;

	float fReloadTimeModifier;
	float fBulletSpreadModifier;
	float fBulletSpreadMultiplierModifier;
};
