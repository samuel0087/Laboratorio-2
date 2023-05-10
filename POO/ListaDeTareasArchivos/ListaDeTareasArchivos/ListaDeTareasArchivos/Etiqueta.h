#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class Etiqueta{
	private:
		char _nombre[10][21];
		int _cantidad;

	public:
		Etiqueta();
		bool setNombre(std::string tag);

		int getCantidad();
		std::string* getNombre();

		void mostrar();
};

