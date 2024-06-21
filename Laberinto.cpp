//
// Created by Ximena on 10-06-2024.
//

#include "Laberinto.h"


Laberinto::Laberinto(std::string direccionArchivo) {
    ifstream archivo(direccionArchivo);
    if(!archivo) {
        std::cout<<"No se pudo abrir el archivo en esta direccion: "<< direccionArchivo<<std::endl;
        return;
    }
    std::string lineas;
    while(getline(archivo,lineas)) {
        if(ancho==0) {
            ancho=lineas.size();
        }
        alto++;
    }
    archivo.close();

    archivo.open(direccionArchivo);
    laberinto = new char *[alto];

   for(int i=0;i<alto;i++) {
       laberinto[i]=new char[ancho];
   }
    while(getline(archivo,lineas)) {
        for (int i=0; i<alto;i++) {
            for(int j=0;j<ancho;ancho++) {
                laberinto[i][j]=lineas[j];
            }
        }
    }
    archivo.close();
    encontrarCamino();
}

Laberinto::~Laberinto() {
    for(int i=0;i<alto;i++) {
        delete[]laberinto[i];
    }
    delete[]laberinto;
}

int Laberinto::getCoordXActual() const {
    return coordXActual;
}

void Laberinto::setCoordXActual(int coordXActual) {
    Laberinto::coordXActual = coordXActual;
}

int Laberinto::getCoordYActual() const {
    return coordYActual;
}

void Laberinto::setCoordYActual(int coordYActual) {
    Laberinto::coordYActual = coordYActual;
}


void Laberinto::imprimirLaberinto() {
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            cout << laberinto[i][j];
        }
        cout << endl;
    }

}

void Laberinto::encontrarCamino() {
    for(int i=0;i<alto;i++) {
        for (int j=0;j<ancho;j++) {
            if (laberinto[i][j]== 'S') {
                inicioX=i;
                inicioY=j;
                coordXActual=i;
                coordYActual=j;
            }else if(laberinto[i][j]=='E') {
                finalX=i;
                finalY=j;
            }
        }
    }
}

void Laberinto::espacioLab() {

    laberinto = new char * [ancho];
    for (int i = 0; i < ancho; ++i) {
        laberinto[i] = new char [alto];
    }
}

bool Laberinto::verificarUp() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[coordXActual][coordYActual + 1] == espacioVacio && laberinto[coordXActual][coordYActual + 1] != pared){
        return true;
    }
    return false;
}

bool Laberinto::verificarDown() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[coordXActual][coordYActual - 1] == espacioVacio && laberinto[coordXActual][coordYActual - 1] != pared){
        return true;
    }
    return false;
}

bool Laberinto::verificarRight() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[coordXActual + 1][coordYActual] == espacioVacio && laberinto[coordXActual + 1][coordYActual] != pared){
        return true;
    }
    return false;
}

bool Laberinto::verificarLeft() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[coordXActual - 1][coordYActual] == espacioVacio && laberinto[coordXActual - 1][coordYActual] != pared){
        return true;
    }
    return false;
}

void Laberinto::moverArriba() {
    if (verificarUp()){
        setCoordYActual(coordYActual + 1);
    }
}

void Laberinto::moverAbajo() {
    if (verificarDown()){
        setCoordYActual(coordYActual - 1);
    }
}

void Laberinto::moverDerecha() {
    if (verificarRight()){
        setCoordXActual(coordXActual + 1);
    }
}

void Laberinto::moverIzquierda() {
    if (verificarLeft()){
        setCoordXActual(coordXActual - 1);
    }
}

bool Laberinto::noExitUp() {
    char pared = '#';
    if (laberinto[coordXActual][coordYActual + 1] == pared && laberinto[coordXActual - 1][coordYActual] == pared && laberinto[coordXActual + 1][coordYActual] == pared){
        return true;
    }
    return false;
}

bool Laberinto::noExitDown() {
    char pared = '#';
    if (laberinto[coordXActual][coordYActual - 1] == pared && laberinto[coordXActual - 1][coordYActual] == pared && laberinto[coordXActual + 1][coordYActual] == pared){
        return true;
    }
    return false;
}

bool Laberinto::noExitRight() {
    char pared = '#';
    if (laberinto[coordXActual + 1][coordYActual] == pared && laberinto[coordXActual][coordYActual + 1] == pared && laberinto[coordXActual][coordYActual - 1] == pared){
        return true;
    }
    return false;
}

bool Laberinto::noExitLeft() {
    char pared = '#';
    if (laberinto[coordXActual - 1][coordYActual] == pared && laberinto[coordXActual][coordYActual + 1] == pared && laberinto[coordXActual][coordYActual - 1] == pared){
        return true;
    }
    return false;
}

bool Laberinto::testExitUp() {
    char salida = 'E';
    if (laberinto[coordXActual][coordYActual + 1] == salida){
        setCoordYActual(coordYActual + 1);
        return true;
    }
    return false;
}

bool Laberinto::testExitDown() {
    char salida = 'E';
    if (laberinto[coordXActual][coordYActual - 1] == salida){
        setCoordYActual(coordYActual - 1);
        return true;
    }
    return false;
}

bool Laberinto::testExitRight() {
    char salida = 'E';
    if (laberinto[coordXActual + 1][coordYActual] == salida){
        setCoordXActual(coordXActual + 1);
        return true;
    }
    return false;
}

bool Laberinto::testExitLeft() {
    char salida = 'E';
    if (laberinto[coordXActual - 1][coordYActual] == salida){
        setCoordXActual(coordXActual - 1);
        return true;
    }
    return false;
}

void Laberinto::marcarCamino(int x, int y) {
    laberinto[x][y]='/';
}

bool Laberinto::movimientoValido(int x, int y) {
    if (x >= 0 && x < alto && y >= 0 && y < ancho) {
        if (laberinto[x][y] == ' ' || laberinto[x][y] == 'E') {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Laberinto::salidaEncontrada(int x, int y) {
    return laberinto[x][y]='E';
}








