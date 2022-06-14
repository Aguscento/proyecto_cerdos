#include <iostream>

using namespace std;

int main()
{
    int jugador1,jugardor2;
    //----------------------------------------------------------------------------

    //hago un if para preguntar quien posee mas trufas

        int TrufasJ1 = 0, TrufasJ2 = 0;
        int PuntosJ1,PuntosJ2=0;


        if (TrufasJ1>TrufasJ2){
            PuntosJ1=5;
        }
        else{
            if (TrufasJ2>TrufasJ1){
                    PuntosJ2=5;
            }
        }

    //-------------------------------------------------------------------------------

    //Conteo de puntos cada 50 trufas suma 1 PDV

    int Cada50J1,Cada50J2; //variable para guardar los puntos de cada 50 trufas

    Cada50J1=TrufasJ1/50;
    Cada50J2=TrufasJ2/50;

    //--------------------------------------------------------------------------------

    //Conteo de OINKS
    int Oink1=0,Oink2=0;

    //--------------------------------------------------------------------------------

    //Conteo de Lanzamientos
    int lanzamientosJ1=0,lanzamientosJ2=0;
    int codicia1,codicia2=0;

        if (lanzamientosJ1>lanzamientosJ2){
            codicia1=3;
        }
        else{
                if(lanzamientosJ2>lanzamientosJ1){
                codicia2=3;
                }
        }



    //------------------------------------------------------------------------------

    cout << "GRAN CERDO" << endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<endl<<endl;
    cout << "HITO                              "<<jugador1<<"                                     "<<jugador1<<endl;
    cout <<"---------------------------------------------------------------------------------------"<<endl;
    cout <<endl<<endl;
    cout << "Mas trufas en total        "<<PuntosJ1<<" PDV ("<<TrufasJ1<<" Trufas)"<<"                      "<<PuntosJ2<<" PDV ("<<TrufasJ2<<" Trufas)"<<endl<<endl;
    cout << "Cada 50 trufas             "<<Cada50J1<<" PDV ("<<(Cada50J1*50)<<" Trufas)"<<"                      "<<Cada50J2<<" PDV ("<<(Cada50J2*50)<<" Trufas)"<<endl<<endl;
    cout << "Oinks                      "<<(Oink1*2)<<" ("<<Oink1<<" Oinks)"<<"                           " <<(Oink2*2)<<" ("<<Oink2<<" Oinks)"<<endl<<endl;
    cout << "Cerdo codicioso            "<<codicia1<<" PDV ("<<lanzamientosJ1<<" lanzamientos)"<<"                "<<codicia2<<" PDV ("<<lanzamientosJ2<<" lanzamientos)"<< endl<<endl;
    return 0;
}
