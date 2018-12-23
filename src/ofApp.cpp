#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(0);

	ofSetFrameRate(FRAME_RATE);
	ofSetVerticalSync(VERTICAL_SYNC);
	ofSetLogLevel(LOG_LEVEL);

	data = new slData();

	for (int x = 0; x < SCAN_LINES; x++) {
		slScanLine *scanline = new slScanLine(data);
		scanline->setSourceImage(data->sourceImages[rand() % data->sourceImages.size()]);
		scanLines.push_back(scanline);
	}

	data->bMouseInMainWindow = false;
	
	data->currentScanLine = rand() % scanLines.size();

	ofSetFullscreen(data->bFullScreen);

	//if (data->bShowMousePtr) ofShowCursor(); else ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){

	if (!data->bPauseScene) updateCore();
}

//--------------------------------------------------------------
void ofApp::draw(){


	ofSetColor(255);
	data->canvas->draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	if (data->bHeadsUpGUI) { drawGui(); data->scanlineFlock->draw(); data->scanlineFlock->drawGui(); }
}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
