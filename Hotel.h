//
// Created by Maria Jose Linares on 2019-07-04.
//

#ifndef PROYECTOFINALPOO_HOTEL_H
#define PROYECTOFINALPOO_HOTEL_H


#include "Objeto.h"
#include "Tipos.h"


class Hotel: public Objeto{

    TipoEntero Estrellas;
    TipoString Disponibilidad;
public:
    Hotel(){};
    Hotel(const TipoString& nombre, TipoCaracter color,
          TipoEntero posX, TipoEntero posY, const TipoString& Direccion,
          TipoEntero Calificacion, TipoEntero _Estrellas, const TipoString& _Disponibilidad);
    void mostrar_disponibilidad();
    void mostrar_Estrellas();
};


#endif //PROYECTOFINALPOO_HOTEL_H
