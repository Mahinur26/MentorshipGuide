# HydroSense - Mentorship Guide

## Prerequisites

Do these in order. Each step takes a few minutes, and later steps assume the
earlier ones are done. Feel free to skip the steps you already have done.

### 1. Create a GitHub account

**→ [Sign up for GitHub](https://github.com/signup)**

GitHub is where you'll store your code remotely.

### 2. Install Git

Git is the tool that tracks changes to your code. GitHub is the website; Git is
the program on your computer that talks to it. You need both.

- **→ [Mac install guide](docs/mac-git-setup.md)**
- **→ [Windows install guide](docs/windows-git-setup.md)**

### 3. Learn how to use Git/Github 

Don't worry you don't have to learn all of git at once, but here is a great resource to gradually learn how to use it. 

- **→ [Github video Playlist](https://www.youtube.com/watch?v=r8jQ9hVA2qs&list=PL0lo9MOBetEFcp4SCWinBdpml9B2U25-f)**

### 4. Install the CP210x USB-to-UART drivers

**→ [Download from Silicon Labs](https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)**

Your ESP32 talks to your computer over USB through a chip made by Silicon Labs.
Without this driver, if you plug the board into your computer it won't show up on Arduino IDE.

### 5. Install Arduino IDE

**→ [Download the Arduino IDE](https://www.arduino.cc/en/software/)**

This is where you'll write code for the ESP32 and upload it to the board. Get
the latest version on the website.

### 6. Install a code editor

**→ [Download VS Code](https://code.visualstudio.com/download)**

The Arduino IDE is only used for firmware code on the ESP32, but any other features that use other languages/frameworks should be worked on in VS Code or IDE of choice.

---

## Hardware Tests

Once your setup is done, use these guides to test each component on its own. I'll be adding on to this list as the mentorship program progresses

- **→ [Temperature/Humidity Sensor (DHT11)](Hardware_Test/Temperature_Sensor/README.md)**
