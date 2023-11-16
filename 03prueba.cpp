#include <iostream>
#include "Equipo.h"
#include "UFSet.h"


int main()
{
    Equipo arg = crearEquipo(ARGENTINA, "A");
    Equipo bol = crearEquipo(BOLIVIA, "A");
    Equipo chi = crearEquipo(CHILE, "A");
    Equipo uru = crearEquipo(URUGUAY, "A");
    Equipo col = crearEquipo(COLOMBIA, "A");
    Equipo cr = crearEquipo(COSTARICA, "A");
    
    UFSet argS = createUFS(arg);
    UFSet bolS = createUFS(bol);
    UFSet chiS = createUFS(chi);
    UFSet uruS = createUFS(uru);
    UFSet colS = createUFS(col);
    UFSet crS = createUFS(cr);

    
    unionUFS(uruS,bolS);
    unionUFS(colS,chiS);
    unionUFS(argS,crS);
    unionUFS(argS,colS);
    unionUFS(argS,uruS);

  // cout<< nombreEquipo(elemUFS(padre(argS)))<<endl;
   cout<< "padre bol(pre comp): " + nombreEquipo(elemUFS(padre(bolS)))<<endl;
  // cout<< nombreEquipo(elemUFS(padre(chiS)))<<endl;
  // cout<< nombreEquipo(elemUFS(padre(uruS)))<<endl;


  cout<< "root bol: " + nombreEquipo(elemUFS(findUFS(bolS)))<<endl;

  // cout<< nombreEquipo(elemUFS(padre(argS)))<<endl;
   cout<< "padre bol(post comp): " + nombreEquipo(elemUFS(padre(bolS)))<<endl;
  // cout<< nombreEquipo(elemUFS(padre(chiS)))<<endl;
  // cout<< nombreEquipo(elemUFS(padre(uruS)))<<endl;
}
