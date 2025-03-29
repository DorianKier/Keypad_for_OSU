#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 1
#define NUMCOLS 2

byte buttons[NUMROWS][NUMCOLS] = {
  { 88, 90 }
};

byte pinRows[NUMROWS] = { 18 };
byte pinCols[NUMCOLS] = { 19, 20 };

Keypad buttOSU = Keypad(makeKeymap(buttons), pinRows, pinCols, NUMROWS, NUMCOLS);

void setup() {
  Keyboard.begin();
}

void loop() {
  CheckButtons();
}

void CheckButtons(void) {
  if(buttOSU.getKeys()){
    for(int i=0; i<LIST_MAX; i++){
      if(buttOSU.key[i].stateChanged){
        switch(buttOSU.key[i].kstate){
          case PRESSED:
          case HOLD:
            Keyboard.press(buttOSU.key[i].kchar);
            break;
          case RELEASED:
          case IDLE:
            Keyboard.release(buttOSU.key[i].kchar);
            break;
        }
      }
    }
  }
}