# Title

**Difficulty:** Beginner / Intermediate / Advanced

**Estimated Time:** e.g., 30 minutes

**Hardware Needed:** e.g., None, LED + Button, I²C sensor

---

### Overview

State the main goal of the tutorial and the key Particle features it demonstrates.

Example: Learn how to use a Webhook to fetch live weather data and print it to Serial.

---

### Tools & Materials

- Particle device (Photon 2, Boron, etc.)
- USB cable
- Optional sensors or components
- Particle Workbench or CLI installed

---

### Dependencies

- Device OS dependencies
- Library dependencies

---

### Steps

1. **Clone this repository:**

   ```bash
   git clone https://github.com/particle-iot/blueprint-intermediate-temperature-ledger.git
   cd blueprint-intermediate-temperature-ledger
   ```

2. **Open the project** in Particle Workbench or your preferred editor.

3. **Flash to your device:**

   - Configure project for your device using Particle Workbench and the command pallette (cmd / ctrl + shift + p):
      ![Configure project for device](./images/configure-project.png)
   - Select your device model and Device OS release:
      ![Select device](./images/configure-msom.png)
      ![Select device OS](./images/configure-device-os.png)

4. **Open a serial terminal**:

   - Open a serial monitor session by choosing `Particle: Serial monitor` from the command pallette:
      ![Serial monitor](./images/serial-monitor.png)

5. **Observe output**

---

### How It Works

Explain the main logic of the firmware.

Describe the key functions, data flow, and what triggers events or responses.

---

### Usage

Describe how to interact with the project once running.

Include expected outputs or example Console actions.

---

### Topics Covered

List the Particle APIs and features demonstrated. Add links pointing to their documentation.

Example:

- `Particle.publish()`
- `Particle.function()`
- `Serial`

---

### Extensions

List optional ideas or improvements the user can try.
Or Link to next relevant Blueprint.

Example: Add a second sensor, store data to Ledger, or trigger alerts.
