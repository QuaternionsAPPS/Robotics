#include "LedControlMS.h"

int sensorPinX = A0;
int sensorPinY = A1;
int sensorValueX = 0;
int sensorValueY = 0;
int row1=3;
String statuss;
LedControl matrix = LedControl(12, 11, 10, 1); //din, clk, cs, number
 
byte location = B00010000;

void read_data() {

  sensorValueX = analogRead (sensorPinX);
  sensorValueY = analogRead (sensorPinY); 
}

void check_data(){
  
  if (sensorValueX<10)
    {
      statuss = "left";
    }
  if (sensorValueX>600)
    {
       
       statuss = "right";
    }  
  if (sensorValueY<10)
    {
       statuss = "down";
    }  
   if (sensorValueY>600)
    {
       statuss = "up";
    }  
}

void movement (){
  if (statuss == "left")
    {
       if (location==B10000000){
              location=B00000001;
       } 
      else{ location=location<<1;}
    }
  if (statuss == "right")
    {
       if (location==B00000001){
          location=B10000000;
       }
       else {location=location>>1;}
    }  
  if (  statuss == "up")
    {
       row1++;
       if (row1==8)
        {
          row1=0; 
        }
    }  
   if (statuss == "down")
    {
       row1--; 
       if (row1==-1)
        {
          row1=7; 
        }
    }  
}
void setup() {
  // put your setup code here, to run once:
matrix.shutdown(0, false);
matrix.setIntensity(0, 15);
matrix.clearDisplay(0);
Serial.begin(9600);
}

void loop() {
  matrix.clearAll();
  read_data();
  check_data();
  movement();
  matrix.setRow(0, row1, location);
  statuss = "";
  delay(100); 
  Serial.println(statuss);
  //buttom_status;
  
}
