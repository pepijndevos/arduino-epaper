#ifndef ePaper_h
#define ePaper_h


// Include the standard types
#include <Arduino.h>

// Define the Shifter class
class ePaper
{
  public:
    // Constructor
    
     ePaper(int EIO1pin, int XCKpin, int LATCHpin, int SLEEPBpin, int DI0pin, int ENpin, int VCCpin);
   	
  	void writeDisplay(int bw);
  	void writeBottom(char * characterData);
  	void writeTop(char * characterData);
  	void writeNumberBottom(long input);
  	void writeNumberTop(long input);
  	
	



  private:
  	void latch();
  	void print(uint16_t data[], int bw, int com);
	void printAll(uint16_t* top, uint16_t* bottom, int bw, int com);
  	void createData(uint16_t characterData[], char * text);
	void shiftBits(uint8_t count, uint16_t val);

  	uint16_t topData[10];
	uint16_t bottomData[10];
  
  	int _EIO;
  	int _XCK;
  	int _LATCH;
  	int _SLPB;
  	int _DI0;
  	int _EN;
	int _VCC;
  	

  	
  	
  
};

#endif //Shifter_h
