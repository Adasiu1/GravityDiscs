#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    gui.setup();
    gui.add(dtSlider.setup("Delta time value", 0.15, 0.001, 0.45));
    gui.add(viscoSlider.setup("Viscosity Slider", 1.0e-2, 1.0e-4, 0.1));
    gui.add(gravityX.setup("Gravity point - x coord.", 0, 1, 1024));
    gui.add(gravityY.setup("Gravity point - Y coord.", 0, 1, 768));
    gui.add(numSlider.setup("Number of spheres", 0, 1, 1000));
    gui.add(setGPoint.setup("Activate Gravity"));
    gui.add(reset.setup("RESET"));

    
    ofSetVerticalSync(true);
    int num = 1000;
    spheres.assign(num, DiscGroup());

    SphereReset();
}

void ofApp::SphereReset()
{
    gPoints.clear();
    for (unsigned int i = 0; i < spheres.size(); i++) {
        spheres[i].setGravity(&gPoints);
        spheres[i].reset();
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (unsigned int i = 0; i < spheres.size(); i++) {
        spheres[i].update();
    }

    int ypos = gravityY;
    int xpos = gravityX;

    if (setGPoint){
        gPoints.push_back(glm::vec3(xpos, ypos, 0));
        for (unsigned int i = 0; i < spheres.size(); i++) {
            spheres[i].setGravity(&gPoints);
        }
    }

    if (reset)
    {
        SphereReset();
    }
    if (numSlider != spheres.size())
    {
        spheres.clear();
        spheres.assign(numSlider, DiscGroup());
        SphereReset();
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackgroundGradient(ofColor(60, 60, 60), ofColor(10, 10, 10));
    ofSetColor(110, 200, 111);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth() / 2, ofGetHeight());
    
    for (unsigned int i = 0; i < spheres.size(); i++) {
        spheres[i].dt = dtSlider;
        spheres[i].visco = viscoSlider;
        spheres[i].draw();
    }
    int x = gravityX;
    int y = gravityY;
    ofSetColor(255, 255, 0);
    ofDrawCircle(x, y, 12);

    ofSetColor(255, 0, 0);
    for (unsigned int i = 0; i < gPoints.size(); i++) {
        ofDrawCircle(gPoints[i], 15);
    }
    ofSetColor(230);

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
