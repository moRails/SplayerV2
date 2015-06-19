#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i = 0; i < 16; i++)
    {
        film[i].loadMovie("film" + ofToString(i) + ".mp4");
        if (i > 0)
        {
            film[i].setLoopState(OF_LOOP_NONE);
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
    if (filmNumber < 4 && film[filmNumber].getIsMovieDone())
    {
        beforeSwitchFilm();
        filmNumber = 0;
        film[filmNumber].play();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    film[filmNumber].draw(0,0);
    ofDrawBitmapString("film number = " + ofToString(filmNumber), 20, 20);
    ofDrawBitmapString("Pause state = " + ofToString(filmOnPause),20, 40);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

    if (filmNumber > 15)
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
