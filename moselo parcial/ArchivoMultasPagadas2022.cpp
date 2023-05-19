#include "ArchivoMultasPagadas2022.h"
#include <cstdio>

ArchivoMultasPagadas2022::ArchivoMultasPagadas2022()
{
    _ruta = "ArchivoMultasPagadas2022.dat";
}

ArchivoMultasPagadas2022::ArchivoMultasPagadas2022(std::string ruta)
{
    _ruta = ruta;
}

int ArchivoMultasPagadas2022::getCantidadRegistros()
{
    FILE* p = fopen(_ruta.c_str(), "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Multa);
}

bool ArchivoMultasPagadas2022::guardar(Multa reg)
{
    FILE* p = fopen(_ruta.c_str(), "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Multa), 1, p);
    fclose(p);
    return pudoEscribir;
}


Multa ArchivoMultasPagadas2022::leer(int nroRegistro)
{
    Multa aux;
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Multa), SEEK_SET);
    fread(&aux, sizeof(Multa), 1, p);
    fclose(p);
    return aux;
}

void ArchivoMultasPagadas2022::leer(Multa* vec, int cantidadRegistrosALeer) {
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return;
    }

    fread(vec, sizeof(Multa), cantidadRegistrosALeer, p);
    fclose(p);
}

int ArchivoMultasPagadas2022::buscar(int ID)
{
    int i, cantidadRegistros = this->getCantidadRegistros();
    Multa aux;

    for (i = 0; i < cantidadRegistros; i++)
    {
        aux = this->leer(i);
        if (aux.getIDMulta() == ID)
        {
            return i;
        }
    }
    return -1;
}

void ArchivoMultasPagadas2022::vaciar() {
    FILE* p = fopen(_ruta.c_str(), "wb");
    if (p == NULL)
    {
        return;
    }
    fclose(p);
}
