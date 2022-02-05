#pragma once
#include "Components.h"

class cPlayerGun
{
public:
	void shoot(bool altFire);
	float reload(); //return reload time

	int getMagSize(); 
	int getCurrentAmmo();

	void setMagSize(int MagSize);
	void setCurrentAmmo(int CurrentAmmo);

private:
	//component modifiable
	int iProjectilesPerShot;
	int iMagSize;
	int iDamage;
	int iWeakspotMultiplier;
	int iROF; //rate of fire, in r/min

	float fReloadTime;
	float fBulletSpread; //lesser accurater, in degrees
	float fBulletSpreadMultiplier; //as you shoot/move

	//non
	int iCurrentAmmoInMag;
	int iCurrentAmmoInTotal;
	int iMaxAmmo;
};