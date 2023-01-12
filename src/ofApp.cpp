#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("celias epic boxes");
	ofEnableDepthTest();
	sound.load("sun_1.wav");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	cam.disableMouseInput();
	cam.setDistance(550);
	ofNoFill();

	ofRotateX(40);
	ofRotateY(ofGetFrameNum() * 0.3333333333);
	val = ofSoundGetSpectrum(25); //must be a perfect square
	boxgrid(5, val);
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a') {
		sound.play();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}



void ofApp::boxgrid(int sideLength, float* spectrum) {
	
	for (int i = 0; i < sideLength;++i)
		for (int j = 0; j< sideLength; ++j) {
			ofDrawBox(ofPoint(-250 + (100 * i) ,0 , -250 + (100 * j)), 100, 100 + (5000 * spectrum[3 * i + j]), 100);
		}//xyz
}