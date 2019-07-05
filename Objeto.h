//
// Created by utec on 21/06/19.
//

#ifndef GAME_OBJETO_H
#define GAME_OBJETO_H

#include "Tipos.h"

class Objeto {
private:
    string        nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoString Direccion;
    TipoEntero Calificacion;
public:
    Objeto(){};
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY, const TipoString& Direccion, TipoEntero Calificacion);
    virtual ~Objeto(){};
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    char getColor();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
    string mostrarDireccion();
    int getCalificacion();
};



#endif //GAME_OBJETO_H