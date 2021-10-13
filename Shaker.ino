


void checkForShake(int ShakerPin){

  buttonState = digitalRead(ShakerPin);

   if (buttonState == HIGH){

    Serial.println("SHAKE SHAKE SHAKE");
    
    checkDrink(); //other tab 
    
    BottlePourTime1 = 0;
    BottlePourTime2 = 0;
    BottlePourTime3 = 0;
    overflowCheck(); //to show that everything has reset
    turnOffShaker ();
    NumOfRed=0;
    NumOfGreen=0;
    NumOfBlue=0;
    
  }

}



void lightShaker (int bottleNum){
 
 int numOfActiveLights = 0;
 // numOfActiveLights = ((BottlePourTime1 + BottlePourTime2 + BottlePourTime3)/10);
numOfActiveLights = NumOfRed + NumOfGreen + NumOfBlue;
uint32_t color = ShakerStrip.Color(0 ,   0,   0);




 
          
          
          
           //  Set pixel's color (in RAM)
 
    
    if(bottleNum == 1){
        for(int i=(NumOfBlue+NumOfGreen); i<numOfActiveLights; i++){
        color = ShakerStrip.Color(255 ,   0,   0);
        ShakerStrip.setPixelColor(i, color); 
         ShakerStrip.show();
        }
       }
    
    
    
  if(bottleNum ==2){
          
          for(int i=(NumOfBlue+NumOfRed); i<numOfActiveLights; i++){
        color = ShakerStrip.Color(0 ,   255,   0);
        ShakerStrip.setPixelColor(i, color); 
         ShakerStrip.show();
          }
    
 
  
  }

   if(bottleNum ==3){
    for(int i=(NumOfRed+NumOfGreen); i<numOfActiveLights; i++){
        color = ShakerStrip.Color(0 ,   0,   255);
        ShakerStrip.setPixelColor(i, color); 
         ShakerStrip.show();
          }

  }


    
    
     
    


 



}


void turnOffShaker (){

  for(int i=0; i<ShakerStrip.numPixels(); i++) {
   uint32_t color = ShakerStrip.Color(0 ,   0,   0);
    ShakerStrip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    ShakerStrip.show();              
    }
}




void flashForCorrectDrink (int whatDrink){ 

 uint32_t color = ShakerStrip.Color(0 ,   0,   0);

    if(whatDrink == 0){
      color = ShakerStrip.Color((255*.7), (255*.15),   0);  //MARSgarita (Brown)
    }

    if(whatDrink == 2){
      color = ShakerStrip.Color(0, (255*.6), (255*.5));  //MOON MULE (Cyan)
    }

    if(whatDrink == 4){
       color = ShakerStrip.Color((255*.6), 0,  (255*.4));  //Cosmos (Purple)
    }

    if(whatDrink == 6){
       color = ShakerStrip.Color(255, 255,  0);   // Space Station Sunrise (Yellow)
    }

     if(whatDrink == 8){
       
       
       color = ShakerStrip.Color(255 , 255,  255 ); // Halley's Cocktail (white)
    }




    for(int i=0; i<ShakerStrip.numPixels(); i++) {
    
    ShakerStrip.setPixelColor( i , color);         
    ShakerStrip.show();                          //  This is to 
                     
    
      }
   delay(400); //  Pause for a moment
   

   uint32_t Blankcolor = ShakerStrip.Color(0 ,   0,   0);
  for(int i=0; i<ShakerStrip.numPixels(); i++) {
    
    ShakerStrip.setPixelColor( i , Blankcolor);         
    ShakerStrip.show();                          //  
                   
    
      }
  

  delay(400);

 for(int i=0; i<ShakerStrip.numPixels(); i++) {
    
    ShakerStrip.setPixelColor( i , color);         
    ShakerStrip.show();                          //  This is to 
                     
    
      }

delay(400);


for(int i=0; i<ShakerStrip.numPixels(); i++) {
    
    ShakerStrip.setPixelColor( i , Blankcolor);         
    ShakerStrip.show();                          //  
                   
    
      }
delay(400);


 for(int i=0; i<ShakerStrip.numPixels(); i++) {
    
    ShakerStrip.setPixelColor( i , color);         
    ShakerStrip.show();                          //  This is to 
                     
    
      }

delay(400);


for(int i=0; i<ShakerStrip.numPixels(); i++) {
    
    ShakerStrip.setPixelColor( i , Blankcolor);         
    ShakerStrip.show();                          //  
                   
    
      }

delay(400);

 for(int i=0; i<ShakerStrip.numPixels(); i++) {
    
    ShakerStrip.setPixelColor( i , color);         
    ShakerStrip.show();                          //  This is to 
                     
    
      }
  delay(400);

  }
