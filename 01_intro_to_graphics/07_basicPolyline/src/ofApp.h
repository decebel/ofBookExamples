
#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		ofPolyline straightSegmentPolyline;
		ofPolyline curvedSegmentPolyline;
		ofPolyline closedShapePolyline;

};