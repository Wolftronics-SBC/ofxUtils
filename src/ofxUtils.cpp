#include "ofxUtils.h"

string ofxGetDateCompact()
{
    stringstream returnDate;
    
    // Year
    returnDate << ofToString(ofGetYear()) + "_";
    // LEADING ZEROS
    // Month
    returnDate << setw(2) << setfill('0') << ofGetMonth();
    returnDate << "_";
    // Day
    returnDate << setw(2) << setfill('0') << ofGetDay();
    returnDate << "-";
    // Hour
    returnDate << setw(2) << setfill('0') << ofGetHours();
    returnDate << "_";
    // Minutes
    returnDate << setw(2) << setfill('0') << ofGetMinutes();
    returnDate << "_";
    // Seconds
    returnDate << setw(2) << setfill('0') << ofGetSeconds();
    
    return returnDate.str();
}


string ofxGetMonthDayCompact()
{
    stringstream returnDate;
    
    // Month
    returnDate << setw(2) << setfill('0') << ofGetMonth();
    returnDate << "_";
    // Day
    returnDate << setw(2) << setfill('0') << ofGetDay();
    
    return returnDate.str();
}

string ofxGetLeadingZeros(const string & value, int numberOfZeros)
{
    stringstream returnDate;
    
    returnDate << setw(numberOfZeros) << setfill('0') << value;
    
    return returnDate.str();
}

string ofxGetLeadingZeros(const int & value, int numberOfZeros)
{
    return ofxGetLeadingZeros(ofToString(value), numberOfZeros);
}

ofPoint ofxFitToScreen(const int & width, const int & height, const int & screenWidth, const int & screenHeight, bool upScale)
{
    ofPoint returnSize;
    
    float windowRatio = (float) screenWidth / screenHeight;
    float frameRatio = (float) width / height;
    
    if (!upScale && screenWidth > width && screenHeight > height)
    {
        returnSize = ofPoint(width, height);
        // ofLogNotice("ofxUtils", "upScale is set to false, so no change.");
        return returnSize;
    }
    
    else
    {
        if (windowRatio > frameRatio)
        {
            returnSize.x = (int) screenHeight * frameRatio;
            returnSize.y = screenHeight;
        }
        
        else if (windowRatio < frameRatio)
        {
            returnSize.x = screenWidth;
            returnSize.y = (int) screenWidth / frameRatio;
        }
        
        else if (windowRatio == frameRatio)
        {
            returnSize.x = screenWidth;
            returnSize.y = screenHeight;
        }
        
        return returnSize;
    }
}
