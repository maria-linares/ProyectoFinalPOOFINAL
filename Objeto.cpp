//
// Created by utec on 21/06/19.
//

#include "Objeto.h"
#include "Tierra.h"

Objeto::Objeto(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY,const TipoString& Direccion, TipoEntero Calificacion){
    this->nombre=nombre;
    this->color=color;
    this->posX=posX;
    this->posY=posY;
    this->Direccion=Direccion;
    this->Calificacion=Calificacion;

}


void Objeto::setNombre(const TipoString& nombre) { this->nombre = nombre; }
void Objeto::moverse(TipoEntero x, TipoEntero y) {} //--  por implementar

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoCaracter Objeto::getColor()  { return color; }

TipoString Objeto::mostrarPosicion() {
    return "X = " + to_string(posX) + " Y = " + to_string(posY);
}

string Objeto::mostrarDireccion() {
    return Direccion;
}

int Objeto::getCalificacion() {
    return Calificacion;
}