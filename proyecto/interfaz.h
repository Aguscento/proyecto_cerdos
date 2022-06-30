#ifndef PROYECTO_INTERFAZ_H
#define PROYECTO_INTERFAZ_H
using namespace std;
/// muestra la interfaz del juego
void juego(string jugador1, string jugador2, int trufasj1, int trufasj2, string turno_de, int i, int lanzamientos, int trufas);

/// consulta al jugador si quiere continuar lanzando
bool consulta();

/// muestra el menu principal
int menu_principal();

/// tira numeros aleatorios
void tirarDados(int dados[],int cantidad);

/// define que jugador tira primero
void definir_comienzo(int vec[], int cantidad,int vec2[],int cant, string &jugando, string jugador1, string jugador2);

/// dibuja los dados
void imprimir_dados(int dados_que_salieron[], int cant);

#endif //PROYECTO_INTERFAZ_H
