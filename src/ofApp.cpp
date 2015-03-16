#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cout << "test" << endl;
    // load sounds
    sounds[0].loadSound( "sons1/SonAuditorium.mp3");
    sounds[1].loadSound( "sons1/SonCtreCommercial.mp3");
    sounds[2].loadSound( "sons1/SonDauphine.mp3");
    sounds[3].loadSound( "sons1/SonGare.mp3");
    sounds[4].loadSound( "sons1/SonPD.mp3");
    sounds[5].loadSound( "sons1/SonRenaudel.mp3");
    sounds[6].loadSound( "sons1/SonResidence.mp3");


    cout << "test2" << endl;
	// volume
    for (int i=0; i<NB_SOUND; i++){
        sounds[i].setVolume(0.75f);
    }

    cout << "test3" << endl;
    // Arduino
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup("/dev/ttyACM0", baud);
    json = "";

    cout << "test4" << endl;
    // init
    for (int i=0; i<NB_SOUND; i++){
        switchers[i].on = false;

        switchers[i].name = "btn"+ofToString(i);
    }

    cout << "test5" << endl;
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

                for (int i=0; i<NB_SOUND; i++){
                    if( jsonEl[ switchers[i].name ] == 1 && switchers[i].on == false && sounds[i].getIsPlaying() == false) {
                        switchers[i].on = true;
                        sounds[i].play();
                    } else {
                        switchers[i].on = false;
                        sounds[i].stop();
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
