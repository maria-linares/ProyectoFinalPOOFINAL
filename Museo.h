//
// Created by Maria Jose Linares on 2019-07-04.
//

#ifndef PROYECTOFINALPOO_MUSEO_H
#define PROYECTOFINALPOO_MUSEO_H

#include "Tipos.h"
#include "Objeto.h"

class Museo: public Objeto {
    TipoString Exposicion;
public:
    Museo(){};
    Museo(const TipoString& nombre, TipoCaracter color,
          TipoEntero posX, TipoEntero posY, const TipoString& Direccion, TipoEntero Calificacion,const TipoString& _Exposicion);
    void mostrar_Exposicion();


};



#endif //PROYECTOFINALPOO_MUSEO_H
