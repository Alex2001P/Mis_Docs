#include <stdio.h>
#include <pthread.h>
/*thread function definition*/
void* carro1(void* args)
{
    while(1)
    {
        printf("Soy el carro 1.\n");
    }
}
void* carro2(void* args)
{
    while(1)
    {
        printf("Soy el carro 2.\n");
    }
}

int main()
{
    /*creating thread id*/
    pthread_t id1;
    int ret1;
    
    /*creating thread*/
    ret1=pthread_create(&id1,NULL,&carro1,NULL);
    if(ret1==0){
        printf("Se creo exitosamente hilo para carro 1.\n");
    }
    else{
        printf("No se pudo crear el hilo para el carro 1.\n");
        return 0; /*return from main*/
    }
    
     /*creating thread id*/
    pthread_t id2;
    int ret2;

    /*creating thread*/
    ret2=pthread_create(&id2,NULL,&carro2,NULL);
    if(ret2==0){
        printf("Se creo exitosamente hilo para carro 2.\n");
    }
    else{
        printf("No se pudo crear el hilo para el carro 2.\n");
        return 0; /*return from main*/
    }


    while(1)
    {
        printf("Soy el programa principal.\n");      
    }
    
    return 0;
}
// gcc carros.c -o carros -lpthread
// codigo para poder compilar en la terminal seguido de ./carros
