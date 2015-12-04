#include "LinkedList.h"

LinkedList::LinkedList(void) {
	head = NULL;
}

LinkedList::~LinkedList(void) {
	delete head;
}

void LinkedList::add(Entity *anEntity) {
	head = new Node(anEntity, head);
}
void LinkedList::drawContents(){
	if(head)
		head->drawContents();
}
void LinkedList::collisionCheck(PlayerEntity *player){
	if(head)
		head->collisionCheck(player);
}
Node* LinkedList::getHead() { return head; };

