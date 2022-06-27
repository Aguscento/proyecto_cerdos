#include<iostream>
#include <cstdlib>
#include <time.h>
#include "interfaz.h"
using namespace std;

int main(){
    string jugador1, jugador2;                             // strings para solicitar nombres de jugadores
    int TrufasJ1 = 0, TrufasJ2 = 0, lanzamientos;          // contador de trufas y lanzamientos
    int lanzamientosJ1 = 0, lanzamientosJ2 = 0;            // contador de lanzamientos
    string jugando;                                        // variable para el jugador del turno
    string continuar;                                      // string para continuar
    int trufas_acumuladas = 0;                             // trufas acumuladas en el turno
    int total1 = 0, total2 = 0;                            // acumulador de puntos totales
    int PuntosJ1 = 0, PuntosJ2 = 0;                        // acumulador de puntos
    int Cada50J1, Cada50J2;                                // variable para guardar los puntos de cada 50 trufas
    int Oink1 = 0, Oink2 = 0;                              // contador de Oinks
    int codicia1 = 0, codicia2 = 0;                        // acumulador de puntos de codicia
    string salir = "N";                                    // variable para cerrar del juego
    int const cantidad = 2;                                // constante para vector de dados
    int dados[cantidad]={};
    int dados2[cantidad]={};                               // vecrores de dados
    int resultado;                                         // donde se suman los puntos de las condiciones
    srand(time(NULL));                          // seteo del rand

    while (salir == "N") {
        switch( menu_principal())
        {
            case 1:
                //---------------------------------------------------------------------

                /* ingreso de nombre de jugadores */
                cin.ignore();                                          // para ignorar el "enter" en el ultimo ingreso
                cout << "Jugador #1:";
                getline(cin, jugador1);                         // permite agregar espacios en los nombres ej: maria isabel
                for (int i = 0; i < jugador1.size(); ++i) {            // string.size() muestra el tamaño del string
                    jugador1[i] = toupper(jugador1[i]);             // la funcion toupper() convierte el caracter a mayuscula
                }
                cout << "Jugador #2:";
                getline(cin, jugador2);
                for (int i = 0; i < jugador2.size(); ++i) {
                    jugador2[i] = toupper(jugador2[i]);
                }
                //---------------------------------------------------------------------
                /* definicion de comienzo */
                cout << "DADOS DE JUGADOR #1:" << endl;
                tirarDados(dados, cantidad);
                for (int i = 0; i < 2; ++i) {
                    cout <<dados[i]<<endl;
                }
                cout << "DADOS DE JUGADOR #2:" << endl;
                tirarDados(dados2,cantidad);
                for (int i = 0; i < 2; ++i) {
                    cout <<dados2[i]<<endl;
                }
                definir_comienzo(dados,cantidad,dados2,cantidad, jugando, jugador1, jugador2);
                do {                                                   // while para continuar
                    cout << "Escriba S para continuar:";
                    cin >> continuar;
                    continuar[0] = toupper(continuar[0]);
                } while (continuar != "S");
                //----------------------------------------------------------------------

                /* sistema de turnos y lanzadas */
                for (int i = 1; i <= 5; ++i) {                                    // 5 rondas en total
                    for (int j = 0;j < 2; ++j) {                                  // 2 jugadores, jugador uno seria j=0 u jugador dos seria j=1
                        lanzamientos = 0;                                         // contador de lanzamientos
                        bool continuar = true;                                    // booleno para volver a lanzar
                        do {                                                      //do while para lanzar otra vez
                            lanzamientos++;
                            juego(jugador1, jugador2, TrufasJ1, TrufasJ2, jugando, i, lanzamientos, trufas_acumuladas); // turno de jugador
                            tirarDados(dados, cantidad);
                            for (int k = 0; k < cantidad; ++k) {
                                cout << dados[k] << endl;
                            }
                            if(dados[0] != dados[1] && dados[0] !=1 && dados[1]!=1){              // Si las caras son distintas entre sí y ninguna de ellas es un as
                                trufas_acumuladas += (dados[0]+ dados[1]);
                                resultado = (dados[0]+ dados[1]);
                                cout<<"SUMASTE: "<<resultado<<endl;
                            }else if(dados[0] == dados[1] && dados[0] != 1 && dados[1] != 1){      // Si las caras son iguales entre sí y no son ases. Entonces el cerdo hizo un Oink
                                trufas_acumuladas += (dados[0] + dados[1]) * 2;
                                resultado = (dados[0] + dados[1]) * 2;
                                cout<<"OINK!!!"<<endl;
                                cout<<"SUMASTE: "<<resultado<<endl;
                                if (jugando == jugador1){
                                    Oink1 ++;
                                }else{
                                    Oink2 ++;
                                }
                            }else if(dados[0] != dados[1] && (dados[0] == 1 || dados[1] == 1)){    // Si las caras son distintas entre sí y hay un as entre ellas
                                trufas_acumuladas = 0;
                                resultado = 0;
                                continuar = false;                                                 // booleano para ceder el turno
                                cout << "PIERDES LAS TRUFAS ACUMULADAS!" << endl;
                                cout<<"SUMASTE: "<< resultado <<endl;
                            }else if(dados[0] == dados [1] && dados[0] == 1){                      // Si dos de las caras son iguales entre sí y son ases.
                                trufas_acumuladas = 0;
                                resultado = 0;
                                if (jugando == jugador1){
                                    TrufasJ1 = 0;
                                }else TrufasJ2 = 0;
                                continuar = false;                                                 // booleando para ceder el turno
                                cout << jugando << " SE HUNDE EN EL BARRO!" << endl;
                                cout << "PIERDES TODO!" << endl;
                            }
                        } while (consulta() && continuar);
                        if (jugando == jugador1){                                                  // asignacion de trufas y lanzamientos a jugador correspondiente
                            TrufasJ1 += trufas_acumuladas;
                            if (lanzamientos > lanzamientosJ1){
                                lanzamientosJ1 = lanzamientos;
                            }
                        }else{
                            TrufasJ2 += trufas_acumuladas;
                            if (lanzamientos > lanzamientosJ2){
                                lanzamientosJ2 = lanzamientos;
                            }
                        }
                        trufas_acumuladas = 0;
                        if (jugando == jugador1){                                                 // cambio de jugador
                            jugando = jugador2;
                        }else jugando = jugador1;
                    }
                }

                /* Sistema de puntos */
                //----------------------------------------------------------------------------

                //hago un if para preguntar quien posee mas trufas
                if (TrufasJ1 > TrufasJ2) {
                    PuntosJ1 = 5;
                } else {
                    if (TrufasJ2 > TrufasJ1) {
                        PuntosJ2 = 5;
                    }
                }
                if (TrufasJ1 == TrufasJ2){
                    PuntosJ1 = 5;
                    PuntosJ2 = 5;
                }
                total1 += PuntosJ1;
                total2 += PuntosJ2;

                //-------------------------------------------------------------------------------

                //Conteo de puntos cada 50 trufas suma 1 PDV
                Cada50J1 = TrufasJ1 / 50;
                Cada50J2 = TrufasJ2 / 50;
                total1 += Cada50J1;
                total2 += Cada50J2;

                //--------------------------------------------------------------------------------

                //Conteo de OINKS
                total1 += Oink1 * 2;
                total2 += Oink2 * 2;

                //--------------------------------------------------------------------------------

                //comparacion de lanzamientos codicia
                if (lanzamientosJ1 > lanzamientosJ2) {
                    codicia1 = 3;
                } else {
                    if (lanzamientosJ2 > lanzamientosJ1) {
                        codicia2 = 3;
                    }
                }
                if (lanzamientosJ1 == lanzamientosJ2){
                    codicia1 = 3;
                    codicia2 = 3;
                }
                total1 += codicia1;
                total2 += codicia2;

                //------------------------------------------------------------------------------

                cout << "GRAN CERDO" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                cout << endl << endl;
                cout << "HITO                            " << jugador1 << "                                  " << jugador2<< endl;
                cout << "---------------------------------------------------------------------------------------" << endl;
                cout << endl;
                cout << "Mas trufas en total        " << PuntosJ1 << " PDV (" << TrufasJ1 << " Trufas)"<< "                      " << PuntosJ2 << " PDV (" << TrufasJ2 << " Trufas)" << endl << endl;
                cout << "Cada 50 trufas             " << Cada50J1 << " PDV (" << (Cada50J1 * 50) << " Trufas)"<< "                      " << Cada50J2 << " PDV (" << (Cada50J2 * 50) << " Trufas)" << endl << endl;
                cout << "Oinks                      " << (Oink1 * 2) << " (" << Oink1 << " Oinks)"<< "                           " << (Oink2 * 2) << " (" << Oink2 << " Oinks)" << endl << endl;
                cout << "Cerdo codicioso            " << codicia1 << " PDV (" << lanzamientosJ1 << " lanzamientos)"<< "                " << codicia2 << " PDV (" << lanzamientosJ2 << " lanzamientos)" << endl << endl;
                cout << "---------------------------------------------------------------------------------------" << endl;
                cout << "TOTAL                      " << total1 << " PDV                                 " << total2<< " PDV" << endl;
                if (total1 == total2){
                     cout << "EMPATE!" << endl << endl;
                }else{
                    if (total1 > total2){
                        cout << "GANADOR " << jugador1 << " con " << total1 << " puntos de victoria!" << endl << endl;
                    }else{
                        cout << "GANADOR " << jugador2 << " con " << total2 << " puntos de victoria!" << endl << endl;
                    }
                }
                cin.ignore();
                do {                                                   // while para continuar
                    cout << "Escriba Oink para continuar:";
                    cin >> continuar;
                    for (int i = 0; i < continuar.size(); ++i) {
                        continuar[i] = toupper(continuar[i]);
                    }
                } while (continuar != "OINK");
                break;

                //------------------------------------------------------------------------------
                // estadisticas
            case 2:

                break;

                //------------------------------------------------------------------------------
                // cerditos
            case 3:
                cout << "GRUPO: ______"<< endl; //falta el nombre del grupo
                cout << "Apellido, nombre y legajos del equipo: " << endl;
                cout << endl<<endl;
                cout << "Benitez Andres Esteban "<<endl;
                cout << "Legajo 27009 "<<endl;
                cout << endl<<endl;
                cout << "Albornos Agustin Mariano "<<endl;
                cout << "Legajo 26809"<<endl;
                cout << endl<<endl;
                cout << "Centomani Agustin "<<endl;
                cout << "Legajo 25675 "<< endl;
                cout << endl<<endl;
                do {                                                   // while para continuar
                    cout << "Escriba S para continuar:";
                    cin >> continuar;
                    continuar[0] = toupper(continuar[0]);
                } while (continuar != "s");
                cout << "---------------------------------------------------------------------------------------" << endl;
                break;

                //------------------------------------------------------------------------------
                // salir
            case 0:
                do {                                                        // ciclo para volver a consultar si no se ingreso s o n
                    cout << "Seguro desea salir? (S/N)" << endl;
                    cin >> salir;
                    salir[0] = toupper(salir[0]);                        // la letra "salir" a mayuscula
                } while (salir != "N" && salir != "S");
                break;
        }
    }
    return 0;
}

