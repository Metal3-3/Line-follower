void sensoroku(){

uint16_t position = zemin ? qtra.readLineWhite(sensors) : qtra.readLineBlack(sensors); // 7  6  5 4 3 2 1 0
int yenihata = position - 3500;
hata = 0.75 * hata + 0.25 * yenihata; // ani gürültü sıçramalarını yumuşatan basit filtre
}
