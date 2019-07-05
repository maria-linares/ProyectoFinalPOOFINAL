//
// Created by utec on 21/06/19.
//

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
enum class Opciones {
    Agregar = 1, Remover, Mostrar, Ubicar1,Ubicar2,Ubicar3

}; // se usa un tipo enumerado para indicar las opciones


/*
 ********
 *
 * Funciones de Ayuda
 *
 ********
 */

void limpiar() {
#ifndef WIN32
    cout << "\033[2J\033[0;0H";
#else
    system("cls");
#endif
}

void esperar() {
    TipoCaracter w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    } while (toupper(w) != 'C');
}



Menu::Menu(int altura, int ancho): tierra(altura, ancho), opcion{} {}

void Menu::agregarObjeto() {
    auto tipo = input<TipoCaracter >("Ingrese Tipo de Establecimiento (H=Hotel, R=Restaurante, M=Museo): ");
    auto nombre = input<TipoString>("Ingrese Nombre del establecimiento : ");
    auto direccion = input<TipoString>("Ingrese la Direccion del Establecimiento : ");
    auto calificacion = input<TipoEntero >("Ingrese la Calificacion del Establecimiento (1-5): ");

    auto x = input<TipoEntero>("Ingrese posicion X : ");
    while (x < 0 || x >= tierra.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0,400 "
             << tierra.getAncho() - 1 << "\n";
        x = input<TipoEntero>("Ingrese posicion X : ");
    }

    auto y = input<TipoEntero>("Ingrese posicion Y : ");
    while (y < 0 || y >= tierra.getAncho()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0,600 "
              << tierra.getAltura() - 1 << "\n";
        y = input<TipoEntero>("Ingrese posicion Y : ");
    }
    if(tipo == 'H'){
        auto estrellas = input<TipoEntero >("Ingrese la Cantidad de Estrellas del Hotel (1-7): ");
        auto disponibilidad = input<TipoString >("Ingrese la Disponibilidad del Hotel: ");
        tierra.adicionarObjeto(new Hotel(nombre,'R', x, y,direccion,calificacion,estrellas,disponibilidad));

    }else if(tipo == 'R'){
        auto tipocomida = input<TipoString >("Ingrese el Tipo de Comida que se Sirve: ");
        auto especialidad = input<TipoString >("Ingrese la Especialidad del Restaurant): ");
        tierra.adicionarObjeto(new Restaurant(nombre,'G',x,y,direccion,calificacion,
                                              tipocomida, especialidad));
    }else if(tipo == 'M'){
        auto exposicion = input<TipoString >("Ingrese la Exposicion que se Exhibe en este momento: ");
        tierra.adicionarObjeto(new Museo(nombre,'B',x,y,direccion,calificacion,
                                         exposicion));
    }

}

void Menu::removerObjeto() {

    auto nombre = input<TipoString>("Ingrese Nombre del Establecimiento qu desea remover: ");

    auto obj = tierra.removerObjeto(nombre);  //-- separa el objeto de la tierra
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    esperar();

}

void Menu::dibujarMapa() {
    limpiar();
    tierra.dibujarTierra();
}

void Menu::mostrarMenu() {
    limpiar();
    cout << "Menu\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Mostrar todos los objetos\n";
    cout << "4. Ubicar los tres lugares mas cerca del punto\n";
    cout << "5. Ubicar los 3 mejores lugares por tipo\n";
    cout << "6. Ubicar los 3 lugares con mayor calificacion\n";
    cout << "0. Para Salir\n\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case Opciones::Ubicar1: // Ubica los tres lugares más cerca a un punto dado
            ubicarpunto();
            break;
        case Opciones::Ubicar2: //Ubica al hotel, museo y restaurante de mayor calificación
            ubicarmejores();
            break;
        case Opciones::Ubicar3: //Ubica a los tres establecimientos con mejor calificación
            ubicarmascalif();
            break;
    }
}

void Menu::ejecutar() {
    do {
        mostrarMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::ubicarpunto() {
    cout<<"Ingrese su Ubicacion Actual"<<endl;
    auto x = input<TipoEntero >("Ingrese posicion X : ");
    while (x < 0 || x >= tierra.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0,400 "
             << tierra.getAncho() - 1 << "\n";
        x = input<TipoEntero>("Ingrese posicion X : ");
    }
    auto y = input<TipoEntero>("Ingrese posicion Y : ");
    while (y < 0 || y >= tierra.getAltura()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0,600 "
              << tierra.getAltura() - 1 << "\n";
        y = input<TipoEntero>("Ingrese posicion Y : ");
    }
    tierra.MasCerca(x,y);
}

void Menu::ubicarmejores() {
    tierra.UbicarMejoresTipos();
}

void Menu::ubicarmascalif() {
    tierra.Ubicar3max();

}