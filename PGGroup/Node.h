#ifndef _NODE_
#define _NODE_

#include "PlayerEntity.h"

class Entity;
class PlayerEntity;
class Node {
private:
	Entity* entity;
	Node* next;

public:
	Node(Entity* anEntity, Node* aNext);
	~Node(void);
	virtual Node* getNext();
	virtual Entity* getEntity();
	virtual void drawContents();
	void collisionCheck(PlayerEntity *player);
};

#endif
