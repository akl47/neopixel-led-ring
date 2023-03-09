// NeoPixel test program showing use of the WHITE channel for RGBW
// pixels only (won't look correct on regular RGB NeoPixel strips).

#include <Adafruit_NeoPixel.h>


#define LED_PIN     10
#define LED_COUNT  64
#define BRIGHTNESS 10 // Set BRIGHTNESS to about 1/5 (max = 255)
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
int arrivingdatabyte;  

void setup() {
  Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  if (Serial.available() > 0) {     //wait for data available
    String raw_str = Serial.readString();  //read until timeout
    parse_string(raw_str);
  }
}

void parse_string(String raw_str) {
  for(int i=0;i<raw_str.length();i++) {
    Serial.println(raw_str[i]);
  }
}

void split_string() {

  String strs[20];
  int StringCount = 0;  
}

void setPixels(int i,int r, int g, int b, int w){
  strip.setPixelColor(i, strip.Color(r,g,b,w));
  // strip.show();
}