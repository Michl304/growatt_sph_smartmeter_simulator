#include "modbus.h"
#include "WiFi.h"

ModbusRTU rtu_mb;

void init_Modbus_Rtu() 
{
    Serial1.begin(9600, SERIAL_8N1, RX_PIN_DEV, TX_PIN_DEV); 
    #if defined(ESP32) || defined(ESP8266)
        rtu_mb.begin(&Serial1, DE_RE_PIN);
        //mb.begin(&Serial1);
    #else
        rtu_mb.begin(&Serial1, DE_RE_PIN);
        rtu_mb.setBaudrate(115200);
    #endif
    rtu_mb.slave(SLAVE_ID);

    for (uint16_t i = 0; i < NUM_REGS; i++) 
    {
        rtu_mb.addIreg(i);
        rtu_mb.Ireg(i, 0);
    }

}

void RTUputCharToBuf(uint16_t value,uint16_t reg)
{
    rtu_mb.Ireg(reg, value);
}


uint16_t RTUgetCharFromBuf(uint16_t reg)
{
    return(rtu_mb.Ireg(reg));
}


void RTUputFloatToBuf(float value, uint16_t start_reg)
{
    // First convert the 32-bit float number into a 32-bit unsinged integer
    uint32_t int_value;
    uint16_t parts[2] = {0,0};
    // Copy the bit representation from float to uint32_t
    memcpy(&int_value, &value, sizeof(float));
    
    // Extract the 16-bit values
    parts[0] = (int_value & 0xFFFF);        // Die unteren 16 Bits
    parts[1] = (int_value >> 16) & 0xFFFF; // Die oberen 16 Bits

    RTUputCharToBuf(parts[0],start_reg);
    RTUputCharToBuf(parts[1],start_reg + 1);
}

float RTUgetFloatFromBuf(uint16_t start_reg)
{
    uint32_t parts = 0;
    float value = 0;
    parts = ((uint32_t)RTUgetCharFromBuf(start_reg + 1) << 16) | ((uint32_t)RTUgetCharFromBuf(start_reg));

    memcpy(&value, &parts, sizeof(float));

    return(value);
}
