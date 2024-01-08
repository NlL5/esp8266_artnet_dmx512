#include <Arduino.h>
#include <NeoPixelBus.h>

#define colorSaturation 128


#ifdef WS2812X
const uint16_t PixelCount = 55; // this example assumes 4 pixels, making it smaller will cause a failure

//NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBangWs2812xMethod> stripBit(PixelCount, 4);
NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PixelCount);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);
#endif

#ifdef FW1906
const uint16_t PixelCount = 12;

NeoPixelBus<NeoGrbcwxFeature, Neo800KbpsMethod> strip(PixelCount);

RgbwwColor red(colorSaturation, 0, 0);
RgbwwColor green(0, colorSaturation, 0);
RgbwwColor blue(0, 0, colorSaturation);
RgbwwColor white(colorSaturation);
RgbwwColor black(0);
#endif

void setup()
{
    /*Serial.begin(115200);
    while (!Serial); // wait for serial attach

    Serial.println();
    Serial.println("Initializing...");
    Serial.flush();*/
    pinMode(LED_BUILTIN, OUTPUT);

    
    strip.Begin();

    //strip.ClearTo(black);   // this resets all the DotStars to an off state
    //strip.Show();

    
    /*stripBit.Begin();

    stripBit.ClearTo(black);   // this resets all the DotStars to an off state
    stripBit.Show();*/
    
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);   // Arduino: turn the LED on (HIGH)
                                        // D1 Mini: turns the LED *off*
    delay(500);                       // wait for a second
    
    strip.SetPixelColor(0, green);
    //strip.SetPixelColor(1, green);
    //strip.SetPixelColor(2, green);
    strip.SetPixelColor(3, white);
    strip.Show();

    /*stripBit.SetPixelColor(0, white);
    //stripBit.SetPixelColor(1, green);
    stripBit.SetPixelColor(2, green);
    //stripBit.SetPixelColor(3, white);
    stripBit.Show();*/

    digitalWrite(LED_BUILTIN, LOW);    // Arduino: turn the LED off (LOW)
                                        // D1 Mini: turns the LED *on*
    delay(500);                       // wait for a second

    strip.SetPixelColor(0, red);
    //strip.SetPixelColor(1, green);
    //strip.SetPixelColor(2, blue);
    strip.SetPixelColor(3, blue);
    strip.Show();

    /*stripBit.SetPixelColor(0, blue);
    //stripBit.SetPixelColor(1, green);
    stripBit.SetPixelColor(2, blue);
    //stripBit.SetPixelColor(3, blue);
    stripBit.Show();*/
}
