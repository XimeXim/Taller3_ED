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

bool Laberinto::moverArriba() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[ancho][alto + 1] == espacioVacio && laberinto[ancho][alto + 1] != pared){
        coordYActual = coordYActual + 1;
        return true;
    }
    return false;
}

bool Laberinto::moverAbajo() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[ancho][alto - 1] == espacioVacio && laberinto[ancho][alto - 1] != pared){
        coordYActual = coordYActual - 1;
        return true;
    }
    return false;
}

bool Laberinto::moverDerecha() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[ancho + 1][alto] == espacioVacio && laberinto[ancho + 1][alto] != pared){
        coordXActual = coordXActual + 1;
        return true;
    }
    return false;
}

bool Laberinto::moverIzquierda() {
    char espacioVacio = ' ';
    char pared = '#';
    if (laberinto[ancho - 1][alto] == espacioVacio && laberinto[ancho - 1][alto] != pared){
        coordXActual = coordXActual - 1;
        return true;
    }
    return false;
}




