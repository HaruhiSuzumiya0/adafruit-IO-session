#include "config.h"
#include <Adafruit_NeoPixel.h>

/************************ Example Starts Here *******************************/

#define LED_PIN 21

#define LED_COUNT  12
#define BRIGHTNESS 20

// Declare neopixel Ring
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// set up the 'digital' feed
AdafruitIO_Feed *exercice = io.feed("exercice");

void setup() {

  ring.begin();
  ring.setBrightness(BRIGHTNESS);

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while (!Serial)
    ;

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'digital' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  exercice->onMessage(handleMessage);

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  exercice->get();
}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();
}

// this function is called whenever an 'digital' feed message
// is received from Adafruit IO. it was attached to
// the 'digital' feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
    ring.fill(data->toNeoPixel());
    ring.show();
    
}
