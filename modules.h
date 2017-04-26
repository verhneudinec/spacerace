#include "ship.h"
#include "asteroid.h"

void game(int p); //основная функция
void writerec(int &);  //запись рекорда (-ов)
void checkblow(asteroid *, ship &); //проверка столкновения
void checkdefeat(ship &); //определение конца игры
void checkdefeat(ship &, ship &);

void home(); //главный экран
void go2main(); //возврат на гланый экран
void help(); //помощь
void seerec(); //просмотр рекордов
