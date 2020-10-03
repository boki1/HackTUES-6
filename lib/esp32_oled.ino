#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "time.h"

#include "esp32_oled_inn.ino"

const static unsigned SCREEN_WIDTH = 128; 
const static unsigned SCREEN_HEIGHT = 64;

const static unsigned C_BEGIN = 1;
const static unsigned C_END = 5;

#define OLED_RESET     (-1)
#define ENDLESS_LOOP   for (; ; ;);

#define LOG_WRITE(msg) \
    Serial.println(F(msg)); 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 

enum ButtonNames { BT_MINUS, BT_SELECT, BT_PLUS };

struct Button {
	int id;
	int state;
	int prev_state;
	int val;
} buttons[3];

unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;

TaskHandle_t OLED;
TaskHandle_t Network;
TaskHandle_t Task1;

const char* ssid       = "UltraCloudSolution";
const char* password   = "kremi123";

const char *ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void buttons_init() {
  // buttons is global
  buttons[0].id = BT_MINUS; buttons[1].id = BT_SELECT; buttons[2].id = BT_PLUS;
  for (int i = 0; i < N_BUTTONS; ++i) {
	pinMode(buttons[i], INPUT);
	buttons[i].prev_state = LOW;
  }
}

void display_init() 
{ 
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
	  LOG_WRITE("SSD1306 allocation failed");
	  ENDLESS_LOOP
  	}
}

void setup() {
  Serial.begin(115200);

  buttons_init();

  display_init();

  display.display();
  display.clearDisplay();
}


void loop() {
	
  int cursor = C_BEGIN;
  // int lastDebounceTime;

  for (int i = 0; i < N_BUTTONS; ++i) {
	buttons[i].val = digitalRead(buttons[i].id);		
	if (buttons[i].val == buttons[i].state)
  	  lastDebounceTime = millis();

	if ((millis() - lastDebounceTime > debounceDelay)) {
		if (buttons[i].val != buttons[i].state) {
			buttons[i].state = buttons[i].val;
			if (buttons[i].state == HIGH) switch (buttons[i].id) {
					case BT_MINUS:
						cursor = (cursor == C_BEGIN) ? C_END : cursor - 1; 
						break;
					case BT_SELECT:
						LOG_WRITE("Select");
						break;
					case BT_PLUS:
						cursor = (cursor == C_END) ? C_BEGIN : cursor + 1;
						break;
				}
		}
	}

	buttons[i].state = buttons[i].val;
  }

  drawNumbers(cursor);
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


void drawNumbers(int number){
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.drawRect(8, 8, display.width()-2*8, display.height()-2*8, WHITE);
   display.setCursor(50,22);
   display.setTextSize(3);
   display.println(number);
   display.display();
}
