#include "UFSet.h"

/*
 * UFSet.cpp contiene la implementación de la interfaz para UFSet declarada en UFSet.h.
 * Deben implementarse las operaciones de acuerdo a la representación elegida para el tipo UFSet.
 */

/* El tipo UFNode* representa:
 *  1. un elemento de un UFSet (o sea, un nodo del árbol que contiene a todos los elementos del conjunto)
 *  2. al conjunto en su totalidad, si el nodo es la raíz del arbol
 *
 *  El nodo tiene un puntero a su elemento asociado en el campo element.
 *  Deberán agregarse los campos necesarios para completar la representación.
 */
struct UFNode
{
   ELEM_TYPE element;
   UFNode *padre;
   int altura;
};

/*
 * Inicializa el UFSet ufset, cuyo valor asociado será value
 */
UFSet createUFS(ELEM_TYPE value)
{
   UFSet ufs = new UFNode;
   ufs->element = value;
   ufs->padre = ufs;
   ufs->altura = 0;
   return ufs;
}

ELEM_TYPE elemUFS(UFSet ufset)
{
   return ufset->element;
}


int rank(UFSet ufset){
   return ufset->altura;
}

/*
 * Encuentra el elemento distinguido para el UFSet dado.
 * Esta operación puede ser optimizada con la técnica de compresión de camino.
 */
// UFSet findUFS(UFSet elem)
// {
//    if (elem->padre == elem) // si el padre es igual a si mismo => es su propio padre
//    {
//       return elem;
//    }

//    return findUFS(elem->padre); // sino que siga buscando en su misma rama
// }

UFSet findUFS(UFSet elem) { //MEJORA 1
   if (elem->padre != elem) // si el padre es distinto de si mismo => su nuevo padre es el distinguido del padre
   {
      elem->padre = findUFS(elem->padre);
   }

   return elem->padre; // devuelve su padre, ya sea si mismo o el distinguido de su padre.
}

/*
 * Calcula la unión entre los conjuntos ufset1 y ufset2.
 * Esta operación puede ser optimizada con la técnica de unión por rango.
 */
// void unionUFS(UFSet ufset1, UFSet ufset2)
// {
//    findUFS(ufset1)->padre = ufset2;
// }

void unionUFS(UFSet ufset1, UFSet ufset2) // MEJORA1
{
   if (ufset1->altura > ufset2->altura)
   {
      ufset2->padre = findUFS(ufset1);
   }
   else if (ufset2->altura > ufset1->altura)
   {
      ufset1->padre = findUFS(ufset2);
   }
   else
   {
      ufset2->padre = findUFS(ufset1);
      findUFS(ufset1)->altura++;
   }
}