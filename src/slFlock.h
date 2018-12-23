#pragma once

#include "defines.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "Flock2d.h"

class slFlock
{
public:
	slFlock();
	~slFlock();


	void                    setup();
	void                    update();
	void                    draw();
	void                    drawGui();


	//flocking for scanlines
	Flock2d                 flock;
	vector<ofVec2f*>        scanFlock;
	ofxPanel				flockGui;

	ofxFloatSlider			separate, align, cohesion, distSeparation, distAlign, distCohesion, maxTurn, maxSpeed, maxForce, attraction, attractiondeviation;

	ofxFloatSlider			radius;
};

