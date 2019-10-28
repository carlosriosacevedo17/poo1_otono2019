#include <iostream>
#include <cstdlib>
#define MaxTamaCola 5
using namespace std;
template <class T>
class Cola{
private:
	T A[MaxTamaCola];
	int frente,final;
public:
	Cola(){frente=0;final=0;}
	~Cola(){cout<<"Entra el destructor";};
	bool EstallenaC(){return final==MaxTamaCola;}
    bool EstaVaciaC(){return frente==final;}
	void Encolar(T elemento){
		if (EstallenaC())
        { cout << "Desbordamiento Cola";
          exit(1);
        }
        A[final]=elemento;
        final++;
    }
	T Desencolar(){
	 T Aux;
	  if (EstaVaciaC())
       {
        cout << "Se intenta sacar un elemento en cola vacia";
        exit(1);
       }
      Aux=A[frente];
      frente++;
     return Aux;
	}
};
class Persona{
private:
	string nombre;
	int edad;
public:
	string getNombre(){return nombre;}
	int getEdad(){return edad;}
	void setNombre(string n){nombre=n;}
	void setEdad(int e){edad=e;}
};
int main(int argc, char** argv) {
	Persona p1,p2,p3,p4,aux;
	p1.setNombre("Juan");
	p1.setEdad(30);
	p2.setNombre("Pedro");
	p2.setEdad(40);
	p3.setNombre("Adriana");
	p3.setEdad(20);
	p4.setNombre("PALOMINO");
	p4.setEdad(20);
	Cola <Persona> ColaOriginal;
	ColaOriginal.Encolar(p1);
	ColaOriginal.Encolar(p2);
	ColaOriginal.Encolar(p3);
	ColaOriginal.Encolar(p4);
	aux=ColaOriginal.Desencolar();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	aux=ColaOriginal.Desencolar();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	aux=ColaOriginal.Desencolar();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	ColaOriginal.Encolar(p4);
	aux=ColaOriginal.Desencolar();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	aux=ColaOriginal.Desencolar();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	system("PAUSE");
	return 0;
}
