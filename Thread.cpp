//
// Created by Ximena on 10-06-2024.
//

#include "Thread.h"


Thread::Thread(Laberinto &lab): laberinto(lab),resuelto(false) {
}

Thread::~Thread() {
}

bool Thread::isResuelto() {
    return resuelto;
}

void Thread::resolverLab(int x, int y) {
    if (resuelto) return;
    std::lock_guard<std::mutex> lock(mtx);
    if (resuelto) return;
    // Verifica si la posición actual es la salida y si es asi el laberinto esta resuelto
    if (laberinto.salidaEncontrada(x, y)) {
        resuelto = true;
        laberinto.imprimirLaberinto();
        std::cout << "Enhorabuena chaval! El laberinto ha sioh resuelto, joder!" << std::endl;
        return;
    }
    // Si la posición actual no es una por la que se mover no hace nada
    if (!laberinto.movimientoValido(x, y)) {
        return;
    }
    // Marca la posición en el camino segun su posicion actual
    laberinto.marcarCamino(x, y);

    if (laberinto.verificarRight()) {
        threads.emplace_back(&Thread::resolverLab, this, x, y + 1);
    }
    if (laberinto.verificarDown()) {
        threads.emplace_back(&Thread::resolverLab, this, x + 1, y);
    }
    if (laberinto.verificarLeft()) {
        threads.emplace_back(&Thread::resolverLab, this, x, y - 1);
    }
    if (laberinto.verificarUp()) {
        threads.emplace_back(&Thread::resolverLab, this, x - 1, y);
    }
}

void Thread::comienzaAResolver() {
    // thread para comenzar a resolver desde la posición inicial del laberinto
    threads.emplace_back(&Thread::resolverLab, this, laberinto.getCoordXActual(), laberinto.getCoordYActual());

    // espera que los threads terminen su ejecución
    for (int i = 0; i < static_cast<int>(threads.size()); ++i) {
        auto& t = threads[i];
        if (t.joinable()) {
            t.join();
        }
    }
    // No encontró una solución, imprime aviso
    if (!resuelto) {
        std::cout << "Pamplinas... este laberinto no tiene solucion amigo :(" << std::endl;
        laberinto.imprimirLaberinto();
    }
}
