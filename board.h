#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "player.h"

using namespace std;


class board
{
public:
    char ** matriz;
    int filas = 8,columnas = 8;
    int cant_negras = 2 ,cant_blancas = 2,cant_vacios;
    short unsigned cantmovimientosposibles;
public:
    board();
    void imprimir_matriz( );
    short validacionentrada1(char entrada);
    int validacion_entrada_fila(int fila);

    char otroturno(char turnoactual);
    void movimientosposibles(char turnoactual);
    char getvalue(int fila, int columna);
    bool sandwichCheck(unsigned short fila, unsigned short columna, short sumax, short sumay,char micaracter);
    bool adyacentcelds(unsigned short fila, unsigned short columna, char turnoactual);
    bool checklimits(unsigned short fila, unsigned short columna, short sumax, short sumay);
    bool checklimits2(unsigned short fila, unsigned short columna, short sumax, short sumay);
    void insert_piece(player jugador);
    void change_color(unsigned short fila, unsigned short columna, short sumax, short sumay,player jugador);

};



#endif // BOARD_H
