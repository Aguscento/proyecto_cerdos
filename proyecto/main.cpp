#include <stdlib.h>
#include<iostream>
#include <string>

using namespace std;

/* solicitacion de nombre de jugadores */

int main(){
    string jugador1, jugador2;
    cin.ignore();
    cout << "Jugador #1:";
    getline(cin, jugador1);
    cout << "Jugador #2:";
    getline(cin, jugador2);
    return 0;
}
