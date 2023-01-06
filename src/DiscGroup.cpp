#include "DiscGroup.h"


DiscGroup::DiscGroup() {
	gpts = nullptr;
}


void DiscGroup::setGravity(vector<glm::vec3>* attract)
{
	gpts = attract;
}

void DiscGroup::reset()
{
	position.x = ofRandomWidth() ;
	position.y = ofRandomHeight();
	position.z = 0;
    scale = ofRandom(1, 2.0);
    r = ofRandom(1.0, 3.5);
    drag = ofRandom(0.9, 0.998);
	velocity.x = ofRandom(-5.f, 5.f);
	velocity.y = ofRandom(-5.f, 5.f);
	velocity.z = 0;
    gmass = 15000.0f;

	friction = glm::vec3(0, 0, 0);
    mass = ofRandom(0.5, 4.0);

	color.g = velocity.x * 100.f * mass;
	color.b = fmod(color.g, 200.0f);
	color.r = 100.f * mass;
}

void DiscGroup::update()
{
    // bouncing
    if (position.x > ofGetWidth()) {
        position.x = ofGetWidth();
        velocity.x *= -1.0;
    }   else if (position.x < 0) {
        position.x = 0;
        velocity.x *= -1.0;
    }
    if (position.y > ofGetHeight()) {
        position.y = ofGetHeight();
        velocity.y *= -1.0;
    }   else if (position.y < 0) {
        position.y = 0;
        velocity.y *= -1.0;
    }
    //
	if (gpts){
		glm::vec3 closestPt;
		int closest = -1;
		float closestDist = 9999999;
        position += velocity * dt;  // position

        for (unsigned int i = 0; i < gpts->size(); i++){
            float len = glm::length2(gpts->at(i) - position);
            if (len < closestDist){
                closestDist = len;
                closest = i;
            }
        }
        
        if (closest != -1){
            closestPt = gpts->at(closest);
            float dist = sqrt(closestDist);
            glm::vec3 dir = (closestPt - position) / dist;
                    
            friction = mass * gmass / pow(closestDist + 100.0, 3.0 / 2.0) * (closestPt - position); // friction
            
            if (position.x < ofGetWidth() / 2) {
                res = -6.0 * 3.14159 * velocity * visco * r;
                acceleration = (friction + res) / mass;
            }else{ acceleration = friction / mass; }
                velocity += acceleration * dt;
		}

	}
}

void DiscGroup::draw()
{
	ofSetColor(color.r, color.g, color.b);
	ofDrawCircle(position.x, position.y, scale * r);

}
