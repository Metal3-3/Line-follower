#include <QTRSensors.h> //QTR 3.0

#define sagmotor2 8
#define sagmotor1 7
#define sagmotorpwmpin 9
#define solmotor2  5
#define solmotor1  4
#define solmotorpwmpin  3
#define STBY 6
#define LED 13

QTRSensorsAnalog qtra((unsigned char[]) {  A7, A6, A5, A4, A3, A2, A1, A0}, 8);
unsigned int sensors[8];
float Kp = 0.025;  
float Kd = 0.42;
int tabanhiz=110;       
int ekhiz = 0;
int sonhata = 0;
int hata = 0;
int sagmotorpwm = 0;
int solmotorpwm = 0;
int zemin = 1;
int kalibrehizi = 50;
int sagcataldurum=0;

void setup() {
  //Serial.begin(9600);
  pinMode(sagmotor2, OUTPUT);
  pinMode(sagmotor1, OUTPUT);
  pinMode(sagmotorpwmpin, OUTPUT);
  pinMode(solmotor2, OUTPUT);
  pinMode(solmotor1, OUTPUT);
  pinMode(solmotorpwmpin, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(STBY, OUTPUT);
  delay(1500);

  digitalWrite(STBY,1);//MOTOR SÜRÜCÜ 1 AKTİF, 0 PASİF
  
  for (int i = 0; i < 150; i++)
  {
    if (0 <= i && i < 5) motorkontrol(kalibrehizi, -kalibrehizi);
    if (5 <= i && i < 15) motorkontrol(-kalibrehizi, kalibrehizi);
    if (15 <= i && i < 25) motorkontrol(kalibrehizi, -kalibrehizi);
    if (25 <= i && i < 35) motorkontrol(-kalibrehizi, kalibrehizi);
    if (35 <= i && i < 45) motorkontrol(kalibrehizi, -kalibrehizi);
    if (45 <= i && i < 55) motorkontrol(-kalibrehizi, kalibrehizi);
    if (55 <= i && i < 65) motorkontrol(kalibrehizi, -kalibrehizi);
    if (65 <= i && i < 75) motorkontrol(-kalibrehizi, kalibrehizi);
    if (75 <= i && i < 85) motorkontrol(kalibrehizi, -kalibrehizi);
    if (85 <= i && i < 95) motorkontrol(-kalibrehizi, kalibrehizi); 
    if (95 <= i && i < 100) motorkontrol(kalibrehizi, -kalibrehizi); 
    qtra.calibrate(); delay(1);
    if (i >= 100) {
      motorkontrol(0, 0);
      delay(3);
    }
  }
flashyap();
}

void loop() {
 sensoroku();
 pid();
 motorkontrol(solmotorpwm,sagmotorpwm);

}
