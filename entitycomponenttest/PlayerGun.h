#pragma once
#include "Components.h"

//not implemented yet
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
	int iCurrentAmmoInMag;
	int iCurrentAmmoInTotal;
	int iMaxAmmo;
};