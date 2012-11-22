#ifndef ePaper_h
#define ePaper_h


// Include the standard types
#include <Arduino.h>

typedef struct Changes {
	uint16_t add[10];
	uint16_t addNeg[10];
	uint16_t del[10];
	uint16_t delNeg[10];
	uint16_t addDel[10];
	uint16_t addDelNeg[10];
} Changes;

// Define the Shifter class
class ePaper
{
  public:
    // Constructor
    
     ePaper(int XCKpin, int LATCHpin, int SLEEPBpin, int DI0pin, int ENpin, int VCCpin);
   	
	void completeData(char*, char*);
	void incrementalData(char*, char*);
	void writeSimple(int, int);
	void write757(int, int);
	



  private:
  	void latch();
  	void print(uint16_t data[], int bw, int com);
	void printAll(uint16_t* top, uint16_t* bottom, int bw, int com);
	void zeroOut();
	void wakeup();
	void shutdown();
	void shiftBits(uint8_t count, uint16_t val);

  	uint16_t _topData[10];
	uint16_t _bottomData[10];
	Changes *_topChanges;
	Changes *_bottomChanges;
  
  	int _XCK;
  	int _LATCH;
  	int _SLPB;
  	int _DI0;
  	int _EN;
	int _VCC;
  	
};


#endif //Shifter_h
