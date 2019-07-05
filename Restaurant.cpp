//
// Created by Maria Jose Linares on 2019-07-04.
//

#include "Restaurant.h"
#include <iostream>
using namespace std;
Restaurant::Restaurant(const TipoString& nombre,TipoCaracter color,TipoEntero posX,TipoEntero posY,const TipoString& Direccion,TipoEntero Calificacion,
                       const TipoString& _TipodeComida, const TipoString& _Especialidad):Objeto(nombre,color,posX,posY,Direccion,Calificacion) {

    TipodeComida = _TipodeComida;
    Especialidad = _Especialidad;
}

void Restaurant::Mostrar_Especialidad(){
    cout<<"Especialidad"<<Especialidad<<endl;

}
void Restaurant::Mostrar_TipodeComida() {
    cout<<"Tipo de comida"<<TipodeComida<<endl;
}