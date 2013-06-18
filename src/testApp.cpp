#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    backgroundScale=1.;
    backgroundPosition=ofPoint(0,0);
    animationCanvas=ofRectangle(0.1*ofGetWidth(),0.1*ofGetHeight(),0.8*ofGetWidth(),0.9*ofGetHeight());
    
    gui = new ofxUISuperCanvas("pathsCreator", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->addTextArea("pathsCreator","Adjust parameters.");
    gui->addSpacer();
    gui->addSlider("backgroundScale", 0., 2., &backgroundScale);
    gui->add2DPad("backgroundPosition",ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()),&backgroundPosition);
    gui->add2DPad("animationCanvasOrigin",ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()),&animationCanvas.position);
    gui->addSlider("animationCanvasWidth", 0, ofGetWidth(), &animationCanvas.width);
    gui->addSlider("animationCanvasHeight", 0, ofGetHeight(), &animationCanvas.height);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
    
    if(ofFile::doesFileExist("GUI/guiSettings.xml"))
        gui->loadSettings("GUI/guiSettings.xml");

}

//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e){
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    if(background.isAllocated()){
        ofPushMatrix();
        ofScale(backgroundScale,backgroundScale);
        background.draw(backgroundPosition);
        ofPopMatrix();
    }
    ofPushStyle();
    ofSetColor(0,255,255);
    ofRect(animationCanvas);
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::exit(){
    gui->saveSettings("GUI/guiSettings.xml");
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}