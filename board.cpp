#include "board.h"


board::board(){
    cant_vacios= ((columnas*filas) - cant_blancas -cant_negras);
    matriz =  new char* [filas];

    for (unsigned short i = 0;i<filas;i++){
        matriz[i]= new char [columnas];
    }

    for (unsigned short i = 0; i<filas; i++){
        for (unsigned short u = 0; u<columnas; u++ ){

            if (i==(columnas/2) && u== i || i == (columnas/2)-1 && u == i) {
                matriz[i][u] = '*';
            }
            else if (u  ==(filas/2) && i == u-1 || u  ==(filas/2)-1 && i == u+1 ){
                matriz[i][u] = '-';
            }
            else{
                matriz[i][u]= 'o';
            }
        }
    }
}


short board::validacionentrada1(char entrada)
{
    short retu;
    if(entrada>=65 &&entrada<=72){
        retu=entrada-65;
    }else if(entrada>=97 &&entrada<=104){
        retu=entrada-97;
    }else{
        retu=-1;
    }
    return retu;
}

int board::validacion_entrada_fila(int fila){

    if (cin.fail()|| fila<0 || fila> columnas){
        cin.clear();
        cin.ignore(100, '\n');
        return 0;
    }
    else if (fila>0 && fila <columnas){
        return fila;

    }
}

char board::otroturno(char turnoactual)
{
    char otroturno;
    if(turnoactual=='-'){
        otroturno='*';
    }else if(turnoactual=='*'){
        otroturno='-';
    }
    else{
        cout<<"Error hallando turno";
    }
    return otroturno;
}

void board::movimientosposibles(char turnoactual){
    cantmovimientosposibles=0;
    cant_blancas = 0;
    cant_negras = 0;

    cout<<"    A     B     C     D     E     F     G     H"<<endl;
    for (int i = 0; i<filas; i++){
        cout<<i+1<<" ";
        for (int u = 0; u<columnas; u++ ){
            if (matriz[i][u]=='*'){
                cant_blancas++;
            }
            if (matriz[i][u]=='-'){
                cant_negras++;
            }

            if(matriz[i][u]== 'o'){
                bool status=adyacentcelds(i,u,turnoactual);
                if(status){
                    cout<< "  "<<"X"<<"  "<<" ";
                    cantmovimientosposibles++;
                }else
                    cout<<"  "<<'o'<<"  "<<" ";

            }

            else
                cout<<"  "<< matriz[i][u]<<"  " << " ";

        }
        cout<<i+1<<" ";
        cout<< endl<<endl;

    }
    cout<<"    A     B     C     D     E     F     G     H"<<endl;


}
bool board::adyacentcelds(unsigned short fila, unsigned short columna, char turnoactual){
    char otroturn=otroturno(turnoactual);
    bool arriba,abajo,izquierda,derecha,diagonal1,diagonal2,diagonal3,diagonal4,flag;
    if(columna!=0){
        if(getvalue(fila,columna-1)==otroturn){
            arriba=sandwichCheck(fila,columna,0,-1,turnoactual);
        }else
            arriba=false;
    }else
        arriba=false;

    if (columna!=(columnas-1)){
        if(getvalue(fila,columna+1)==otroturn){
            abajo=sandwichCheck(fila,columna,0,+1,turnoactual);
        }else
            abajo=false;
    }
    else abajo=false;

    if(fila!=0){
        if(getvalue(fila-1,columna)==otroturn){
            izquierda=sandwichCheck(fila,columna,-1,0,turnoactual);
        }else
            izquierda=false;
    }
    else izquierda=false;

    if(fila!=filas-1){
        if(getvalue(fila+1,columna)==otroturn){
            derecha=sandwichCheck(fila,columna,1,0,turnoactual);}
        else
            derecha=false;
    }else derecha=false;

    if(columna!=columnas-1 && fila!=filas-1){
        if(getvalue(fila+1,columna+1)==otroturn){
            diagonal1=sandwichCheck(fila,columna,1,1,turnoactual);}
        else
            diagonal1=false;
    }else diagonal1=false;

    if(columna!=columnas-1 && fila!=0){
        if(getvalue(fila-1,columna+1)==otroturn){
            diagonal2=sandwichCheck(fila,columna,-1,1,turnoactual);}
        else
            diagonal2=false;
    }else diagonal2=false;

    if(columna!=0 && fila!=filas-1){
        if(getvalue(fila+1,columna-1)==otroturn){
            diagonal3=sandwichCheck(fila,columna,1,-1,turnoactual);}
        else diagonal3=false;
    }else diagonal3=false;

    if(columna!=0 && fila!=0){
        if(getvalue(fila-1,columna-1)==otroturn){
            diagonal4=sandwichCheck(fila,columna,-1,-1,turnoactual);}
        else diagonal4=false;
    } else diagonal4=false;

    if(arriba||abajo||derecha||izquierda||diagonal4||diagonal3||diagonal2||diagonal1){
        flag=true;
    }else
        flag=false;
    return flag;
}
bool board::sandwichCheck(unsigned short fila, unsigned short columna, short sumax, short sumay,char micaracter){
    bool flag=checklimits(fila,columna,sumax,sumay);
    if(flag){
        if(checklimits2(fila,columna,sumax,sumay)&&matriz[fila+sumax][columna+sumay]=='o'){
            flag= false;
        }
        else if(checklimits2(fila,columna,sumax,sumay)&&matriz[fila+sumax][columna+sumay]==micaracter){
            flag=true;
        }
        else{
            flag=sandwichCheck(fila+sumax,columna+sumay,sumax,sumay,micaracter);
        }
    }
    return flag;
}
bool board:: checklimits(unsigned short fila, unsigned short columna, short sumax, short sumay){
    bool flag=true;
    if(fila>filas-1||fila<0){
        if(sumax!=0){
            flag= false;
        }
    }
    if(columna>columnas-1||columna<0){
        if(sumay!=0){
            flag= false;
        }
    }
    return flag;
}

bool board::checklimits2(unsigned short fila,unsigned  short columna, short sumax, short sumay)
{
    bool flag=true;
    if(fila==filas-1||fila==0){
        if(sumax!=0){
            flag= false;
        }
    }
    if(columna==columnas-1||columna==0){
        if(sumay!=0){
            flag= false;
        }
    }
    return flag;
}

char board::getvalue(int fila, int columna){
    return matriz[fila][columna];

}
void board::insert_piece(player jugador){
    int z= 0;
    char colum_aux;
    short columna;
    int fila;
    while (z == 0){
        cout<<"Ingrese la  letra de la columna donde se ubicara la ficha"<<endl;
        cin >> colum_aux;
        columna=validacionentrada1(colum_aux);
        cout<<"ingerese el numero de la fila donde se ubicara la ficha "<<endl;
        cin>>fila;
        fila =validacion_entrada_fila(fila);
        fila--;
        char color = jugador.getpieza();
        if (columna != -1 && fila != -1){
            if (adyacentcelds(fila,columna,color)&&getvalue(fila,columna)!='0'){

                if (sandwichCheck(fila,columna, 0, -1,color)){//arriba{
                    change_color(fila,columna, 0, -1,jugador);
                }
                if(sandwichCheck(fila,columna, 0, 1,color)){//abajo
                    change_color(fila,columna, 0, 1,jugador);
                }
                if(sandwichCheck(fila,columna, -1, 0,color)){//izquierda
                    change_color(fila,columna, -1, 0,jugador);
                }
                if(sandwichCheck(fila,columna, 1, 0,color)){//derecha
                    change_color(fila,columna, 1, 0,jugador);
                }
                if(sandwichCheck(fila,columna, 1, 1,color)){//diagonal derecha abajo
                    change_color(fila,columna, 1, 1,jugador);
                }
                if(sandwichCheck(fila,columna, 1, -1,color)){//diagonal derecha arriba
                    change_color(fila,columna, 1, -1,jugador);
                }
                if (sandwichCheck(fila,columna, -1, -1,color)){//diagonal izquierda arriba
                    change_color(fila,columna, -1, -1,jugador);
                }
                if(sandwichCheck(fila,columna, -1, 1,color)){//diagonal derecha abajo
                    change_color(fila,columna, -1, 1,jugador);
                }

                z=1;
            }
        }
        else{
            cout<<"En la ubicacion ingresada no es posible colocar una ficha"<<endl;
        }
    }
    cant_vacios--;
}
void board::change_color(unsigned short fila, unsigned short columna, short sumax, short sumay,player jugador){
    bool flag=checklimits(fila,columna,sumax,sumay);
    char color_opuesto;
    if (jugador.getpieza()== '*'){
        color_opuesto = '-';
    }
    else{
        color_opuesto= '*';
    }

    matriz[fila][columna]= jugador.getpieza();
    if(flag ){


        if(matriz[fila+sumax][columna+sumay]== color_opuesto){
            matriz[fila+sumax][columna+sumay]= jugador.getpieza();


            change_color(fila+sumax,columna+sumay,sumax,sumay,jugador);
        }
        else if(matriz[fila+sumax][columna+sumay]==jugador.getpieza()){

        }
        else {

        }
    }

}
