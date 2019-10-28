#include <iostream>

using namespace std;
typedef int TipoDeDato; // tipo de los elementos de la pila
// archivo de cabecera pilalineal.h
const int TAMPILA = 49;
class PilaLineal
{
private:
int cima;
TipoDeDato listaPila[TAMPILA];
public:
PilaLineal()
{
cima = -1; // condición de pila vacía
}
// operaciones que modifican la pila
void insertar(TipoDeDato elemento);
TipoDeDato quitar();
void limpiarPila();
// operación de acceso a la pila
TipoDeDato cimaPila();
// verificación estado de la pila
bool pilaVacia();
bool pilaLlena();
};
void PilaLineal::insertar(TipoDeDato elemento)
{
	if (pilaLlena())
{
throw "Desbordamiento pila";
}
//incrementar puntero cima y copia elemento
cima++;
listaPila[cima] = elemento;
}
TipoDeDato PilaLineal::quitar()
{
TipoDeDato aux;
if (pilaVacia())
{
throw "Pila vacía, no se puede extraer.";
}
// guarda elemento de la cima
aux = listaPila[cima];
// decrementar cima y devolver elemento
cima--;
return aux;
}
TipoDeDato PilaLineal::cimaPila()
{
if (pilaVacia())
{
throw "Pila vacía, no hay elementos.";
}
return listaPila[cima];
}
bool PilaLineal::pilaVacia()
{
return cima == -1;
}
bool PilaLineal::pilaLlena()
{
return cima == TAMPILA - 1;
}
void PilaLineal::limpiarPila()
{
cima = -1;
}

int main(int argc, char** argv) {
	PilaLineal pila; // crea pila vacía
TipoDeDato x,y;
const TipoDeDato CLAVE = -1;
cout << "Teclea elemento de la pila(termina con -1)" << endl;
try {
do {
cin >> x;
pila.insertar(x);
}while (x != CLAVE);
// proceso de la pila
cout << "Elementos de la Pila eliminados: " ;
while (!pila.pilaVacia())
{
x = pila.quitar();
cout << x << " ";
}
}
catch (const char * error)
{
cout << "Excepción: " << error;
}


	return 0;
}
