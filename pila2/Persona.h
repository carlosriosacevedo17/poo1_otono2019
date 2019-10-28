#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
class Persona
{
	public:
		string getNombre();
		int getEdad();
	    void setNombre(string);
	    void setEdad(int);
	private:
		string nombre;
		int edad;
};

#endif
