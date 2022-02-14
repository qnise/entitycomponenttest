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

std::map<int, float> cComponent::combineComponents(std::vector<std::string> componentNames)
{
	GunBase::initBaseStats(); //basically resets the gun everytime combine components is called
	std::map<int, float> combinedStats = GunBase::getMap();

	for (int it = 0; it < componentNames.size(); it++)
	{
		for (int it2 = 0; it2 < vComponentModifierMaps.size(); it2++)
		{
			if (vComponentModifierMaps.at(it2).first.componentName == componentNames[it])
			{
				for (int iStatsTypes = 0; iStatsTypes < max_eGunStatsTypes; iStatsTypes++)
				{
					if (vComponentModifierMaps[it2].second.count(iStatsTypes)) //check if stat modifier exists in component
					{
						combinedStats.at(iStatsTypes) = math.fMath(combinedStats.at(iStatsTypes), //sums components stats
							vComponentModifierMaps[it2].second.at(iStatsTypes)._operator,
							vComponentModifierMaps[it2].second.at(iStatsTypes).value);
					}
				}
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
	createNewComponent({ "pistolBody", 0, body }, pistolBody);

	//light barrel
	std::map<int, modifier>lightBarrel{
		{damage, {'-', 1}},
		{ROF, {'*', 2}} };
	createNewComponent({ "lightBarrel", 1, body }, lightBarrel);

	//heavy barrel
	std::map<int, modifier>heavyBarrel{
		{damage, {'+', 1}},
		{ROF, {'/', 2}} };
	createNewComponent({ "heavyBarrel", 2, barrel }, heavyBarrel);
}


