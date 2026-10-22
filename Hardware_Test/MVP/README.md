# MVP: DHT11 + Soil Moisture Sensor + OLED

This code reads the DHT11 (temperature & humidity) and the Capacitive Analog Soil Moisture Sensor (3.3-5.5V), then shows the readings on the 0.96" OLED screen and prints them in the serial monitor. Set the serial monitor baud to 115200.

## Libraries

Install these from the Library Manager in the Arduino IDE:

- `DHT sensor library` by Adafruit
- `Adafruit SSD1306` by Adafruit
- `Adafruit GFX Library` by Adafruit

## Wiring

Circuit Diagram [here](https://app.cirkitdesigner.com/project/14553905-3c2d-4010-ac0b-152319eb3408): 

<img width="1866" height="1092" alt="image" src="https://github.com/user-attachments/assets/b219b853-5a82-435b-962a-85c6ba717946" />


The DHT11 and OLED use the same pins as the `OLED+DHT/screen.ino` test.

| Part | Sensor pin | ESP32 pin |
| --- | --- | --- |
| DHT11 | DATA | GPIO 4 |
| DHT11 | VCC | 3V3 |
| DHT11 | GND | GND |
| OLED | SDA | GPIO 21 |
| OLED | SCL | GPIO 22 |
| OLED | VCC | 3V3 |
| OLED | GND | GND |
| Soil sensor | AOUT | GPIO 34 |
| Soil sensor | VCC | 3V3 |
| Soil sensor | GND | GND |

All three parts need 3V3 and GND, but the ESP32 only has one 3V3 pin. Run a jumper from 3V3 to the breadboard's **+** rail and from GND to the **-** rail, then connect each part's VCC and GND to those rails. Any GND pin on the ESP32 works.

## Calibrating the soil sensor

Every soil sensor reads a little differently, so set the dry and wet values once:

1. Upload the code and open the serial monitor. Each line ends with something like `Soil: 40 % (raw 2350)`.
2. Hold the probe in the **air** (dry) and write down the `raw` number.
3. Put the probe in a cup of **water** up to the line on the board (don't submerge the electronics at the top) and write down the `raw` number.
4. In `all_sensors.ino`, set `SOIL_DRY_RAW` to the air number and `SOIL_WET_RAW` to the water number, then upload again.

Now dry soil should read close to 0% and soaked soil close to 100%.

## What you should see

Serial monitor (every 3 seconds):

```
Humidity: 45 %  |  Temp: 22.5 C / 72.5 F  |  Heat index: 72.1 F  |  Soil: 63 % (raw 2230)
```

OLED screen:

```
Feels like: 72.1 F
72.5 F
45 % RH
Soil 63%
```

## Troubleshooting

- **Screen stays blank:** check SDA/SCL aren't swapped. If the wiring is right, change `OLED_ADDRESS` from `0x3C` to `0x3D`.
- **"DHT11 read failed!":** check the DHT11 data wire is on GPIO 4. The soil reading still updates when this happens.
- **Soil reading barely changes between air and water:** some cheap boards use a chip that doesn't work well at 3.3V. Move the soil sensor's VCC to the ESP32's **VIN/5V** pin and recalibrate. This is usually safe because the sensor's output stays below about 3V, but check it with a multimeter first if you can.
- **Soil reading stuck at 0 or 4095:** the AOUT wire is loose or on the wrong pin.
