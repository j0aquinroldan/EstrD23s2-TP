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

/*
   INV REP:
      * padre no puede ser NULL. En caso de que padre coincida con si mismo, entonces es el elemento distinguido. 
      * no pueden existir nodos idénticos mas allá de padre e hijo, ya que no hay repetidos en los conjuntos disjuntos.
      * element no puede ser NULL.
      * rango:
         * es mayor o igual a 0. 
         * su valor solo puede incrementar de a 1.
         * representa la altura máxima alcanzada por el árbol (sin tener en cuenta compresiones de camino).
         * en caso de que el nodo NO sea elemento distinguido entonces el rango es MENOR que el rango de su padre.
         * en caso de que el nodo SI sea elemento distinguido entonces el rango es IGUAL que el rango de su padre.
*/
struct UFNode
{
   ELEM_TYPE element;
   UFNode *padre;
   int rango;
};

/*
 * Inicializa el UFSet ufset, cuyo valor asociado será value
 */
UFSet createUFS(ELEM_TYPE value)
{
   UFSet ufs = new UFNode;
   ufs->element = value;
   ufs->padre = ufs;
   ufs->rango = 0;
   return ufs;
}

/*
 * devuelve el valor asociado a ufset
 */
ELEM_TYPE elemUFS(UFSet ufset)
{
   return ufset->element;
}

/*
 * Encuentra el elemento distinguido para el UFSet dado.
 * Esta operación puede ser optimizada con la técnica de compresión de camino.
 */

// UFSet findUFS(UFSet elem) // version indexada SIN compresion de camino
// {   
//     UFSet dis = elem; // recorrido para encontrar el elemento distinguido del set
//     while (dis->padre != dis) { // se busca el ufset que sea su propio padre (raiz)
//         dis = dis->padre;
//     }

//     return dis;
// }

// UFSet findUFS(UFSet elem) { // version recursiva CON compresion de camino.
//    if (elem->padre != elem) // si el padre es distinto de si mismo => su nuevo padre es el distinguido del padre
//    {
//       elem->padre = findUFS(elem->padre);
//    }

//    return elem->padre; // devuelve su padre, ya sea si mismo o el distinguido de su padre.
// }

UFSet findUFS(UFSet elem) // version indexada CON compresion de camino
{                         // primer recorrido para encontrar el distinguid y el segundo para hacer compresion de camino.

   UFSet dis = elem; // recorrido para encontrar el elemento distinguido del set
   while (dis->padre != dis)
   { // se busca el ufset que sea su propio padre (raiz)
      dis = dis->padre;
   }

   while (elem->padre != dis)
   { // recorrido para borrar los punteros de cada elemento y que ahora apunten al distinguido(path compression)
      UFSet padre = elem->padre;
      elem->padre = dis;
      elem = padre;
   }

   return dis;
}

/*
 * Calcula la unión entre los conjuntos ufset1 y ufset2.
 * Esta operación puede ser optimizada con la técnica de unión por rango.
 */
// void unionUFS(UFSet ufset1, UFSet ufset2)
// {
//    findUFS(ufset1)->padre = ufset2;
// }

void unionUFS(UFSet ufset1, UFSet ufset2) // mejora union por rango 
{

   // busca el distinguido de cada conjunto
   UFSet d1 = findUFS(ufset1);
   UFSet d2 = findUFS(ufset2);

   // si es el mismo conjunto no es necesario unirlos
   if (d1 == d2 )
   {
      return;
   }

   // si el rango de d2 es mayor al rango de d1, entonces d2 pasa a ser distinguido de ambos.
   if (d2->rango > d1->rango)
   {
      d1->padre = d2;
   }
   else // sino, d1 pasa a ser distinguido de ambos.
   {
      d2->padre = d1;
      if (d1->rango == d2->rango) // si tienen mismo rango entonces este se incrementa en 1
      {
         d1->rango++;
      }  
   }
}
