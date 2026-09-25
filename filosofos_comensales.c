#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define F 10//Cantidad de filosofos que quieren comer (cola)
#define P 5//Cantidad de palillos

pthread_t filosofos[F];
sem_t palillos[P];
int num_filosofo[F];

//Funciones filosofos
void pensar();
void tomar_palillos();
void comer();
void soltar_palillos();
int izquierda(int i);
int derecha(int i);
void* filosofo(void* arg);

int main(void)
{
    //Inicializa semaforos
    for (int i = 0; i < P; ++i) {
        sem_init(&palillos[i], 0, 1);
    }
    
    //hilos, 1 por filosofo
    for (int i = 0; i < F; i++)
    {
        num_filosofo[i] = i;
        int res_t = pthread_create(&filosofos[i], NULL, filosofo,&num_filosofo[i]);
        
        if (res_t > 0)
        {
            printf("Error al crear el hilo %d", i);
            return 1;
        }
    }
 
    for (int i = 0; i < F; i++) {
        pthread_join(filosofos[i], NULL);
    }

    return 0;
}

void pensar(int i)
{
    printf("pensando (filosofo %d)", i);
    sleep(1);
}

void comer(int i)
{
    printf("comiendo (filosofo %d)", i);
    sleep(1);
}

void tomar_palillos(int i)
{
    printf("Filosofo %d entra en espera por palillos", i);
    sem_wait(&palillos[derecha(i)]);
    sem_wait(&palillos[izquierda(i)]);
    printf("Filosofo %d obtiene palillos", i);
}

void soltar_palillos(int i)
{
    sem_post(&palillos[derecha(i)]);
    sem_post(&palillos[izquierda(i)]);
    printf("Filosofo %d libera palillos", i);
}

int izquierda(int i) {
    return i;
}

int derecha(int i) {
    return (i + 1) % F;
}

void* filosofo(void* arg){
    int i = *(int*) arg;
    
    tomar_palillos(i);
    comer(i);
    pensar(i);
    soltar_palillos(i);    
}