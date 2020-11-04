#include <iostream>
#include "laboratorio.h"

using namespace std;

int main(){

    Laboratorio lab;
    string op;

    while ( true ){

        cout << "0) Salir" << endl;
        cout << "1) Agregar Computadora" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Buscar" << endl;
        getline( cin,op );
        if ( op == "0" ){
            break;
        }
        else if ( op == "1" ){

            Computadora c;
            cin >> c;

            lab.agregarFinal(c);
            cin.ignore();

        }
        else if ( op == "2" ){

            lab.mostrar();

        } 
        else if ( op == "3" ){

            lab.respaldar();

        } 
        else if ( op == "4" ){

            lab.recuperar();

        }
        else if ( op == "5" ){

            Computadora c;
            cin >> c;

            size_t p;
            cout << "Posición: ";
            cin >> p; cin.ignore();
            if ( p >= lab.size() ){
                cout << "Posición no válida" << endl;
            } else {
                lab.insertar( c, p );
            }

        }
        else if ( op == "6" ){

            Computadora c;
            cin >> c;

            size_t n;
            cout << "N: ";
            cin >> n; cin.ignore();

            lab.inicializar( c,n );

        }
        else if ( op == "7" ){

            size_t p;
            cout << "Posición: ";
            cin >> p; cin.ignore();
            if ( p >= lab.size() ){
                cout << "Posición no válida" << endl;
            } else {
                lab.eliminar(p);
            }

        }
        else if ( op == "8" ){
            lab.ordenar();            
        }
        else if ( op == "9" ){

            Computadora c;
            cin >> c;  cin.ignore();
            Computadora *ptr = lab.buscar( c );

            if ( ptr == nullptr ){
                cout << "No encontrado" << endl;
            } else {
                cout << *ptr <<  endl;
            }

        } else {
            cout << "Opción no válida, intenta de nuevo" << endl; 
        }
    }

    return 0;

}

