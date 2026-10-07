/*
  DHT11 Temperature & Humidity Test
  Reads temperature and humidity every 3 seconds and prints them
  to the Serial Monitor.

  Libraries (Arduino IDE -> Library Manager):
    - "DHT sensor library" by Adafruit

  Serial Monitor: 115200 baud
*/

#include <DHT.h>  

// Defining constants
#define DHT_PIN   4        // GPIO (D4) the sensor's data pin is connected to
#define DHT_TYPE  DHT11    // Sensor model 

// How often to take a reading, in milliseconds.
// 3000 ms = 3 seconds
const unsigned long READ_INTERVAL_MS = 3000;

// Create the sensor object, telling ESP32 which pin and model to use
DHT dht(DHT_PIN, DHT_TYPE);

// Timestamp of the last reading, used by the timer in loop() to determine how much time has passed
unsigned long lastRead = 0;

void setup() {
  Serial.begin(115200);    // Select 115200 baud in serial monitor to see output
  delay(1000);             // Give the serial connection and sensor time to settle
  dht.begin();             // Initialize the sensor
  Serial.println("DHT11 test starting...");
}

// In Arduino code, the loop() function runs over and over again forever, until the board is turned off or reset.
void loop() {
  /*---------- Non-blocking timer ----------
   millis() returns time passed since boot. If 3s haven't passed since the
   last reading, exit loop() early and check again on the next pass.
   Unlike delay(), this doesn't freeze the board, so you can add
   other tasks (like the soil sensor) later.
  */
  unsigned long now = millis();
  if (now - lastRead < READ_INTERVAL_MS) {
    return;
  }
  lastRead = now;

  // ---------- Read the sensor ----------
  float humidity = dht.readHumidity();          // Relative humidity in %
  float tempC    = dht.readTemperature();       // Temperature in Celsius
  float tempF    = dht.readTemperature(true);   // True arg makes it return Fahrenheit 

  // ---------- Error check ----------
  // If a read fails (bad wiring, wrong pin, timing glitch), the library
  // returns NaN ("not a number"). So we print out an error message to hint to what may be wrong
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT11 - check wiring and pin.");
    return; // Start the loop() again
  }

  // Heat index = "feels like" temperature (think of weather app), combining temp and humidity
  float heatIndexF = dht.computeHeatIndex(tempF, humidity);

  // ---------- Print results ----------
  // The second argument to print() sets the number of decimal places.
  // Humidity uses 0 because the DHT11 only reports whole percentages.
  // All of this can be viewed in your serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity, 0);
  Serial.print(" %  |  Temp: ");
  Serial.print(tempC, 1);
  Serial.print(" C / ");
  Serial.print(tempF, 1);
  Serial.print(" F  |  Heat index: ");
  Serial.print(heatIndexF, 1);
  Serial.println(" F"); 
}