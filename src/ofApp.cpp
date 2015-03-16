#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // load sounds
    sounds[0].loadSound( "sons2/sonKlaxon.mp3");
    sounds[1].loadSound( "sons2/sonMoto.mp3");
    sounds[2].loadSound( "sons2/sonSncf.mp3");
    sounds[3].loadSound( "sons2/sonTram.mp3");

	// volume
    for (int i=0; i<NB_SOUND; i++){
        sounds[i].setVolume(0.75f);
    }

    // Arduino
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup("/dev/ttyACM0", baud);
    json = "";

    // init
    for (int i=0; i<NB_SOUND; i++){
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

                for (int i=0; i<NB_SOUND; i++){
                    if( jsonEl[ switchers[i].name ] == 1 && switchers[i].on == false){
                        switchers[i].on = true;
                        if(sounds[i].getIsPlaying() == false) {
                            sounds[i].play();
                            sounds[i].setLoop(true);
                            for (int j=0; j<NB_SOUND; j++){
                                if( i != j ){
                                    sounds[j].stop();
                                }
                            }
                        }
                        else{
                            sounds[i].stop();
                        }
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
