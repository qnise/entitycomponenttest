#include "Components.h"
#include <iostream>

void main()
{
	cComponent CComponent;
	CComponent.initComponents();
	std::cout << CComponent.combineComponents({ 1 , 3 }).at(GunBase::eGunStatsTypes::ROF);
}