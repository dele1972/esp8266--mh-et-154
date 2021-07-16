// my minimum example for MH-ET Live 1.54" ePaper
// based on GxEPD_MinimumExample by Jean-Marc Zingg

// https://github.com/dele1972/esp8266--mh-et-154

#include <GxEPD.h>

#include <GxGDEW0154Z04/GxGDEW0154Z04.h>  // 1.54" b/w/r 200x200

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

// constructor for AVR Arduino, copy from GxEPD_Example else
GxIO_Class io(SPI, /*CS=*/ SS, /*DC=*/ 0, /*RST=*/ 2); // arbitrary selection of 8, 9 selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=*/ 2, /*BUSY=*/ 4); // default selection of (9), 7


void setup()
{
  
  Serial.begin(115200);

  // try to get the first serial.print lines printed 
  // yield();
  // delay(0.3 * 60000);                 // wait a third of a minute
  
  // the following two lines will never print on serial monitor
  Serial.println("Start of Script");
  Serial.printf("Heap before DISPLAY INIT: %d\n", ESP.getFreeHeap());
  display.init(115200); // init with 115200 will print out some debug informations
  Serial.printf("Heap after DISPLAY INIT: %d\n\n\n", ESP.getFreeHeap());

  //display.eraseDisplay();
  
  Serial.printf("Heap before drawPaged(): %d\n", ESP.getFreeHeap());
  display.drawPaged(drawHelloWorld); // version for AVR using paged drawing, works also on other processors
  Serial.printf("Heap after drawPaged(): %d\n\n\n", ESP.getFreeHeap());

  Serial.println("End of Script");
}

void drawHelloWorld()
{
  
  /*
  Some GFX methods
  
  // the only colors supported by any of these displays; mapping of other colors is class specific
  #define GxEPD_BLACK     0x0000
  #define GxEPD_DARKGREY  0x7BEF       128, 128, 128 
  #define GxEPD_LIGHTGREY 0xC618       192, 192, 192 
  #define GxEPD_WHITE     0xFFFF
  #define GxEPD_RED       0xF800       255,   0,   0 
  
  
  void drawFastVLine(uint16_t x0, uint16_t y0, uint16_t length, uint16_t color);
  void drawFastHLine(uint8_t x0, uint8_t y0, uint8_t length, uint16_t color);
  void drawRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
  void fillRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
  */
  
//  display.fillScreen(GxEPD_WHITE);

  // TextSize 0 = TextSize 1 = chars of 5x8 pixel
  drawExample(/*uint16_t baseY*/ 0, /*uint16_t textSize*/ 0, /*bool bold*/ false, /*uint16_t color*/ GxEPD_BLACK, /*string text*/ "Text Size 0 -B");

  // TextSize 1 = chars of 5x8 pixel
  drawExample(/*uint16_t baseY*/ 30, /*uint16_t textSize*/ 1, /*bool bold*/ true, /*uint16_t color*/ GxEPD_BLACK, /*string text*/ "Text Size 1 -B");

  // TextSize 2 = chars of 10x16 pixel
  drawExample(/*uint16_t baseY*/ 60, /*uint16_t textSize*/ 2, /*bool bold*/ false, /*uint16_t color*/ GxEPD_BLACK, /*string text*/ "Text Size 2 -B");
  
  // DARKGREY this becomes black on my display...
  drawExample(/*uint16_t baseY*/ 95, /*uint16_t textSize*/ 2, /*bool bold*/ true, /*uint16_t color*/ GxEPD_DARKGREY, /*string text*/ "Text Size 2 -DG");
  
  // LIGHTGREY this becomes light red on my display...
  drawExample(/*uint16_t baseY*/ 130, /*uint16_t textSize*/ 2, /*bool bold*/ true, /*uint16_t color*/ GxEPD_LIGHTGREY, /*string text*/ "Text Size 2 -LG");

  drawExample(/*uint16_t baseY*/ 165, /*uint16_t textSize*/ 2, /*bool bold*/ true, /*uint16_t color*/ GxEPD_RED, /*string text*/ "Text Size 2 -R");
}

void drawExample(uint16_t baseY, uint16_t textSize, bool bold, uint16_t color, const char* text) {
  
  display.drawLine(/*uint16_t x0*/ 0, /*uint16_t y0*/ baseY, /*uint16_t x1*/ 200, /*uint16_t y1*/ baseY, /*uint16_t color*/ color);
  display.setTextColor(color, GxEPD_WHITE);   // LIGHTGREY this becomes light red on my display...
  display.setTextSize(textSize); // 10x16 chars
  display.setCursor(5, baseY + 5);
  display.print(text);
  if (bold) {
  // shifted text print to get a bold effect
  display.setTextColor(color);
  display.setCursor(6, baseY + 6);
  display.print(text);
  }

}


void loop() {};
