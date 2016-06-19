#ifndef RELAY1284_H
#define RELAY1284_H

#include "Arduino.h"

static const byte REL_M4  = 1;   //B00000001;
static const byte REL_M10 = 2;   //B00000010;
static const byte REL_M12 = 4;   //B00000100;
static const byte REL_M11 = 8;   //B00001000;
static const byte REL_M6  = 16;  //B00010000;
static const byte REL_M5  = 32;  //B00100000;
static const byte LCD_BKL = 64;  //B01000000;
static const byte REL_M9  = 128; //B10000000;
	  
class RELAY1284
{
   private:
   
      byte I2CAddress;  	
	  byte TPIC2810_ADDRESS;
	  byte TPIC2810_SUBADDR = B01000100;
	  byte TPIC_DATA        = B11111111;
	  byte TPIC_CHANNEL		= B00000000;
	  byte tempCtrl;
	  byte Status;
	  
	  void execute(byte TPIC_DATA);
	    
   public:

      void init 		(byte I2CAddress);
      void on   		(byte TPIC_CHANNEL);
      void off  		(byte TPIC_CHANNEL);
      byte ControlOn    (byte TPIC_CHANNEL); // this function returns the final TPIC_DATA value after boolean operations;
      byte ControlOff   (byte TPIC_CHANNEL); // this function returns the final TPIC_DATA value after boolean operations;	  
	  byte read();
	  
	  byte ST_M4;
	  byte ST_M5;
	  byte ST_M6;
	  byte ST_M9; 
	  byte ST_M10;
	  byte ST_M11; 
	  byte ST_M12; 
	  byte ST_BKL; 
	  
};

#endif