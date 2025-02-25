// Versión jugable en internet: https://minesweeper.online/es/
// Alberto de la Encina 
// Puri Arenas

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "colors.h"

using namespace std;

#include "inputOutput.h"






int main() {
    
    tCelda c1 = { NUMERO,2,false,true };
    tCelda c2 = { MINA,0,false,true };

    tCelda c3 = { VACIA,0,true,false };
    tCelda c4 = { NUMERO,3,true,true };

    tCelda c5 = { MINA,0,false,true };
    tCelda c6 = { VACIA,0,false,false };

    Matriz m = { c1,c2,c3,c4,c5,c6 };
    mostrar_juego_consola(m);
    return 0;
}

