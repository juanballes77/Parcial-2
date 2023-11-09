#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;
class player
{

public:
    player();
    player(string usuario, char pieza);
    char getpieza();
    bool turn;

    string name;
    short unsigned score;
    char piece;

};

#endif // PLAYER_H
