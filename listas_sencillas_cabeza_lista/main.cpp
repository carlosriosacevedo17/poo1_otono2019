#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef class snodo{
    public:
        void InsertarCabezaLista(int);
        void imprimelista();
        int leer(int);
        bool limpiar();
        int Menu(int);
        int dato;
        class snodo * siguiente;
}nodo;

nodo *cabeza_ptr = NULL;

void nodo::InsertarCabezaLista(int x){
    nodo *insertar_ptr;
    insertar_ptr= new nodo;
    insertar_ptr->dato=x;
    insertar_ptr->siguiente=cabeza_ptr;
    cabeza_ptr=insertar_ptr;
    }
int nodo::leer(int dato){
    cin>>dato;
    return dato;
}

void nodo::imprimelista(){
    nodo *p = cabeza_ptr;
    while (p != NULL){
        cout<<setw(4)<<p -> dato;
        p = p ->siguiente;
    }
    cout<<endl;
}
int Menu(int opcion){
     cout<<"1)InsertarCabezaLista\n";
     cout<<"2)Imprimir Lista\n";
     cout<<"3)Salir\n";
     cout<<"\n\nOpcion: ";
     cin>>opcion;
     return opcion;
}

int main(){
    nodo n;
    int x;
    int opcion;
    do{
        opcion = Menu(opcion);
        switch(opcion){
            case 1:
                 cout<<"Ingresa el dato: ";
                 x = n.leer(x);
                 n.InsertarCabezaLista(x);
                 cout<<"El dato fue insertado";
                 break;
            case 2:
                 n.imprimelista();
                 break;
            case 3:
                 return 0;
                 break;
            default:
                 cerr<<"Error";
                 break;
        }
        cin.get();
        cin.get();
        system("cls");
    }while(opcion != 3);
    return EXIT_SUCCESS;
}
