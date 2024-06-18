//
// Created by Ximena on 10-06-2024.
//

#include "Laberinto.h"

Laberinto::Laberinto() {
}

Laberinto::~Laberinto() {
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

void Laberinto::cargarArchivo(string nombreTXT) {
}

void Laberinto::generadorDeLaberinto(int filas, int columnas) {
}

void Laberinto::imprimirLaberinto() {
}

void Laberinto::recorridoPorLaberinto(vector<pair<int, int>> camino) {
}

void Laberinto::resolverLaberinto(Laberinto laberinto) {
}

void Laberinto::encontrarCamino(Laberinto laberinto, int inicioX, int inicioY) {
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








