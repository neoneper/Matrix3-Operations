#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	vaquinha.load("vaquinha.png");
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	Matrix3 scale = Matrix3Of::matrixScale(ofVec2f(0.2f, 0.2f));
	Matrix3 translate = Matrix3Of::matrixTranslate(ofVec2f(300, 200));
	Matrix3 rotate = Matrix3Of::matrixRotation(45);

	ofPushMatrix();
	{
		
		
		ofMultMatrix(Matrix3Of::ToOfMatrix4(translate));
		ofMultMatrix(Matrix3Of::ToOfMatrix4(rotate));

		ofMultMatrix(Matrix3Of::ToOfMatrix4(scale));

		vaquinha.draw(0, 0);
	}
	ofPopMatrix();
	
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
