//
// Created by Maria Jose Linares on 2019-07-04.
//

#ifndef PROYECTOFINALPOO_RESTAURANT_H
#define PROYECTOFINALPOO_RESTAURANT_H

#include "Objeto.h"
#include "Tipos.h"

class Restaurant: public Objeto {

    TipoString TipodeComida;
    TipoString Especialidad;
public:
    Restaurant(){};
    Restaurant(const TipoString& nombre,TipoCaracter color,TipoEntero posX,TipoEntero posY,const TipoString& Direccion,TipoEntero Calificacion,
               const TipoString& _TipoComida, const TipoString& _Especialidad);
    void Mostrar_Especialidad();
    void Mostrar_TipodeComida();

};


#endif //PROYECTOFINALPOO_RESTAURANT_H
