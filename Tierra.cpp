//
// Created by utec on 21/06/19.
//
#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include "Objeto.h"

using namespace std;
Tierra::Tierra() {
    plano.resize(ALTURA);
    for (auto& item: plano)
        item.resize(ANCHO);
}
Tierra::Tierra(TipoEntero altura, TipoEntero ancho) {
    plano.resize(altura);
    for (auto& item: plano)
        item.resize(ancho);
}
Tierra::~Tierra() {}
void Tierra::adicionarObjeto(Objeto* objeto) {
    objetos.emplace_back(objeto);
}
Objeto* Tierra::removerObjeto(string& nombre) {
// Si vector esta vacio
    if (objetos.size() == 0)
        return nullptr;
// Buscando objeto
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter != end(objetos)) {
// Eliminando la referencia al puntero objeto dentro del vector objetos
        objetos.erase(iter);
//-- si encuentra al objeto lo separa del vector,
//-- (no libera de memoria el objeto encontrado), esto se hará en el menú,
//-- donde fue asignado, debido a que el objeto no es parte sino el objeto es un visitante.
        return *iter;
    }
// Si vector esta vacio
    return nullptr;
}
void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto& item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}
void Tierra::actualizarTierra() {
    for (auto &row: plano)
        for (auto &cell: row)
            cell = COLOR;
    for (auto& item: objetos)
        plano[item->getPosX()][item->getPosY()]
                = item->getColor();
}
void Tierra::dibujarTierra() {
    cout << '\n';
    cout << setw(3) << ' ';
    for (auto j = 0; j < getAncho(); ++j)
        cout << setw(3) << j;
    cout << '\n';
    for (auto i = 0; i < getAltura(); ++i) {
        cout << setw(3) << i;
        for (auto j = 0; j < getAncho(); ++j) {
            cout << setw(3) << plano[i][j];
        }
        cout << '\n';
    }
}
TipoEntero Tierra::getAltura() {
    return plano.size();
}
TipoEntero Tierra::getAncho(){
    return plano[0].size();
}

TipoEntero Tierra::getCantidadObjectos() {
    return objetos.size();
}
