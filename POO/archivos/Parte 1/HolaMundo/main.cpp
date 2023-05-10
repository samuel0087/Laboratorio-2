#include <iostream>
#include <cstring>
#include <locale.h>
#include <iomanip>
using namespace std;

#include "Pais.h"
#include "Ciudad.h"

void cargarCadena(char*, int);
bool buscarPais(const char*);
bool registrarPais();
bool listarPaises(const char*);
bool listarCiudades(const char*);
float superficieMundial();


int main()
{
    setlocale(LC_ALL, "");
    int opc;
    char cod[4];

    do{
        cout << "1 - Buscar un registro se pais por codigo" << endl;
        cout << "2 - Agregar registro de pais" << endl;
        cout << "3 - Listar todo los paises " << endl;
        cout << "4 - Listar cidudades y poblacion de un pais" << endl;
        cout << "5 - Listar paises y su superficie" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opc;

        system("cls");

        switch(opc){
            case 1:
                cout << "Ingrese codigo: ";
                cargarCadena(cod, 4);

                if(buscarPais(cod)){
                    cout << "El registro existe" << endl;
                }
                else{
                    cout << "NO EXISTE" << endl;;
                }
                break;

            case 2:
                if(registrarPais()){
                    cout << "Se registro correctamente" << endl;
                }
                else{
                    cout << "No se pudo registrar." << endl;
                }
                break;

            case 3:
                if(!listarPaises("ALL")){
                    cout << "No se pudo mostrar la lista de paises" << endl;
                }
                break;

            case 4:
                cout << "Ingrese codigo: ";
                cargarCadena(cod, 4);

                listarCiudades(cod);
                break;

            case 5:
                if(!listarPaises("SUPERFICIE")){
                    cout << "No se pudo mostrar la lista de paises" << endl;
                }

            case 0:
                break;
        }

    system("pause");
    system("cls");

    }while(opc != 0);

    return 0;
}

//Buscar un registro en el archivo de pais.
bool buscarPais(const char* codPais){
    FILE* pPais;
    Pais pais;

    pPais = fopen("paises.dat", "rb");

    if(pPais == NULL){
        cout << "No se pudo encontrar el archivo" << endl;
        return false;
    }

    while(fread(&pais, sizeof pais, 1, pPais) != 0){
        if(strcmp(pais.getCodigo(), codPais) == 0 || strcmp(pais.getCodigo2(), codPais) == 0){
            fclose(pPais);
            return true;
        }
    }

    fclose(pPais);

    return false;
}

bool registrarPais(){
    char codigo[4], codigo2[3], nombre[45], continente[20];
    float superficie, expectativaDeVida;
    int poblacion;
    short independencia;
    int capital;

    do{
        cout << "Ingrese codigo (3 letras): ";
        cargarCadena(codigo, 3);

        if(buscarPais(codigo)){
            cout << endl;
            cout << "Codigo existente, ingresar uno nuevo por favor" << endl;
        }
    }while(buscarPais(codigo));

    do{
        cout << "Ingrese codigo 2 (2 letras): ";
        cargarCadena(codigo2, 2);

        if(buscarPais(codigo2)){
            cout << endl;
            cout << "Codigo 2 existente, ingresar uno nuevo por favor" << endl;
        }
    }while(buscarPais(codigo2));

    cout << "Ingrese nombre: ";
    cargarCadena(nombre, 44);

    cout << "Ingrese CONTINENTE: ";
    cargarCadena(continente, 20);

    cout << "Ingrese superficie de pais: ";
    cin >> superficie;

    cout << "Ingrese poblacion: ";
    cin >> poblacion;

    cout << "Ingrese año de independencia: ";
    cin >> independencia;

    cout << "Expetativa de vida: ";
    cin >> expectativaDeVida;

    cout << "Ingrese Capital";
    cin >>capital;

    Pais pais;
    pais.setCodigo(codigo);
    pais.setCodigo2(codigo2);
    pais.setNombre(nombre);
    pais.setContinente(continente);
    pais.setSuperficie(superficie);
    pais.setPoblacion(poblacion);
    pais.setIndependencia(independencia);
    pais.setExpectativaDeVida(expectativaDeVida);
    pais.setIDCapital(capital);

    FILE* pPais;

    pPais = fopen("paises.dat", "ab");

    if(pPais == NULL){
        return false;
    }

    fwrite(&pais, sizeof pais, 1, pPais);

    fclose(pPais);

    return true;
}

bool listarPaises(const char * format ="ALL"){
    FILE* pPais;
    Pais pais;
    float superficieM = superficieMundial();

    pPais = fopen("paises.dat", "rb");

    if(pPais == NULL){
        cout << "No se pudo encontrar el archivo" << endl;
        return false;
    }

    while(fread(&pais, sizeof pais, 1, pPais) != 0){
        if(strcmp(format, "ALL") == 0){
            pais.mostrar();
        }
        else if(strcmp(format, "SUPERFICIE") == 0){
            cout << left;
            cout << setw(7) << "Pais:";
            cout << setw(45) << pais.getNombre();
            cout << setw(12) << "superficie:";
            cout << setw(9) << pais.getSuperficie();
            cout << "Ocupa el %" << setprecision(1) << (pais.getSuperficie() * 100 / superficieM) << endl;
        }
    }

    fclose(pPais);

    return true;
}



bool listarCiudades(const char* codPais){
    FILE* aCiudades;
    Ciudad ciudad;

    aCiudades = fopen("ciudades.dat", "rb");

    if(aCiudades == NULL){
        cout << "No se pudo encontrar el archivo" << endl;
        return false;
    }
    cout << left;
    cout << "|";
    cout << setw(30) << "      CIUDAD";
    cout << "|";
    cout << setw(15) << "   POBLACION";
    cout << "|" << endl;
    cout << "------------------------------------------------" << endl;

    while(fread(&ciudad, sizeof ciudad, 1, aCiudades) != 0){
        if(strcmp(ciudad.getIDPais(), codPais) == 0){
            cout << "|";
            cout << setw(30) << ciudad.getNombre();
            cout << "|";
            cout << setw(15) << ciudad.getPoblacion();
            cout << "|" << endl;
            cout << "------------------------------------------------" << endl;
        }
    }

    fclose(aCiudades);

    return false;
}


float superficieMundial(){
    FILE* pPaises;
    Pais pais;
    float acuSuperficie = 0.0f;

    pPaises = fopen("paises.dat", "rb");

    if(pPaises == NULL){
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    while(fread(&pais, sizeof(Pais), 1, pPaises) != 0){
        acuSuperficie += pais.getSuperficie();
    }

    fclose(pPaises);

    return acuSuperficie;
}


void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);

    for(i=0; i<tam; i++){
      pal[i]=cin.get();

	  if(pal[i]=='\n'){
        break;
	  }
    }

    pal[i]='\0';
    fflush(stdin);
}
