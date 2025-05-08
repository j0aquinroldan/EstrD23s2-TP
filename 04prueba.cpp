#include <iostream>
#include "Equipo.h"
#include "UFSet.cpp"

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
  

  

  // arbol de rango 2
  unionUFS(colS, chiS);
  unionUFS(argS, crS);
  unionUFS(argS, colS);

  //arbol de rango 2
  unionUFS(prS,htS);
  unionUFS(uruS, bolS);
  unionUFS(uruS,prS);

  cout<< argS->rango << endl;
//arbol de rango 3
  unionUFS(argS, uruS);
  cout<< argS->rango << endl;
  
  cout << "padre ht(pre compresion): " + nombreEquipo(elemUFS(htS->padre)) << endl;
  cout << "padre pr(pre compresion): " + nombreEquipo(elemUFS(prS->padre)) << endl;

  cout << "root ht: " + nombreEquipo(elemUFS(findUFS(htS))) << endl;

  cout << "padre ht(post compresion): " + nombreEquipo(elemUFS(htS->padre)) << endl;

  cout << "padre pr(post compresion): " + nombreEquipo(elemUFS(prS->padre)) << endl;
  cout << "elem: " + nombreEquipo(elemUFS(prS)) << endl;


  cout<< argS->rango << endl;
}
