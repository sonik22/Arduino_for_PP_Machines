 #include <TFT.h>


#include <TFT.h>  // Arduino LCD library
#include <Encoder.h>
#include <SPI.h>


// pin definition for the Nano
#define cs   10
#define dc   9
#define rst  8


int setTemp1 = 0;
int setTemp2;
int Thermistor1 = 0;
int Thermistor2 = 1;
int Thermistor3 = 2;
int Vo;
float R1 = 1000;
float logR2, R2;
int T;
int prevT = 0;
int rect(4);
float c1 = 1.311626646e-03, c2 = 0.8692932193e-04, c3 = 6.795256366e-07; // Steinhart-Hart and Hart Coefficients
Encoder myEnc(2, 3);
TFT TFTscreen = TFT(cs, dc, rst);
long prevMillis = 0;
int delaytime = 1000;
int relay1 = 6;
int relay2 = 7;

char sensorPrintout1[4];  //setted temperature
char sensorPrintout2[4];  //setted temperature

char sensorPrintout3[4];
char sensorPrintout4[4];
char sensorPrintoutT1[4];   //Nozzle
char sensorPrintoutT2[4];   //Barrel
char sensorPrintoutT3[4];   //Entry


void setup() {
  
Serial.begin(9600);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
  
  TFTscreen.begin();
  TFTscreen.setRotation(3);
  TFTscreen.background(0, 0, 0);
  printGui();

}

void loop() {

   int setTemp2 = setTemp1 * 90 / 100;  // Temp2 is 90% of Temp1
      setTemperature();
    if (millis() - prevMillis > delaytime) {
      tempReading(Thermistor1);
      Serial.print(T);
 
      updateTempNozzle();
    
    if (T <= setTemp1) {
      digitalWrite(relay1, LOW);
    }
    else {
      digitalWrite(relay1, HIGH);
    }
Serial.println(setTemp1);
   //   setTemperature();
      tempReading(Thermistor2);
      Serial.print(T);
      Serial.println(setTemp2);

      updateTempMain();
               
     if (T <= setTemp2) {
      digitalWrite(relay2, LOW);
    }
    else {
      digitalWrite(relay2, HIGH);
    }

      tempReading(Thermistor3);
      Serial.print(T);
      Serial.println(setTemp2);

      updateTempEntry();


/*       int fakeSensor = 0;
  if  (fakeSensor == 0); {

  String stringThree =  String("58");
  stringThree.toCharArray(sensorPrintout3, 4);
  
  String stringFour =  String("24");
  stringFour.toCharArray(sensorPrintout4, 4);

  TFTscreen.fill(0, 0, 0);
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.rect(10, 120, 116, 24); //clear the space with black
  
  TFTscreen.stroke(255, 0, 0);
  
  TFTscreen.text(sensorPrintout3, 15, 131); // measured RPM for Extruder screw
  TFTscreen.text(sensorPrintout4, 74, 131); // RPM or % Display of pulling motor
} 
 */
          prevMillis = millis();
      }

}

