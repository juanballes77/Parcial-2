#ifndef JUEGO_H
#define JUEGO_H
#include <fstream>
#include<Tablero.h>
#include <sstream>
#include <ctime>

using namespace std;

class Juego
{
public:
    Juego();

    void print_register();
    void update_register();
    void nuevapartida();
    void startgame();
    string hour();
    string date();
    void update_register(string Jugador1, string Jugador2, string Ganador, string Puntaje  );
};

#endif // GAME_H
