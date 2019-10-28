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
        void ordenarAscendente();
        int Menu(int);
        int dato;
        class snodo * siguiente;
}nodo;

nodo *cabeza_ptr = NULL;

void nodo::ordenarAscendente()
{
    if (cabeza_ptr!=NULL)
    {
     nodo *siguiente=NULL;
     siguiente=cabeza_ptr->siguiente;
     bool bandera=true;
     while((siguiente!=NULL) && (bandera==true))
     {
     bandera=false;
     nodo *anterior=NULL;
     anterior=cabeza_ptr;
      while(siguiente!=NULL)
       {
         if (anterior->dato>siguiente->dato)
           { int x;
             x=anterior->dato;
             anterior->dato=siguiente->dato;
             siguiente->dato=x;
             bandera=true;
           }
          anterior=anterior->siguiente;
          siguiente=siguiente->siguiente;
        }
        siguiente=cabeza_ptr->siguiente;
     }
    }
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
     cout<<"2)Imprimir Lista\n";
     cout<<"3)OrdernarAscendente\n";
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
                 n.imprimelista();
                 break;
            case 3:
                n.ordenarAscendente();
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
