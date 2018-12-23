#include "slScanLine.h"

slScanLine::slScanLine(slData *data): _data(data){
    
    _sourceForward = true;
    _sourcePosX = 0; _sourcePosY = 0; _sourceScanHeight = 1;
    _scanLineImage = new ofxCvGrayscaleImage();
    allocateScanLineImage();

	_canvasPositionX = _canvasIndexX = 0;
}

slScanLine::~slScanLine(){};

void slScanLine::update() {
    
	/*
    while (abs(_canvasPositionX - _canvasIndexX) != 0) {
        
        if (rand()%1000 == 0) _sourceForward = !_sourceForward; //switch direction
        
		
        if (_canvasIndexX < _canvasPositionX) _canvasIndexX++; else _canvasIndexX--;
        if (_sourceForward) _sourcePosX++; else _sourcePosX--;
        if (_sourcePosX > _sourceImage->getWidth()) {_sourcePosX = _sourceImage->getWidth(); _sourceForward = !_sourceForward;}
        if (_sourcePosX < 0) {_sourcePosX = 0; _sourceForward = !_sourceForward;}
        
        _sourceImage->getCVImage()->setROI(_sourcePosX, _sourcePosY, 1, _sourceScanHeight);
        _scanLineImage->scaleIntoMe(*_sourceImage->getCVImage());
        _sourceImage->getCVImage()->resetROI();
        _data->canvas->setROI(_canvasIndexX, 0, 1, _data->canvas->getHeight());
        cvAddWeighted(_scanLineImage->getCvImage(), getYPerc(), _data->canvas->getCvImage(), 1-getYPerc(), 0, _data->canvas->getCvImage());
        _data->canvas->contrastStretch(); //autoContrast for canvas ROI
        _data->canvas->resetROI();
		
    }
	*/

	while (abs(_canvasPositionX - _canvasIndexX) != 0) {

		if (rand() % 1000 == 0) _sourceForward = !_sourceForward; //switch direction
		if (_canvasIndexX < _canvasPositionX) _canvasIndexX++; else _canvasIndexX--;
		if (_sourceForward) _sourcePosX++; else _sourcePosX--;
		if (_sourcePosX > _sourceImage->getWidth()) { _sourcePosX = _sourceImage->getWidth(); _sourceForward = !_sourceForward; }
		if (_sourcePosX < 0) { _sourcePosX = 0; _sourceForward = !_sourceForward; }

		_sourceImage->getCVImage()->setROI(_sourcePosX, _sourcePosY, 1, _sourceScanHeight);
		_scanLineImage->scaleIntoMe(*_sourceImage->getCVImage());
		_sourceImage->getCVImage()->resetROI();
		_data->canvas->setROI(_canvasIndexX, 0, 1, _data->canvas->getHeight());
		cvAddWeighted(_scanLineImage->getCvImage(), getYPerc(), _data->canvas->getCvImage(), 1 - getYPerc(), 0, _data->canvas->getCvImage());
		_data->canvas->contrastStretch(); //autoContrast for canvas ROI
		_data->canvas->resetROI();

		cout << _canvasIndexX << endl;
	}


	/*
	if (rand() % 1000 == 0) _sourceForward = !_sourceForward; //switch direction
	//if (_canvasIndexX < _canvasPositionX) _canvasIndexX++; else _canvasIndexX--;
	if (_sourceForward) _sourcePosX++; else _sourcePosX--;
	if (_sourcePosX > _sourceImage->getWidth()) { _sourcePosX = _sourceImage->getWidth(); _sourceForward = !_sourceForward; }
	if (_sourcePosX < 0) { _sourcePosX = 0; _sourceForward = !_sourceForward; }

	_sourceImage->getCVImage()->setROI(_sourcePosX, _sourcePosY, 1, _sourceScanHeight);
	_scanLineImage->scaleIntoMe(*_sourceImage->getCVImage());
	_sourceImage->getCVImage()->resetROI();
	_data->canvas->setROI(_canvasIndexX, 0, 1, _data->canvas->getHeight());
	cvAddWeighted(_scanLineImage->getCvImage(), getYPerc(), _data->canvas->getCvImage(), 1 - getYPerc(), 0, _data->canvas->getCvImage());
	_data->canvas->contrastStretch(); //autoContrast for canvas ROI
	_data->canvas->resetROI();
	*/
}

void slScanLine::draw() {}

void slScanLine::allocateScanLineImage(){_scanLineImage->allocate(1, _data->canvas->getHeight());}
void slScanLine::clearScanLineImage(){_scanLineImage->clear();}

void slScanLine::setSourceScanLine(){
    
    float randomScanAmount = ofRandom(0.25, 1);
    _sourceScanHeight = (int)(_sourceImage->getHeight()*randomScanAmount);
    _sourcePosY = (int)(_sourceImage->getHeight()*ofRandom(0, 1-randomScanAmount));
}

float slScanLine::getYPerc(){
    
    return (float)(_canvasPositionY/_data->canvas->getHeight());
}