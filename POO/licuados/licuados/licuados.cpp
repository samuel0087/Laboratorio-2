// licuados.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <iomanip>

#include "Bidon.h";


int main()
{
	float vaso[3] = {10.0f, 0.2f, 0.3f};
	Bidon bidonBanana;
	Bidon bidonAnana;
	Bidon bidonSandia;
	int opcSabor = 1, opcVaso;
	bool status;


	//Carga los datos de los 3 de los bidones
	bidonBanana.setSabor("Banana");
	bidonBanana.setCapacidad(20.0f);

	bidonAnana.setSabor("Anana");
	bidonAnana.setCapacidad(35.0f);

	bidonSandia.setSabor("Sandia");
	bidonSandia.setCapacidad(45.0f);

	//ventas
	std::cout << "Ingrese el sabor del licuado (1-Banana, 2-Anana, 3-Sandia, 0-Salir):  ";
	std::cin >> opcSabor;

	while(opcSabor != 0){
	

		std::cout << "Ingrese la medida del vaso (1-150ml, 2-200ml, 3-300ml): ";
		std::cin >> opcVaso;

		switch (opcSabor) {
			case 1:
				status = bidonBanana.cargaVaso(vaso[opcVaso - 1]);
				if (!status) {
					std::cout << "No hay suficiente cantidad, pruebe con otro vaso o sabor" << std::endl;
					system("pause");
				}
				break;

			case 2:
				bidonAnana.cargaVaso(vaso[opcVaso - 1]);
				break;

			case 3:
				bidonSandia.cargaVaso(vaso[opcVaso - 1]);
				break;

			default:
				std::cout << "Ingrese una opcion del menu por favor" << std::endl;
				break;
		}

		system("cls");

		//ventas
		std::cout << "Ingrese el sabor del licuado (1-Banana, 2-Anana, 3-Sandia, 0-Salir):  ";
		std::cin >> opcSabor;

	}

	system("cls");
	std::cout << "Carga de datos terminada, gracias por elegirnos :)" << std::endl; 

	std::cout << std::left;
	std::cout << std::setw(40) << "------------------------------------------------" << std::endl;
	std::cout << std::setw(20) << "SABOR";
	std::cout << std::setw(10) << "LITROS";
	std::cout << std::setw(10) << "VENTAS" << std::endl;


	std::cout << std::setw(40) << "------------------------------------------------" << std::endl;
	std::cout << std::setw(20) << bidonBanana.getSabor();
	std::cout << std::setw(10) << bidonBanana.getCapacidad();
	std::cout << std::setw(10) << bidonBanana.getVentas() << std::endl;

	std::cout << std::setw(40) << "------------------------------------------------" << std::endl;

	std::cout << std::setw(20) << bidonAnana.getSabor();
	std::cout << std::setw(10) << bidonAnana.getCapacidad();
	std::cout << std::setw(10) << bidonAnana.getVentas() << std::endl;

	std::cout << std::setw(40) << "------------------------------------------------" << std::endl;

	std::cout << std::setw(20) << bidonSandia.getSabor();
	std::cout << std::setw(10) << bidonSandia.getCapacidad();
	std::cout << std::setw(10) << bidonSandia.getVentas() << std::endl;
	std::cout << std::setw(40) << "------------------------------------------------" << std::endl;
}

