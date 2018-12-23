#include "ofApp.h"

void ofApp::updateCore(){

    data->update();
	if (data->bMouseInput) updateScanMouse(); else updateScanFlock();
}

void ofApp::updateScanFlock(){

    for (int x = 0; x < scanLines.size(); x++) {
        
        if (!scanLines[x]->getActive()){
			scanLines[x]->setCanvasIndexX(data->canvas->getWidth()/2);
			scanLines[x]->setCanvasPositionX(data->canvas->getWidth()/2);
            scanLines[x]->setActive(true);
        } else {
            scanLines[x]->setCanvasPositionX((int)(((float)data->scanlineFlock->scanFlock[x]->x/ofGetWindowWidth())*data->canvas->getWidth()));
            scanLines[x]->setCanvasPositionY((int)(((float)data->scanlineFlock->scanFlock[x]->y/ofGetWindowHeight())*data->canvas->getHeight()));
            scanLines[x]->update();
        }
    }
}

void ofApp::updateScanMouse(){
    
    for (int x = 0; x < scanLines.size(); x++) {
        if (x == data->currentScanLine){
            if (!scanLines[x]->getActive())
                scanLines[x]->setCanvasIndexX((int)(((float)ofGetMouseX()/ofGetWindowWidth())*data->canvas->getWidth()));
				scanLines[x]->setCanvasPositionX((int)(((float)ofGetMouseX()/ofGetWindowWidth())*data->canvas->getWidth()));
            scanLines[x]->setActive(true);
        } else scanLines[x]->setActive(false);

        if (scanLines[x]->getActive()){
            scanLines[x]->setCanvasPositionX((int)(((float)ofGetMouseX()/ofGetWindowWidth())*data->canvas->getWidth()));
            scanLines[x]->update();
        }
    }
    
    if (data->bMouseInMainWindow){
            scanLines[data->currentScanLine]->setCanvasPositionX((int)(((float)ofGetMouseX()/ofGetWindowWidth())*data->canvas->getWidth()));
            scanLines[data->currentScanLine]->setCanvasPositionY((int)(((float)ofGetMouseY()/ofGetWindowHeight())*data->canvas->getHeight()));
    }
}