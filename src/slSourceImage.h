#pragma once

#include	"defines.h"
#include	"ofMain.h"
#include    "ofxOpenCv.h"

class slSourceImage {
    
public:
    
    slSourceImage (string filepath);
    
    void                    update();
    void                    draw();
    
    ofImage                 * getImage(){return &image;};
    bool                    isImageLoaded(){return bImageLoaded;};
    
    ofxCvGrayscaleImage     * getCVImage(){return &imageCV;};
    bool                    isCVImageLoaded(){return bImageCVLoaded;};
    
    float                   getAspectRatio(){return aspectRatio;};
    int                     getWidth(){return width;};
    int                     getHeight(){return height;};
    
private:
    
    string                  imagePath;
    
    ofImage                 image;
    bool                    bImageLoaded;
    
    ofxCvGrayscaleImage     imageCV;
    bool                    bImageCVLoaded;
    
    int						width, height;
    float                   aspectRatio;
    
};
