#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  display.clearDisplay();

  loading(3);
}

void loop() {
}

void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(4);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  delay(2000);
}

void drawText(char str[] ) {

  display.clearDisplay();
  display.drawRect(8, 8, display.width()-2*8, display.height()-2*8, WHITE);

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25,22);
  display.println(F(str));
  display.display();
  }

void drawDots(){
  int i;
  display.setCursor(40,30);
  display.println(F("."));
  delay(1000);
  display.display();
  display.setCursor(60,30);
  display.println(F("."));
  delay(1000);
  display.display();
  display.setCursor(80,30);
  display.println(F("."));
  delay(1000);
  display.display();
}

void loading(int t){
  int i;
  for(i=0; i<=t; i++){
    drawText("Loading");
    drawDots();
    display.clearDisplay();
  }
  display.clearDisplay();
}
