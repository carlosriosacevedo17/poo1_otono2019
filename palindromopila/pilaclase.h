#ifndef PILACLASE_H
#define PILACLASE_H
typedef char TipoDeDato;
const int TAMPILA = 100;

class PilaLineal
{
private:
        int cima;
        TipoDeDato listaPila[TAMPILA];
public:
       PilaLineal()
        {cima = -1; // condici�n de pila vac�a
		}
// operaciones que modifican la pila
void insertar(TipoDeDato elemento);
TipoDeDato quitar();
void limpiarPila();
// operaci�n de acceso a la pila
TipoDeDato cimaPila();
// verificaci�n estado de la pila
bool pilaVacia();
bool pilaLlena();
};


void PilaLineal::insertar(TipoDeDato elemento)
  {
	if (pilaLlena())
       {throw "Desbordamiento pila";}
    //incrementar puntero cima y copia elemento
    cima++;
    listaPila[cima] = elemento;
  }

TipoDeDato PilaLineal::quitar()
 {
  TipoDeDato aux;
    if (pilaVacia())
    {throw "Pila vac�a, no se puede extraer.";}
     // guarda elemento de la cima
     aux = listaPila[cima];
     // decrementar cima y devolver elemento
     cima--;
     return aux;
  }
TipoDeDato PilaLineal::cimaPila()
   {
    if (pilaVacia())
	{throw "Pila vac�a, no hay elementos.";}
    return listaPila[cima];
   }
bool PilaLineal::pilaVacia()
    {return cima == -1;}
bool PilaLineal::pilaLlena()
    {return cima == TAMPILA - 1;}
void PilaLineal::limpiarPila()
    {cima = -1;}



#endif
