# growatt_sph_smartmeter_simulator
ESP32-S3 Based Smart Meter Simulator for Home Assistant using Modbus TCP

1. Install ESP32-S3 in the Arduino IDE Board Manager
2. Flash the Software on a ESP32-S3 Dev Board
3. Connect a RS-485 Board to (e. MAX-485) the RESP32-S3 PIN 16 RX, PIN 17 TX
4. Connect A of the RS-485 Board to the Pin 5 of the Meter-RJ45-Cable, Connect B of the RS-485 Board to the Pin 1 of the Meter-RJ45-Cable
5. Power on your ESP32-S3 and check for its IP in your router rettings
6. Write Data to the INPUT-Registers 0-18 (9xFloat)
