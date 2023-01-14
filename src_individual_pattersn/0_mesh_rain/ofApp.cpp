#include "ofApp.h"
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");
	ofBackground(0);


	this->mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
	poppins.load("poppins.ttf", 225, true, true);
	
}
//--------------------------------------------------------------
void ofApp::update() {
	titleUpdate();
}

//--------------------------------------------------------------
void ofApp::draw() {
	titleDraw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
void ofApp::titleDraw() {
	ofSetLineWidth(2);
	this->mesh.drawWireframe();
	ofSetColor(255);
	poppins.drawString("YOUR", ofGetWidth() / 2 - 400, ofGetHeight() / 2 - 300);
	ofSetColor(85, 214, 255);
	poppins.drawString("KALEIDOSCOPE", ofGetWidth() / 2 - 400, ofGetHeight() / 2 - 75);

	for (int i = 0; i < this->mesh.getNumVertices(); i++) {

		ofSetColor(this->mesh.getColor(i));
		ofDrawCircle(this->mesh.getVertex(i), 2);
	}
}
void ofApp::titleUpdate() {

	ofSeedRandom(39);
	++frame_num;
	if (frame_num == 25) frame_num = 0;
	this->mesh.clear();
	int count = 0;
	ofColor color;

	for (int i = 0; i < 4; i++) {

		for (int x = ofGetWidth() / 2 - 300; x <= ofGetWindowWidth(); x += 15) {

			auto noise_seed = ofRandom(500);
			auto y = ofRandom(-1000, 4000);
			auto y_new = y + (ofGetHeight() / 20 * frame_num);
			if (y_new > ofGetHeight() + 2000) y_new -= ofGetHeight() + 2000;


			this->mesh.addVertex(glm::vec3(x, y_new, 0));
			color.setHsb(ofMap(x, 0, ofGetWindowWidth(), 0, 255), 200, 255);
			this->mesh.addColor(color);
			this->mesh.addVertex(glm::vec3(x, y_new + 200, 0));
			color.setHsb(ofMap(x, 0, ofGetWindowWidth(), 0, 255), 200, 255);
			this->mesh.addColor(color);


		}
	}

}
