#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
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
		void cargar(int canTags);
};

