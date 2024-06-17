//
// Created by Ximena on 10-06-2024.
//

#include "Laberinto.h"

Laberinto::Laberinto() {
}

Laberinto::~Laberinto() {
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

void Laberinto::espacioLab(char** laberinto, int alto, int ancho) {

    laberinto = new char * [ancho];
    for (int i = 0; i < ancho; ++i) {
        laberinto[i] = new char [alto];
    }
}

bool Laberinto::moverArriba(char **laberinto) {


    //for (int i = 0; i < ancho; i++) {
        //for (int j = 0; j < alto; j++) {

        //}

    //}
}
