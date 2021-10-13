

void SetMenuLEDs() {
  for(int i=0; i<MenuStrip.numPixels(); i++) { // For each pixel in strip...


   
    uint32_t color = MenuStrip.Color(0 ,   0,   0); // turn off the set
    
    if(i == 0){
      color = MenuStrip.Color((255*.7), (255*.15),   0);  //MARSgarita (Brown)
    }

    if(i == 2){
      color = MenuStrip.Color(0, (255*.6), (255*.5));  //MOON MULE (Cyan)
    }

    if(i == 4){
       color = MenuStrip.Color((255*.6), 0,  (255*.4));  //Cosmos (Purple)
    }

    if(i == 6){
       color = MenuStrip.Color(255, 255,  0);   // Space Station Sunrise (Yellow)
    }

     if(i == 8){
       
       
       color = MenuStrip.Color(255 , 255,  255 ); // Halley's Cocktail (white)

       
    }


    
    MenuStrip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    MenuStrip.show();                          //  Update strip to match
  
 
  }
}


void turnOffMenuItem (int menuItem){ 
 
 
 uint32_t color = MenuStrip.Color(0 ,   0,   0);
 MenuStrip.setPixelColor(menuItem, color);
    MenuStrip.show();                          //  Update strip to match

  
}
