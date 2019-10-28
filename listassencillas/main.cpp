#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef class snodo{
    public:
        bool agregar(int);
        bool push(int);
        void imprimelista();
        int leer(int);
        bool buscar(int);
        bool borrar(int);
        bool limpiar();
        bool vaciar();
        int Menu(int);
        int dato;
        class snodo * siguiente;
}nodo;

nodo *lista = NULL;

bool nodo::agregar(int x){
    if(lista == NULL){//listaa vacia
        lista = new nodo;lista -> dato = x;
        lista -> siguiente = NULL;
        return true;}
    nodo *p = lista;//lista no vacia
    nodo *q;
    //buscar lugar de la insercion
    while(p != NULL && p -> dato < x){
         q = p;
         p = p -> siguiente;
    }//insercion por el final de la lista
    if(p == NULL){
        nodo *aux = new nodo;
        aux -> dato = x;
        aux -> siguiente = NULL;
        q -> siguiente = aux;
    }//insercion
    //el nuevo dato ya existente
    else{
        if(p -> dato == x)  return false;
        if(p == lista){//agregacion por el inicio
            nodo *aux = new nodo;
            aux -> dato = x;lista = aux;aux -> siguiente = p;}
        else{//gregacion a la mitad de la lista
            nodo *aux = new nodo;
            aux -> dato = x;
            q -> siguiente = aux;
            aux ->siguiente = p;}
    }
    return true;}

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




int nodo::leer(int dato){
    cin>>dato;
    return dato;
}

void nodo::imprimelista(){
    nodo *p = lista;
    while (p != NULL){
        cout<<setw(4)<<p -> dato;
        p = p ->siguiente;
    }
    cout<<endl;
}

bool nodo::buscar(int x){
     nodo *p = lista;
     while(p != NULL && p -> dato <= x){
         if(p -> dato == x)
             return true;
         else
             p = p -> siguiente;
     }
     return false;
}

bool nodo::borrar(int x){//Mal
    nodo *p = lista;
    nodo *q;
    while((p != NULL) && (p -> dato <= x)){
        if(p -> dato == x){
            if(p == lista)
                lista = p -> siguiente;
            else{
                q -> siguiente = p -> siguiente;
                delete p;
                return true;
            }
        }
        else{
            q = p;
            p = p -> siguiente;
        }
    }
    return false;
}

bool nodo::limpiar(){
    nodo *q;
    while(lista != NULL){
        q = lista;
        lista = lista -> siguiente;
        delete q;
    }
    lista = NULL;
    return true;
}

bool nodo::vaciar(){
     return lista == NULL;
}

int Menu(int opcion){
     cout<<"1)agregar\n";
     cout<<"2)buscar\n";
     cout<<"3)eliminar\n";
     cout<<"4)vaciar lista\n";
     cout<<"5)verificar si la lista esta vacia\n";
     cout<<"6)Imprimir Lista\n";
     cout<<"7)PUSH PILA\n";
     cout<<"8)Salir\n";
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
                 if(n.agregar(x)){
                     cout<<"El dato fue insertado";
                     n.imprimelista();
                 }
                 else
                     cout<<"el dato no fue insertado\n";
                 break;
            case 2:
                 x = n.leer(x);
                 if(n.buscar(x)){
                     cout<<"El dato fue encontrado";
                     n.imprimelista();
                 }
                 else
                     cout<<"el dato no fue encontrado\n";
                 break;
            case 3:
                 x = n.leer(x);
                 if(n.borrar(x)){
                     cout<<"El dato fue eliminado";
                     n.imprimelista();
                 }
                 else
                     cout<<"el dato no fue encontrado\n";
                 break;
            case 4:
                 if(n.limpiar()){
                     cout<<"la lista esta vacia";
                     n.imprimelista();
                 }
                 else
                     cout<<"la lista aun no esta vacia";
                 break;
            case 5:
                 if(n.vaciar()){
                     cout<<"la lista esta vacia";
                     n.imprimelista();
                 }
                 else
                     cout<<"la lista no esta vacia";
                 break;
            case 6:
                 n.imprimelista();
                 break;
            case 7:
                 cout<<"Ingresa el dato: ";
                 x = n.leer(x);
                 if(n.push(x)){
                     cout<<"El dato fue insertado";
                     n.imprimelista();
                 }
                 else
                     cout<<"el dato no fue insertado\n";
                 break;
            case 8:
                 n.limpiar();
                 return 0;
                 break;
            default:
                 cerr<<"Error";
                 break;
        }
        cin.get();
        cin.get();
        system("cls");
    }while(opcion != 8);
    return EXIT_SUCCESS;
}
