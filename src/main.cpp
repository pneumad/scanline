#include "ofMain.h"
#include "ofApp.h"
#include "defines.h"

//========================================================================
int main( ){
	ofSetupOpenGL(SCREEN_WIDTH, SCREEN_HEIGHT, OF_WINDOW);			// <-------- setup the GL context

	ofRunApp(new ofApp());
}
