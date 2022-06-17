#include<iostream>
#include "interfaz.h"
using namespace std;

int main(){

    //---------------------------------------------------------------------

    /* ingreso de nombre de jugadores */
    string jugador1, jugador2;                             // solicitacion de nombre de jugadores
    // cin.ignore();                                       // para ignorar el "enter" en el ultimo ingreso (por ahora negado porque no hay nada arriba)
    cout << "Jugador #1:";
    getline(cin, jugador1);                         // permite agregar espacios en los nombres ej: maria isabel
    cout << "Jugador #2:";
    getline(cin, jugador2);

    //----------------------------------------------------------------------

    /* sistema de turnos y lanzadas */
    int TrufasJ1 = 0, TrufasJ2 = 0, lanzamientos;          // contador de trufas y lanzamientos
    int lanzamientosJ1=0,lanzamientosJ2=0;
    string jugando;                                        // variable para el jugador del turno
    for (int i = 1; i <= 5; ++i) {                         // 5 rondas en total
        jugando = jugador1;
        for (int j = 0; j < 2; ++j) {                      // 2 jugadores, jugador uno seria j=0 u jugador dos seria j=1
            lanzamientos = 0;                              // contador de lanzamientos
            do {                                           // while para lanzar otra vez
                lanzamientos ++;
                juego(jugador1, jugador2, TrufasJ1, TrufasJ2, jugando, i, lanzamientos); // turno de jugador
            } while (consulta());
            if (j == 0){                                   // asigno cantidad de lanzamientos correspondientes a jugadores
                lanzamientosJ1 += lanzamientos;
            } else{
                lanzamientosJ2 += lanzamientos;
            }
            jugando = jugador2;                            // aca cambia la variable string por el nombre del jugador2
        }
    }

    /* Sistema de puntos */
    //----------------------------------------------------------------------------

    int total1=0, total2 =0;

    //hago un if para preguntar quien posee mas trufas
    int PuntosJ1=0, PuntosJ2=0;
    if (TrufasJ1>TrufasJ2){
        PuntosJ1=5;
    }
    else{
        if (TrufasJ2>TrufasJ1){
            PuntosJ2=5;
        }
    }
    total1 += PuntosJ1;
    total2 += PuntosJ2;

    //-------------------------------------------------------------------------------

    //Conteo de puntos cada 50 trufas suma 1 PDV

    int Cada50J1,Cada50J2; //variable para guardar los puntos de cada 50 trufas

    Cada50J1=TrufasJ1/50;
    Cada50J2=TrufasJ2/50;
    total1 += Cada50J1;
    total2 += Cada50J2;

    //--------------------------------------------------------------------------------

    //Conteo de OINKS
    int Oink1=0,Oink2=0;
    total1 += Oink1 * 2;
    total2 += Oink2 * 2;

    //--------------------------------------------------------------------------------

    //comparacion de lanzamientos codicia
    int codicia1=0, codicia2=0;

    if (lanzamientosJ1>lanzamientosJ2){
        codicia1=3;
    }
    else{
        if(lanzamientosJ2>lanzamientosJ1){
            codicia2=3;
        }
    }
    total1 += codicia1;
    total2 += codicia2;

    //------------------------------------------------------------------------------

    cout << "GRAN CERDO" << endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<endl<<endl;
    cout << "HITO                            "<<jugador1<<"                                  "<<jugador2<<endl;
    cout <<"---------------------------------------------------------------------------------------"<<endl;
    cout << endl;
    cout << "Mas trufas en total        "<<PuntosJ1<<" PDV ("<<TrufasJ1<<" Trufas)"<<"                      "<<PuntosJ2<<" PDV ("<<TrufasJ2<<" Trufas)"<<endl<<endl;
    cout << "Cada 50 trufas             "<<Cada50J1<<" PDV ("<<(Cada50J1*50)<<" Trufas)"<<"                      "<<Cada50J2<<" PDV ("<<(Cada50J2*50)<<" Trufas)"<<endl<<endl;
    cout << "Oinks                      "<<(Oink1*2)<<" ("<<Oink1<<" Oinks)"<<"                           " <<(Oink2*2)<<" ("<<Oink2<<" Oinks)"<<endl<<endl;
    cout << "Cerdo codicioso            "<<codicia1<<" PDV ("<<lanzamientosJ1<<" lanzamientos)"<<"                "<<codicia2<<" PDV ("<<lanzamientosJ2<<" lanzamientos)"<< endl<<endl;
    cout <<"---------------------------------------------------------------------------------------"<<endl;
    cout << "TOTAL                      "<<total1<<" PDV                                 " << total2 << " PDV";
    return 0;
}

