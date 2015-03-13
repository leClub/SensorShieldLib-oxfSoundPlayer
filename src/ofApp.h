#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#define NB_SOUND 7

struct Btn {
    bool on;
    string name;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofSoundPlayer accident;
        ofSoundPlayer bird;
        ofSoundPlayer cow;
        ofSoundPlayer jackpot;
        ofSoundPlayer printer;
        ofSoundPlayer synth;

        ofSoundPlayer sounds[NB_SOUND];

		ofSerial serial;
		char lastChar;
		ofxJSONElement jsonEl;
        std::string json;
        Btn switchers[NB_SOUND];

};
