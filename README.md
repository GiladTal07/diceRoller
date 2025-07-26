# 🎲 Dice Roller

A graphical dice roller built for the **ESP32** microcontroller and a **GC9A01 SPI-based circular LCD display**. Ideal for tabletop gamers, D&D players, or hobbyists looking to integrate hardware and game logic.

---

## ⚙️ Hardware Requirements

- **Microcontroller**: ESP32 (3.3V logic)
- **Display**: GC9A01 240×240 round TFT LCD (SPI interface)
- **Input**: 4 momentary pushbuttons
- **Power**: 3.3V regulated supply (compatible with ESP32 and display)

---

## 🧠 Software Overview

The system is driven by a **Finite State Machine (FSM)** that:
- Monitors for **button release events**
- Switches between display states (e.g., dice selection, roll result)
- Handles debounce logic internally

---

## 🎲 Features

- **Supports up to 5 dice** rolled at once
- Choose **any combination** of the following die types:
  - D4, D6, D8, D10, D12, D20
- Displays individual results **and** their **total sum**
- User-friendly, minimal interface optimized for a small circular screen
- Designed for **low-power operation** on embedded systems

## 🧩 Libraries Used

- [`TFT_eSPI`](https://github.com/Bodmer/TFT_eSPI) – for display communication

---

## 📸 Screenshots / Demo

<img width="744" height="603" alt="Screenshot 2025-07-25 at 14 25 11" src="https://github.com/user-attachments/assets/806d127d-be9d-4f38-bc6e-2d3e5409163c" />

---

## 📄 License

This project is licensed under the MIT License.
