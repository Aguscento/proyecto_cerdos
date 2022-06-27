#include<iostream>
#include <cstdlib>
#include "Interfaz.h"

using namespace std;

void juego(string jugador1, string jugador2, int trufasj1, int trufasj2, string turno_de, int i, int lanzamientos, int trufas) {
    cout << "_________________________________________________________________________________" << endl;
    cout << endl << "GRAN CERDO" << endl;
    cout << "_________________________________________________________________________________" << endl;
    cout << jugador1 << ":" << trufasj1 << " trufas acumuladas" << "            " << jugador2 << ":" << trufasj2 << " trufas acumuladas" << endl;
    cout << endl << "TURNO DE " << turno_de << endl;
    cout << "+------------------------+" << endl;
    cout << "| RONDAS #" << i << "              |" << endl;
    cout << "| TRUFAS DE LA RONDA:" << trufas << "    |" << endl;
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
    string opcion;
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
    do {                                                        // ciclo para volver a consultar si no se ingreso 0,1,2,3
        cout << "Elija opcion:";
        cin >> opcion;
    } while (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "0");  // uso tipo string porque si uso tipo int y meto una letra en la variable opcion se bugea
    cout << "------------------------" << endl;
    return stoi(opcion);                                     // stoi pasa de string a tipo int
}

void tirarDados(int dados[],int cantidad){
    for(int i=0;i<cantidad;i++){
        dados[i]=rand()%6+1;
    }
}

void definir_comienzo(int vec[], int cantidad,int vec2[],int cant, string &jugando, string jugador1, string jugador2){ // jugando es pasado por referencia para asignarle a la varible "jugando" el jugador ganador del comienzo
    int suma = vec[0]+vec[1];
    int suma2 = vec2[0]+vec2[1];                                    // sumatoria de caras
    int mayor1, mayor2;
    if(suma > suma2){
        cout<<"Felicitaciones Comienza el jugador #1: " << jugador1 << endl;         // comparacion de resultados
        jugando = jugador1;
    }else if(suma2 > suma){
        cout<<"Felicitaciones Comienza el jugador #2: " << jugador2 << endl;
        jugando = jugador2;
        }else if(suma==suma2){                                      // comparacion de numero mayor en caso de empate
            mayor1 = vec[0];
            if (vec[1] > mayor1) {
                mayor1 = vec[1];
            }
            mayor2 = vec2[0];
            if (vec2[1] > mayor2) {
                mayor2 = vec2[1];
            }
            if(mayor1 > mayor2) {
                cout << "Felicitaciones Comienza el jugador #1: " << jugador1 << endl;
                jugando = jugador1;
            }
            if(mayor2 > mayor1){
                cout<<"Felicitaciones Comienza el jugador #2: " << jugador2 << endl;
                jugando = jugador2;
            }else if(vec[0] == vec2[0] && vec[0] == vec2[1]){
                    cout<<"Empate absoluto, hay que tirar de nuevo"<<endl;
                    tirarDados(vec, cantidad);
                    tirarDados(vec2,cant);
                    definir_comienzo(vec, cantidad, vec2, cant, jugando, jugador1, jugador2);
                }

        }

}