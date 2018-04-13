#pragma once

#include "ofMain.h"

string ofxGetDateCompact();

string ofxGetMonthDayCompact();

string ofxGetLeadingZeros(const string & value, int numberOfZeros);

string ofxGetLeadingZeros(const int & value, int numberOfZeros);

ofPoint ofxFitToScreen(const int & width, const int & height, const int & screenWidth, const int & screenHeight, bool upScale = false);