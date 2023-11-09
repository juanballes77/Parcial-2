#ifndef GAME_H
#define GAME_H
#include <fstream>
#include<tablero.h>
#include <sstream>
#include <ctime>

using namespace std;

class game
{
public:
    game();

    void print_register();
    void update_register();
    void nuevapartida();
    void startgame();
    string hour();
    string date();
    void update_register(string player1, string player2, string winner, string score  );
};

#endif // GAME_H
