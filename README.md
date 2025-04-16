# UART to 7-Segment Display on Arduino

This project demonstrates how to interface a 7-segment display with an Arduino Uno and use UART (Serial Monitor) to input numeric data and control the display dynamically.

## 🔧 Project Overview

The goal is to display user-input numbers (via Serial Monitor) on a single 7-segment display. The project includes special behaviors for certain inputs, such as remapping or countdown effects.

## 🧰 Components Required

- Arduino Uno
- Breadboard
- 7-Segment Display (Common Cathode or Anode)
- 220Ω Resistors (x8)
- Jumper Wires
- USB Cable for Arduino

## ⚙️ Features

- ✅ **Standard Display:** Enter a positive integer, each digit will be shown one-by-one with 1-second delay.
- 🔁 **Remapping:** When the digit `4` is entered, it is displayed as `8`.
- ⏬ **Countdown Mode:** If the digit `3` is entered, the display will count down from 3 to 0 before showing the next digit.
- ❌ **Clear Display:** Sending the character `c` clears (turns off) the display.
- 🔁 **Continuous Execution:** The program runs indefinitely; no need to re-upload or reset.

## 🖥️ How to Use

1. Upload the code to your Arduino via Arduino IDE.
2. Open the Serial Monitor (9600 baud rate).
3. Type any integer or the character `c` and observe the behavior on the 7-segment display.

## 💡 Example Scenarios

- Input: `835` → Displays `8`, then `3`, `2`, `1`, `0`, then `5`
- Input: `14` → Displays `1`, then `8` (since 4 is replaced with 8)
- Input: `c` → Clears the display

## 📷 Circuit Diagram

*You can add an image here of your breadboard setup or a schematic.*

## 🧠 Notes

- Ensure your 7-segment display is wired correctly and the appropriate pins are used in your Arduino code.
- Resistors are important to prevent burning out the LEDs.

## 👨‍💻 Author

CMPE 453 – Section 4  
Lab 3 Submission

