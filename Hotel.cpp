//
// Created by Maria Jose Linares on 2019-07-04.
//

#include "Hotel.h"
#include <iostream>
using namespace std;


void Hotel::mostrar_disponibilidad() {
    cout<<"Disponibilidad"<<Disponibilidad<<endl;
}

Hotel::Hotel(const TipoString &nombre, TipoCaracter color, TipoEntero posX, TipoEntero posY,
             const TipoString &Direccion, TipoEntero Calificacion, TipoEntero _Estrellas,
             const TipoString &_Disponibilidad):Objeto(nombre,color,posX,posY,Direccion,Calificacion) {
    Disponibilidad=_Disponibilidad;
    Estrellas=_Estrellas;
}

void Hotel::mostrar_Estrellas() {
    cout<<"Estrellas"<<Estrellas<<endl;
}