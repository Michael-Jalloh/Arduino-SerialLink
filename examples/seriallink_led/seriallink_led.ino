#include <SerialLink.h>

SerialLink serial(115200, '<','>');

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    serial.init(); // Initialize Serial port here or it wouldn't work on the Ardunio, but works on the esp8266
}

void loop() {
    serial.poll();
    if (serial.newData == true) {
        char* data = serial.getNewData();
        String a = data;
        // data
        if (a == "on"){
            digitalWrite(LED_BUILTIN, HIGH);
            serial.sendData(data);
        }
        else if( a == "off") {
            digitalWrite(LED_BUILTIN, LOW);
            serial.sendData(data);
        }   
    }
}