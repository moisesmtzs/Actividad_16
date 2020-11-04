#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <vector>

class Laboratorio{

    vector<Computadora> computadoras;

public:
    Laboratorio();
    void agregarFinal( const Computadora &c );
    void mostrar();
    void respaldar();
    void recuperar();

    void insertar( const Computadora &c, size_t p );
    size_t size();
    void inicializar( const Computadora &c, size_t n );
    void eliminar( size_t p );
    void ordenar();
    Computadora* buscar( const Computadora &c );

    friend Laboratorio& operator<<( Laboratorio &l, const Computadora &c ){

        l.agregarFinal(c);
        return l;
    }
};

#endif