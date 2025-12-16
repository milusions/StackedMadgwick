# StackedMadgwick

## Overview

**StackedMadgwick** is an enhanced implementation of the Madgwick AHRS (Attitude and Heading Reference System) algorithm for Arduino.<br>
This library is built on top of Madgwick AHRS by Arduino with built-in filtering for smoother and more stable IMU orientation data. 

It is designed to be **modular, easy to integrate**, and fully compatible with the Arduino IDE.

---

## Key Features

* Additional filtering stages before sensor fusion:

  * Low-pass filter
  * Average filter
  * Moving average (mean) filter
  
* Modular C++ design with multiple source files

---


## Dependencies

This library depends on the following Arduino libraries:

* **MPU6050_tockn**
* **MadgwickAHRS**

These dependencies are declared in `library.properties` and will be handled automatically by the Arduino Library Manager.

---

## Installation

### Option 1: Arduino IDE (Recommended)

1. Download the library as a ZIP file
2. Open **Arduino IDE**
3. Go to **Sketch → Include Library → Add .ZIP Library**
4. Select the downloaded ZIP file

### Option 2: Manual Installation

1. Clone or download the repository
2. Install the library by using the include library from .zip in arduino
3. Restart the Arduino IDE

---

## Basic Usage

```cpp
#include <StackedMadgwick.h>

// Initialize and use the StackedMadgwick class as required
```

Check the `examples` folder for complete working sketches.

---



