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

uint16_t topData[10]    = {0,0,0,0,0,0,0,0,0,0};
uint16_t bottomData[10] = {0,0,0,0,0,0,0,0,0,0};
	
// Constructor
ePaper::ePaper(int EIO, int XCK, int LATCH, int SLPB, int DI0, int EN, int VCC){
	_EIO = EIO; //not used
  	_XCK = XCK;
  	_LATCH = LATCH;
  	_SLPB = SLPB;
  	_DI0 = DI0;
	_EN = EN;
	_VCC = VCC;
	
	
  pinMode(_EIO, OUTPUT);
  pinMode(_XCK, OUTPUT);
  pinMode(_LATCH, OUTPUT);
  pinMode(_SLPB, OUTPUT);
  pinMode(_DI0, OUTPUT);
  pinMode(_EN, OUTPUT);
  pinMode(_VCC, OUTPUT);
  
  
  // Initial Pin Configurations -----------------------
  digitalWrite(_SLPB, LOW);      // Sleep high turns the display on
  digitalWrite(_DI0, LOW);         // Initialize data high
  digitalWrite(_XCK, LOW);
  digitalWrite(_EIO, LOW);
  digitalWrite(_LATCH, LOW);
  digitalWrite(_EN, LOW);
  digitalWrite(_VCC, LOW);
  
  // --------------------------------------------------
  
  //delay(100);
  
}

void ePaper::shiftBits(uint8_t nbits, uint16_t val)
{
	uint8_t i;

	for (i = 0; i < nbits; i++)  {
		// Little endian
		//digitalWrite(_DI0, !!(val & (1 << i)));
		// Big endian
		digitalWrite(_DI0, !!(val & (1 << (nbits - 1 - i))));

		digitalWrite(_XCK, HIGH);
		digitalWrite(_XCK, LOW);		
	}
}


uint16_t reverse(uint16_t x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    //x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return ((x >> 8) | (x << 8));

}

void reverseData(uint16_t characterData[]) {
  for (int i=0; i<10; i++) {
    characterData[i] = reverse(characterData[i]);
  }
}

void flipData(uint16_t characterData[]){
/* void flipData(char * characterData)
  char * characterData is an array of 160 char*'s (10 characters, 16 segments each).
  Each variable in characterData should be either a 1 or a 0.
  
  There is no return value, however the array sent to this function will be modified
  such that the order of the array is reversed (last byte becomes first, etc.).
  
  This function is useful if you want to flip a display. It's necessary if you want both
  displays to face the same direction.
*/


  uint16_t tempData[10];
  
  for (int i=0; i<10; i++)
    tempData[i] = characterData[i];
    
  for (int i=0; i<10; i++)
    characterData[i] = tempData[9-i];
}


void ePaper::print(uint16_t data[], int bw, int com){
  /* ePrint(char * displayTop, char * displayBottom, int bw, int com)
  This function displays the data in displayTop and displayBottom onto a 10x2
  ePaper display. The first and last bits of data transmission are configurable.
  There is no return value.
  
  char * displayTop - This should be an array of 160 1's or 0's. A 1 will turn
    a segment on, a 0 will turn a segment off. Each character consists of 16 segments.
  char * displayBottom - Same as display top.
  int bw - This should be a 1 or a 0, and will decide whether the BW (the fist bit) bit is set or not.
  int com - This should be a 1 or a 0, and will decide whether the COM (the last bit) bit is set or not.
*/

  
  shiftBits(1, bw);

  for(int i=0; i<10; i++)
  {
    shiftBits(16, data[i]);
  }

  shiftBits(1, com);
}


// latch(): Simple function to activate and deactivate the latch
void ePaper::latch()
{
  digitalWrite(_LATCH, HIGH);
  digitalWrite(_LATCH, LOW);
}


void ePaper::writeNumberTop(long input){

	char buffer [11];
	snprintf(buffer, 11, "%ld          ", input);
	
	createData(topData, buffer);
}


void ePaper::writeNumberBottom(long input){

	char buffer [11];
	snprintf(buffer, 11, "%ld          ", input);
	
	createData(bottomData, buffer);
}



void ePaper::writeTop(char * characterData){
	char buffer [11];
	snprintf(buffer, 11, "%s          ", characterData);
	createData(topData, buffer);
}


void ePaper::writeBottom(char * characterData){
	char buffer [11];
	snprintf(buffer, 11, "%s          ", characterData);
	createData(bottomData, buffer);
}

void ePaper::writeDisplay(){

  flipData(bottomData);  // If data is not flipped, it will look upside down.
  reverseData(topData);


  digitalWrite(_DI0, HIGH);
  digitalWrite(_VCC, HIGH);
  delay(50);
  
  digitalWrite(_EN, HIGH);
  digitalWrite(_SLPB, HIGH);

  delay(100);
  latch();

  int x;
  for(x=0; x<15; x++) {
	  print(bottomData, 0, 0);
	  print(topData,    0, 0);
	  latch();
	  delay(100);
	  print(bottomData, 0, 1);
	  print(topData,    0, 1);
	  latch();
	  delay(100);
  }

  digitalWrite(_SLPB, LOW);
  digitalWrite(_DI0, LOW);
  digitalWrite(_XCK, LOW);
  digitalWrite(_LATCH, LOW);
  digitalWrite(_EN, LOW);

  delay(50);
  digitalWrite(_VCC, LOW);

}


void ePaper::createData(uint16_t characterData[], char * toDisplay){
/* void createData(char * characterData, char * toDisplay)
  This function turns ASCII characters into data that is readable by the display.
  
  There are no return values. The data on char * toDisplay is transformed into
  the corresponding 1's and 0's for the display to understand, and char * characterData
  is updated to reflect that data. toDisplay will not be affected by this functione.
  
  If you want to add more displayable characters to this code, you'll need to add another
  case statment to the large switch. You should be able to pattern the statment after the
  other cases.
*/

  for (int i=0; i<10; i++)
  {
    switch (toDisplay[i])
    {
      case 'A':
      case 'a':
        characterData[i] = aChar;
        break;
      case 'B':
      case 'b':
        characterData[i] = bChar;
        break;
      case 'C':
      case 'c':
        characterData[i] = cChar;
        break;
      case 'D':
      case 'd':
        characterData[i] = dChar;
        break;
      case 'E':
      case 'e':
        characterData[i] = eChar;
        break;
      case 'F':
      case 'f':
        characterData[i] = fChar;
        break;
      case 'G':
      case 'g':
        characterData[i] = gChar;
        break;
      case 'H':
      case 'h':
        characterData[i] = hChar;
        break;
      case 'I':
      case 'i':
        characterData[i] = iChar;
        break;
      case 'J':
      case 'j':
        characterData[i] = jChar;
        break;
      case 'K':
      case 'k':
        characterData[i] = kChar;
        break;
      case 'L':
      case 'l':
        characterData[i] = lChar;
        break;
      case 'M':
      case 'm':
        characterData[i] = mChar;
        break;
      case 'N':
      case 'n':
        characterData[i] = nChar;
        break;
      case 'O':
      case 'o':
        characterData[i] = oChar;
        break;
      case 'P':
      case 'p':
        characterData[i] = pChar;
        break;
      case 'Q':
      case 'q':
        characterData[i] = qChar;
        break;
      case 'R':
      case 'r':
        characterData[i] = rChar;
        break;
      case 'S':
      case 's':
        characterData[i] = sChar;
        break;
      case 'T':
      case 't':
        characterData[i] = tChar;
        break;
      case 'U':
      case 'u':
        characterData[i] = uChar;
        break;
      case 'V':
      case 'v':
        characterData[i] = vChar;
        break;
      case 'W':
      case 'w':
        characterData[i] = wChar;
        break;
      case 'X':
      case 'x':
        characterData[i] = xChar;
        break;
      case 'Y':
      case 'y':
        characterData[i] = yChar;
        break;
      case 'Z':
      case 'z':
        characterData[i] = zChar;
        break;
      case '0':
        characterData[i] = zeroChar;
        break;
      case '1':
        characterData[i] = oneChar;
        break;
      case '2':
        characterData[i] = twoChar;
        break;
      case '3':
        characterData[i] = threeChar;
        break;
      case '4':
        characterData[i] = fourChar;
        break;
      case '5':
        characterData[i] = fiveChar;
        break;
      case '6':
        characterData[i] = sixChar;
        break;
      case '7':
        characterData[i] = sevenChar;
        break;
      case '8':
        characterData[i] = eightChar;
        break;
      case '9':
        characterData[i] = nineChar;
        break;
      case ',':
      case '.':
        characterData[i] = commaChar;
        break;
      case '-':
        characterData[i] = dashChar;
        break;
      case '_':
        characterData[i] = uscorChar;
        break;
      case '(':
      case '<':
        characterData[i] = oparnChar;
        break;
      case ')':
      case '>':
        characterData[i] = cparnChar;
        break;
      case '#':
        characterData[i] = hashChar;
        break;
      case '$':
        characterData[i] = dolarChar;
        break;
      case '%':
        characterData[i] = prcntChar;
        break;
      case '*':
        characterData[i] = starChar;
        break;
      case '+':
        characterData[i] = plusChar;
        break;
      case '?':
        characterData[i] = questChar;
        break;
      case '"':
        characterData[i] = quoteChar;
        break;
      case '/':
        characterData[i] = slashChar;
        break;
      case '=':
        characterData[i] = equalChar;
        break;
      default:
          characterData[i] = 0;
        break;
    }
  }
}
