#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    
    filmWidth  = ofGetWindowWidth(); // change it later with the saving data
    filmHeight = ofGetWindowHeight(); // change it later with the saving data
    filmPosX = 0;
    filmPosY = 0;
    
    gui.setup();
    gui.add(fWidth.setup ( "fWidth",  filmWidth,  0, ofGetWindowWidth()	));
    gui.add(fHeight.setup( "fHeight", filmHeight, 0, ofGetWindowHeight()));
    gui.add(fPosX.setup( "fPosX", filmPosX, 0, ofGetWindowWidth()));
    gui.add(fPosY.setup( "fPosY", filmPosY, 0, ofGetWindowHeight()));
    gui.add(infoPosX.setup( "infoPosX", filmWidth/2, 0, ofGetWindowWidth()));
    gui.add(infoPosY.setup( "infoPosY", filmHeight/2, 0, ofGetWindowHeight()));
    
    gui.loadFromFile("settings.xml");
    
    showGui = false;
    showCursor = false;
    CGDisplayHideCursor(NULL);
    
    for (int i = 0; i < 16; i++)
    {
        film[i].loadMovie("film" + ofToString(i) + ".mp4");
        if (i > 0)
        {
            film[i].setLoopState(OF_LOOP_NONE); //-- not for the starting loop
        }
    }

    filmNumber = 0;
    film[filmNumber].play();
    filmOnPause = true;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (film[filmNumber].isLoaded())
    {
        film[filmNumber].update();
        if (filmNumber > 3 && film[filmNumber].getIsMovieDone())
        {
            if (filmNumber > 3 && filmNumber < 8)
            {
                filmNumber = 1;
            }
            else if (filmNumber > 7 && filmNumber < 12)
            {
                filmNumber = 2;
            }
            else if (filmNumber > 11 && filmNumber < 16)
            {
                filmNumber = 3;
            }
            film[filmNumber].play();
        }
    }
    if (filmNumber < 4 && film[filmNumber].getIsMovieDone()) //-- if the language loop is done go to loop 0
    {
        beforeSwitchFilm();
        filmNumber = 0;
        film[filmNumber].play();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    film[filmNumber].draw(fPosX, fPosY, fWidth, fHeight);
    if(showGui)
    {
        gui.draw();
        ofSetColor(0, 200);
        ofFill();
        ofRect(infoPosX - 20,infoPosY - 20,300, 200);
        ofSetColor(255);
        ofDrawBitmapString("FrameRate = "   + ofToString(ofGetFrameRate()), infoPosX, infoPosY);
        ofDrawBitmapString("film number = " + ofToString(filmNumber),       infoPosX, infoPosY + 20);
        ofDrawBitmapString("Pause state = " + ofToString(filmOnPause),      infoPosX, infoPosY + 40);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f')
    {
        ofToggleFullscreen();
    }
    
    if (key == 'g')
    {
        showGui =! showGui;
        showCursor = !showCursor;
        if (showCursor == true)
        {
            CGDisplayShowCursor(NULL);
        }
        else if ( showCursor == false)
        {
            CGDisplayHideCursor(NULL);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 'p')
    {
        if (filmNumber > 3)
        {
            filmOnPause = !filmOnPause;
            film[filmNumber].setPaused(!filmOnPause);
        }

    }
    else
    {
        switch (key)
        {
            case 'a':
                beforeSwitchFilm();
                filmNumber = 1; //--Loop fr
                break;
                
            case 'z':
                beforeSwitchFilm();
                filmNumber = 2; //--Loop En
                break;
                
            case 'e':
                beforeSwitchFilm();
                filmNumber = 3; //--Loop De
                break;
                
            default:
                
                break;
        }

        if (filmNumber == 1 || (filmNumber > 3 && filmNumber < 8))
        {
            switch (key)
            {
                case 'r':
                    beforeSwitchFilm();
                    filmNumber = 4; //--Film 1 FR
                    break;
                    
                case 'u':
                    beforeSwitchFilm();
                    filmNumber = 5; //--Film 2 FR
                    break;
                    
                case 'i':
                    beforeSwitchFilm();
                    filmNumber = 6; //--Film 3 FR
                    break;
                    
                case 'o':
                    beforeSwitchFilm();
                    filmNumber = 7; //--Film 4 FR
                    break;
                    
                default:
                    break;
            }

        }
        else if (filmNumber == 2 || (filmNumber > 7 && filmNumber < 12))
        {
            switch (key)
            {
                case 'r':
                    beforeSwitchFilm();
                    filmNumber = 8; //--Film 1 EN
                    break;
                    
                case 'u':
                    beforeSwitchFilm();
                    filmNumber = 9; //--Film 2 EN
                    break;
                    
                case 'i':
                    beforeSwitchFilm();
                    filmNumber = 10; //--Film 3 EN
                    break;
                    
                case 'o':
                    beforeSwitchFilm();
                    filmNumber = 11; //--Film 4 EN
                    break;
                    
                default:
                    break;
            }
            
        }
        else if (filmNumber == 3 || (filmNumber > 11 && filmNumber < 16))
        {
            switch (key)
            {
                case 'r':
                    beforeSwitchFilm();
                    filmNumber = 12; //--Film 1 DE
                    break;
                    
                case 'u':
                    beforeSwitchFilm();
                    filmNumber = 13; //--Film 2 DE
                    break;
                    
                case 'i':
                    beforeSwitchFilm();
                    filmNumber = 14; //--Film 3 DE
                    break;
                    
                case 'o':
                    beforeSwitchFilm();
                    filmNumber = 15; //--Film 4 DE
                    break;
                    
                default:
                    break;
            }
            
        }
        film[filmNumber].play();
    }

    if (filmNumber > 15) //-- Just a security
    {
        filmNumber = 0;
    }
   
}

//--------------------------------------------------------------
void ofApp::beforeSwitchFilm()
{
    film[filmNumber].stop();
    film[filmNumber].firstFrame();
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
