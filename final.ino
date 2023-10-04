// Initially, we began with the Arduino example code "servo sweep" and tailored it for a one-motor-to-one-sensor setup. 
// Subsequently, we modified the code further to coordinate the movement of four motors, guiding a ball to a 
// randomly selected corner based on light sensor inputs. 

#include <Servo.h>

Servo myservo1; // for four std motors
Servo myservo2;
Servo myservo3;
Servo myservo4;

int lightSensor1 = A7; // for four light sensors
int lightSensor2 = A6;
int lightSensor3 = A5;
int lightSensor4 = A4;


int lightSensorVal1;  // value of four light sensors
int lightSensorVal2;
int lightSensorVal3;
int lightSensorVal4;

int lightSensorThreshold = 930;  

long randNumber; 


void setup() {
  myservo1.attach(2);  // attach 4 motors
  myservo2.attach(3);
  myservo3.attach(4); 
  myservo4.attach(5); 
  Serial.begin(9600);
  randomSeed(analogRead(0)); // random initializer

}

void loop() {
  lightSensorVal1 = analogRead(lightSensor1);  // reading and assigning values of 4 senosors
  lightSensorVal2 = analogRead(lightSensor2);
  lightSensorVal3 = analogRead(lightSensor3);
  lightSensorVal4 = analogRead(lightSensor4);
  
if (lightSensorVal1<=lightSensorThreshold) // 1st sensor and motor
  {
  randNumber = random(3);
  delay(1000);
   if (randNumber == 0) //lower corner 2
   {
     myservo2.write(120);
     myservo1.write(60);
     myservo3.write(60);
     myservo4.write(0);
    delay(50);


   }
   else if (randNumber == 1) // lower corner 3
   {

     myservo3.write(0);
     myservo2.write(60);
     myservo1.write(120);
     myservo4.write(60);
      delay(50); 

   }

   else // lower corner 4
   {

    myservo4.write(120);
    myservo2.write(60);
    myservo1.write(60);
    myservo3.write(0);
    delay(50);

   }
  


 Serial.println("COVEREDSERVO1!!");
 Serial.println(randNumber);
  }

else  if (lightSensorVal2<=lightSensorThreshold) // 2nd sensor and motor
  {

  randNumber = random(3);
  delay(1000);
  
   if (randNumber == 0) //lower corner 1
   {
    myservo1.write(0);
    myservo2.write(60);
    myservo3.write(60);
    myservo4.write(120);
    delay(100);


   }
   else if (randNumber == 1) // lower corner 3
   {

      myservo3.write(0);
      myservo2.write(60);
      myservo4.write(60);
      myservo1.write(120);
      delay(50);

   }

   else // lower corner 4
   {

    
      myservo4.write(120);
      myservo3.write(60);
      myservo2.write(0);
      myservo1.write(60);
      delay(50);

   }
  Serial.println(randNumber);
  Serial.println("COVEREDSERVO2!!");
  }
 
   
  
  
else  if (lightSensorVal3<=lightSensorThreshold) // 3rd sensor and motor
  {
  randNumber = random(3);
  delay(1000);
   if (randNumber == 0) //lower corner 1
   {
    myservo2.write(60);
    myservo1.write(0);
    myservo4.write(60);
    myservo3.write(120);
    delay(50);


   }
   else if (randNumber == 1) // lower corner 2
   {

      myservo2.write(120);
      myservo4.write(0);
      myservo1.write(60);
      myservo3.write(60);
      delay(50);

   }

   else // lower corner 4
   {

      
      myservo4.write(120);
      myservo1.write(60);
      myservo3.write(60);
      myservo2.write(0);
      delay(50);

   }


 Serial.println("COVEREDSERVO3!!");
 Serial.println(randNumber);
  }
  
  
  
  
  
else  if (lightSensorVal4<=lightSensorThreshold) // 4th sensor and motor
  {
  randNumber = random(3);
  delay(1000);
   if (randNumber == 0) //lower corner 1
   {
    myservo1.write(0);
    myservo2.write(60);
    myservo3.write(120);
    myservo4.write(60);
    delay(50);


   }
   else if (randNumber == 1) // lower corner 2
   {

      myservo2.write(120);
      myservo1.write(60);
      myservo4.write(0);
      myservo3.write(60);
      delay(50);

   }

   else // lower corner 3
   {

      
      myservo3.write(0);
      myservo2.write(60);
      myservo1.write(120);
      myservo4.write(60);
      delay(50);
 
   }


 Serial.println("COVEREDSERVO4!!");
 Serial.println(randNumber);
  }
 
else{
   
   Serial.println("NOTCOVERED!!"); //no sensors covered 
}

}

  

