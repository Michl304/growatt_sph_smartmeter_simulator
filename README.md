# growatt_sph_smartmeter_simulator
ESP32-S3 Based Smart Meter Simulator for Home Assistant using Modbus TCP

1. Install ESP32-S3 in the Arduino IDE Board Manager
2. Open the meter_gateway.ino and change your wifi credentials (SSID and PW) in the modbus_tcp.cpp
3. Flash the Software on a ESP32-S3 Dev Board
4. Connect a RS-485 Board to (e. MAX-485) the RESP32-S3 PIN 18 RX, PIN 17 TX, Pin 16 Direction (if needed)
5. Connect A of the RS-485 Board to the Pin 5 of the Meter-RJ45-Cable, Connect B of the RS-485 Board to the Pin 1 of the Meter-RJ45-Cable
6. Power on your ESP32-S3 and check for its IP in your router rettings
7. Write Data to the INPUT-Registers 0-18 (9xFloat)
