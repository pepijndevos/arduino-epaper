// Include the standard types
#include <Arduino.h>
#include <ePaper.h>


// Character definitions
//                    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
char aChar[16] =     {1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0};
char bChar[16] =     {0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1};
char cChar[16] =     {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
char dChar[16] =     {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1};
char eChar[16] =     {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1};
char fChar[16] =     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0};
char gChar[16] =     {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
char hChar[16] =     {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0};
char iChar[16] =     {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1};
char jChar[16] =     {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
char kChar[16] =     {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0};
char lChar[16] =     {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1};
char mChar[16] =     {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0};
char nChar[16] =     {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0};
char oChar[16] =     {1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
char pChar[16] =     {1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0};
char qChar[16] =     {1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
char rChar[16] =     {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0};
char sChar[16] =     {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1};
char tChar[16] =     {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
char uChar[16] =     {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1};
char vChar[16] =     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0};
char wChar[16] =     {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0};
char xChar[16] =     {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0};
char yChar[16] =     {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0};
char zChar[16] =     {1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1};
char zeroChar[16] =  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
char oneChar[16] =   {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
char twoChar[16] =   {1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1};
char threeChar[16] = {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1};
char fourChar[16] =  {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0};
char fiveChar[16] =  {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1};
char sixChar[16] =   {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1};
char sevenChar[16] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
char eightChar[16] = {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1};
char nineChar[16] =  {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1};
//                    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
char commaChar[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
char dashChar[16] =  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
char uscorChar[16] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
char oparnChar[16] = {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char cparnChar[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0};
char hashChar[16] =  {0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};
char dolarChar[16] = {1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1};
char prcntChar[16] = {0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0};
char starChar[16] =  {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0};
char plusChar[16] =  {0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0};
char questChar[16] = {1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
char quoteChar[16] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0};
char slashChar[16] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
char equalChar[16] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1};

	char topData[160] = {
	//a,b,c, d, e, f, g, h, i, j, k, l, m, n, o, p
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D1
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D2
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D3
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D4
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D5
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D6
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D7
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D8
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D9
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // D10
	

	
	char bottomData[160] = {
	//a,b,c, d, e, f, g, h, i, j, k, l, m, n, o, p
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D1
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D2
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D3
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D4
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D5
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D6
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D7
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D8
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // D9
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // D10



// Constructor
ePaper::ePaper(int EIO, int XCK, int LATCH, int SLPB, int DI0, int EN, int VCC){
	_EIO = EIO;
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


void ePaper::flipData(char * characterData){
/* void flipData(char * characterData)
  char * characterData is an array of 160 char*'s (10 characters, 16 segments each).
  Each variable in characterData should be either a 1 or a 0.
  
  There is no return value, however the array sent to this function will be modified
  such that the order of the array is reversed (last byte becomes first, etc.).
  
  This function is useful if you want to flip a display. It's necessary if you want both
  displays to face the same direction.
*/


  char tempData[160];
  
  for (int i=0; i<160; i++)
    tempData[i] = characterData[i];
    
  for (int i=0; i<160; i++)
    characterData[i] = tempData[159-i];
}


void ePaper::print(char * displayTop, char * displayBottom, int bw, int com){
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

  
  digitalWrite(_EIO, LOW);
  if (bw)
    digitalWrite(_DI0, HIGH);
  else
    digitalWrite(_DI0, LOW);
  delayMicroseconds(1);
  clock();     // Y0
  digitalWrite(_EIO, HIGH);

  for(int i = 0; i<160; i++)
  {
    if (!displayBottom[i])
      digitalWrite(_DI0, LOW);
    else
      digitalWrite(_DI0, HIGH);
    delayMicroseconds(1);
    clock();
  }
  if (com)
    digitalWrite(_DI0, HIGH);
  else
    digitalWrite(_DI0, LOW);
  clock();     // Y161
  
  //--- 2nd display ---
  
  if (bw)
    digitalWrite(_DI0, HIGH);
  else
    digitalWrite(_DI0, LOW);
  
  clock();     // Y0

  for(int i = 0; i<160; i++)
  {
    if (!displayTop[i])
      digitalWrite(_DI0, LOW);
    else
      digitalWrite(_DI0, HIGH);
    delayMicroseconds(1);
    clock();
  }
  if (com)
    digitalWrite(_DI0, HIGH);
  else
    digitalWrite(_DI0, LOW);
  delayMicroseconds(1);
  clock();     // Y161  
  
  latch();
}



// clock(): Simple function to advance the XCK line one period
void ePaper::clock()
{
  digitalWrite(_XCK, HIGH);
  delayMicroseconds(1);
  digitalWrite(_XCK, LOW);
  delayMicroseconds(1);
}




// latch(): Simple function to activate and deactivate the latch
void ePaper::latch()
{
  digitalWrite(_LATCH, HIGH);
  delayMicroseconds(5);
  digitalWrite(_LATCH, LOW);
  delayMicroseconds(5);
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

  flipData(topData);  // If data is not flipped, it will look upside down.


  digitalWrite(_DI0, HIGH);
  digitalWrite(_EIO, HIGH);
  digitalWrite(_VCC, HIGH);
  delay(50);
  
  digitalWrite(_EN, HIGH);
  digitalWrite(_SLPB, HIGH);

  delay(100);
  latch();

  int x;
  for(x=0; x<15; x++) {
	  print(topData, bottomData, 0, 0);
	  delay(100);
	  print(topData, bottomData, 0, 1);
	  delay(100);
  }

  digitalWrite(_SLPB, LOW);
  digitalWrite(_DI0, LOW);
  digitalWrite(_XCK, LOW);
  digitalWrite(_EIO, LOW);
  digitalWrite(_LATCH, LOW);
  digitalWrite(_EN, LOW);

  delay(50);
  digitalWrite(_VCC, LOW);

}


void ePaper::createData(char * characterData, char * toDisplay){
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
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = aChar[j];
        break;
      case 'B':
      case 'b':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = bChar[j];
        break;
      case 'C':
      case 'c':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = cChar[j];
        break;
      case 'D':
      case 'd':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = dChar[j];
        break;
      case 'E':
      case 'e':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = eChar[j];
        break;
      case 'F':
      case 'f':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = fChar[j];
        break;
      case 'G':
      case 'g':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = gChar[j];
        break;
      case 'H':
      case 'h':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = hChar[j];
        break;
      case 'I':
      case 'i':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = iChar[j];
        break;
      case 'J':
      case 'j':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = jChar[j];
        break;
      case 'K':
      case 'k':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = kChar[j];
        break;
      case 'L':
      case 'l':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = lChar[j];
        break;
      case 'M':
      case 'm':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = mChar[j];
        break;
      case 'N':
      case 'n':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = nChar[j];
        break;
      case 'O':
      case 'o':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = oChar[j];
        break;
      case 'P':
      case 'p':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = pChar[j];
        break;
      case 'Q':
      case 'q':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = qChar[j];
        break;
      case 'R':
      case 'r':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = rChar[j];
        break;
      case 'S':
      case 's':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = sChar[j];
        break;
      case 'T':
      case 't':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = tChar[j];
        break;
      case 'U':
      case 'u':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = uChar[j];
        break;
      case 'V':
      case 'v':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = vChar[j];
        break;
      case 'W':
      case 'w':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = wChar[j];
        break;
      case 'X':
      case 'x':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = xChar[j];
        break;
      case 'Y':
      case 'y':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = yChar[j];
        break;
      case 'Z':
      case 'z':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = zChar[j];
        break;
      case '0':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = zeroChar[j];
        break;
      case '1':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = oneChar[j];
        break;
      case '2':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = twoChar[j];
        break;
      case '3':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = threeChar[j];
        break;
      case '4':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = fourChar[j];
        break;
      case '5':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = fiveChar[j];
        break;
      case '6':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = sixChar[j];
        break;
      case '7':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = sevenChar[j];
        break;
      case '8':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = eightChar[j];
        break;
      case '9':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = nineChar[j];
        break;
      case ',':
      case '.':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = commaChar[j];
        break;
      case '-':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = dashChar[j];
        break;
      case '_':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = uscorChar[j];
        break;
      case '(':
      case '<':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = oparnChar[j];
        break;
      case ')':
      case '>':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = cparnChar[j];
        break;
      case '#':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = hashChar[j];
        break;
      case '$':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = dolarChar[j];
        break;
      case '%':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = prcntChar[j];
        break;
      case '*':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = starChar[j];
        break;
      case '+':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = plusChar[j];
        break;
      case '?':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = questChar[j];
        break;
      case '"':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = quoteChar[j];
        break;
      case '/':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = slashChar[j];
        break;
      case '=':
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = equalChar[j];
        break;
      default:
        for (int j=0; j<16; j++)
          characterData[(9-i)*16 + j] = 0;
          break;
    }
  }
}
