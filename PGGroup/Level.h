#ifndef _LEVEL_
#define _LEVEL_

#include "LinkedList.h"
#include "PlaneEntity.h"
#include "PlayerEntity.h"
#include "WizardEntity.h"
#include "InteractableEntity.h"
#include "CoinInteractableEntity.h"
#include <fstream>

class Level{
private:
	PlayerEntity* player;
	WizardEntity* wizard;
	LinkedList* planeList;
	LinkedList* interactableList;
	GLuint* createTexture(string name);
	int stringToInt(string s);
	GLfloat stringToGLfloat(string s);
	PlaneEntity* createPlaneEntity(ifstream *f);


public:
	Level(string filename, PlayerEntity* aPlayer);
	~Level();
	void drawEveryThing();
	void collisionCheck();

};

#endif