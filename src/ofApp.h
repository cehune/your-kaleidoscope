#pragma once

#include "ofMain.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawWave(float avg, int playerNum, bool playing,
			int red, int green, int blue);
		void totalWave(float avg);

		void loadMusic();
		
		int num_waves = 8;
		int waveColours[14][3] = {
			{255, 124, 124},
			//{255, 175, 86},
			{108, 255, 255 },
			//{255, 222, 86},
			{103, 254, 122 },
			//{79, 255, 188 },
			{255, 171, 199},


			{108, 202, 255},
			//{86, 132, 255 },
			{147, 109, 248},
			//{223, 109, 248},
			{216, 245, 71},
			//{252, 145, 234},
			{255, 255, 255 }
		};
		vector<ofSoundPlayer>voices;
		ofSoundPlayer voice1, voice2, voice3, voice4, voice5, voice6, voice7;
		bool b_autoPlay;
		float tempo, currTime;
		ofTrueTypeFont myfont;
		int totalVoices, totalChoir;
		char choirKeys[6] = { 'q', 'w', 'e', 'r', 't', 'y' };
		bool b_Gui;
		ofSoundPlayer drums;
		
};
