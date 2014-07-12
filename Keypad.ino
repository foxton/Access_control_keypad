#include "Keypad.h"
#include "Wire.h" // for I2C LCD
//#include "LiquidCrystal_I2C.h" // for I2C bus LCD module

 
// keypad type definition
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] =
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
 
byte rowPins[ROWS] = {
  5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {
  8, 7, 6}; // connect to the column pinouts of the keypad
 int password[4] = {1, 2, 3, 6};
 char input[4];
int count=0;
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup()
{
 // lcd.init();          // initialize the lcd
  //lcd.backlight(); // turn on LCD backlight
  Serial.begin(9600);
  Serial.print("Enter Password");
  Serial.print("\n");
  
}
 
void loop()
{
     
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    
      input[count] = key;
      count = count + 1;
      Serial.print(count); Serial.print("\t");
      Serial.print(key); Serial.print("\n");
}  
if(count == 4)
{
    Serial.println("INPUT");
    for(int i = 0; i < 4; i = i + 1)
    {
      Serial.println(input[i] - 48);
     }
    Serial.println("CORRECT PASSWORD"); 
     for(int j = 0; j < 4; j = j + 1)
    {
      Serial.println(password[j]);
     }      

int result = 1;
for (int x=0; x<4; x = x + 1)
{ 
  int test1 = (input[x] - 48);  //Compare positions one by one
  int test2 = (password[x]);
  if (test1 != test2)
  {
   result = 0; 
  }
  if (test1 == test2)
  {
   result = 1; 
  }
 Serial.print("Input: ");Serial.println(input[x]);   //Just for debugging purpose
 Serial.print("Password: ");Serial.println(password[x]); //Just for debugging purpose
 Serial.print("test1: ");Serial.println(test1);   //Just for debugging purpose
 Serial.print("test2: ");Serial.println(test2);   //Just for debugging purpose
}
Serial.print("Approved = "); Serial.println(result); //Just for debugging purpose
if(result == 1)
{
	Serial.println("ACCESS GRANTED");
}
else
{
	Serial.println("ACCESS DENIED");
}
    count = 0;
  }
}
  
