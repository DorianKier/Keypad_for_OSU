/* Keypad do gry OSU! */
/* Kod pisany dla płytki Arduino Leonardo Pro Micro.
z wykorzystaniem switchy Cherry MX Red/Blue.
Piny podłączoe w sposób taki:
GND = GND,
Lewy przcisk = 6 pin,
Prawy przycisk = 8 pin,
Autor kodu: Dorian Kiewro*/
#include <Keyboard.h>

// zmienne przypisujące lewy przcisk do pinu 6 oraz prawy przycisk do pinu 8
#define left_click digitalRead(6)
#define right_click digitalRead(8)

void setup(){
  pinMode(6, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  Keyboard.begin();
}

void loop(){
  if(left_click == LOW){
    Keyboard.press(90); // code ASCII 90 = Z
  }
  else if(right_click == LOW){
    Keyboard.press(88); // code ASCII 88 = X
  }
  else{
    Keyboard.releaseAll(); // puszczanie przycisków
  }
}
