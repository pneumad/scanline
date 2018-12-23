#include "slData.h"

slData::slData(){
    
	bPauseScene = false;

    bFullScreen = FULLSCREEN; bMouseInput = MOUSE_INPUT; bHeadsUpGUI = HEADS_UP_GUI; bShowMousePtr = SHOW_MOUSE_PTR;
    
    canvas = new ofxCvGrayscaleImage();
    canvas->allocate(SCREEN_WIDTH, SCREEN_HEIGHT);
    canvas->set(0);
    
    //load images ///////////////////////////////////////////////////////////////////////////

    dir.listDir("textures/"); dir.sort();
    for(int i = 0; i < (int)dir.size(); i++){
        slSourceImage *newImage = new slSourceImage(dir.getPath(i));
        sourceImages.push_back(newImage);
    }

	scanlineFlock = new slFlock();
}

slData::~slData(){};

void slData::setup(){


}


void slData::update(){
    

	scanlineFlock->update();
}