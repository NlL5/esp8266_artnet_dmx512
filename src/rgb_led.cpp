#include "rgb_led.h"

#ifdef ENABLE_LED_STRIP
#include <NeoPixelBus.h>
extern NeoPixelBus<NEO_FEATURE, NEO_METHOD> strip;
#endif

void ledInit() {
#ifndef ENABLE_LED_STRIP
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
#endif
}

#ifdef COMMON_ANODE
  #define LED_ON  LOW
  #define LED_OFF HIGH
#else 
  #define LED_ON  HIGH
  #define LED_OFF LOW
#endif

void ledRed() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(128, 0, 0);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_ON);
  digitalWrite(LED_G, LED_OFF);
  digitalWrite(LED_B, LED_OFF);
#endif
}

void ledGreen() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(0, 128, 0);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_OFF);
  digitalWrite(LED_G, LED_ON);
  digitalWrite(LED_B, LED_OFF);
#endif
}

void ledBlue() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(0, 0, 128);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_OFF);
  digitalWrite(LED_G, LED_OFF);
  digitalWrite(LED_B, LED_ON);
#endif
}

void ledYellow() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(100, 100, 0);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_ON);
  digitalWrite(LED_G, LED_ON);
  digitalWrite(LED_B, LED_OFF);
#endif
}

void ledMagenta() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(110, 0, 100);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_ON);
  digitalWrite(LED_G, LED_OFF);
  digitalWrite(LED_B, LED_ON);
#endif
}

void ledCyan() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(0, 105, 100);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_OFF);
  digitalWrite(LED_G, LED_ON);
  digitalWrite(LED_B, LED_ON);
#endif
}

void ledBlack() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(0, 0, 0);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_OFF);
  digitalWrite(LED_G, LED_OFF);
  digitalWrite(LED_B, LED_OFF);
#endif
}

void ledWhite() {
#ifdef ENABLE_LED_STRIP
  RgbColor color(100, 100, 90);
  strip.SetPixelColor(0, color);
  strip.Show();
#else
  digitalWrite(LED_R, LED_ON);
  digitalWrite(LED_G, LED_ON);
  digitalWrite(LED_B, LED_ON);
#endif
}
