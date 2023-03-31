// licuados.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

#include "Bidon.h";


int main()
{
	Bidon bidonBanana;

	std::cout << bidonBanana.getSabor() << std::endl;
	std::cout << bidonBanana.getCapacidad() << std::endl;

	bidonBanana.setSabor("Tamatindo");
	bidonBanana.setCapacidad(40.0f);

	std::cout << "Datos cargados" << std::endl;
	std::cout << bidonBanana.getSabor() << std::endl;
	std::cout << bidonBanana.getCapacidad() << std::endl;
}

