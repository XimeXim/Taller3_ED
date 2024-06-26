//
// Created by Ximena on 10-06-2024.
//

#include "Sistema.h"
#include <iostream>
#include <string>

#include "Laberinto.h"
#include "Thread.h"


Sistema::Sistema() {
}

Sistema::~Sistema() {
}

void Sistema::Menu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Resolver laberinto" << std::endl;
    std::cout << "2. Salir" << std::endl;
    std::cout << "Seleccione una opcion: " << std::endl;
}

void Sistema::Iniciar() {
    int opcionSeleccionada;
    while (true) {
        Menu();
        std::cin >> opcionSeleccionada;
        if (opcionSeleccionada == 1) {
            std::string direccionArchivo;
            std::cout << "Favor de ingresar una direccion donde se encuentra el archivo del laberinto: " << std::endl;
            std::cin >> direccionArchivo;
            Laberinto lab(direccionArchivo);
            Thread thread(lab);
            thread.comienzaAResolver();
            srand(time(nullptr));
            if (thread.isResuelto()) {
                std::cout << std::endl;
                std::cout << "Enhorabuena chaval! El laberinto si tiene solucion." << std::endl;
                std::cout << std::endl;
                lab.imprimirLaberinto();
                std::cout << std::endl;
            } else {
                std::cout << std::endl;
                std::cout << "Pamplinas... este laberinto no tiene solucion amigo :(" << std::endl;
                std::cout << std::endl;
            }
        } else if (opcionSeleccionada == 2) {
            std::cout << "Saliendo... tu te lo pierdes >:(" << std::endl;
            break;
        } else {
            std::cout << "Lo lamento pero parece que esta opcion no es valida, ponga el numero 1 o 2 plis" << std::endl;
        }
    }
}
