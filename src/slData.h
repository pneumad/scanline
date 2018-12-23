#pragma once

#include "defines.h"
#include "ofMain.h"
#include "slSourceImage.h"
#include "ofxGui.h"
#include "Flock2d.h"
#include "slFlock.h"

class slData {
    
public:
    slData();
    virtual ~slData();
    
    void                    setup();
    void                    update();
    
    ofDirectory             dir;

	bool                    bFullScreen, bPauseScene, bMouseInput, bMouseInMainWindow, bShowMousePtr, bHeadsUpGUI;

	//overall canvas
    ofxCvGrayscaleImage*    canvas;

    //shared media
    vector<slSourceImage*>	sourceImages;
    
	slFlock*				scanlineFlock;

    int                     currentScanLine;
};



