#include <iostream>
#include <cstdlib>
#define MaxTamaPila 5
using namespace std;
class Pila{
private:
	int A[MaxTamaPila],cima;
public:
	Pila(){cima=-1;}
	~Pila(){cout<<"Entra el destructor";};
	bool EstallenaP()
    {return cima==MaxTamaPila-1;}
    bool EstaVaciaP()
    {return cima==-1;}
	void Push(int elemento){
		if (EstallenaP())
        {
          cout << "Desbordamiento Pila";
          exit(1);
        }
        cima++;
        A[cima]=elemento;
	}
	int Pop(){
	 int Aux;
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
int main(int argc, char** argv) {
	Pila PilaOriginal;
	PilaOriginal.Push(3);
	PilaOriginal.Push(2);
	PilaOriginal.Push(5);
	PilaOriginal.Push(6);
	PilaOriginal.Push(7);
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	cout<<PilaOriginal.Pop()<<endl;
	system("PAUSE");
	return 0;
}
