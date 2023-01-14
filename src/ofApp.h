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

		float avg;
		//TITLE FIRST PAGE
		//--------------------------------
		void titleUpdate(float avg);
		void titleDraw(float avg);
		int frame_num = 0;
		ofTrueTypeFont poppins_small;
		ofMesh mesh;
		int count = 0;
		ofTrueTypeFont poppins;
		//-----------------------------


		void drawWave(float avg, int playerNum, bool playing,
			int red, int green, int blue);
		void totalWave(float avg);

		void loadMusic();


		int flag;
		
		int num_waves = 8;
		int waveColours[14][3] = {
			{255, 124, 124},
			{108, 255, 255 },
			{103, 254, 122 },
			{255, 171, 199},
			{108, 202, 255},
			{147, 109, 248},
			{216, 245, 71},
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
		

		void boxgrid(int sideLength, float* spectrum);

		vector<int> randColorList = { 0xf44336, 0x9C27B0, 0x3F51B5, 0x03A9F4,
			0x009688, 0x8BC34A, 0xFFEB3B, 0xFF9800 ,
			0xFFEB3B, 0xFF9800,
			0xf44336, 0x9C27B0,
			0x8BC34A, 0xFFEB3B,
			0x9C27B0, 0x3F51B5,
			0x009688, 0x8BC34A,
			0x8BC34A, 0xFFEB3B,
			0xf44336, 0x9C27B0, 0x3F51B5,0xFF9800
		};
		int center;
		ofEasyCam cam;
};
