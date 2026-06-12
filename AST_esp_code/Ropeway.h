#import <AccelStepper.h>

// Abstrakte Basisklasse
class Station {
  public:
    virtual void update() = 0;
};

// Talstation mit Motor
class AntriebsStation : public Station {
  private:
    int leftSensorPin = 12;
    int rightSensorPin = 11;

    int stepperRopePin = ;a
    int stepper1LeftPin = ;
    int stepper2LeftPin = ;
    int stepper3LeftPin = ;
    int stepperDistanceLeftPin = ;
    int stepper1RightPin = ;
    int stepper2RightPin = ;
    int stepper3RightPin = ;
    int stepperDistanceRightPin = ;
    int stepperTurnPin = ;

  public:
    AntriebsStation() : Station() {}

    void update() override {

    }
};

// Bergstation (Nur Umlenkung)
class GST : public Station {
  private: 
    int leftSensorPin = 12;
    int rightSensorPin = 11;

    int stepper1LeftPin = ;
    int stepper2LeftPin = ;
    int stepper3LeftPin = ;
    int stepperDistanceLeftPin = ;
    int stepper1RightPin = ;
    int stepper2RightPin = ;
    int stepper3RightPin = ;
    int stepperDistanceRightPin = ;
    int stepperTurnPin = ;

    AccelStepper turnStepper = AccelStepper(stepper1LeftPin usw.); //für jeden stepper inen stepper hier anlegen

  public:
    GST() : Station() {

    }

    void update() override {
      
    }
};