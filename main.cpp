#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
class Empleado{
private:
	char *nombre;
	char *paterno;
	static int cuenta;
public:
	Empleado(const char*, const char*);
	~Empleado();
	const char *getNombre() const;
	const char *getPaterno() const;
	static int getCuenta();
};

int Empleado::cuenta=0;
int Empleado::getCuenta(){return cuenta;}
Empleado::Empleado(const char *nom, const char *pat)
{
	nombre=new char[strlen(nom)+1];
	assert(nombre!=0);
	strcpy(nombre,nom);
	paterno=new char[strlen(pat)+1];
	assert(paterno!=0);
	strcpy(paterno,pat);
	++cuenta;
	cout <<"Constructor de Empleado para "<<nombre
	    << " " << paterno << " llamado." << endl;
}

Empleado::~Empleado()
{
	cout << "~Empleado() llamado para " <<nombre
	     << " " << paterno <<endl;
	delete [] nombre;
	delete [] paterno;
	--cuenta;
}
const char *Empleado::getNombre() const{return nombre;}
const char *Empleado::getPaterno() const{return paterno;}
int main(int argc, char** argv) {
	cout <<"El numero de empleados antes de crear la instancia es: "
	     <<Empleado::getCuenta()<<endl;
	Empleado *ptrE1 = new Empleado("Susana", "Baez");
	Empleado *ptrE2 = new Empleado("Roberto","Jimenez");
	
	cout <<"El numero de empleados despues de crear la instancia es: "
	     <<Empleado::getCuenta()<<endl;  
	cout <<"\n\nEmpleado 1: "
	     <<ptrE1->getNombre()
	     <<" "<<ptrE2->getPaterno()
	     <<"\n\nEmpleado 2: "
	     <<ptrE2->getNombre()
	     <<" "<<ptrE2->getPaterno()<<"\n\n";
	delete ptrE1;
	ptrE1=0;
	delete ptrE2;
	ptrE2=0;
	cout <<"\nEl numero de empleados despues de la eliminacion es: "
	     <<Empleado::getCuenta()<<endl; 
	     
	return 0;
}
