#include <iostream>
#include <cstdlib>
#define MaxTamaPila 5
using namespace std;
template <class T>
class Pila{
private:
	T A[MaxTamaPila];
	int cima;
public:
	Pila(){cima=-1;}
	~Pila(){cout<<"Entra el destructor";};
	bool EstallenaP(){return cima==MaxTamaPila-1;}
    bool EstaVaciaP(){return cima==-1;}
	void Push(T elemento){
		if (EstallenaP())
        { cout << "Desbordamiento Pila";
          exit(1);
        }
        cima++;
        A[cima]=elemento;
	}
	T Pop(){
	 T Aux;
	  if (EstaVaciaP())
       {
        cout << "Se intenta sacar un elemento en pila vacia";
        exit(1);
       }
      Aux=A[cima];
      cima--;
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
	Persona p1,p2,p3,aux;
	p1.setNombre("Juan");
	p1.setEdad(30);
	p2.setNombre("Pedro");
	p2.setEdad(40);
	p3.setNombre("Adriana");
	p3.setEdad(20);
	Pila <Persona> PilaOriginal;
	PilaOriginal.Push(p1);
	PilaOriginal.Push(p2);
	PilaOriginal.Push(p3);
	aux=PilaOriginal.Pop();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	aux=PilaOriginal.Pop();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	aux=PilaOriginal.Pop();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	aux=PilaOriginal.Pop();
	cout <<"el nombre es:"<<aux.getNombre()<<endl;
	cout <<"la edad es:"<<aux.getEdad()<<endl;
	//Pila <string> PilaOriginal;
	/*PilaOriginal.Push("CARLOS ARMANDO");
	PilaOriginal.Push("EDUARDO PEREZ");
	PilaOriginal.Push("ARTURO");
	PilaOriginal.Push("CRISTINA");
	PilaOriginal.Push("ADRIANA");
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;*/
	system("PAUSE");
	return 0;
}
