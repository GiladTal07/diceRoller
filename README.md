Dice Roller

Built to be used with an ESP32 microcontroller and a GC9A01 display that has SPI functionality. **Designed to run on 3.3V.** 

Software-wise, it runs on an FSM (Finite State Machine) that detects when a button is released to change between states.

Functionality to roll up to 5 of any combination of D4, D6, D8, D10, D12, or D20 dice and calculate the sum of the dice rolled.

<img width="744" height="603" alt="Screenshot 2025-07-25 at 14 25 11" src="https://github.com/user-attachments/assets/806d127d-be9d-4f38-bc6e-2d3e5409163c" />

<hr>

**Materials List (for if you want to make your own**
- 1 ESP32 microcontroller
- 3 GC9A01A LCD Display (or any other display that supports SPI)
- WIRES (too many of them)
- 1 L7805 Voltage Regulator (optional, for if using a 9V battery or a non-3.3V power source)
