#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
class Persona{
private:
	string nombre;
public:
	Persona(string n)	{nombre=n;}
	string getNombre()	{return nombre;}
	void setNombre(string n) {nombre=n;}
};
typedef class snodo{
    public:
        bool push(int);//1
        bool pop();//2
        void imprimelista();//3
        bool buscar(int);//4
        bool vaciar();//5
        int leer(int);
        bool limpiar();
        int Menu(int);
        int dato;
        class snodo * siguiente;
}nodo;

nodo *lista = NULL;

int nodo::leer(int dato){
    cin>>dato;
    return dato;
}

bool nodo::push(int x){
    if(lista == NULL){
        lista = new nodo;
        lista -> dato = x;
        lista -> siguiente = NULL;
        return true;
        }
    else
    {
        nodo *aux;
        nodo *q;
        q=lista;
        while(q->siguiente!=NULL)
            q=q->siguiente;
        aux = new nodo;
        aux->dato=x;
        aux->siguiente=NULL;
        q->siguiente=aux;
        return true;
    }
}

void nodo::imprimelista(){
    nodo *p = lista;
    while (p != NULL){
        cout<<setw(4)<<p -> dato;
        p = p ->siguiente;
    }
    cout<<endl;
}

int Menu(int opcion){
     cout<<"1)PUSH\n";
     cout<<"2)POP\n";
     cout<<"3)IMPRIME LISTA\n";
     cout<<"4)BUSCAR\n";
     cout<<"5)VACIAR\n";
     cout<<"6)SALIR\n";
     cout<<"\n\nOpcion: ";
     cin>>opcion;
     return opcion;
}
int main(int argc, char** argv) {
	nodo n;
    int x;
    int opcion;
    do{
        opcion = Menu(opcion);
        switch(opcion){
            case 1:
                 cout<<"Ingresa el dato: ";
                 x = n.leer(x);
                 if(n.push(x)){
                     cout<<"El dato fue insertado";
                     n.imprimelista();
                 }
                 else
                     cout<<"el dato no fue insertado\n";
                 break;
            case 2:
                 break;
            case 3:
                 n.imprimelista();
                 break;
            case 4:
                 /*x = n.leer(x);
                 if(n.borrar(x)){
                     cout<<"El dato fue eliminado";
                     n.imprimelista();
                 }
                 else
                     cout<<"el dato no fue encontrado\n";*/
                 break;
            case 5:
                 /*if(n.vaciar()){
                     cout<<"la lista esta vacia";
                     n.imprimelista();
                 }
                 else
                     cout<<"la lista no esta vacia";*/
                 break;
            case 6:
                 /*n.limpiar();
                 return 0;*/
                 break;
            default:
                 cerr<<"Error";
                 break;
        }
        cin.get();
        cin.get();
        system("cls");
    }while(opcion != 6);
    return EXIT_SUCCESS;
}
