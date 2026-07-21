# LPC1768 DAC Ramp Waveform Generator

Generate a smooth analog **Ramp (Sawtooth) waveform** using the **10-bit Digital-to-Analog Converter (DAC)** available in the **NXP LPC1768** microcontroller through direct register programming.

This project demonstrates how digital values are converted into analog voltages to produce a continuously repeating ramp waveform. It is a beginner-friendly project for learning **Embedded C**, **Register-Level Programming**, and **DAC peripherals** of the LPC1768.

---

## 📌 Features

- Register-Level Programming
- Uses LPC1768 Internal 10-bit DAC
- Generates Continuous Ramp Waveform
- Adjustable Ramp Speed using Software Delay
- Oscilloscope Verification
- Simple and Well-Commented Embedded C Code

---

## 📖 Project Overview

The LPC1768 contains an onboard **10-bit DAC** whose analog output is available on **P0.26 (AOUT)**.

This project:

- Configures P0.26 as DAC output.
- Initializes the DAC peripheral.
- Increments DAC values from **0 to 1023**.
- Converts each digital value into its corresponding analog voltage.
- Resets the output to **0V** after reaching the maximum value.
- Continuously repeats the process to generate a Ramp (Sawtooth) waveform.

---

## 🛠 Hardware Required

- LPC1768 Development Board
- USB Cable
- Oscilloscope / Digital Storage Oscilloscope (DSO)
- Connecting Wires

---

## 💻 Software Required

- Keil µVision IDE
- CMSIS LPC17xx Header Files
- Embedded C

---

# 📚 Theory

A **Digital-to-Analog Converter (DAC)** converts digital binary values into corresponding analog voltages.

The LPC1768 features a **10-bit DAC**, allowing **1024 different voltage levels**.

### DAC Specifications

| Parameter | Value |
|-----------|-------|
| Resolution | 10-bit |
| Digital Range | 0 – 1023 |
| Reference Voltage | 3.3V |
| Output Pin | P0.26 (AOUT) |

The output voltage is calculated as:

\[
V_{OUT}=\frac{DAC\ Value}{1023}\times3.3V
\]

---

# ⚙ Working Principle

The program performs the following steps:

1. Configure **P0.26** as DAC output.
2. Enable the DAC peripheral.
3. Start with a DAC value of **0**.
4. Increment the DAC value from **0 to 1023**.
5. Write each value into the **DACR** register.
6. Introduce a small delay after every update.
7. Once the maximum value is reached, reset the DAC output to **0V**.
8. Repeat the sequence indefinitely.

The gradual increase followed by an instant reset produces a **Ramp (Sawtooth) waveform**.

---

# 🔄 Program Flow

```text
Start
   │
   ▼
Initialize DAC
   │
   ▼
Configure P0.26 as AOUT
   │
   ▼
Write DAC Value
   │
   ▼
Increment DAC Value
   │
   ▼
Delay
   │
   ▼
Reached 1023?
   │
 ┌─┴───────────┐
 │             │
No            Yes
 │             │
 └──────► Reset to 0
              │
              ▼
        Repeat Forever
```

---

# 📝 Register Configuration

## Configure DAC Output Pin

```c
LPC_PINCON->PINSEL1 &= ~(3 << 20);
LPC_PINCON->PINSEL1 |=  (2 << 20);
```

Configures **P0.26** as the analog output pin (**AOUT**).

---

## DAC Register

```c
LPC_DAC->DACR = (value & 0x3FF) << 6;
```

The LPC1768 DAC accepts a **10-bit value** stored in **bits [15:6]** of the **DACR** register.

---

# 📂 Project Structure

```
LPC1768-DAC-Ramp-Waveform/
│
├── main.c
├── README.md
├── images/
│   ├── setup.jpg
│   ├── waveform.png
│   └── oscilloscope_output.jpg
└── videos/
    └── demo.mp4
```

---

# 📈 Output Waveform

The generated waveform appears as follows:

```text
Voltage

3.3V |                /
     |              /
     |            /
     |          /
     |        /
0V   |_______/

           Time →
```

---

# 🔍 Observations

- The DAC output increased smoothly from **0V to 3.3V**.
- After reaching the maximum value, the voltage instantly reset to **0V**.
- A continuous Ramp (Sawtooth) waveform was observed on the oscilloscope.
- Increasing the software delay reduced the waveform frequency.
- Decreasing the delay increased the waveform frequency.

---

# 🎯 Applications

- Function Generators
- Signal Processing
- Analog Signal Generation
- Embedded System Learning
- Control Systems
- DAC Peripheral Demonstration
- Sensor Simulation
- Industrial Automation

---

# 📸 Results

> **Add your setup image here**

```
images/setup.jpg
```

---

> **Add the oscilloscope output here**

```
images/oscilloscope_output.jpg
```

---

# 🎥 Demo Video

Upload your demonstration video to the repository and embed it here.

```
videos/demo.mp4
```

Or upload it to YouTube and add the link.

```text
https://youtu.be/your_video_link
```

---

# 🚀 Future Improvements

- Triangle Wave Generation
- Sine Wave Generation
- PWM vs DAC Comparison
- Timer Interrupt-Based DAC Output
- DMA-Based Waveform Generation
- Audio Tone Generation
- User-Controlled Waveform Selection

---

# 🧑‍💻 Author

**Pushpak Srinivas**

B.Tech Electronics and Communication Engineering  
SRM University-AP

---

## ⭐ If you found this project useful, consider giving it a Star!
