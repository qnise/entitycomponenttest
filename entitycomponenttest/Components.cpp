#include "Components.h"

cComponent::cComponent()
{

}

cComponent::~cComponent()
{

}

void cComponent::createNewComponent(componentIdentifier _componentIdentifier, std::map<int, modifier> mapComponentModifier)
{
	//assemble it first because fuck
	std::pair<componentIdentifier, std::map<int, modifier>>putinthisshitlol{
		_componentIdentifier, mapComponentModifier };
	vComponentModifierMaps.push_back(putinthisshitlol);
}

std::map<int, float> cComponent::combineComponents(std::vector<int> componentUIDs)
{
	GunBase::initBaseStats(); //basically resets the gun everytime combine components is called
	std::map<int, float> combinedStats = GunBase::getMap(); 

	for (int i = 0; i < componentUIDs.size(); i++)
	{
		for (int iStatsTypes = 0; iStatsTypes < max_eGunStatsTypes; iStatsTypes++)
		{
			if (vComponentModifierMaps[componentUIDs[i]].second.count(iStatsTypes)) //check if stat modifier exists in component
			{
				combinedStats.at(iStatsTypes) = math.fMath(combinedStats.at(iStatsTypes), //sums components stats
					vComponentModifierMaps[componentUIDs[i]].second.at(iStatsTypes)._operator,
					vComponentModifierMaps[componentUIDs[i]].second.at(iStatsTypes).value);
			}
		}
	}
	return combinedStats;
}

void cComponent::initComponents() //stores and inits component data
{
	//{, {, }},
	//pistol body
	std::map<int, modifier>pistolBody{
		{projectilesPerShot, {'+', 1}},
		{magSize, {'+', 8}},
		{damage, {'+', 10}},
		{weakspotMultiplier, {'+', 2}},
		{ROF, {'+', 300}},
		{reloadTime, {'+', 4}},
		{bulletSpread, {'+', 5}},
		{bulletSpreadMultiplier, {'+', 1.1f}} };
	createNewComponent({ 0, body }, pistolBody);

	//shotgun body
	std::map<int, modifier>shotgunBody{
		{projectilesPerShot, {'+', 8}},
		{magSize, {'+', 2}},
		{damage, {'+', 2}},
		{weakspotMultiplier, {'+', 2}},
		{ROF, {'+', 600}},
		{reloadTime, {'+', 1}},
		{bulletSpread, {'+', 10}},
		{bulletSpreadMultiplier, {'+', 1.5f}} };
	createNewComponent({ 1, body }, shotgunBody);

	//light barrel
	std::map<int, modifier>lightBarrel{
		{damage, {'-', 1}},
		{ROF, {'*', 2}} };
	createNewComponent({ 2, body }, lightBarrel);

	//heavy barrel
	std::map<int, modifier>heavyBarrel{
		{damage, {'+', 1}},
		{ROF, {'/', 2}} };
	createNewComponent({ 3, barrel }, heavyBarrel);

	/*
	//3 - light grip
	std::map<int, modifier>lightGrip

	//4 - heavy grip
	std::map<int, modifier>heavyGrip
	*/
}


