#include <iostream>
using namespace std;
#include <string.h>
#include "pilaclase.h"

int main(int argc, char** argv) {
PilaLineal pilaChar; // crea pila vacía
TipoDeDato ch;
bool esPal;
char pal[81];
cout << "Teclea la palabra verificar si es palindromo: ";
gets(pal);
for (int i = 0; i < strlen(pal); )
{
char c;
c = pal[i++];
pilaChar.insertar(c);
}
// se comprueba si es palíndromo
esPal = true;
for (int j = 0; esPal && !pilaChar.pilaVacia(); )
{
char c;
c = pilaChar.quitar();
esPal = pal[j++] == c;
}
pilaChar.limpiarPila();
if (esPal)
cout << "La palabra " << pal << " es un palindromo \n";
else
cout << "La palabra " << pal << " no es un palindromo \n";
	return 0;
}
