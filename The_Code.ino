//Control the servo motor via potiomometer
//This code is made with the help of ((https://create.arduino.cc/projecthub/H0meMadeGarbage/robot-arm-with-controller-2038df?ref=similar&ref_id=122220&offset=1)) 
#include <Servo.h>

Servo  myservo1, myservo2; 

float th1=90.0,th2=90.0;
float  val1, val2;

void setup() {
    Serial.begin(9600);

    myservo1.attach(10, 820, 2140); //DS3115
    myservo2.attach(11, 820, 2140); //DS3115
    set_servo();
}

void loop() {
   
    val1 = analogRead(A2);
    val2 = analogRead(A3);

  
    th1 = map(val1, 150.0, 860.0, 0.0, 180.0);
    if(th1 >= 180.0){
        th1 = 180.0;
    }else if(th1 <= 0.0){
        th1 = 0.0;
    }

    th2 = map(val2, 860.0, 160.0, 0.0, 180.0);
    if(th2 >= 180.0){
        th2 = 180.0;
    }else if(th2 <= 45.0){
        th2 = 45.0;
    }

    set_servo();
}

void set_servo(){
  
    myservo1.write(th1);
    myservo2.write(th2);
}
