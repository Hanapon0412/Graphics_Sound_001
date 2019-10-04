#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    fft.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    fft.update();
    int counter = 0;
    
    for (auto &vert : line.getVertices() ){
        if (fft.getBins()[80] > 0.11) {
            //specific bins received the line will be smoothed
            vert.x += (vert.x - line2[counter].x) * ofRandom(-0.5,0);
            vert.y += (vert.y - line2[counter].y) * ofRandom(-0.5,0);
        } else {
            //nothing happens the line will get noisy
            //these coming 2 lines to make line noisy
            //are borrowed from ofBook https://openframeworks.cc/ofBook/chapters/intro_to_graphics.html#brushesfromfreeformshapes
            vert.x += ofRandom(-1,1);
            vert.y += ofRandom(-1,1);
            
        }
        counter += 1;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    line.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofPoint pt;
    pt.set(x, y);
    line2.push_back(pt);  //a fake line to track the original positions
    line.addVertex(pt);   //the line to be drawn
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line.clear();
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
