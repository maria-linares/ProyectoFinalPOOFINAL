//
// Created by utec on 21/06/19.
//

#include <cmath>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
#include "Tierra.h"



map<char, sf::Color> listaColores = {
        {'R', sf::Color::Red},
        {'G', sf::Color::Green},
        {'B', sf::Color::Blue}};


using namespace std;

Tierra::Tierra() : altura{}, ancho{} {
    plano = nullptr;
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) : altura{altura}, ancho{ancho} {
    plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
    delete plano;
}

void Tierra::adicionarObjeto(Objeto *objeto) {
    objetos.emplace_back(objeto);
}

Objeto *Tierra::removerObjeto(string &nombre) {
// Si vector esta vacio
    if (objetos.size() == 0)
        return nullptr;
// Buscando objeto
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto *obj) { return obj->getNombre() == nombre; });
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
    for (auto &item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}

void Tierra::actualizarTierra() {
    plano->clear();
    for (auto obj: objetos) {
        sf::CircleShape shape(10);
        shape.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
        shape.setFillColor(listaColores[obj->getColor()]);
        plano->draw(shape);
    }
    plano->display();
}
void Tierra::dibujarTierra() {

    // Verifica si plano ha sido creado anteriormente
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final - Presione [ESC] para salir... ");
    else
        plano->display();

    // Bucle principal
    while (plano->isOpen()) {
        capturarEventos();
        actualizarTierra();
    }
}

TipoEntero Tierra::getAltura() {
    return altura;
}

TipoEntero Tierra::getAncho() {
    return ancho;
}

TipoEntero Tierra::getCantidadObjectos() {
    return objetos.size();
}

void Tierra::capturarEventos() {
    sf::Event event{};

    while (plano->pollEvent(event)) {

        switch (event.type) {
            case sf::Event::Closed:
                plano->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    plano->close();
                break;
        }
    }
}

void Tierra::MasCerca(TipoEntero x, TipoEntero y) {
    vector<TipoDouble> aux1;
    vector<TipoString> aux2;
    for(Objeto* i:objetos){
        aux1.push_back(sqrt(((i->getPosX())^2)*((i->getPosY())^2)));
        aux2.push_back(i->getNombre());
    }
    float temporal;
    string temp;

    for (int i = 0;i < aux1.size(); i++){
        for (int j = 0; j< aux1.size()-1; j++){
            if (aux1[j] > aux1[j+1]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                temporal = aux1[j];
                temp=aux2[j];
                aux1[j] = aux1[j+1];
                aux2[j]=aux2[j+1];
                aux1[j+1] = temporal;
                aux2[j+1]=temp;
            }
        }
    }
    for (int i = 0;  (i<aux1.size()) && (i<3); ++i) {
        cout<<aux2[i]<<" a "<<aux1[i]<<" metros"<<endl;
    }
    cout<<endl;


}

void Tierra::UbicarMejoresTipos() {
    TipoEntero ah=0,ar=0,am=0;
    TipoString bh,br,bm;
    for (Objeto *tipo:objetos) {
        if (tipo->getColor() == 'R'){
            if(ah<tipo->getCalificacion()) {
                ah = tipo->getCalificacion();
                bh=tipo->getNombre();
            }
        }
        else if(tipo->getColor() == 'G'){
            if(ar<tipo->getCalificacion()) {
                ar = tipo->getCalificacion();
                br=tipo->getNombre();
            }
        }
        else if(tipo->getColor() == 'B'){
            if(am<tipo->getCalificacion()) {
                am = tipo->getCalificacion();
                bm=tipo->getNombre();
            }
        }
    }
    cout<<"Los Establecimientos por Tipo Mejor Valorados son: "<<endl;
    cout<<"Hotel: "<<bh<<endl;
    cout<<"Restaurant: "<<br<<endl;
    cout<<"Museo: "<<bm<<endl;
}

void Tierra::Ubicar3max() {
    vector<TipoEntero > aux1;
    vector<TipoString> aux2;
    for (Objeto *i:objetos) {
        aux1.push_back(i->getCalificacion());
        aux2.push_back(i->getNombre());
    }
    TipoEntero temporal;
    TipoString temp;

    for (int i = 0; i < aux1.size(); i++) {
        for (int j = 0; j < aux1.size() - 1; j++) {
            if (aux1[j] < aux1[j + 1]) { // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                temporal = aux1[j];
                temp = aux2[j];
                aux1[j] = aux1[j + 1];
                aux2[j] = aux2[j + 1];
                aux1[j + 1] = temporal;
                aux2[j + 1] = temp;
            }
        }
    }
    for (int i = 0; (i < aux1.size()) && (i < 3); ++i) {
        cout << aux2[i] << " tiene " << aux1[i] << " de calificacion" << endl;
    }
    cout << endl;
}

