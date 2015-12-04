#ifndef _LEVEL_
#define _LEVEL_

#include "PlaneEntity.h"
#include "PlayerEntity.h"
#include "WizardEntity.h"
#include "InteractableEntity.h"
#include "LinkedList.h"
#include <fstream>

using namespace std;

class Level{
private:
	LinkedList *planeList;
	LinkedList *interactableList;
	//Linked coinList;
	WizardEntity *wizard;
	//PortalEntity nextLevel;
	void addPlane(PlaneEntity *newPlane);
	void addInteractable(InteractableEntity *newInteractable);
	//void addCoin(CoinEntity newCoin);
	void addWizard(WizardEntity *newWizard);
	//void addPortal(PortalEntity *newPortal);
	void drawLevel();
	PlayerEntity *player;

	Entity* createEntity(ifstream *f);
	PlaneEntity* createPlaneEntity(ifstream *f);
	InteractableEntity* createInteractableEntity(ifstream *f);
	PlayerEntity* createPlayerEntity(ifstream *f);
	WizardEntity* createWizardEntity(ifstream *f);
	GLuint* createTexture(string name);
	int stringToInt(string s);
	GLfloat stringToGLfloat(string s);
public:
	Level(string filename,PlayerEntity* aPlayer);
	~Level();
	void drawEveryThing();
	void collisionCheck();
};

#endif