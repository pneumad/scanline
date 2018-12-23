#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::drawGui(){
    
    ofSetColor(0,255,0,255);
    ofDrawBitmapString(ofGetFrameRate(),20,20);
    ofSetColor(255,0,0,255);
    if (data->bMouseInMainWindow) {
        ofSetLineWidth(2);
        ofDrawLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetWindowHeight());
    }
}