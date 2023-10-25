#include <Keypad.h>
#include <Servo.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypa
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v_passcode="";
Servo servo_10;
Servo servo_11;
void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  servo_10.attach(10);
  servo_11.attach(11);
  servo_10.write(0);
  servo_11.write(0);
}

void loop(){
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    //Serial.println(key);
    
    v_passcode = v_passcode + key;
    
    if(key=='*')
    {
        Serial.println("Enter Password ending with D");
        v_passcode="";

    }
    
    if(key=='#')
    {
        Serial.println("Enter Password again ending with D");
        v_passcode="";
      	Serial.println(v_passcode);

    }
    
    if(key=='D')
    {
        Serial.println("Validating the Password");
          Serial.println(v_passcode);
          
          if (v_passcode=="589D")//change" "to change password
          {
          Serial.println("Access Granted for Person 1");
            servo_10.write(90);
            delay(1000);
            servo_10.write(0);
              
             v_passcode="";
          }
       	  else if (v_passcode=="123D")//change" "to change password
          {
          Serial.println("Access Granted for Person 2");
            servo_11.write(90);
            delay(1000);
            servo_11.write(0);
              
             v_passcode="";
          }
          else
        {
            Serial.println("Access Denied");
             v_passcode="";
        }      
    } 
  }
} 
