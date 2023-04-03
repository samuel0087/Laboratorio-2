#pragma once
#include <string>

class Bidon {
private:
	std::string _sabor;
	float _capacidad;
	int _ventas;

public:
	Bidon();	//Constructor

	void setSabor(std::string);
	void setCapacidad(float);

	std::string  getSabor();
	float getCapacidad();

	bool cargaVaso(float);

	int getVentas();

};

