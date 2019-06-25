//
// Created by utec on 21/06/19.
//

#ifndef GAME_CONTROLADOR_H
#define GAME_CONTROLADOR_H

#include <limits>

#include "Tierra.h"
#include "Tipos.h"

using namespace std;
template <typename T>
T input(string label) {
    T value;
    cout << label;
    cin >> value;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return value;
}

class Controlador {
    TipoEntero opcion;
    Tierra tierra;
    void imprimirControlador();
    void seleccionarOpcion();
    void agregarObjeto();
    void removerObjeto();
    void dibujarMapa();
public:
    Controlador(): opcion{} {}
    void ejecutar();
};


#endif //GAME_CONTROLADOR_H
