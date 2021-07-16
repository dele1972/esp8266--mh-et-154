void updateDisplay() {
  Serial.println("Updating Display");
  ePaper.init(115200); // enable diagnostic output on Serial
  Serial.println("Init Display");
  ePaper.drawPaged(epaperUpdate);
}

void epaperUpdate() {
  ePaper.eraseDisplay();
  ePaper.drawBitmap(gImage_youTubeImage, 170, 0, 300, 300, GxEPD_BLACK);
  ePaper.setTextColor(GxEPD_BLACK);

  const GFXfont* f = &FreeMonoBold24pt7b;
  ePaper.setFont(f);
  ePaper.setCursor(100, 324);
  ePaper.println("Hello YouTube");
//  f = &FreeMonoBold18pt7b;
//  ePaper.setFont(f);
//  ePaper.println("Hello World");
}

