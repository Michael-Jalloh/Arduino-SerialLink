#include "SerialLink.h"

// SerialLink::SerialLink(){
//     this -> baudrate = 115200;
//     this -> startMaker = '<';
//     this -> endMarker = '>';
//     this -> numChar = 32;
//     this -> receivedChar[32];
//     init();
// }

SerialLink::SerialLink(long baudrate, char startMaker,char endMarker){
    this -> baudrate = baudrate;
    this -> startMaker = startMaker;
    this -> endMarker = endMarker;
    init();
}

void SerialLink::init() {
    Serial.begin(baudrate);
}

void SerialLink::poll(){
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();
        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChar[index] = rc;
                index++;
                if (index >= numChar) {
                    index = numChar -1;
                }
            }
            else {
                receivedChar[index] = '\0';
                recvInProgress = false;
                index = 0;
                newData = true;
            }
        }
        else if(rc == startMaker) {
            recvInProgress = true;
        }
    }
}
        
bool SerialLink::gotNewData(){
    return newData;
}

char* SerialLink::getNewData(){
    newData = false;
    return receivedChar;    
}

void SerialLink::sendData(char* data){
    Serial.print('<');
    Serial.print(data);
    Serial.print('>');
}

void SerialLink::sendData(String data){
    Serial.print('<');
    Serial.print(data);
    Serial.print('>');
}

void SerialLink::sendBool(){
    Serial.print(newData);
}
