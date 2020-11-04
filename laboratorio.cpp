#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio(){


}

void Laboratorio::agregarFinal( const Computadora &c ){

    computadoras.push_back(c);

}

void Laboratorio::mostrar(){
    cout << endl;
    cout << left;
    cout << setw(10) << "Sistema";
    cout << setw(10) << "RAM";
    cout << setw(10) << "Marca";
    cout << setw(10) << "Bateria";
    cout<<endl<<"Operativo"<<endl;
    cout << endl;
    for ( size_t i = 0 ; i < computadoras.size() ; i++ ){

        Computadora &c = computadoras[i];
        cout<<c;
        cout<<endl;

    }
}

void Laboratorio::respaldar(){

    ofstream archivo("computadoras.txt");
    if ( archivo.is_open() ){
        for ( size_t i = 0 ; i < computadoras.size() ; i++ ){
            Computadora &c = computadoras[i];
            archivo << c.getSo()<<endl;
            archivo << c.getRam()<<endl;
            archivo << c.getMarca()<<endl;
            archivo << c.getBateria()<<endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar(){

    ifstream archivo("computadoras.txt");
    if ( archivo.is_open() ){
        string temp;
        float bateria;
        int ram;
        Computadora c;
        while ( true ){

            getline(archivo,temp);
            if ( archivo.eof() ){
                break;
            }
            c.setSo(temp);

            getline(archivo,temp);
            ram = stoi(temp);
            c.setRam(ram);

            getline(archivo,temp);
            c.setMarca(temp);
            
            getline(archivo,temp);
            bateria = stof(temp);
            c.setBateria(bateria);

            agregarFinal(c);

        }
    }
    archivo.close();
}

void Laboratorio::insertar( const Computadora &c, size_t p ){

    computadoras.insert(computadoras.begin()+p, c);

}

size_t Laboratorio::size(){

    return computadoras.size();
}

void Laboratorio::inicializar( const Computadora &c, size_t n ){

    computadoras = vector<Computadora>( n,c );   

}

void Laboratorio::eliminar( size_t p ){

    computadoras.erase(computadoras.begin()+p);

}

void Laboratorio::ordenar(){

    sort( computadoras.begin(), computadoras.end() );   

}

Computadora* Laboratorio::buscar( const Computadora &c ){

    auto it = find( computadoras.begin(), computadoras.end(), c );

    if ( it == computadoras.end() ){
        return nullptr;
    } else {

        return &(*it);

    }

}