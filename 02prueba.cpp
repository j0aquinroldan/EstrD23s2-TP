#include <iostream>
#include "Equipo.h"
#include "UFSet.h"


int main()
{
    Equipo arg = crearEquipo(ARGENTINA, "A");
    Equipo col = crearEquipo(COLOMBIA, "A");
    Equipo chi = crearEquipo(CHILE, "A");
    
    UFSet argS = createUFS(arg);
    UFSet colS = createUFS(col);
    UFSet chiS = createUFS(chi);



    cout<<  nombreEquipo(elemUFS(findUFS(argS))) << endl<<endl;

    unionUFS(argS,colS);

    cout<<  nombreEquipo(elemUFS(findUFS(argS))) << endl;
    cout<<  nombreEquipo(elemUFS(findUFS(colS))) << endl<<endl;


    unionUFS(colS,chiS);
    cout<<  nombreEquipo(elemUFS(findUFS(chiS))) << endl;
}
