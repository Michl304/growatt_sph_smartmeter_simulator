#include "modbus_tcp.h"

const int NUMBER_OF_HREGS = 1500;

//ModbusIP object
ModbusIP tcp_mb;

void init_modbus_tcp()
{
   WiFi.begin("WLAN SSID", "WLAND PW");
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
  }
 
  tcp_mb.server();

  for(int reg = 0; reg <= NUMBER_OF_HREGS; reg++)
  {
      tcp_mb.addIreg(reg);
      tcp_mb.Ireg(reg, 0);
  }
}


void TCPputCharToBuf(uint16_t value,uint16_t reg)
{
    tcp_mb.HIreg(reg, value);
}


uint16_t TCPgetCharFromBuf(uint16_t reg)
{
    return(tcp_mb.Ireg(reg));
}


void TCPputFloatToBuf(float value, uint16_t start_reg)
{
    // First convert the 32-bit float number into a 32-bit unsinged integer
    uint32_t int_value;
    uint16_t parts[2] = {0,0};
    // Copy the bit representation from float to uint32_t
    memcpy(&int_value, &value, sizeof(float));
    
    // Extract the 16-bit values
    parts[0] = (int_value & 0xFFFF);        // Die unteren 16 Bits
    parts[1] = (int_value >> 16) & 0xFFFF; // Die oberen 16 Bits

    TCPputCharToBuf(parts[0],start_reg);
    TCPputCharToBuf(parts[1],start_reg + 1);
}


float TCPgetFloatFromBuf(uint16_t start_reg)
{
    uint32_t parts = 0;
    float value = 0;
    parts = ((uint32_t)TCPgetCharFromBuf(start_reg + 1) << 16) | ((uint32_t)TCPgetCharFromBuf(start_reg));

    memcpy(&value, &parts, sizeof(float));

    return(value);
}

void forwardTCPtoRTU(uint16_t reg)
{
  RTUputFloatToBuf(TCPgetFloatFromBuf(reg), reg);
}