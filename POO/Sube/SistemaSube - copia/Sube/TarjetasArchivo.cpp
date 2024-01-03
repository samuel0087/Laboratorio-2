#include "TarjetasArchivo.h"

TarjetasArchivo::TarjetasArchivo()
{
    strcpy(_ruta, "tarjetas.dat");
}

TarjetasArchivo::TarjetasArchivo(const char* ruta = "tarjetas.dat")
{
    strcpy(_ruta, ruta);
}

int TarjetasArchivo::guardar(Tarjeta reg){
    FILE* archivoT = fopen(_ruta, "ab");

    if(archivoT == NULL){
        return -1;
    }

    int result = fwrite(&reg, sizeof(Tarjeta), 1, archivoT);
    fclose(archivoT);
    return result;
}

int TarjetasArchivo::guardar(Tarjeta reg, int pos){
    FILE* archivoT = fopen(_ruta, "rb+");

    if(archivoT == NULL){
        return -1;
    }

    fseek(archivoT, sizeof(Tarjeta) * pos, SEEK_SET);
    int result = fwrite(&reg, sizeof(Tarjeta), 1, archivoT);
    fclose(archivoT);

    return result;
}

int TarjetasArchivo::buscarDni(int dni){
    FILE* archivoT = fopen(_ruta, "rb");
    Tarjeta reg;

    if(archivoT == NULL){
        reg.setNumeroTarjeta(-1);
        return -1;
    }

    int cantRegistros = getCantidadRegistros();
    for(int i = 0; i < cantRegistros; i++){
        reg = leer(i);

        if(reg.getDniUsuario() == dni){
            return i;
        }
    }

    return -2;
}

int TarjetasArchivo::buscar(int numTarjeta){
    Tarjeta reg;

    int cantRegistros = getCantidadRegistros();
    for(int i = 0; i < cantRegistros; i++){
        reg = leer(i);

        if(reg.getNumeroTargeta() == numTarjeta){
            return i;
        }
    }

    return -1;
}

Tarjeta TarjetasArchivo::leer(int pos){
    FILE* archivoT = fopen(_ruta, "rb");
    Tarjeta reg;

    if(archivoT == NULL){
        reg.setNumeroTarjeta(-1);
        return reg;
    }

    fseek(archivoT, sizeof(Tarjeta) * pos, SEEK_SET);
    fread(&reg, sizeof(Tarjeta), 1, archivoT);
    fclose(archivoT);

    return reg;
}

void TarjetasArchivo::leer(Tarjeta* tarjetas, int cantidadRegistros){
    FILE* archivoT = fopen(_ruta, "rb");

    if(archivoT == NULL){
        return;
    }

    fread(&tarjetas, sizeof(Tarjeta), cantidadRegistros, archivoT);
    fclose(archivoT);

}

int TarjetasArchivo::getCantidadRegistros(){
    FILE* archivoT = fopen(_ruta, "rb");

    if(archivoT == NULL){
        return -1;
    }

    fseek(archivoT, 0, SEEK_END);
    int byte = ftell(archivoT);
    int result = byte / sizeof(Tarjeta);
    fclose(archivoT);

    return result;
}

