#ifndef _ENTITY_
#define _ENTITY_

#include <iostream>
#include <string>
#include <cstdlib>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Vector.h"
using namespace std;

#define X 0
#define Y 1
#define Z 2
#define SENSITIVITY 0.2f

typedef enum {
	POSITION,
	ROTATION,
	VELOCITY
} LocationInfo;

class PlaneEntity;
class Entity {
protected:
	Vector* position;
	Vector* rotation;
	Vector* velocity;
	float opacity;
	float radius;
	GLuint* texture;
	GLfloat vertices[12];
	
	Vector* getCorrespondingVector(LocationInfo locationInfo);
	void rotateEntity();

public:
	Entity(Vector* aPosition, GLuint *aTexture, GLfloat* aVertices, float aRadius);
	~Entity(void);

	virtual bool hasCollided(Entity* otherEntity);
	virtual bool checkForCollision(Entity* otherEntity);
	virtual bool isMovingToward(Entity* otherEntity);
	virtual void drawSelf();

	void move(float gravity);
	bool hasCollided(PlaneEntity* otherEntity);
	bool checkForCollision(PlaneEntity* otherEntity);
	bool isMovingToward(PlaneEntity* otherEntity);
	bool withinPlaneBoundaries(PlaneEntity* plane);
	void incrementXOf(LocationInfo locInfo, float x);
	void incrementYOf(LocationInfo locInfo, float y);
	void incrementZOf(LocationInfo locInfo, float z);
	Vector* getPosition();
	Vector* getRotation();
	Vector* getVelocity();
	float getRadius();
};

#endif
