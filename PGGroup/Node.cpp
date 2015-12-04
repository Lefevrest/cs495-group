#include "Node.h"

Node::Node(Entity* anEntity, Node* aNext) {
	entity = anEntity;
	next = aNext;
}

Node::~Node(void) {
	delete next;
}

void Node:: drawContents(){
		entity->drawSelf();
		if(next)
			next->drawContents();
}

void Node:: collisionCheck(PlayerEntity *player){
	entity->checkForCollision(player);
	if (next)
		next->collisionCheck(player);
}

Node* Node::getNext() { return next; }
Entity* Node::getEntity() { return entity; }
