#include <FastLED.h>
#define NUM_LEDS 50
#define DATA_PIN 3
CRGB leds[NUM_LEDS];
float val;
float start;
float rosso, verde, blu;

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

void setup() {
  FastLED.addLeds<GS1903, DATA_PIN, BRG>(leds, NUM_LEDS);
  Serial.begin(9600);
  start = analogRead(A0);
}

void loop() {
  val = analogRead(A0);

  if (val > start + 30) {
    rosso = mapfloat(val, start, 200, 0, 255);
    verde = mapfloat(val, start, 290, 0, 255);
    blu = mapfloat(val, start, 100, 0, 255);
    Serial.println( rosso);

    for (int i = 0; i < NUM_LEDS; i ++) {
      leds[i].red   = rosso;
      leds[i].green   = verde;
      leds[i].blue   = blu;
      FastLED.show();
      delay(30);
      // leds[i]= CRGB::Black;
    }
  } else {
        for (int i = NUM_LEDS ; i > 0; i --) {
          
leds[i]= CRGB::Black;
      FastLED.show();
      delay(30);

        }
    }

}


  /*else {

        for (int j = 49; j < NUM_LEDS; j--){

    leds[j]= CRGB::Black;
    FastLED.show();
    delay(10);

    }


    }*/
/*
  for (int i = 0; i < NUM_LEDS; i ++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(100);
    leds[i]= CRGB::Black;
    if (val <30) {
      leds[i] = CRGB::Red;
      }
    else {
      leds[i]= CRGB::Green;
      }
       FastLED.show();

      FastLED.clear();
    }
  leds[NUM_LEDS-1]= CRGB::Black;
  FastLED.show();


*/






/*
  }
    int numLedsToLight = map(val, start, 150, 0, NUM_LEDS);

    // First, clear the existing led values
    FastLED.clear();
    for(int led = 0; led < numLedsToLight; led++) {
        leds[led] = CRGB::Blue;
        Serial.println("fine for");
    }
    FastLED.show();
*/
