#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "time.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1

const int Button1 = 4;
const int Button2 = 2;
const int Button3 = 15;

int button1State;
int button2State;
int button3State;
int lastButton1State = LOW;
int lastButton2State = LOW;
int lastButton3State = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  //Wire.begin(13, 14);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  Serial.println("qwe");
  //display.display();
  //display.clearDisplay();
}

unsigned reg = 1,
         reg_max = 3;

void loop() {
  int buttonMinus = digitalRead(Button1);
  int buttonSelect = digitalRead(Button2);
  int buttonPlus = digitalRead(Button3);

  if (buttonMinus != lastButton1State) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if (buttonSelect != lastButton2State) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if (buttonPlus != lastButton3State) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonMinus != button1State) {
      button1State = buttonMinus;
      if (button1State == HIGH) {
        reg -= 1;

        reg = (reg - 1) % reg_max + 1;
      }
    }

    if (buttonSelect != button2State) {
      button2State = buttonSelect;
      if (button2State == HIGH) {
        Serial.println("Select");
      }
    }

    if (buttonPlus != button3State) {
      button3State = buttonPlus;
      if (button3State == HIGH) {
        reg = (reg % reg_max) + 1;
      }
    }

  }
  lastButton1State = buttonMinus;
  lastButton2State = buttonSelect;
  lastButton3State = buttonPlus;
  drawNumbers(reg);
}

void drawText(char str[] ) {

  display.clearDisplay();
  display.drawRect(8, 8, display.width() - 2 * 8, display.height() - 2 * 8, WHITE);

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25, 22);
  display.println(F(str));
  display.display();
}

void drawDots() {
  display.setCursor(40, 30);
  display.println(F("."));
  delay(1000);
  display.display();
  display.setCursor(60, 30);
  display.println(F("."));
  delay(1000);
  display.display();
  display.setCursor(80, 30);
  display.println(F("."));
  delay(1000);
  display.display();
}

void loading(int t) {
  int i;
  for (i = 0; i <= t; i++) {
    drawText("Loading");
    drawDots();
    display.clearDisplay();
  }
  display.clearDisplay();
}


void drawNumbers(int number) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.drawRect(8, 8, display.width() - 2 * 8, display.height() - 2 * 8, WHITE);
  display.setCursor(50, 22);
  display.setTextSize(3);
  display.println(number);
  display.display();
}
