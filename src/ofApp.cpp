#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // load sounds
    sounds[0].loadSound( "sounds/accident.mp3");
    sounds[1].loadSound( "sounds/bird.mp3");
    sounds[2].loadSound( "sounds/cow.mp3");
    sounds[3].loadSound( "sounds/jackpot.mp3");
    sounds[4].loadSound( "sounds/printer.mp3");
    sounds[5].loadSound( "sounds/synth.wav");

	// volume
    for (int i=0; i<6; i++){
        sounds[i].setVolume(0.75f);
    }

    // Arduino
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup("/dev/ttyACM0", baud);
    json = "";

    // init
    for (int i=0; i<6; i++){
        switchers[i].on = false;
        switchers[i].name = "btn"+ofToString(i);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    if( serial.available() ){

        while( serial.available() ){
            lastChar = char( serial.readByte() );
            json += ofToString( lastChar );
        }

        if(lastChar == '\n'){
            bool parsingSuccessful = jsonEl.parse( json );
            std::cout << json << std::endl;
            std::cout << "parsingSuccessful: " << ofToString( parsingSuccessful ) << std::endl;

            if( parsingSuccessful ){
                // ofLog() << "btnA: " + ofToString( jsonEl[ "btnA" ] );

                for (int i=0; i<6; i++){
                    if( jsonEl[ switchers[i].name ] == 1 && switchers[i].on == false && sounds[i].getIsPlaying() == false) {
                        switchers[i].on = true;
                        sounds[i].play();
                    } else {
                        switchers[i].on = false;
                    }
                }
            }
            json = "";
        }

    }

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'a' ){
        cout << "key a" << endl;
        bird.play();
	} else if( key == 'z' ){
        cout << "key z" << endl;
        accident.play();
	} else if( key == 'e' ){
        cout << "key e" << endl;
        cow.play();
	} else if( key == 'r' ){
        cout << "key r" << endl;
        jackpot.play();
	} else if( key == 't' ){
        cout << "key t" << endl;
        printer.play();
	} else if( key == 'y' ){
        cout << "key t :synth" << endl;
        synth.play();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
