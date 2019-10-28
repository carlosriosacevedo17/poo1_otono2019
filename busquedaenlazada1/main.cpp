#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef class snodo{
    public:
        void InsertarFinalLista(int);
        void imprimelista();
        int leer(int);
        bool limpiar();
        class snodo * Buscar(int);
        int Menu(int);
        int dato;
        class snodo * siguiente;
}nodo;

nodo *cabeza_ptr = NULL;

nodo* nodo::Buscar(int x)
{
    nodo *pos=cabeza_ptr;
    for(;pos!=NULL;pos=pos->siguiente)
        if (pos->dato==x)
           return pos;
    return NULL;
}

void nodo::InsertarFinalLista(int x){
    nodo *insertar_ptr= new nodo;
    insertar_ptr->dato=x;
    insertar_ptr->siguiente=NULL;
    if (cabeza_ptr==NULL)
       cabeza_ptr=insertar_ptr;
    else
       {
        nodo *ptr = cabeza_ptr;
        nodo *ultimo;
        while(ptr != NULL)
         {
          ultimo = ptr;
          ptr = ptr -> siguiente;
         }
        ultimo->siguiente=insertar_ptr;
       }
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
     cout<<"1)InsertarFinalLista\n";
     cout<<"2)Buscar en Lista\n";
     cout<<"3)Imprime en Lista\n";
     cout<<"4)Salir\n";
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
                 n.InsertarFinalLista(x);
                 cout<<"El dato fue insertado";
                 n.imprimelista();
                 break;
            case 2:
                 cout<<"Ingresa el dato: ";
                 x = n.leer(x);
                 cout<<"la direccion es: "<<n.Buscar(x)<<"/n";
                 break;
            case 3:
                 n.imprimelista();
                 break;
            case 4:
                 return 0;
                 break;
            default:
                 cerr<<"Error";
                 break;
        }
        cin.get();
        cin.get();
        system("cls");
    }while(opcion != 4);
    return EXIT_SUCCESS;
}
