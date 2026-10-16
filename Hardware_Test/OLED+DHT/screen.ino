/*
  DHT11 Temperature & Humidity + OLED Display
  Reads temperature and humidity every 3 seconds, prints them to the
  Serial Monitor, and shows them on a 0.96" SSD1306 OLED (I2C).

  Libraries (Arduino IDE -> Library Manager):
    - "DHT sensor library" by Adafruit
    - "Adafruit SSD1306" by Adafruit
    - "Adafruit GFX Library" by Adafruit

  Wiring:
    DHT11 data -> GPIO 4
    OLED SDA   -> GPIO 21
    OLED SCL   -> GPIO 22
    OLED VCC   -> 3V3
    OLED GND   -> GND

  Serial Monitor: 115200 baud
*/

#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- DHT settings ----------
#define DHT_PIN   4        // GPIO (D4) the sensor's data pin is connected to
#define DHT_TYPE  DHT11    // Sensor model

// ---------- OLED settings ----------
#define SCREEN_WIDTH   128   // OLED width in pixels
#define SCREEN_HEIGHT  64    // OLED height in pixels (some 0.91" modules are 32)
#define OLED_RESET     -1    // No reset pin on these modules, so share the ESP32 reset
#define OLED_ADDRESS   0x3C  // Most common I2C address (try 0x3D if the screen stays blank)

// How often to take a reading, in milliseconds.
const unsigned long READ_INTERVAL_MS = 3000;

// Create the sensor and display objects
DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Timestamp of the last reading
unsigned long lastRead = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  dht.begin();

  // Start I2C on the ESP32's default pins (SDA = 21, SCL = 22)
  Wire.begin(21, 22);

  // Start the OLED. If it isn't found, print an error and stop.
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED not found - check wiring and I2C address.");
    while (true) { delay(100); }
  }

  // Splash message while waiting for the first reading
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("DHT11 starting...");
  display.display();   // Nothing appears on screen until display() is called

  Serial.println("DHT11 + OLED test starting...");
}

void loop() {
  // ---------- Non-blocking timer ----------
  unsigned long now = millis();
  if (now - lastRead < READ_INTERVAL_MS) {
    return;
  }
  lastRead = now;

  // ---------- Read the sensor ----------
  float humidity = dht.readHumidity();
  float tempC    = dht.readTemperature();
  float tempF    = dht.readTemperature(true);

  // ---------- Error check ----------
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT11 - check wiring and pin.");

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("DHT11 read failed!");
    display.println("Check wiring/pin.");
    display.display();
    return;
  }

  float heatIndexF = dht.computeHeatIndex(tempF, humidity);

  // ---------- Print to Serial Monitor ----------
  Serial.print("Humidity: ");
  Serial.print(humidity, 0);
  Serial.print(" %  |  Temp: ");
  Serial.print(tempC, 1);
  Serial.print(" C / ");
  Serial.print(tempF, 1);
  Serial.print(" F  |  Heat index: ");
  Serial.print(heatIndexF, 1);
  Serial.println(" F");

  // ---------- Show on OLED ----------
  display.clearDisplay();          // Wipe the previous frame

  // Title
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("DHT11 Readings");

  // Temperature (big text)
  display.setTextSize(2);
  display.setCursor(0, 14);
  display.print(tempF, 1);
  display.print(" F");

  // Humidity (big text)
  display.setCursor(0, 34);
  display.print(humidity, 0);
  display.print(" % RH");

  // Heat index (small text)
  display.setTextSize(1);
  display.setCursor(0, 56);
  display.print("Feels like: ");
  display.print(heatIndexF, 1);
  display.print(" F");

  display.display();               // Push everything to the screen
}