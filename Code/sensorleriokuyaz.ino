 void sensorlerioku_yaz(){
 for (unsigned char z = 0; z < 8; z++)
  {
    Serial.print(sensors[z]);
    Serial.print('\t'); 
    
  }
  
  Serial.println();  
  delay(50); 
 }
