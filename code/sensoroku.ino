void sensoroku(){

unsigned int position = qtra.readLine(sensors,1,zemin);// 7  6  5 4 3 2 1 0
hata=position-3500;
}
