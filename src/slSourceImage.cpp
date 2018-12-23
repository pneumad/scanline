#include "slSourceImage.h"

slSourceImage::slSourceImage(string filepath): imagePath(filepath) {
    
    image.load(imagePath);
    image.setImageType(OF_IMAGE_GRAYSCALE);
    width = image.getWidth(); height = image.getHeight(); aspectRatio = (float) width/height;
    imageCV.allocate(width, height);
    ofPixels myPixels = image.getPixels();
    imageCV.setFromPixels(myPixels.getPixels(), width, height);
    //image.clear();
}

void slSourceImage::update() {}
void slSourceImage::draw() {}