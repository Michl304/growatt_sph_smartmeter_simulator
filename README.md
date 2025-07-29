feat: add ESP32-S3 based Growatt SPH smart meter simulator over Modbus TCP

- Initial release of a smart meter simulator for Growatt SPH devices
- Uses ESP32-S3 as a Modbus RTU Slave (Slave ID 2) receiving data via Modbus TCP over Wi-Fi
- Accepts input registers (0–18) as Float32 values to simulate voltage, current, and power data
- Designed for integration with Home Assistant or similar Modbus TCP clients

Setup:
1. Install ESP32-S3 board support in Arduino IDE
2. Edit Wi-Fi credentials in modbus_tcp.cpp
3. Flash meter_gateway.ino to ESP32-S3 board
4. Connect RS-485 module (e.g. MAX485) to ESP32-S3:
   - RX: Pin 18
   - TX: Pin 17
   - DE/RE (direction): Pin 16 (optional)
5. RS-485 to meter RJ45 cable:
   - A → Pin 5
   - B → Pin 1
6. Power on and find ESP32 IP via router
7. Send Float32 values to input registers 0–18 using Home Assistant or Modbus client

Register Map (Float32):
- 0: PHASE_1_LINE_TO_NEUTRAL_VOLTS
- 2: PHASE_2_LINE_TO_NEUTRAL_VOLTS
- 4: PHASE_3_LINE_TO_NEUTRAL_VOLTS
- 6: PHASE_1_CURRENT
- 8: PHASE_2_CURRENT
- 10: PHASE_3_CURRENT
- 12: PHASE_1_ACTIVE_POWER
- 14: PHASE_2_ACTIVE_POWER
- 16: PHASE_3_ACTIVE_POWER

Debug tips:
- Confirm Wi-Fi connection post-boot
- Use QModMaster to verify Modbus TCP communication
- Use USB-RS485 adapter to test RTU requests (9600 8N1, Slave ID 2)
