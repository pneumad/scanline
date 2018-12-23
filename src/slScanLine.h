#pragma once

#include	"defines.h"
#include	"ofMain.h"
#include    "slSourceImage.h"
#include    "slData.h"

class slScanLine {
    
public:
    
    slScanLine(slData *data);
    virtual ~slScanLine();
    
    void                    update();
    void                    draw();
    
    
    void                    setActive(const bool bActive){_bActive = bActive;}
    void                    setSourceImage(slSourceImage *image) {_sourceImage = image; setSourceScanLine();}
    void                    setSourceScanLine();
    void                    setCanvasPositionX(const int &posX) {_canvasPositionX = posX;}
    void                    setCanvasPositionY(const int &posY) {_canvasPositionY = posY;}
    void                    setCanvasIndexX(const int &posX) {_canvasIndexX = posX;}
    void                    setCanvasSize(const int &sizeX, const int &sizeY) {_canvasSizeX = sizeX; _canvasSizeY = sizeY;}
    
    
    bool                    getActive(){return _bActive;};
    slSourceImage*          getSourceImage(){return _sourceImage;};
    int                     getSourcePosX(){return _sourcePosX;}
    int                     getSourcePosY(){return _sourcePosY;}
    int                     getSourceScanHeight(){return _sourceScanHeight;}
    ofxCvGrayscaleImage*    getScanLineImage(){return _scanLineImage;};
    float                   getYPerc();
    
    
    void                    allocateScanLineImage();
    void                    clearScanLineImage();
    
    
private:
    
    slData*                 _data;
    
    bool                    _bActive = false;
    
    slSourceImage*          _sourceImage;
    
    bool                    _sourceForward;
    int                     _sourcePosX, _sourcePosY, _sourceScanHeight;
    
    int                     _canvasPositionX, _canvasPositionY, _canvasIndexX, _canvasIndexY;
    int                     _canvasSizeX, _canvasSizeY;
    
    ofxCvGrayscaleImage*    _scanLineImage;
    
};
