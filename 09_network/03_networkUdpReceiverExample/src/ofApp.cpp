#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofEnableAntiAliasing();

    //create the socket and bind to port 11999
	udpConnection.Create();
	udpConnection.Bind(11999);
	udpConnection.SetNonBlocking(true);

	ofSetBackgroundAuto(false);
	ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){

	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
	if(message!=""){
		stroke.clear();
		float x,y;
		vector<string> strPoints = ofSplitString(message,"[/p]");
		for(unsigned int i=0;i<strPoints.size();i++){
			vector<string> point = ofSplitString(strPoints[i],"|");
			if( point.size() == 2 ){
				x=atof(point[0].c_str());
				y=atof(point[1].c_str());
				stroke.push_back(ofPoint(x,y));
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(20);
	for(unsigned int i=1;i<stroke.size();i++){
		ofDrawLine(stroke[i-1].x,stroke[i-1].y,stroke[i].x,stroke[i].y);
	}

    ofDrawBitmapStringHighlight("UDP Receiver Example ", 10, 20);
}
