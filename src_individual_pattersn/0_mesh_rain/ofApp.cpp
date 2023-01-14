#include "ofApp.h"
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);

	this->mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
	
	
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
	++frame_num;
	if (frame_num == 25) frame_num = 0;
	this->mesh.clear();
	int count = 0;
	ofColor color;
	
	for (int i = 0; i < 4; i++) {

		for (int x = ofGetWidth() / 2; x <= ofGetWindowWidth(); x += 15) {
			
			auto noise_seed = ofRandom(500);
			auto y = ofRandom(-1000, 4000) ;
			auto y_new = y + (ofGetHeight() / 20 * frame_num) ;
			if (y_new > ofGetHeight() + 2000) y_new -= ofGetHeight() + 2000 ;
			

			this->mesh.addVertex(glm::vec3(x, y_new, 0));
			color.setHsb(ofMap(x, 0, ofGetWindowWidth(), 0, 255), 200, 255);
			this->mesh.addColor(color);
			this->mesh.addVertex(glm::vec3(x, y_new + 200, 0));
			color.setHsb(ofMap(x, 0, ofGetWindowWidth(), 0, 255), 200, 255);
			this->mesh.addColor(color);
			
			
		}
	}
	/*
	for (int i = 0; i < this->mesh.getNumVertices(); i++) {

		auto min_distance = 30;
		for (int k = i + 1; k < this->mesh.getNumVertices(); k++) {

			float distance = glm::distance(this->mesh.getVertex(i), this->mesh.getVertex(k));
			if (distance < 30) {

				this->mesh.addIndex(i);
				this->mesh.addIndex(k);

				if (distance < min_distance) {

					min_distance = distance;
				}
			}
		}

		this->mesh.setColor(i, ofColor(this->mesh.getColor(i), ofMap(min_distance, 0, 30, 255, 0)));
	}*/
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->mesh.drawWireframe();
	

	for (int i = 0; i < this->mesh.getNumVertices(); i++) {

		ofSetColor(this->mesh.getColor(i));
		ofDrawCircle(this->mesh.getVertex(i), 2);
	}
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