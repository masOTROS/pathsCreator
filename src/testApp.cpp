#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    backgroundScale=1.;
    backgroundPosition=ofPoint(0,0);
    animationCanvas=ofRectangle(0.1*ofGetWidth(),0.1*ofGetHeight(),0.8*ofGetWidth(),0.9*ofGetHeight());
    animationCanvasPosition=ofPoint(animationCanvas.x,animationCanvas.y);

    gui = new ofxUISuperCanvas("pathsCreator", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->addTextArea("pathsCreator","Adjust parameters.");
    gui->addSpacer();
    gui->addSlider("backgroundScale", 0., 2., &backgroundScale);
    gui->add2DPad("backgroundPosition",ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()),&backgroundPosition);
    gui->add2DPad("animationCanvasOrigin",ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()),&animationCanvasPosition);
    gui->addSlider("animationCanvasWidth", 0, ofGetWidth(), &animationCanvas.width);
    gui->addSlider("animationCanvasHeight", 0, ofGetHeight(), &animationCanvas.height);
    gui->addSpacer();
    gui->addLabelToggle("pathOpen",pathOpen);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);

    if(ofFile::doesFileExist("GUI/guiSettings.xml"))
        gui->loadSettings("GUI/guiSettings.xml");

}

//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e){
    ofxUIWidget* widget=e.widget;
    if(widget->getName()=="pathOpen"){
        if(pathOpen){
            path.clear();
        }
        else{
            if(path.size())
                savePath();
        }
    }
    else if(widget->getName()=="animationCanvasOrigin"){
        animationCanvas.x=animationCanvasPosition.x;
        animationCanvas.y=animationCanvasPosition.y;
    }
}

//--------------------------------------------------------------
void testApp::savePath(){
    ofBuffer buf;
    for(int i=0;i<path.size();i++){
        ofPoint p = path[i];
        p-=animationCanvasPosition;
        p.x/=animationCanvas.width;
        p.y/=animationCanvas.height;
        //buf.append(ofToString(p)+"\n");
    }
    ofBufferToFile(ofToString(ofGetYear(),4,'0')+ofToString(ofGetMonth(),2,'0')+ofToString(ofGetDay(),2,'0')+ofToString(ofGetHours(),2,'0')+ofToString(ofGetMinutes(),2,'0')+ofToString(ofGetSeconds(),2,'0')+".path",buf);
}

//--------------------------------------------------------------
void testApp::update(){
    if(pathOpen){
        if(ofGetMousePressed()){
            if(path.size()){
                if(abs(mouseX-path[path.size()-1].x)>=1 || abs(mouseY-path[path.size()-1].y)>=1)
                    path.addVertex(mouseX,mouseY);
            }
            else{
                path.addVertex(mouseX,mouseY);
            }
        }
    }
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
    ofSetColor(0,255,255,100);
    ofRect(animationCanvas);
    ofSetColor(255,255,255,100);
    path.draw();
    if(pathOpen){
        ofSetColor(255,0,0);
        ofCircle(mouseX,mouseY,1,1);
    }
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
    background.loadImage(dragInfo.files[0]);
}
