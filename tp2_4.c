#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMA 5

struct Pc
{
    int velocidadProcesamiento;
    int anioFabricacion;
    char *tipo_cpu;
    int nucleos;
};
typedef  struct Pc ObjPc;

ObjPc cargarPc(char tiposCpu[6][10]);
void cargarCompus(ObjPc compus[], char tiposCpu[6][10]);
void mostrarCompus(ObjPc compus[]);
void compuMasVieja(ObjPc compus[]);
void compuMasVeloz(ObjPc compus[]);

int main(){
    srand(time(NULL));
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    ObjPc compus[TAMA];
    cargarCompus(compus, tipos);
    mostrarCompus(compus);
    compuMasVieja(compus);
    compuMasVeloz(compus);

    return 0;
}

// ii) Considera valores enteros aleatorios para la velocidad: entre 1 y 3, para el año: entre
// 2015 y 2024, para la cantidad de núcleos: entre 1 y 8.
ObjPc cargarPc(char tiposCpu[6][10]){
    ObjPc compu;
    compu.velocidadProcesamiento = 1 + rand()%3; //emtre 1 y 3
    compu.anioFabricacion = 2015 + rand()%10; //emtre 2015 y 2024
    compu.nucleos = 1 + rand()%8; //emtre 1 y 3    
    int posicionRandom = rand()%6;
    compu.tipo_cpu = tiposCpu[posicionRandom];
    return compu;
}
void cargarCompus(ObjPc compus[], char tiposCpu[6][10]){
    for (int i = 0; i < TAMA; i++) {
        compus[i] = cargarPc(tiposCpu);
    }
}
void mostrarCompus(ObjPc compus[]){
    for (int i = 0; i < TAMA; i++)
    {
        printf("---------------------------------------");
        printf("Compu %i: \n", i);
        printf("velocidad en GHz: %d\n", compus[i].velocidadProcesamiento);
        printf("anio de fabricacion: %d\n", compus[i].anioFabricacion);
        printf("cantidad de nucleos: %d\n", compus[i].nucleos);
        printf("tipo cpu: %s\n", compus[i].tipo_cpu);
    }
}
void compuMasVieja(ObjPc compus[]){ //falta agregar condicional para el caso que sea MAS de una la mas vieja
    int menor = compus[0].anioFabricacion;
    int posicion= 0;

    for (int i = 0; i < TAMA; i++)
    {
        if( compus[i].anioFabricacion < menor){
            menor = compus[i].anioFabricacion;
            posicion = i;
        }
    }
    printf("---------------------------------------");
    printf("La compu mas VIEJA es la PC Num %d \n", posicion);
    printf("Sus caracteristicas son: \n");
    printf("--->velocidad en GHz: %d\n", compus[posicion].velocidadProcesamiento);
    printf("--->anio de fabricacion: %d\n", compus[posicion].anioFabricacion);
    printf("--->cantidad de nucleos: %d\n", compus[posicion].nucleos);
    printf("--->tipo cpu: %s\n", compus[posicion].tipo_cpu);
}
void compuMasVeloz(ObjPc compus[]){ //falta agregar condicional para el caso que sea MAS de una las mas veloces
    int veloz = compus[0].velocidadProcesamiento;
    int posicion= 0;

    for (int i = 0; i < TAMA; i++)
    {
        if( compus[i].velocidadProcesamiento > veloz){
            veloz = compus[i].velocidadProcesamiento;
            posicion = i;
        }
    }
    printf("---------------------------------------");
    printf("La compu mss VELOZ es la PC Num %d \n", posicion);
    printf("Sus caracteristicas son: \n");
    printf("--->velocidad en GHz: %d\n", compus[posicion].velocidadProcesamiento);
    printf("--->anio de fabricacion: %d\n", compus[posicion].anioFabricacion);
    printf("--->cantidad de nucleos: %d\n", compus[posicion].nucleos);
    printf("--->tipo cpu: %s\n", compus[posicion].tipo_cpu);
}