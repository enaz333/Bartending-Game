

int checkDrink (){

if(BottlePourTime1 + BottlePourTime2 + BottlePourTime3 >= (shakerCapcity*.8)){ //must be within 80% of full to check

  if (checkForMARSgarita()){
    turnOffMenuItem(0);
    Serial.println(" YOU MADE A MARSgarita!!!! ");
    numOfPoints++;
    flashForCorrectDrink(0); //MARSgarita (Brown)
  }
 
  if(checkForMoonMule()){
    turnOffMenuItem(2);
     Serial.println(" YOU MADE A MOON MULE!!!!");
     numOfPoints++;
     flashForCorrectDrink(2);
  }

  
  if(checkForCosmos()){
    turnOffMenuItem(4);
      Serial.println(" YOU MADE A Cosmos!!!!");
       numOfPoints++;
       flashForCorrectDrink(4);
  }

 if(checkForSpaceStationSunrise()){
    turnOffMenuItem(6);
      //Serial.println(" YOU MADE A Space Station Sunrise!!!!");
      Serial.println(" YOU MADE A SpaceShip Fuel!!!!");
       numOfPoints++;
       flashForCorrectDrink(6);
  }
  
 if(checkForHalleysCocktail()){
    turnOffMenuItem(8);
     // Serial.println(" YOU MADE A Halley's Cocktail!!!!");
     Serial.println(" YOU MADE AN Alien Water!!!!");
       numOfPoints++;
       flashForCorrectDrink(8);
  }


// MARSgarita - pin 0
//MoonMules - pin 2
//Cosmos - pin 4 
//SpaceStation Sunrise - pin 6
//Halleys Cocktail -pin 8


} //if statment



}//CheckDrink 






bool checkForMARSgarita(){


if(BottlePourTime3 > 0){ // none of bottle 3 allowed
  return false;
}

if ( BottlePourTime1 > (shakerCapcity*.6) && BottlePourTime1 < (shakerCapcity*.8)){
  
      if ( BottlePourTime2 > (shakerCapcity*.2) && BottlePourTime2 < (shakerCapcity*.4)){ 


          return true; //drink made sucsessfully 

      }
  
}
  
return false;
 
 }



bool checkForMoonMule(){

if(BottlePourTime1 > 0){ // none of bottle 1 allowed
  return false;
}

if ( BottlePourTime3 > (shakerCapcity*.6) && BottlePourTime3 < (shakerCapcity*.8)){ //Blue 70%
  
      if ( BottlePourTime2 > (shakerCapcity*.2) && BottlePourTime2 < (shakerCapcity*.4)){  // Green 30%


          return true; //drink made sucsessfully 

      }
  
}
  

return false;
}



bool checkForCosmos(){

if(BottlePourTime2 > 0){ // none of bottle 2 allowed
  return false;
}

if ( BottlePourTime1 > (shakerCapcity*.5) && BottlePourTime1 < (shakerCapcity*.7)){ //red 60%
  
      if ( BottlePourTime3 > (shakerCapcity*.3) && BottlePourTime3 < (shakerCapcity*.5)){  // blue 50%


          return true; //drink made sucsessfully 

      }
  
}
  

return false;
  
}


bool checkForSpaceStationSunrise(){
  
  if (BottlePourTime3 > 0){ // none of bottle 3 allowed
  return false;
}

if ( BottlePourTime1 > (shakerCapcity*.4) && BottlePourTime1 < (shakerCapcity*.6)){ //red 50%
  
      if ( BottlePourTime2 > (shakerCapcity*.4) && BottlePourTime2 < (shakerCapcity*.6)){  // blue 50%


          return true; //drink made sucsessfully 

      }
  
}
  

return false;
  
}

bool checkForHalleysCocktail(){
 


if ( BottlePourTime1 > (shakerCapcity*.3) && BottlePourTime1 < (shakerCapcity*.5)){ //red 30%
  
      if ( BottlePourTime2 > (shakerCapcity*.2) && BottlePourTime2 < (shakerCapcity*.4)){  // green 30%

           if ( BottlePourTime3 > (shakerCapcity*.2) && BottlePourTime3 < (shakerCapcity*.4)){   // blue 30%
           
                 return true; //drink made sucsessfully 
          
           }
         }
       }
  

return false;
  
}
