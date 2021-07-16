//trigBoard Sample Code for use with Waveshare ePaper Displays
// 8/16/17  Kevin Darrah
// RELEASED

#include <GxEPD.h>
#include <GxGDEW075T8/GxGDEW075T8.cpp>      // 7.5" b/w  640x384            

//#include GxEPD_BitmapExamples
#include "images.h"

//FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>

GxIO_Class io(SPI, /*CS=D16*/ 16, /*DC=D4*/ 4, /*RST=D5*/ 5); 
GxEPD_Class ePaper(io, 5, 12 /*RST=D5*/ /*BUSY=D12*/);


//FUNCTIONS
void updateDisplay();
void epaperUpdate();

void setup() {
  Serial.begin(115200);//debug
  updateDisplay();
}



void loop() {

}






