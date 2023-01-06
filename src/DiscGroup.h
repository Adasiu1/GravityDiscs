#pragma once
#include "ofMain.h"

class DiscGroup
{
public:
	DiscGroup();


	void setGravity(vector <glm::vec3>* attract);
    

	void reset();
	void update();
	void draw();

	float drag;
	float scale;
	float mass;
	float r;
	float dt;
    float gmass;
    float visco;

    vector <glm::vec3>* gpts;
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 friction;
    glm::vec3 res;
	glm::vec3 acceleration;
	glm::vec3 force;
	ofColor color;
};

