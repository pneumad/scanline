/*
#include "slPostProcessing.h"


slPostProcessing::slPostProcessing() {
    
    // bloom looks interesting, as does DofAltPass, DofPass looks screwy
    // Setup post-processing chain
    
    post_runtime.init(SCREEN_WIDTH*CANVAS_MULTIPLIER,SCREEN_HEIGHT*CANVAS_MULTIPLIER);
    Fxaa_runtime = post_runtime.itg::PostProcessing::createPass<FxaaPass>();
    Fxaa_runtime->setEnabled(DEFAULT_FXAA_ON);
    Bloom_runtime = post_runtime.itg::PostProcessing::createPass<BloomPass>();
    Bloom_runtime->setEnabled(DEFAULT_BLOOM_ON);
    Contrast_runtime = post_runtime.itg::PostProcessing::createPass<ContrastPass>();
    Contrast_runtime->setEnabled(DEFAULT_CONTRAST_ON);
    Contrast_runtime->setBrightness(DEFAULT_POSTPROC_BRIGHTNESS);
    Contrast_runtime->setContrast(DEFAULT_POSTPROC_CONTRAST);
    post_runtime.setFlip(DEFAULT_POSTPROC_SETFLIP);
}

slPostProcessing::~slPostProcessing(){};

void slPostProcessing::update() {}
void slPostProcessing::draw() {}
void slPostProcessing::begin() {}
void slPostProcessing::end() {}

*/