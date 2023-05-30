#include "ViajesArchivo.h"

ViajesArchivo::ViajesArchivo(const char* ruta = "viajes.dat") {
	strcpy_s(_ruta, ruta);
}

int ViajesArchivo::guardar(Viaje reg) {
	FILE* archivoV;
	archivoV = fopen(_ruta, "ab");

	if (archivoV == NULL) {
		return -1;
	}

	int result = fwrite(&reg, sizeof(Viaje), 1, archivoV);
	fclose(archivoV);

	return result;
}

int ViajesArchivo::guardar(Viaje reg, int pos) {
	FILE* archivoV =  fopen(_ruta, "rb+");

	if (archivoV == NULL) {
		return -1;
	}

	fseek(archivoV, pos * sizeof(Viaje), SEEK_SET);
	int result = fwrite(&reg, sizeof(Viaje), 1, archivoV);
	fclose(archivoV);

	return result;
}

int ViajesArchivo::buscar(int numViaje) {
	Viaje reg;
	FILE* archivoV = fopen(_ruta, "rb");

	if (archivoV == NULL) {
		return -1;
	}

	int cantRegistros = getCantidadRegistros();

	for (int i = 0; i < cantRegistros; i++) {
		fread(&reg, sizeof(Viaje), 1, archivoV);
		if (reg.getNumViaje() == numViaje) {
			return i;
		}
	}

	fclose(archivoV);
	return -2;
}
Viaje ViajesArchivo::leer(int pos) {
	Viaje reg;
	reg.setNumViaje(-1);
	FILE* archivoV = fopen(_ruta, "rb");
	
	if (archivoV == NULL) {
		return reg;
	}

	fseek(archivoV, pos * sizeof(Viaje), SEEK_SET);
	fread(&reg, sizeof(Viaje), 1, archivoV);
	fclose(archivoV);

	return reg;
}

void ViajesArchivo::leer(Viaje* viajes, int cantidadRegistros) {
	FILE* archivoV = fopen(_ruta, "rb");

	if (archivoV == NULL) {
		return;
	}

	fread(&viajes, sizeof(Viaje), cantidadRegistros, archivoV);
	fclose(archivoV);
}

int ViajesArchivo::getCantidadRegistros() {
	FILE* archivoV = fopen(_ruta, "rb");
	
	if (archivoV == NULL) {
		return -1;
	}

	fseek(archivoV, 0, SEEK_END);
	int byte = ftell(archivoV);
	int cantidadRegistros = byte / sizeof(Viaje);

	fclose(archivoV);

	return cantidadRegistros;
}