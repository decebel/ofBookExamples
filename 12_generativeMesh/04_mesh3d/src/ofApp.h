#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofImage image;
		ofMesh mesh;
		ofEasyCam easyCam;
};
