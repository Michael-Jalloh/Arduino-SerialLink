#include <SerialLink.h>

SerialLink serial(115200, '<','>');

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
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