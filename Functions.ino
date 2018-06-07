//*******************************************************************************//

void printGui () {
  
  TFTscreen.stroke(0, 0, 255); // set the stroke color to red
  TFTscreen.rect(0, 20, 53, 42); //draw a rectangle across the screen
  TFTscreen.rect(53, 20, 53, 42); //draw a rectangle across the screen
  TFTscreen.rect(106, 20, 54, 42); //draw a rectangle across the screen
  
  TFTscreen.rect(0, 65, 80, 62); //draw a rectangle across the screen
  TFTscreen.rect(80, 65, 80, 62); //draw a rectangle across the screen



  TFTscreen.setTextSize(1);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text("Extruder Controller V 0.1", 5,1);
  TFTscreen.text("Motor", 10, 25);
  TFTscreen.text("Barrel", 63, 25);
  TFTscreen.text("Nozzle", 116, 25);
  TFTscreen.text("SET TEMP:", 5, 79);
  TFTscreen.text("Screw RPM", 88, 79);
  TFTscreen.stroke(200, 200, 200);
 //   TFTscreen.setTextSize(2);
    TFTscreen.text("o", 52, 98);
      TFTscreen.setTextSize(2);
      TFTscreen.text("C", 60, 100);
  }

//******************************************************************************//

 int setTemperature() {

  int newSetTemp1 = myEnc.read();

  if (newSetTemp1 != setTemp1) {
    setTemp1 = newSetTemp1;
     
      String stringOne =  String(setTemp1);
      stringOne.toCharArray(sensorPrintout1, 4);
  
      int setTemp2 = setTemp1 * 90 / 100;  // Temp2 is 90% of Temp1
      
      String stringTwo =  String(setTemp2);
      stringTwo.toCharArray(sensorPrintout2, 4);

    TFTscreen.fill(0, 0, 0);
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.rect(5, 100, 45, 20); //clear the space with black

    TFTscreen.stroke(200, 200, 200);
    TFTscreen.textSize(2);
    TFTscreen.text(sensorPrintout1, 10, 100);    // Print the setted Nozzle temperature

 //   Serial.print("set Temps1 ");
 //   Serial.println(setTemp1);
 
  }
 
  }

//*******************************************************************************//

float tempReading(int Thermistor) {

    Vo = analogRead(Thermistor);
    R2 = R1 * (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
    T = T - 273.15;
    //  T = (T * 9.0)/ 5.0 + 32.0;
    // Serial.println(T);

}
//*******************************************************************************//


void updateTempNozzle() {
  
      String stringT =  String(T);
      stringT.toCharArray(sensorPrintoutT1, 4);


      TFTscreen.fill(0, 0, 0);
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.rect(116, 35, 40, 26); //clear the space with black
      TFTscreen.stroke(0, 0, 255);
      TFTscreen.textSize(2);
      TFTscreen.text(sensorPrintoutT1, 116, 40); // Print the actual Nozzle temperature

  }

  //*****************************************************************************//

  void updateTempMain() {
      String stringT =  String(T);
      stringT.toCharArray(sensorPrintoutT2, 4);
      
      TFTscreen.fill(0, 0, 0);
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.rect(63, 35, 40, 26); //clear the space with black


      TFTscreen.stroke(0, 0, 255);
      TFTscreen.textSize(2);
      // Print the actual Nozzle temperature
      TFTscreen.text(sensorPrintoutT2, 63, 40);
    }

  //*****************************************************************************//

  void updateTempEntry() {
      String stringT =  String(T);
      stringT.toCharArray(sensorPrintoutT3, 4);
      
      TFTscreen.fill(0, 0, 0);
      TFTscreen.stroke(0, 0, 0);
      TFTscreen.rect(10, 35, 40, 26); //clear the space with black


      TFTscreen.stroke(0, 0, 255);
      TFTscreen.textSize(2);
      // Print the actual Nozzle temperature
      TFTscreen.text(sensorPrintoutT3, 10, 40);
    }
