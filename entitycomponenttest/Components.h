#pragma once
#include "gunBase.h"
#include "Math.h"
#include <vector>

//component class just dump every component in here
struct modifier 
{
	char _operator;
	float value;
};

struct componentIdentifier
{
	int componentUID;
	int componentType;
};

class cComponent : public GunBase
{
public:
	cComponent();
	~cComponent();

	enum eComponentTypes {
		body,
		barrel,
		grip,
		sight,
		stock,
		max_eComponentType //keep at end
	};

	//assembles and pushes back to vComponentModifierMaps
	void createNewComponent(componentIdentifier componentIdentifier, 
							std::map<int, modifier> mapComponentModifier);

	//stores and inits component data
	void initComponents();

	//combines components
	std::map<int, float>combineComponents(std::vector<int>componentUIDs);

private: 

	Math math;

	std::vector<std::pair<componentIdentifier, std::map<int, modifier>>>vComponentModifierMaps;

	//modifier modROF,
	//		 modProjectilesPerShot,
	//		 modMagSize,
	//		 modDamage,
	//		 modWeakspotMultiplier,
	//		 modReloadTimeModifier,
	//		 modBulletSpreadModifier,
	//		 modBulletSpreadMultiplierModifier;
};