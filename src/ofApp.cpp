#include "ofApp.h"
#include <cmath>
//--------------------------------------------------------------
void ofApp::setup() {
    // load vocal samples
    // loadVocal();
    // or uncomment this instead to load piano samples
    ofTrueTypeFont::setGlobalDpi(72);
    myfont.load("roboto.ttf", 20, true, true);

    ofSetFrameRate(30);
    ofSetWindowTitle("celias epic boxes");
    ofEnableDepthTest();
    loadMusic();

    tempo = 5000; // starting with five seconds tempo
    b_autoPlay = false;
    currTime = ofGetSystemTimeMillis();

    ofSetBackgroundColor(0);
    // ofSetBackgroundAuto(false);
    b_Gui = true;
    ofEnableSmoothing();
    ofSetLineWidth(3);
    flag = 0;
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
         //if (voices[0].isPlaying()) {
         //    myfont.drawString("foolish trans girl", 20, 500);
         //}
    }



    float nBands = 64;
    float *val = ofSoundGetSpectrum(nBands);
    float avg = 0;
    for (int i = 0; i < 64; ++i) {
        avg += val[i];
    }
    //avg = avg * 10 / nBands;

    switch (flag) {
    case 0:
        ofTranslate(ofGetWindowSize() * 0.5);
        totalWave(avg);
        break;
    case 1:
        cam.begin();
        cam.disableMouseInput();
        cam.setDistance(550);
        ofRotateX(40);
        ofRotateY(ofGetFrameNum() * 0.3333333333);
        boxgrid(8, val);
        cam.end();
        break;
    default:
        break;
    }

    

  
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
    case '1':
        voices[0].setVolume(0.2);
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
        voices[7].play();
        break;

   

    case '9':
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
    case 'b':
        ++flag;
        break;
    case 'v':
        --flag;
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

    for (int i = 0; i < 8; i++) {
        ofSoundPlayer voice;
        string path = "Eno-Choir-0" + ofToString(i) + ".wav";
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
void ofApp::drawWave(float avg, int playerNum,bool playing, int red, int green, int blue) {
    ofBeginShape();
    ofNoFill();
    ofSetColor(red, green, blue);
    for (int x = -ofGetWidth(); x <= ofGetWidth(); x += 1) {

        auto y = sin((x + ofGetWidth() + ofGetFrameNum()) * 0.03 * avg * log(pow(playerNum + 3, 2)) * playing) * (70 + (60 * avg * pow(playerNum + 5, 1.5)));

        ofVertex(x, y);
    }
    ofEndShape();
}

void ofApp::totalWave(float avg) {
    avg /= 5;
    for (int count = 0; count < num_waves; ++count) {
        drawWave(avg, count, voices[count].isPlaying(),
            waveColours[count][0], waveColours[count][1], waveColours[count][2]);
    }
}

void ofApp::boxgrid(int sideLength, float* spectrum) {
    center = sideLength * 100 / 2;
    int leverage = 1;
    for (int i = 0; i < sideLength; ++i)
        for (int j = 0; j < sideLength; ++j) {
            if (3 * i * j > 49) leverage = 6;
            ofSetHexColor(randColorList[i + j + i]);
            ofDrawBox(ofPoint(-center + (100 * i), 0, -center + (100 * j)), 100, 100 + (5000 * spectrum[3 * i + j] * leverage), 100);
        }//xyz
}