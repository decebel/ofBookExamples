#pragma once

#include "ofMain.h"
#include "rectangle.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		rectangle myRectangles[10];
		float pct;
	
};