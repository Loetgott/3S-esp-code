#include <AccelStepper.h> // Wichtig: #include statt #import in C++

// Abstrakte Basisklasse
class Station {
public:
  virtual void update() = 0;
  virtual ~Station() {} // Virtueller Destruktor ist guter Stil bei Polymorphie
};

// Talstation mit Motor
class AntriebsStation : public Station {
private:
  static constexpr uint8_t LEFT_PIN = 14;
  static constexpr uint8_t RIGHT_PIN = 13;
  static constexpr uint8_t DIR_PIN = 1;
  static constexpr uint8_t ENA_PIN = 2;
  static constexpr uint8_t NUM_MOTORS = 10;
  static constexpr uint8_t LED_PIN = 21;

  // Jetzt mit 10 Pins (habe hinten mal eine '12' als Dummy für den Seilmotor ergänzt)
  const uint8_t STEP_PINS[NUM_MOTORS] = { 4, 9, 7, 8, 5, 10, 6, 3, 11, 12 };

  // Objekte nur deklarieren, noch nicht initialisieren!
  AccelStepper stepperLeft1;
  AccelStepper stepperLeft2;
  AccelStepper stepperLeft3;
  AccelStepper stepperLeft4;
  AccelStepper stepperRight1;
  AccelStepper stepperRight2;
  AccelStepper stepperRight3;
  AccelStepper stepperRight4;
  AccelStepper stepperTurn;
  AccelStepper stepperRope;

  // Array aus Pointern auf die Stepper
  AccelStepper* steppers[NUM_MOTORS];

public:
  // Die Initialisierung passiert genau HIER im Konstruktor:
  AntriebsStation()
    : Station(),
      stepperLeft1(AccelStepper::DRIVER, STEP_PINS[0], DIR_PIN),
      stepperLeft2(AccelStepper::DRIVER, STEP_PINS[1], DIR_PIN),
      stepperLeft3(AccelStepper::DRIVER, STEP_PINS[2], DIR_PIN),
      stepperLeft4(AccelStepper::DRIVER, STEP_PINS[3], DIR_PIN),
      stepperRight1(AccelStepper::DRIVER, STEP_PINS[4], DIR_PIN),
      stepperRight2(AccelStepper::DRIVER, STEP_PINS[5], DIR_PIN),
      stepperRight3(AccelStepper::DRIVER, STEP_PINS[6], DIR_PIN),
      stepperRight4(AccelStepper::DRIVER, STEP_PINS[7], DIR_PIN),
      stepperTurn(AccelStepper::DRIVER, STEP_PINS[8], DIR_PIN),
      stepperRope(AccelStepper::DRIVER, STEP_PINS[9], DIR_PIN) 
  {
    // Pointer-Array im Konstruktor-Body befüllen
    steppers[0] = &stepperLeft1;  steppers[1] = &stepperLeft2;
    steppers[2] = &stepperLeft3;  steppers[3] = &stepperLeft4;
    steppers[4] = &stepperRight1; steppers[5] = &stepperRight2;
    steppers[6] = &stepperRight3; steppers[7] = &stepperRight4;
    steppers[8] = &stepperTurn;   steppers[9] = &stepperRope;

    pinMode(LEFT_PIN, INPUT);
    pinMode(RIGHT_PIN, INPUT);
  }

  void update() override {
    // Hier später z.B. für alle Stepper runSpeed() aufrufen:
    // for(int i=0; i<NUM_MOTORS; i++) { steppers[i]->runSpeed(); }
  }
};

// Bergstation (Nur Umlenkung)
class GegenStation : public Station {
private:
  static constexpr uint8_t LEFT_PIN = 14;
  static constexpr uint8_t RIGHT_PIN = 13;
  static constexpr uint8_t DIR_PIN = 1;
  static constexpr uint8_t ENA_PIN = 2;
  static constexpr uint8_t NUM_MOTORS = 9;
  static constexpr uint8_t LED_PIN = 21;

  const uint8_t STEP_PINS[NUM_MOTORS] = { 4, 9, 7, 8, 5, 10, 6, 3, 11 };

  AccelStepper stepperLeft1;
  AccelStepper stepperLeft2;
  AccelStepper stepperLeft3;
  AccelStepper stepperLeft4;
  AccelStepper stepperRight1;
  AccelStepper stepperRight2;
  AccelStepper stepperRight3;
  AccelStepper stepperRight4;
  AccelStepper stepperTurn;

  AccelStepper* steppers[NUM_MOTORS];

  bool leftSensorActive = false;  // Direkt mit false initialisieren
  bool rightSensorActive = false; // Direkt mit false initialisieren

  void sendSensorData() {
    //...
  }

public:
  // Konstruktor für die Bergstation
  GegenStation()
    : Station(),
      stepperLeft1(AccelStepper::DRIVER, STEP_PINS[0], DIR_PIN),
      stepperLeft2(AccelStepper::DRIVER, STEP_PINS[1], DIR_PIN),
      stepperLeft3(AccelStepper::DRIVER, STEP_PINS[2], DIR_PIN),
      stepperLeft4(AccelStepper::DRIVER, STEP_PINS[3], DIR_PIN),
      stepperRight1(AccelStepper::DRIVER, STEP_PINS[4], DIR_PIN),
      stepperRight2(AccelStepper::DRIVER, STEP_PINS[5], DIR_PIN),
      stepperRight3(AccelStepper::DRIVER, STEP_PINS[6], DIR_PIN),
      stepperRight4(AccelStepper::DRIVER, STEP_PINS[7], DIR_PIN),
      stepperTurn(AccelStepper::DRIVER, STEP_PINS[8], DIR_PIN) 
  {
    steppers[0] = &stepperLeft1;  steppers[1] = &stepperLeft2;
    steppers[2] = &stepperLeft3;  steppers[3] = &stepperLeft4;
    steppers[4] = &stepperRight1; steppers[5] = &stepperRight2;
    steppers[6] = &stepperRight3; steppers[7] = &stepperRight4;
    steppers[8] = &stepperTurn;

    pinMode(LEFT_PIN, INPUT);
    pinMode(RIGHT_PIN, INPUT);
  }

  void update() override {
    if (digitalRead(LEFT_PIN) == LOW && !leftSensorActive) {
      leftSensorActive = true;
      sendSensorData();
    } else if (digitalRead(LEFT_PIN) == HIGH && leftSensorActive) {
      leftSensorActive = false;
    }

    if (digitalRead(RIGHT_PIN) == LOW && !rightSensorActive) {
      rightSensorActive = true;
      sendSensorData();
    } else if (digitalRead(RIGHT_PIN) == HIGH && rightSensorActive) {
      rightSensorActive = false;
    }


  }
};