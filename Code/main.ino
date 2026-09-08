#include <QTRSensors.h> //Yeni Pololu QTRSensors kütüphanesi

#define sagmotor2 4
#define sagmotor1 5
#define sagmotorpwmpin 3
#define solmotor2  8
#define solmotor1  7
#define solmotorpwmpin  9
#define STBY 6
#define LED 2

QTRSensors qtra;
uint16_t sensors[8];
float Kp = 0.04;  
float Kd = 0.03;
int tabanhiz=70;       
int ekhiz = 0;
int sonhata = 0;
int hata = 0;
int sagmotorpwm = 0;
int solmotorpwm = 0;
int zemin = 0;
int kalibrehizi = 90;
int sagcataldurum=0;

void setup() {
  Serial.begin(9600);
  qtra.setTypeAnalog();
  qtra.setSensorPins((const uint8_t[]) {A7, A6, A5, A4, A3, A2, A1, A0}, 8);
  qtra.setSamplesPerSensor(8); // gürültüyü azaltmak için örnek sayısını artır (varsayılan 4)

  pinMode(sagmotor2, OUTPUT);
  pinMode(sagmotor1, OUTPUT);
  pinMode(sagmotorpwmpin, OUTPUT);
  pinMode(solmotor2, OUTPUT);
  pinMode(solmotor1, OUTPUT);
  pinMode(solmotorpwmpin, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH); // QTR-8A IR LED'lerini kalıcı olarak AÇIK tut — bir daha KAPATMA
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

  // --- DEBUG: kalibrasyon çalışmış mı kontrol et ---
  Serial.println("Kalibrasyon MIN:");
  for (uint8_t i = 0; i < 8; i++) {
    Serial.print(qtra.calibrationOn.minimum[i]);
    Serial.print('\t');
  }
  Serial.println();
  Serial.println("Kalibrasyon MAX:");
  for (uint8_t i = 0; i < 8; i++) {
    Serial.print(qtra.calibrationOn.maximum[i]);
    Serial.print('\t');
  }
  Serial.println();
  // --- DEBUG SONU ---
}

void loop() {
 sensoroku();
 pid();
 motorkontrol(solmotorpwm,sagmotorpwm);

 // --- DEBUG: pozisyon, hata ve ham sensör değerlerini izle (sorun çözülünce sil) ---
 sensorlerioku_yaz();
 Serial.print("hata: ");
 Serial.print(hata);
 Serial.print("\tsol pwm: ");
 Serial.print(solmotorpwm);
 Serial.print("\tsag pwm: ");
 Serial.println(sagmotorpwm);
}
