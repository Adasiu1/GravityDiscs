#pragma once

#include "ofMain.h"
#include "DiscGroup.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    void SphereReset();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
   
    
    
    
    vector <DiscGroup> spheres;
    vector<glm::vec3> gPoints;
    
    ofxPanel gui;
    ofxFloatSlider dtSlider;
    ofxFloatSlider viscoSlider;
    ofxIntSlider gravityX;
    ofxIntSlider gravityY;
    ofxIntSlider numSlider;
    ofxButton setGPoint;
    ofxButton reset;
    ofxButton addVisco;
};
