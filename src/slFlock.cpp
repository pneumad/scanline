#include "slFlock.h"


slFlock::slFlock()
{

	flockGui.setup();
	flockGui.setPosition(10, 10);
	flockGui.add(radius.setup("radius", 3, 0.1, 20));
	flockGui.add(separate.setup("separate", 55, 0, 500));
	flockGui.add(align.setup("align", 12, 0, 50));
	flockGui.add(cohesion.setup("cohesion", 12, 0, 50));

	flock.setup(SCAN_LINES*FLOCK_COEF, ofGetWidth(), ofGetHeight(), ofGetWidth());
	flock.setBounds(0, 0, ofGetWidth(), ofGetHeight());
	flock.setBoundmode(0);
	flock.setMaxSpeed(1.0);

	for (int i = 0; i < SCAN_LINES; i++) { ofVec2f *newPt = new ofVec2f(); scanFlock.push_back(newPt); }
}


slFlock::~slFlock()
{
}

void slFlock::setup() {

}

void slFlock::update() {

	flock.setAlign(align);
	flock.setSeparate(separate);
	flock.setCohesion(cohesion);

	flock.update();

	for (int i = 0; i<flock.size(); i++) {
		if (i%FLOCK_COEF == 0) { Boid2d * b = flock.get(i); scanFlock[(int)i / FLOCK_COEF]->x = b->x; scanFlock[(int)i / FLOCK_COEF]->y = b->y; }
	}
}

void slFlock::draw() {

	ofSetColor(255, 0, 0, 255);
	for (int i = 0; i<flock.size(); i++) {
		Boid2d * b = flock.get(i);
		ofDrawCircle(ofVec2f(b->x, b->y), radius);
	}

	ofSetColor(0, 255, 0, 255);
	for (int i = 0; i<SCAN_LINES; i++) {
		ofSetLineWidth(2);
		ofDrawLine(scanFlock[i]->x, 0, scanFlock[i]->x, ofGetWindowHeight());
	}
}

void slFlock::drawGui() {



	flockGui.draw();
}

