#ifndef SerialLINK_H
#define SerialLINK_H

#include <Arduino.h>

class SerialLink {
    private:
        long baudrate;
        char startMaker;
        char endMarker;
        byte numChar = 32;
        bool recvInProgress;
        byte index = 0;
        char receivedChar[32];
    
    public:
        bool newData;
        // Seriallink();
        SerialLink(long baudrate, char startMaker,char endMarker);

        void init();
        
        void poll();
        
        bool gotNewData();
        
        char* getNewData();
        
        void sendData(char* data);
        void sendData(String data);
        
        void sendBool();

};

#endif