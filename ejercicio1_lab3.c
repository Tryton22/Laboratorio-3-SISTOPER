/*Laboratorio 3, Ejercicio 1.
Integrantes: Fonseca, Matías
             Oliva, Raimundo  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Inicializar la variable para los valores de la impresiones.
int valor = 1;

// Void con la funcion a ejecutar de los hilos. 
void *FuncionImpresion(void *args)
{   
    printf("\n");
    // Nombre de los hilos.
    char *nombre = (char*)args;

    // For para asignarle valores a las distintas impresiones.
    for(int i = valor; i < valor + 5; i++){
        printf("Hilo %s impresiones %d\n", nombre, i);
    }
    // Sumar 5 al valor para lograr el 25 al final del programa.
    valor += 5;
    printf("\n");
    return NULL;
}

// Main del programa.
int main(void){
    // Inicializar las 5 hebras.
    pthread_t hebra1, hebra2, hebra3, hebra4, hebra5;

    /*Creacion de las 5 hebras junto a un join para que se muestren
    en orden en la terminal.*/
    pthread_create(&hebra1, NULL, FuncionImpresion, "0");
    pthread_join(hebra1, NULL);
    pthread_create(&hebra2, NULL, FuncionImpresion, "1");
    pthread_join(hebra2, NULL);
    pthread_create(&hebra3, NULL, FuncionImpresion, "2");
    pthread_join(hebra3, NULL);
    pthread_create(&hebra4, NULL, FuncionImpresion, "3");
    pthread_join(hebra4, NULL);
    pthread_create(&hebra5, NULL, FuncionImpresion, "4");
    pthread_join(hebra5, NULL);
    
    // Print que indica la finalizacion del programa.
    printf("Fin del programa principal\n");

    return 0;
}