//
// Created by Maria Jose Linares on 2019-07-04.
//

#include "Museo.h"
#include <iostream>
using namespace std;

Museo::Museo(const TipoString& nombre, TipoCaracter color,
             TipoEntero posX, TipoEntero posY, const TipoString& Direccion,
             TipoEntero Calificacion,const TipoString& _Exposicion):Objeto(nombre,color,posX,posY,Direccion,Calificacion) {

    Exposicion = _Exposicion;
}

void Museo::mostrar_Exposicion() {
    cout<<"Exposicion Acutal"<<Exposicion<<endl;
}