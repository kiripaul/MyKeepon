#pragma once

#include "ofRectangle.h"
#include "ofxUI.h"
#include <set>

class MyKeeponControlPanel{
	public:
		MyKeeponControlPanel(const ofVec2f p);
		~MyKeeponControlPanel();
		void update();
		void guiListener(ofxUIEventArgs &args);
		const bool& toDelete() const;
		void setX(const int x_);
		const ofRectangle getRectangle();
		struct Values {
			float pan = 0.5, tilt = 0.5;
			float panSpeed = 0.5, tiltSpeed = 0.5, sideSpeed = 0.5;
		};
	private:
		// GUI handlers
		ofxUICanvas mGui;
		ofxUIDropDownList* mSerialList;
		ofxUI2DPad* m2DPad;
		ofxUISlider* mPanSlider, *mTiltSlider, *mSideSlider;
		// Serial
		ofSerial mSerial;
		// bools
		bool bDelete, bUpdateSerialList, bSerialInited, bIsSync, bUpdateGuiFromValues;
		Values mValues;
		// helpers
		void sendPanAndTilt();
		void sendPanSpeed();
		void sendTiltSpeed();
		void sendSideSpeed();
		// statics
		static vector<string> theSerials;
		static vector<string>& updateSerialList();
		static Values syncValues;
		static set<MyKeeponControlPanel*> theSyncPanels;
		static void sendSyncPanAndTilt();
		static void sendSyncPanSpeed();
		static void sendSyncTiltSpeed();
		static void sendSyncSideSpeed();
};
