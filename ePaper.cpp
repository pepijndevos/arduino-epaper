// Include the standard types
#include <Arduino.h>
#include <ePaper.h>


// Character definitions
//                         abcdefghijklmnop
uint16_t aChar =     0b1011100001011100;
uint16_t bChar =     0b0001101101011101;
uint16_t cChar =     0b1000001001010101;
uint16_t dChar =     0b1010101111000001;
uint16_t eChar =     0b1000001001011101;
uint16_t fChar =     0b1000000001011100;
uint16_t gChar =     0b1001101001010101;
uint16_t hChar =     0b0011100000011100;
uint16_t iChar =     0b1000001111000001;
uint16_t jChar =     0b1000000111000101;
uint16_t kChar =     0b0100010000011100;
uint16_t lChar =     0b0000001000010101;
uint16_t mChar =     0b0110100000110100;
uint16_t nChar =     0b0010110000110100;
uint16_t oChar =     0b1010101001010101;
uint16_t pChar =     0b1011000001011100;
uint16_t qChar =     0b1010111001010101;
uint16_t rChar =     0b1011010001011100;
uint16_t sChar =     0b1001101001100001;
uint16_t tChar =     0b1000000111000000;
uint16_t uChar =     0b0010101000010101;
uint16_t vChar =     0b0100000000010110;
uint16_t wChar =     0b0010110000010110;
uint16_t xChar =     0b0100010000100010;
uint16_t yChar =     0b0100000010100000;
uint16_t zChar =     0b1100001001000011;
uint16_t zeroChar =  0b1010101001010101;
uint16_t oneChar =   0b0000000110000000;
uint16_t twoChar =   0b1011001001001101;
uint16_t threeChar = 0b1101101001000001;
uint16_t fourChar =  0b0011100000011000;
uint16_t fiveChar =  0b1001101001011001;
uint16_t sixChar =   0b1001101001011101;
uint16_t sevenChar = 0b1100000001000010;
uint16_t eightChar = 0b1011101001011101;
uint16_t nineChar =  0b1011101001011001;
//                         abcdefghijklmnop
uint16_t commaChar = 0b0000000000000010;
uint16_t dashChar =  0b0001000000001000;
uint16_t uscorChar = 0b0000001000000001;
uint16_t oparnChar = 0b0100010000000000;
uint16_t cparnChar = 0b0000000000100010;
uint16_t hashChar =  0b0011101110001001;
uint16_t dolarChar = 0b1001101111011001;
uint16_t prcntChar = 0b0101101111011010;
uint16_t starChar =  0b0101010000101010;
uint16_t plusChar =  0b0001000110001000;
uint16_t questChar = 0b1011000011010000;
uint16_t quoteChar = 0b0000000100010000;
uint16_t slashChar = 0b0100000000000010;
uint16_t equalChar = 0b0001001000001001;

uint16_t toBits(char ch) {
// turn a character into 16 bits of segment data

    switch (ch)
    {
      case 'A':
      case 'a':
        return aChar;
      case 'B':
      case 'b':
        return bChar;
      case 'C':
      case 'c':
        return cChar;
      case 'D':
      case 'd':
        return dChar;
      case 'E':
      case 'e':
        return eChar;
      case 'F':
      case 'f':
        return fChar;
      case 'G':
      case 'g':
        return gChar;
      case 'H':
      case 'h':
        return hChar;
      case 'I':
      case 'i':
        return iChar;
      case 'J':
      case 'j':
        return jChar;
      case 'K':
      case 'k':
        return kChar;
      case 'L':
      case 'l':
        return lChar;
      case 'M':
      case 'm':
        return mChar;
      case 'N':
      case 'n':
        return nChar;
      case 'O':
      case 'o':
        return oChar;
      case 'P':
      case 'p':
        return pChar;
      case 'Q':
      case 'q':
        return qChar;
      case 'R':
      case 'r':
        return rChar;
      case 'S':
      case 's':
        return sChar;
      case 'T':
      case 't':
        return tChar;
      case 'U':
      case 'u':
        return uChar;
      case 'V':
      case 'v':
        return vChar;
      case 'W':
      case 'w':
        return wChar;
      case 'X':
      case 'x':
        return xChar;
      case 'Y':
      case 'y':
        return yChar;
      case 'Z':
      case 'z':
        return zChar;
      case '0':
        return zeroChar;
      case '1':
        return oneChar;
      case '2':
        return twoChar;
      case '3':
        return threeChar;
      case '4':
        return fourChar;
      case '5':
        return fiveChar;
      case '6':
        return sixChar;
      case '7':
        return sevenChar;
      case '8':
        return eightChar;
      case '9':
        return nineChar;
      case ',':
      case '.':
        return commaChar;
      case '-':
        return dashChar;
      case '_':
        return uscorChar;
      case '(':
      case '<':
        return oparnChar;
      case ')':
      case '>':
        return cparnChar;
      case '#':
        return hashChar;
      case '$':
        return dolarChar;
      case '%':
        return prcntChar;
      case '*':
        return starChar;
      case '+':
        return plusChar;
      case '?':
        return questChar;
      case '"':
        return quoteChar;
      case '/':
        return slashChar;
      case '=':
        return equalChar;
      default:
        return 0;
    }
}

uint16_t reverse(uint16_t x) {
// reverse all bits in two bytes

    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    //x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return ((x >> 8) | (x << 8));

}

uint16_t* reverseData(uint16_t *data, uint16_t characterData[]) {
// reverse all elements, causing it to be upside down

  for (int i=0; i<10; i++) {
    data[i] = reverse(characterData[i]);
  }

  return data;
}

uint16_t* flipData(uint16_t *data, uint16_t characterData[]) {
// cause text to flow in the other direction

  for (int i=0; i<10; i++)
    data[9-i] = characterData[i];

  return data;
    
}

Changes* newData(Changes *ch, uint16_t data[]) {
// generate a Changes structure where all input bits are added,
// all others removed, and the negative is precalculated too.

  for(int i=0; i<10; i++) {
    ch->add[i] = data[i];
    ch->del[i] = ~(data[i]);
    ch->addNeg[i] = ch->del[i];
    ch->delNeg[i] = ch->add[i];
    ch->addDel[i] = 0xFFFF;
    ch->addDelNeg[i] = 0;
  }

  return ch;
}

Changes* changedData(Changes *ch, uint16_t oldData[], uint16_t data[]) {
// Generate a Canges structure with all the bits
// that are in new but not in old,
// all the bits that are in old but now in new,
// and the negative of both

  for(int i=0; i<10; i++) {
    ch->add[i] = (oldData[i] ^ data[i]) & data[i];
    ch->del[i] = (oldData[i] ^ data[i]) & ~(data[i]);
    ch->addNeg[i] = ~(ch->add[i]);
    ch->delNeg[i] = ~(ch->del[i]);
    ch->addDel[i] = ch->add[i] | ch->del[i];
    ch->addDelNeg[i] = ~(ch->addDel[i]);
  }

  return ch;
}


	
// Constructor
ePaper::ePaper(int XCK, int LATCH, int SLPB, int DI0, int EN, int VCC){
  _XCK = XCK;
  _LATCH = LATCH;
  _SLPB = SLPB;
  _DI0 = DI0;
  _EN = EN;
  _VCC = VCC;
  
  pinMode(_XCK, OUTPUT);
  pinMode(_LATCH, OUTPUT);
  pinMode(_SLPB, OUTPUT);
  pinMode(_DI0, OUTPUT);
  pinMode(_EN, OUTPUT);
  pinMode(_VCC, OUTPUT);
  
  
  // Initial Pin Configurations -----------------------
  digitalWrite(_SLPB, LOW);      // Sleep high turns the display on
  digitalWrite(_DI0, LOW);
  digitalWrite(_XCK, LOW);
  digitalWrite(_LATCH, LOW);
  digitalWrite(_EN, LOW);
  digitalWrite(_VCC, LOW);

  _topChanges = (Changes*)malloc(sizeof(Changes));
  _bottomChanges = (Changes*)malloc(sizeof(Changes));
  
  // --------------------------------------------------
  
  //delay(100);
  
}

void ePaper::shiftBits(uint8_t nbits, uint16_t val) {
// write N bits in val to the data and clock lines

	uint8_t i;

	for (i = 0; i < nbits; i++)  {
		// Little endian
		//digitalWrite(_DI0, !!(val & (1 << i)));
		// Big endian
		digitalWrite(_DI0, !(val & (1 << (nbits - 1 - i))));

		digitalWrite(_XCK, HIGH);
		digitalWrite(_XCK, LOW);		
	}
}

void ePaper::print(uint16_t data[], int bw, int com){
// uint16 data[] - 10*16=160 bits of segment data 
// int bw - This should be a 1 or a 0, and will decide whether the BW (the fist bit) bit is set or not.
// int com - This should be a 1 or a 0, and will decide whether the COM (the last bit) bit is set or not.
  
  shiftBits(1, bw);

  for(int i=0; i<10; i++) {
    shiftBits(16, data[i]);
  }

  shiftBits(1, com);
}

void ePaper::printAll(uint16_t topData[], uint16_t bottomData[], int bw, int com) {
// print both displays and throw the latch
  print(bottomData, bw, com);
  print(topData,    bw, com);
  latch();
}


void ePaper::zeroOut() {
  uint16_t empty[10] = {0,0,0,0,0,0,0,0,0,0};
  printAll(empty, empty, 0, 0);
}

void ePaper::latch() {
// latch(): Simple function to activate and deactivate the latch
  digitalWrite(_LATCH, HIGH);
  digitalWrite(_LATCH, LOW);
}

void ePaper::wakeup() {
// power the chip and display and wake it from sleep
  digitalWrite(_VCC, HIGH);
  delay(50);
  
  digitalWrite(_EN, HIGH);
  digitalWrite(_SLPB, HIGH);

  delay(100);
  latch(); // do we need this?
}

void ePaper::shutdown() {
// put all pins to LOW
  digitalWrite(_SLPB, LOW);
  digitalWrite(_DI0, LOW);
  digitalWrite(_XCK, LOW);
  digitalWrite(_LATCH, LOW);
  digitalWrite(_EN, LOW);

  delay(50);
  digitalWrite(_VCC, LOW);
}

void ePaper::completeData(char *top, char *bottom) {
// write a full display update to memory, updates all segments
  for (int i=0; i<10; i++) {
    _topData[i] = reverse(toBits(top[i]));
    _bottomData[9-i] = toBits(bottom[i]);
  }
  newData(_topChanges, _topData);
  newData(_bottomChanges, _bottomData);
}

void ePaper::incrementalData(char *top, char *bottom) {
// write an incrementl display update to memory, updates only changed segments
  uint16_t topData[10];
  uint16_t bottomData[10];

  for (int i=0; i<10; i++) {
    topData[i] = reverse(toBits(top[i]));
    bottomData[9-i] = toBits(bottom[i]);
  }
  changedData(_topChanges, _topData, topData);
  changedData(_bottomChanges, _bottomData, bottomData);

  for (int i=0; i<10; i++) {
    _topData[i] = topData[i];
    _bottomData[i] = bottomData[i];
  }
}

void ePaper::writeSimple(int bw) {
// a simple update that fades sooner than the 7-5-7 but looks better

  wakeup();
  
  // added = 1
  // deleted = 0
  // unchanged = 1
  printAll(_topChanges->delNeg, _bottomChanges->delNeg, 1, 1);
  delay(1400);
  // added = 1
  // deleted = 1
  // unchanged = 0
  printAll(_topChanges->addDel, _bottomChanges->addDel, 0, 0);
  delay(1400);
  // added = 0
  // deleted = 1
  // unchanged = 1
  printAll(_topChanges->addNeg, _bottomChanges->addNeg, 1, 1);
  delay(1400);
  zeroOut();

  shutdown();
}


/*void ePaper::write757(int bw) {
// write a 7-5-7 waveform to the display
// this is ugly and takes longer, but doesn't fade away as quickly
  
  printAll(top, bottom, bw, 1);
  delay(250);
  printAll(top, bottom, bw, 0);
  delay(250);

  int x;
  for(x=0; x<7; x++) {
    delay(100);
    printAll(top, bottom, bw, 0);
    delay(100);
    printAll(top, bottom, bw, 1);

  }

  for(x=0; x<5; x++) {
    delay(200);
    printAll(inverseTop, inverseBottom, !bw, 0);
    delay(200);
    printAll(top, bottom, bw, 1);
  }

  printAll(inverseTop, inverseBottom, !bw, 0);
  delay(250);
  printAll(inverseTop, inverseBottom, !bw, 1);
  delay(250);

  for(x=0; x<7; x++) {
    delay(100);
    printAll(inverseTop, inverseBottom, !bw, 0);
    delay(100);
    printAll(inverseTop, inverseBottom, !bw, 1);
  }

  zeroOut();

}*/



