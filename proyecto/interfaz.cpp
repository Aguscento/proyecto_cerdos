#include<iostream>
#include "Interfaz.h"

using namespace std;

void juego(string jugador1, string jugador2, int trufasj1, int trufasj2, string turno_de, int i, int lanzamientos) {
    cout << endl << "GRAN CERDO" << endl;
    cout << "_________________________________________________________________________________" << endl;
    cout << jugador1 << ":" << trufasj1 << " trufas acumuladas" << "            " << jugador2 << ":" << trufasj2 << " trufas acumuladas" << endl;
    cout << endl << "TURNO DE " << turno_de << endl;
    cout << "+------------------------+" << endl;
    cout << "| RONDAS #" << i << "              |" << endl;
    cout << "| TRUFAS DE LA RONDA:    |" << endl;
    cout << "| lANZAMIENTOS: " << lanzamientos << "        |" << endl;
    cout << "+------------------------+" << endl;
}

bool consulta(){
    string continuar;
    do {
    cout << "Continuar? (S/N)" << endl;
    cin >> continuar;
    continuar[0] = toupper(continuar[0]);           // la funcion toupper() convierte el caracter a mayuscula
    } while (continuar != "N" && continuar != "S");    // while por si el usuario mete un caracter que no es S o N
    if (continuar == "S"){
        return true;
    }
    return false;
}

int menu_principal(){
    int  opcion;
    cout<< "GRAN CERDO";
    cout<<endl;
    cout<<"------------------------";
    cout<<endl;
    cout<<"1 - JUGAR"<<endl;
    cout<<"2 - ESTADISTICAS";
    cout<<endl;
    cout<<"3 - CERDITOS";
    cout<<endl;
    cout<<"------------------------";
    cout<<endl;
    cout<<"0 - SALIR";
    cout<<endl;
    cout << "Elija opcion:";
    cin >> opcion;
    cout << "------------------------" << endl;
    return opcion;
}
