#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofPath path;
		ofMatrix4x4 m;
		
};
