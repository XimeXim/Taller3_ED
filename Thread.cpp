//
// Created by Ximena on 10-06-2024.
//

#include "Thread.h"


Thread::Thread(Laberinto &lab): laberinto(lab), resuelto(false) {
}

Thread::~Thread() {
}

bool Thread::isResuelto() {
    if (laberinto.getFin() == true) {
        return resuelto = true;
    }
    return resuelto;
}

void Thread::resolverLab(int x, int y, int hilo) {
    switch (hilo) {
        case 1:
            resolverDerechaPrimero(x, y);
            break;
        case 2: resolverAbajoPrimero(x, y);
            break;
        case 3: resolverIzquierdaPrimero(x, y);
            break;
        case 4: resolverArribaPrimero(x, y);
            break;
        default:
            if (!laberinto.movimientoValido(x, y)) {
                break;
            }
    }
}


void Thread::resolverIzquierdaPrimero(int x, int y) {
    if (laberinto.verificarIzquierda()) {
        resolverLab(x, y - 1, 3);
    }
    if (laberinto.verificarAbajo()) {
        resolverLab(x + 1, y, 2);
    }
    if (laberinto.verificarDerecha()) {
        resolverLab(x, y + 1, 1);
    }
    if (laberinto.verificarArriba()) {
        resolverLab(x - 1, y, 4);
    }
}

void Thread::resolverArribaPrimero(int x, int y) {
    if (laberinto.verificarArriba()) {
        resolverLab(x - 1, y, 4);
    }
    if (laberinto.verificarDerecha()) {
        resolverLab(x, y + 1, 1);
    }
    if (laberinto.verificarIzquierda()) {
        resolverLab(x, y - 1, 3);
    }
    if (laberinto.verificarAbajo()) {
        resolverLab(x + 1, y, 2);
    }
}

void Thread::resolverDerechaPrimero(int x, int y) {
    if (laberinto.verificarDerecha()) {
        resolverLab(x, y + 1, 1);
    }
    if (laberinto.verificarAbajo()) {
        resolverLab(x + 1, y, 2);
    }
    if (laberinto.verificarIzquierda()) {
        resolverLab(x, y - 1, 3);
    }
    if (laberinto.verificarArriba()) {
        resolverLab(x - 1, y, 4);
    }
}

void Thread::resolverAbajoPrimero(int x, int y) {
    if (laberinto.verificarAbajo()) {
        resolverLab(x + 1, y, 2);
    }
    if (laberinto.verificarDerecha()) {
        resolverLab(x, y + 1, 1);
    }
    if (laberinto.verificarIzquierda()) {
        resolverLab(x, y - 1, 3);
    }
    if (laberinto.verificarArriba()) {
        resolverLab(x - 1, y, 4);
    }
}

void Thread::comienzaAResolver() {
    // thread para comenzar a resolver desde la posición inicial del laberinto
    threads.emplace_back(&Thread::resolverLab, this, laberinto.getCoordXActual(), laberinto.getCoordYActual(), 1);
    threads.emplace_back(&Thread::resolverLab, this, laberinto.getCoordXActual(), laberinto.getCoordYActual(), 2);
    threads.emplace_back(&Thread::resolverLab, this, laberinto.getCoordXActual(), laberinto.getCoordYActual(), 3);
    threads.emplace_back(&Thread::resolverLab, this, laberinto.getCoordXActual(), laberinto.getCoordYActual(), 4);

    // espera que los threads terminen su ejecución
    for (auto &t: threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}
