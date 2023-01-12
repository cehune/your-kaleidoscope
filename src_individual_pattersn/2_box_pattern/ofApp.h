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

		void boxgrid(int sideLength, float *spectrum);
	
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
		float* val;
		
		
		ofSoundPlayer sound;
		ofEasyCam cam;
};
