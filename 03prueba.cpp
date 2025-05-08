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
  Equipo pr = crearEquipo(PARAGUAY, "A");
  Equipo ht = crearEquipo(HAITI, "A");

  UFSet argS = createUFS(arg);
  UFSet crS = createUFS(cr);
  UFSet chiS = createUFS(chi);
  UFSet colS = createUFS(col);
  UFSet prS = createUFS(pr);
  UFSet htS = createUFS(ht);
  UFSet uruS = createUFS(uru);
  UFSet bolS = createUFS(bol);
  

  

  // arbol de rango 3
  unionUFS(colS, chiS);
  unionUFS(argS, crS);
  unionUFS(argS, colS);

  //arbol de rango 3

  unionUFS(prS,htS);
  unionUFS(uruS, bolS);
  unionUFS(uruS,prS);


  unionUFS(argS, uruS);

  
  // cout << "padre ht(pre comp): " + nombreEquipo(elemUFS(padre(htS))) << endl;
  // cout << "padre pr(pre comp): " + nombreEquipo(elemUFS(padre(prS))) << endl;

  // cout << "root ht: " + nombreEquipo(elemUFS(findUFS(htS))) << endl;

  // cout << "padre ht(post comp): " + nombreEquipo(elemUFS(padre(htS))) << endl;

  // cout << "padre pr(post comp): " + nombreEquipo(elemUFS(padre(prS))) << endl;
  // cout << "elem: " + nombreEquipo(elemUFS(prS)) << endl;

}
