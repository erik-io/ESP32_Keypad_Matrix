#include <Keypad.h>
 
#define ROWS  4
#define COLS  4
 
char keyMap[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
 
byte rowPins[ROWS] = {14, 27, 12, 13}; // GIOP14, GIOP27, GIOP12, GIOP13
byte colPins[COLS] = {33, 32, 18, 23}; // GIOP33, GIOP32, GIOP18, GIOP23
 
Keypad keypad = Keypad(makeKeymap(keyMap), rowPins, colPins, ROWS, COLS );
 
void setup(){
  Serial.begin(115200);
  keypad.setDebounceTime(5); // Entprellzeit in ms
}

void loop(){

  char key = keypad.getKey();
  if (key != NO_KEY) { 
  // if (key) führt zu unerwarteten Verhalten
    Serial.println(key);
  }
}