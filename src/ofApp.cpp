#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    // load vocal samples
    // loadVocal();
    // or uncomment this instead to load piano samples
    ofTrueTypeFont::setGlobalDpi(72);
    myfont.load("roboto.ttf", 20, true, true);


    loadMusic();

    tempo = 5000; // starting with five seconds tempo
    b_autoPlay = false;
    currTime = ofGetSystemTimeMillis();

    ofSetBackgroundColor(0);
    // ofSetBackgroundAuto(false);
    b_Gui = true;

    ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    //    ofSetColor(0, 0, 0, 10);
    //    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    //
    ofSetColor(255);
    if (b_autoPlay) { // choose a voice to play
        if (ofGetSystemTimeMillis() > currTime + tempo) {
            int num = ofRandom(totalVoices);
            voices[num].play();
            currTime = ofGetSystemTimeMillis();
            cout << "playing voice " << num << endl;
        }
    }

    if (b_Gui) {
        // onscreen display of voices that are playing
        for (int i = 0; i < totalVoices; i++) {
            if (voices[i].isPlaying()) {
                ofDrawRectangle(90, ((i) * 20) + 7, ofMap(voices[i].getPosition(), 0, 1, 20, (ofGetWidth() -110)), 18); // draw a while progress bar
                ofDrawBitmapStringHighlight("voice " + ofToString(i + 1) + ": ", 10, (i + 1) * 20);
            }
            else {
                ofDrawBitmapString("voice " + ofToString(i + 1) + ": ", 10, (i + 1) * 20);
            }
        }
         myfont.drawString("Press q, w, e, r, t, y for choir tracks", 20, 200);
         myfont.drawString("press keys 1-8 to play voices \na to autoplay \n+ /- to increase/decrease tempo  \n'p' to load Piano Samples \n'v' to load vocal samples", 20, 240);
        // on screen instructions
         myfont.drawString("auto play is " + ofToString(b_autoPlay), 20, 360);
         myfont.drawString("tempo is " + ofToString(tempo) + " ms", 20, 400);
         if (voices[0].isPlaying()) {
             myfont.drawString("foolish trans girl", 20, 500);
         }
    }



    float nBands = 10;
    float* val = ofSoundGetSpectrum(nBands);
    float avg = 0;
    for (int i = 0; i < 10; ++i) {
        avg += val[i];
    }
    avg = avg * 10 / nBands;
    

    ofTranslate(ofGetWindowSize() * 0.5);

    auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
    drawWave(1, 3, voices[3].isPlaying());
    drawWave(1, 5, voices[5].isPlaying());
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
    case '1':
        voices[0].play();
        break;
    case '2':
        voices[1].play();
        break;
    case '3':
        voices[2].play();
        break;
    case '4':
        voices[3].play();
        break;
    case '5':
        voices[4].play();
        break;
    case '6':
        voices[5].play();
        break;
    case '7':
        voices[6].play();
        break;

    case '8':
        voices[7].setVolume(0.2);
        voices[7].play();
        break;
    case 'q':
        voices[9].play();
        break;
    case 'w':
        voices[10].play();
        break;
    case 'e':
        voices[11].play();
        break;
    case 'r':
        voices[12].play();
        break;
    case 't':
        voices[13].play();
        break;
    case 'y':
        voices[14].play();
        break;
    

    case 'a':
        b_autoPlay = !b_autoPlay;
        break;

    case '=':
    case'+':
        tempo += 500;
        break;

    case '-':
    case'_':
        if (tempo > 1000) {
            tempo -= 500;
        }
        break;

   

    


    case 'f':
        ofToggleFullscreen();
        break;

    case 'g':
        b_Gui = !b_Gui;
        break;

    default:
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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


//--------------------------------------------------------------

void ofApp::loadMusic() {
    // load piano samples
    totalVoices = 8;
    voices.clear();
    for (int i = 0; i < totalVoices; i++) {
        ofSoundPlayer voice;
        string path = "Eno-Piano-0" + ofToString(i + 1) + ".wav";
        cout << "loading " << path << endl;
        voice.load(path);
        voice.setMultiPlay(true);
        voices.push_back(voice);
    }

    for (int i = 0; i < 7; i++) {
        ofSoundPlayer voice;
        string path = "Eno-Choir-0" + ofToString(i + 1) + ".wav";
        cout << "loading " << path << endl;
        voice.load(path);
        voice.setMultiPlay(true);
        voices.push_back(voice);
    }
}

/*
    drawWave
    The default pattern, draws a sin wave

    params: 
        avg: The average numeric value of the sound spectrum
        playerNum: the number of the soundplayer. Will have a different
            amplitude based on this value
        playing: Boolean received from calling the built in isPlaying() function. Will be what controls 
            whether the sin wave oscillates or sits in a straight line



*/
void ofApp::drawWave(float avg, int playerNum,bool playing) {
    ofBeginShape();
    ofNoFill();
    ofSetColor(255, 255, 255);
    for (int x = -240; x <= 340; x += 1) {

        auto y = sin((x + 340 + ofGetFrameNum()) * 0.005 * playerNum  * playing) * (50 + (100 * avg));

        ofVertex(x, y);
    }
    ofEndShape();
}