void pid(){
 int duzeltmehizi=Kp*hata+Kd*(hata-sonhata);  
 sonhata=hata;


 sagmotorpwm=(tabanhiz+ekhiz)+duzeltmehizi;
 solmotorpwm=(tabanhiz+ekhiz)-duzeltmehizi;

sagmotorpwm=constrain(sagmotorpwm,-254,254);
solmotorpwm=constrain(solmotorpwm, -254,254);
//motorkontrol(solmotorpwm,sagmotorpwm);
}
