#include "RELAY1284.h"  // Class declaration
#include <Wire.h>

//-------------------------------------------------------- INIT
void RELAY1284::init (byte I2CAddress)
{
    TPIC2810_ADDRESS = I2CAddress;
	Wire.begin();
	off(B11111111);
}

//-------------------------------------------------------- ON
void RELAY1284::on(byte TPIC_CHANNEL)
{
  execute(TPIC_DATA |= TPIC_CHANNEL);
}

//-------------------------------------------------------- OFF
void RELAY1284::off(byte TPIC_CHANNEL)
{
  execute(TPIC_DATA ^= TPIC_CHANNEL);
}

//-------------------------------------------------------- EXECUTE (PRIVATE)
void RELAY1284::execute(byte TPIC_DATA)
{
  Wire.beginTransmission(TPIC2810_ADDRESS);
	Wire.write(TPIC2810_SUBADDR);
	Wire.write(TPIC_DATA);    
  Wire.endTransmission();
  ST_M4  = bitRead(TPIC_DATA, 0);   
  ST_M10 = bitRead(TPIC_DATA, 1);   
  ST_M12 = bitRead(TPIC_DATA, 2);   
  ST_M11 = bitRead(TPIC_DATA, 3);   
  ST_M6  = bitRead(TPIC_DATA, 4);   
  ST_M5  = bitRead(TPIC_DATA, 5);   
  ST_BKL = bitRead(TPIC_DATA, 6);  
  ST_M9  = bitRead(TPIC_DATA, 7);  
  
}

//-------------------------------------------------------- CONTROL ON
byte RELAY1284::ControlOn(byte TPIC_CHANNEL)
{
  execute(TPIC_DATA |= TPIC_CHANNEL);
  return TPIC_DATA;
}

//-------------------------------------------------------- CONTROL OFF
byte RELAY1284::ControlOff(byte TPIC_CHANNEL)
{
  execute(TPIC_DATA ^= TPIC_CHANNEL); 
  return TPIC_DATA;
}
