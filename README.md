# SerialLink
SerialLink is a arduino library designed to simplify serial communication with host computers. It enables efficient and seamless data exchange without blocking code execution. By using configurable start and end markers, SerialLink ensures reliable message framing, making it an ideal tool for developers working with embedded systems or serial communication.

### Notes: Need the [python](https://github.com/Michael-Jalloh/SerialLink) companion library on the host computer

## Example
```cpp
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
```
