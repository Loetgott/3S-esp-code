#include <Gondel.h>
#include <Ropeway.h>

#define isAST false

// Wir deklarieren einen Pointer auf die Basisklasse und initialisieren ihn mit "nullptr" (leer)
Station* station = nullptr; 

void setup() {
  Serial.begin(115200);

  if (isAST) {
    station = new AntriebsStation();
  } else {
    station = new GegenStation();
  }
}

void loop() {
  // Wichtig: Da 'station' ein Pointer ist, nutzen wir den Pfeil-Operator (->) statt dem Punkt (.)
  if (station != nullptr) {
    station->update(); 
  }
}