void motorkontrol(int solmotorpwm,int sagmotorpwm){   //Örnek: motorkontrol(-50,50);
if(solmotorpwm<=0){
  solmotorpwm=abs(solmotorpwm);
  digitalWrite(solmotor2,LOW);
  digitalWrite(solmotor1,HIGH);
  analogWrite(solmotorpwmpin,solmotorpwm);
}
else{
  digitalWrite(solmotor2,HIGH);
  digitalWrite(solmotor1,LOW);
  analogWrite(solmotorpwmpin,solmotorpwm);
}

 if(sagmotorpwm<=0){
  sagmotorpwm=abs(sagmotorpwm);
  digitalWrite(sagmotor2,LOW);
  digitalWrite(sagmotor1,HIGH);
  analogWrite(sagmotorpwmpin,sagmotorpwm);
 }
 else{
  digitalWrite(sagmotor2,HIGH);
  digitalWrite(sagmotor1,LOW);
  analogWrite(sagmotorpwmpin,sagmotorpwm);
 }
}
