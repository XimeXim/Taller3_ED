//
// Created by Ximena on 10-06-2024.
//

#include "Thread.h"


Thread::Thread(Laberinto &lab): laberinto(lab),resuelto(false) {
}

Thread::~Thread() {
    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}

bool Thread::isResuelto() {
    return resuelto;
}

bool Thread::resolverLab(int x, int y) {
    if (resuelto) return false;
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (resuelto) return false;
    }

    if (!laberinto.movimientoValido(x, y)) return false;

    laberinto.marcarCamino(x, y);

    if (laberinto.testExitUp() || laberinto.testExitDown() || laberinto.testExitRight() || laberinto.testExitLeft()) {
        std::lock_guard<std::mutex> lock(mtx);
        resuelto = true;
        return true;
    }

    if (laberinto.verificarRight()) {
        threads.emplace_back(&Thread::resolverLab, this, x + 1, y);
    }
    if (laberinto.verificarDown()) {
        threads.emplace_back(&Thread::resolverLab, this, x, y - 1);
    }
    if (laberinto.verificarLeft()) {
        threads.emplace_back(&Thread::resolverLab, this, x - 1, y);
    }
    if (laberinto.verificarUp()) {
        threads.emplace_back(&Thread::resolverLab, this, x, y + 1);
    }

    // Unir los hilos creados
    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    if (!resuelto) {
        laberinto.desmarcarCamino(x, y);
    }

    return resuelto;
}


void Thread::comienzaAResolver() {
    threads.emplace_back(&Thread::resolverLab, this, laberinto.getCoordXActual(), laberinto.getCoordYActual());

    // Unir el hilo inicial
    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    if (resuelto) {
        laberinto.imprimirLaberintoResuelto(); // Marcar el camino encontrado
    } else {
        std::cout << "Pamplinas... este laberinto no tiene solucion amigo :(" << std::endl;
        laberinto.imprimirLaberinto();
    }
}
