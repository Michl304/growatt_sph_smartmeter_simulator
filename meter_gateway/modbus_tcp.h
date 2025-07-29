#include <Arduino.h>
#include <WiFi.h>
#include <ModbusIP_ESP8266.h>
#include "modbus.h"

extern ModbusIP tcp_mb;

void init_modbus_tcp();
void TCPputCharToBuf(uint16_t value,uint16_t reg);
uint16_t TCPgetCharFromBuf(uint16_t reg);
void TCPputFloatToBuf(float value, uint16_t start_reg);
float TCPgetFloatFromBuf(uint16_t start_reg);

void forwardTCPtoRTU(uint16_t reg);