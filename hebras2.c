#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int valor = 1;

void *FuncionImpresion(void *args)
{   
    printf("\n");
    char *nombre = (char*)args;

    for(int i = valor; i < valor + 5; i++){
        printf("Hilo %s impresiones %d\n", nombre, i);
    }
    valor += 5;
    printf("\n");
    return NULL;
}

int main(void){
    pthread_t hebra1, hebra2, hebra3, hebra4, hebra5;

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

    printf("Fin del programa principal\n");

    return 0;
}