#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto numberOfActor = 255;
	ofColor color;

	ofSeedRandom(39);
	for (int i = 0; i < numberOfActor; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
		
		ofSetColor(255);
		for (int k = 0; k < 35; k++) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, k * 0.002 + ofGetFrameNum() * 0.001), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, k * 0.002 + ofGetFrameNum() * 0.001), 0, 1, -350, 350));

			ofDrawCircle(location, 12);
		}

		color.setHsb(ofRandom(255), 100, 255);
		ofSetColor(color);
		for (int k = 0; k < 35; k++) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, k * 0.002 + ofGetFrameNum() * 0.001), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, k * 0.002 + ofGetFrameNum() * 0.001), 0, 1, -350, 350));

			ofDrawCircle(location, 8);
		}
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}