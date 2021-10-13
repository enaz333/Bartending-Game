
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__ //idk what this does lol
#endif

const int Menu_LED_count = 9;  //set as 51 for demo
const int Menu_LED_pin = 10;

const int Shaker_LED_count = 10;  //set as 51 for demo
const int Shaker_LED_pin = 8;

Adafruit_NeoPixel MenuStrip(Menu_LED_count, Menu_LED_pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ShakerStrip(Shaker_LED_count, Shaker_LED_pin, NEO_GRB + NEO_KHZ800);
 
int buttonState = 0; 
bool lostGame = false;
int numOfPoints = 0; //earn one for completing a drink

const int bottlePin = 2; 
const int bottlePin2 = 4;    // the number of the pushbutton pin
const int bottlePin3 = 6; 


const int shakeButtonPin = 12;
const int ledPin =  13;      // the number of the LED pin

unsigned long BottlePourTime1 = 0;
unsigned long BottlePourTime2 = 0;
unsigned long BottlePourTime3 = 0;


const int shakerCapcity = 100;

bool nowPressed = false;
bool wasPressed = false;

int mostRecentColor = 0;
int NumOfRed =0;
int NumOfGreen=0;
int NumOfBlue=0;

void setup() {
  
  MenuStrip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  MenuStrip.show();            // Turn OFF all pixels ASAP
  MenuStrip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  SetMenuLEDs(); //other tab

  ShakerStrip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  ShakerStrip.show();            // Turn OFF all pixels ASAP
  ShakerStrip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(bottlePin, INPUT);
  pinMode(bottlePin2,INPUT);
  pinMode(bottlePin3,INPUT);
  Serial.begin(9600);
  Serial.println (" WELCOME TO THE GAME"); 

  
}

void loop() {
 
  if(lostGame == false){
  
 
  bottlePour (bottlePin);
  bottlePour (bottlePin2);
  bottlePour (bottlePin3);

  
  checkForShake(shakeButtonPin);
  
  winGame();
  lightShaker(mostRecentColor);
  
 }

if (lostGame == true){
  GameOver();
}
  
  
  
}

void bottlePour (int BottleNum){


  buttonState = digitalRead(BottleNum);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {

    
    if(nowPressed == false){
      wasPressed=false;
  
    }
    
    nowPressed = true;
    updatePourTime(BottleNum);
    digitalWrite(ledPin, HIGH);     // turn LED on:
 
 
     if(BottleNum == 2){
    //stuff that only happen when button 1 is pressed
    }

    if(BottleNum==5){
    //stuff that only happen when button 2 is pressed
     
    }
  
  


} //if button state is high


if (buttonState == LOW) {           //if this funtion is called with the light off  
    
    digitalWrite(ledPin, LOW);    // turn LED off:
   
    
    if(nowPressed == true) { //only allows this to run on the first round with no button input 
    overflowCheck();
    nowPressed = false;
    }
    
    
  
  }




}


void updatePourTime(int BottleNum){

if(BottleNum==bottlePin){
BottlePourTime1++;
mostRecentColor=1;
NumOfRed = (BottlePourTime1/10);
}

if(BottleNum==bottlePin2 ){
BottlePourTime2++;
mostRecentColor=2;
NumOfGreen = (BottlePourTime2/10);
}

if(BottleNum==bottlePin3){
BottlePourTime3++;
mostRecentColor=3;
NumOfBlue = (BottlePourTime3/10);
}

}




void overflowCheck(){
  
  
  if( (BottlePourTime1 + BottlePourTime2 + BottlePourTime3 >= shakerCapcity + (shakerCapcity*.15) ) ){   //if you overfill more than 10% you loose
 
    GameOver ();
    Serial.println(" ");
    Serial.println(" ");
    Serial.println("GAME OVER - You Overflowed the cup");
  }



  else{
    Serial.println(" ");
    Serial.print("FILLED- ");
    Serial.print(BottlePourTime1 + BottlePourTime2 + BottlePourTime3);
    Serial.print(" / ");
    Serial.print(shakerCapcity);
    Serial.println(" ");
    Serial.print("From Bottle 1 - ");
    Serial.print(BottlePourTime1);
    Serial.print("   From Bottle 2 - ");
    Serial.print(BottlePourTime2);
    Serial.print(" ");
    Serial.print("   From Bottle 3 - ");
    Serial.print(BottlePourTime3);
    Serial.println(" ");
  }
    
  }



void winGame (){
  
  
  if(numOfPoints >= 5){
  
  // below is to flash green once won
  
  uint32_t color = MenuStrip.Color(0 ,   255,   0); 
    for(int i=0; i<MenuStrip.numPixels(); i++) {
    
    MenuStrip.setPixelColor( i , color);         
    MenuStrip.show();                          //  This is to 
                     
    
      }
   delay(400); //  Pause for a moment

   color = MenuStrip.Color(0 ,   0,   0);
  for(int i=0; i<MenuStrip.numPixels(); i++) {
    
    MenuStrip.setPixelColor( i , color);         
    MenuStrip.show();                          //  
                   
    
      }//  Pause for a moment
  

  delay(400);
  
  
  }//if sttment
        
  }



void GameOver (){

turnOffShaker ();

lostGame = true;
uint32_t color = MenuStrip.Color(255 ,   0,   0); //FLASH RED IF LOOSE- only way to LOOSE is to overflow 
    for(int i=0; i<MenuStrip.numPixels(); i++) {
    
    MenuStrip.setPixelColor( i , color);         
    MenuStrip.show();                          //  This is to 
                     
    
      }
   delay(400); //  Pause for a moment

   color = MenuStrip.Color(0 ,   0,   0);
  for(int i=0; i<MenuStrip.numPixels(); i++) {
    
    MenuStrip.setPixelColor( i , color);         
    MenuStrip.show();                          //  
                   
    
      }//  Pause for a moment
  

  delay(400);
  
  
}
 

 
  
