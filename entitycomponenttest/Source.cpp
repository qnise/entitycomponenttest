#include "Components.h"
#include <iostream>

void main()
{
	cComponent CComponent;
	CComponent.initComponents();
	std::cout << CComponent.combineComponents({ "pistolBody", "lightBarrel"}).at(GunBase::eGunStatsTypes::ROF);
}