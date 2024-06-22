//
// Created by Ximena on 10-06-2024.
//

#include "Laberinto.h"


Laberinto::Laberinto(std::string direccionArchivo) {
    ifstream archivo(direccionArchivo);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo en esta direccion: " << direccionArchivo << std::endl;
        exit(1);
    }
    std::string linea;
    std::getline(archivo, linea);
    ancho = linea.size();
    alto = 1;

    while (std::getline(archivo, linea)) {
        ++alto;
    }

    archivo.clear(); // Limpiamos el estado del archivo
    archivo.seekg(0, ios::beg); // Reiniciamos la posición de lectura

    laberinto = new char *[alto];
    for (int i = 0; i < alto; ++i) {
        laberinto[i] = new char[ancho];
        std::getline(archivo, linea);
        std::copy(linea.begin(), linea.end(), laberinto[i]);
    }

    archivo.close();
    std::cout << "Wow! Un desafio! Permiteme ver si puedo resolverlo!" << std::endl;
    std::cout << std::endl;
    imprimirLaberinto();

    encontrarCamino();
}

Laberinto::~Laberinto() {
    for (int i = 0; i < alto; i++) {
        delete[]laberinto[i];
    }
    delete[]laberinto;
}

bool Laberinto::getFin() const {
    return fin;
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

bool Laberinto::get_salida_existe() const {
    return salidaExiste;
}

void Laberinto::imprimirLaberinto() {
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            cout << laberinto[i][j];
        }
        cout << endl;
    }
}

void Laberinto::imprimirLaberintoConRecorrido(int x, int y) {
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            if (i == x && j == y) {
                marcarCamino(i, j);
            } else {
                cout << laberinto[i][j];
            }
        }
        cout << endl;
    }
}

void Laberinto::encontrarCamino() {
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (laberinto[i][j] == 'S') {
                inicioX = i;
                inicioY = j;
                coordXActual = i;
                coordYActual = j;
            } else if (laberinto[i][j] == 'E') {
                salidaExiste = true;
                finalX = i;
                finalY = j;
            }
        }
    }
}

void Laberinto::espacioLab() {
    laberinto = new char *[ancho];
    for (int i = 0; i < ancho; ++i) {
        laberinto[i] = new char [alto];
    }
}

bool Laberinto::verificarArriba() {
    char espacioVacio = ' ';
    if (laberinto[coordXActual - 1][coordYActual] == espacioVacio) {
        moverArriba();
        marcarCamino(coordXActual, coordYActual);
        return true;
    } else if (laberinto[coordXActual - 1][coordYActual] == 'E') {
        fin = true;
    }
    return false;
}

bool Laberinto::verificarAbajo() {
    char espacioVacio = ' ';
    if (laberinto[coordXActual + 1][coordYActual] == espacioVacio) {
        moverAbajo();
        marcarCamino(coordXActual, coordYActual);
        return true;
    } else if (laberinto[coordXActual + 1][coordYActual] == 'E') {
        fin = true;
    }
    return false;
}

bool Laberinto::verificarDerecha() {
    char espacioVacio = ' ';
    if (laberinto[coordXActual][coordYActual + 1] == espacioVacio) {
        moverDerecha();
        marcarCamino(coordXActual, coordYActual);
        return true;
    } else if (laberinto[coordXActual][coordYActual + 1] == 'E') {
        fin = true;
    }
    return false;
}

bool Laberinto::verificarIzquierda() {
    char espacioVacio = ' ';
    if (laberinto[coordXActual][coordYActual - 1] == espacioVacio) {
        moverIzquierda();
        marcarCamino(coordXActual, coordYActual);
        return true;
    } else if (laberinto[coordXActual][coordYActual - 1] == 'E') {
        fin = true;
    }
    return false;
}

bool Laberinto::movimientoValido(int x, int y) {
    if (x >= 0 && x < alto && y >= 0 && y < ancho) {
        return laberinto[x][y] == ' ' || laberinto[x][y] == 'E';
    }
    return false;
}


int Laberinto::moverArriba() {
    return coordXActual -= 1;
}

int Laberinto::moverAbajo() {
    return coordXActual += 1;
}

int Laberinto::moverDerecha() {
    return coordYActual += 1;
}

int Laberinto::moverIzquierda() {
    return coordYActual -= 1;
}

void Laberinto::marcarCamino(int x, int y) {
    laberinto[x][y] = 'X';
}


//C:/Users/Ximena/Downloads/laberintoEjemplo.txt
//C:/Users/Ximena/Downloads/laberintoEjemploMALO.txt
