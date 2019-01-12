/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
bool home = false;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT); //0 is P0, 1 is P1, 2 is P2, etc. - unlike the analog inputs, for digital outputs the pin number matches. motor speed
  pinMode(3, OUTPUT); //direction
  pinMode(13, OUTPUT); //direction

  //pinMode(10, INPUT_PULLUP);
  // pinMode(9, INPUT_PULLUP);
  Serial.begin(115200);



}

// the loop function runs over and over again forever
void loop() {

  byte sensorValue1 = digitalRead(10); //Returns HIGH or LOW (true or false / 1 or 0).
  byte sensorValue2 = digitalRead(9); //Returns HIGH or LOW (true or false / 1 or 0).

  int  sensorValue = analogRead(A5);
  Serial.print("sensor = ");
  Serial.println(sensorValue);





  if ((sensorValue1 == 0) && (sensorValue2 == 0)) {

    //goto centre 300
    //digitalWrite(1, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(2, LOW); //Turn the pin HIGH (5 V)
    analogWrite(3, 0  ); //Turn the pin on full (100%)

  }




  if ((sensorValue1 == 1) && (sensorValue2 == 1)) { ///HOME
    //digitalWrite(1, LOW);   // turn the LED on (HIGH is the voltage level)
    // digitalWrite(2, LOW); //Turn the pin HIGH (5 V)
    //   analogWrite(3, 0  ); //Turn the pin on full (100%)


    Serial.println("Zero position ");

    if ((sensorValue < 290) && (home == false)) {
      while (home == false) {
        sensorValue = analogRead(A5);
        digitalWrite(2, LOW); //Turn the pin HIGH (5 V)
        analogWrite(3, 100  ); //Turn the pin on full (100%)
        if (sensorValue > 290) {
          home = true;
          digitalWrite(2, LOW); //Turn the pin HIGH (5 V)
          analogWrite(3, 0  ); //Turn the pin on full (100%)

        }
      }    delay(100);

    }




    if ((sensorValue > 360) && (home == false)) {
      while (home == false) {
        sensorValue = analogRead(A5);
        digitalWrite(2, HIGH); //Turn the pin HIGH (5 V)
        analogWrite(3, 100  ); //Turn the pin on full (100%)
        if (sensorValue < 360) {
          home = true;
          digitalWrite(2, LOW); //Turn the pin HIGH (5 V)
          analogWrite(3, 0  ); //Turn the pin on full (100%)
        }
      }
      delay(100);
    }



  }









  if ((sensorValue1 == 0) && (sensorValue2 == 1)) { //GOOD
    home = false;

    // wait for a second
    if (sensorValue >  140) {
      digitalWrite(2, HIGH); //Turn the pin HIGH (5 V)
      //digitalWrite(3, HIGH); //Turn the pin HIGH (5 V)
      analogWrite(3, 110  ); //Turn the pin on full (100%)

      Serial.println("Good Egg towards");

    } else {
      digitalWrite(2, LOW); //Turn the pin HIGH (5 V)
      digitalWrite(3, LOW); //Turn the pin HIGH (5 V)
      //analogWrite(3, 0  ); //Turn the pin on full (100%)
      Serial.println("Good Egg position set");
    }
  }






  if ((sensorValue1 == 1) && (sensorValue2 == 0)) { //BAD
    home = false;

    if (sensorValue > 500) {
      digitalWrite(2, HIGH); //Turn the pin HIGH (5 V)
      analogWrite(3, 0  ); //Turn the pin on full (100%)
      Serial.println("BAD Egg position set");

    } else {
      digitalWrite(2, LOW); //Turn the pin HIGH (5 V)
      //digitalWrite(6, HIGH); //Turn the pin HIGH (5 V)
      // digitalWrite(3, HIGH); //Turn the pin HIGH (5 V)
      analogWrite(3, 110 ); //Turn the pin on full (100%)


      //  analogWrite(3, 255  ); //Turn the pin on full (100%)
      Serial.println("BAD Egg towards");

      //digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
  }







  delay(1);                       // wait for a second
}
