#include "Components.h"
#include <iostream>

void main()
{
	cComponent CComponent;
	CComponent.initComponents();
	std::cout << CComponent.combineComponents({ 1 , 2 }).at(GunBase::eGunStatsTypes::ROF);
}