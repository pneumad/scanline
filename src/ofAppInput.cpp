#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::keyPressed(int key){}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    // pause / save
    if (key == 'p') data->bPauseScene = !data->bPauseScene;
    
	/*
    if (key=='s') saver.finish("stills/frame_" + ofToString(ofGetFrameNum()) + "_high.png", false);
    
    //g - save screen grab
    if (key == 'g') {
        char fileName[255]; sprintf(fileName, "screengrabs/strata_%.7i.jpg", ofGetFrameNum());
        ofImage saveImg; saveImg.allocate(ofGetWindowWidth(), ofGetWindowHeight(), OF_IMAGE_COLOR_ALPHA);
        saveImg.grabScreen(0,0,ofGetWindowWidth(),ofGetWindowHeight());
        saveImg.saveImage(fileName);
    };
    */
    
    //f - toggle between window and fullscreen

    if (key == 'f'){
        data->bFullScreen = !data->bFullScreen; ofSetFullscreen(data->bFullScreen);
        if (!data->bFullScreen){
            ofSetWindowShape(SCREEN_WIDTH, SCREEN_HEIGHT);
            ofSetWindowPosition(0, 0);
        }
    }
    
    if (key == 'h') data->bHeadsUpGUI = !data->bHeadsUpGUI;

    if (key=='a') data->currentScanLine = ofClamp(data->currentScanLine-1, 0, scanLines.size()-1);
    if (key=='z') data->currentScanLine = ofClamp(data->currentScanLine+1, 0, scanLines.size()-1);
    
    if (key=='r') {data->bShowMousePtr = !data->bShowMousePtr; if (data->bShowMousePtr) ofShowCursor(); else ofHideCursor();}
    
    
    if (key=='l') {
        for (int x = 0; x < scanLines.size(); x++) {scanLines[x]->setSourceImage(data->sourceImages[rand()%data->sourceImages.size()]);}
    };
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){data->bMouseInMainWindow = true;}
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){data->bMouseInMainWindow = false;}
