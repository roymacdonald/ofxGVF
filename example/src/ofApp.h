#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxGVF.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
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

    
    void initGui();
    void initColors();
    void displayParticlesOnGesture(GVFGesture currentGesture);
    
private:
    std::vector<float> theSample;
    ofxPanel settingsGui;
    
    // parameters
    ofParameter<float> theNumberOfParticlesDialer = {"precision", 2000, 10, 10000 };
    ofParameter<float> theToleranceDialer = {"tolerance", 0.12, 0.01, 2 };
    ofParameter<float> theScalingVarianceDialer = {"scale adaptation", 0.0001, 0.000001, 0.1 };
    
    ofxGVF * mygvf;
    GVFGesture gesture;
    
    ofRectangle drawArea;
    
    std::vector<ofColor> colors;
    
    float scrW, scrH;
    bool isMouseDrawing;
    bool displayParticles;
    bool displayTemplate;
    bool displayEstimatedGesture;
    bool displayCurrentGesture;
    
    void drawGesture(GVFGesture gesture);
    void drawGesture(float x, float y);
    void drawGesture(float x, float y, float w, float h);

	ofEventListeners guiListeners;
	
	
};
