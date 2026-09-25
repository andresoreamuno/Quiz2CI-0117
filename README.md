## Resultados de Ejecución
**Andres Oreamuno A43842**

**Bryan Jiménez C4G330**

A continuación se muestran los escenarios de prueba ejecutados para verificar el comportamiento de la sincronización de hilos y el uso de semáforos bajo diferentes niveles de concurrencia.

---

### Escenario 1: 5 Filósofos y 6 Palillos

> Se evidencia la ejecución de hilos concurrentes donde múltiples filósofos consiguen adquirir recursos al mismo tiempo sin bloquearse, completando sus ciclos de comer, pensar y liberar palillos de forma coordinada.

```text
Filosofo 2 entra en espera por palillos
Filosofo 2 obtiene palillos comiendo (filosofo 2)
Filosofo 1 entra en espera por palillos
Filosofo 3 entra en espera por palillos
Filosofo 4 entra en espera por palillos
Filosofo 0 entra en espera por palillos
Filosofo 0 obtiene palillos comiendo (filosofo 0)
pensando (filosofo 2)
pensando (filosofo 0)
Filosofo 0 libera palillos 
Filosofo 2 libera palillos 
Filosofo 1 obtiene palillos comiendo (filosofo 1)
Filosofo 3 obtiene palillos comiendo (filosofo 3)
pensando (filosofo 1)
pensando (filosofo 3)
Filosofo 1 libera palillos 
Filosofo 3 libera palillos 
Filosofo 4 obtiene palillos comiendo (filosofo 4)
pensando (filosofo 4)
Filosofo 4 libera palillos
```
### Escenario 2: 10 Filósofos y 11 Palillos

En esta ejecución con 10 hilos en se aprecia cómo el sistema operativo alterna la ejecución de manera fluida con filósofos no adyacentes que obtienen sus recursos e ingresan a comer al mismo tiempo, liberando sus palillos para permitir que los hilos en cola continúen ordenadamente sin bloqueos.

```text
Filosofo 0 entra en espera por palillos
Filosofo 0 obtiene palillos comiendo (filosofo 0)
Filosofo 3 entra en espera por palillos
Filosofo 3 obtiene palillos comiendo (filosofo 3)
Filosofo 1 entra en espera por palillos
Filosofo 2 entra en espera por palillos
Filosofo 5 entra en espera por palillos
Filosofo 5 obtiene palillos comiendo (filosofo 5)
Filosofo 6 entra en espera por palillos
Filosofo 4 entra en espera por palillos
Filosofo 7 entra en espera por palillos
Filosofo 8 entra en espera por palillos
Filosofo 9 entra en espera por palillos
pensando (filosofo 0)
pensando (filosofo 5)
pensando (filosofo 3)
Filosofo 0 libera palillos 
Filosofo 1 obtiene palillos comiendo (filosofo 1)
Filosofo 3 libera palillos 
Filosofo 5 libera palillos 
Filosofo 4 obtiene palillos comiendo (filosofo 4)
Filosofo 6 obtiene palillos comiendo (filosofo 6)
pensando (filosofo 1)
pensando (filosofo 4)
pensando (filosofo 6)
Filosofo 1 libera palillos 
Filosofo 2 obtiene palillos comiendo (filosofo 2)
Filosofo 4 libera palillos 
Filosofo 6 libera palillos 
Filosofo 7 obtiene palillos comiendo (filosofo 7)
pensando (filosofo 2)
pensando (filosofo 7)
Filosofo 2 libera palillos 
Filosofo 7 libera palillos 
Filosofo 8 obtiene palillos comiendo (filosofo 8)
pensando (filosofo 8)
Filosofo 8 libera palillos 
Filosofo 9 obtiene palillos comiendo (filosofo 9)
pensando (filosofo 9)
Filosofo 9 libera palillos
```

### Escenario 3: 8 Filósofos y 8 Palillos

> En esta ejecución se evalúa el problema clásico donde la cantidad de filósofos es exactamente igual a la cantidad de palillos. A diferencia de los escenarios anteriores con palillos extra, aquí no hay recursos sobrantes en la mesa.

```text
Filosofo 0 entra en espera por palillos
Filosofo 0 obtiene palillos comiendo (filosofo 0)
Filosofo 1 entra en espera por palillos
Filosofo 2 entra en espera por palillos
Filosofo 3 entra en espera por palillos
Filosofo 5 entra en espera por palillos
Filosofo 5 obtiene palillos comiendo (filosofo 5)
Filosofo 4 entra en espera por palillos
Filosofo 6 entra en espera por palillos
Filosofo 7 entra en espera por palillos
pensando (filosofo 0)
pensando (filosofo 5)
Filosofo 0 libera palillos 
Filosofo 1 obtiene palillos comiendo (filosofo 1)
Filosofo 6 obtiene palillos comiendo (filosofo 6)
Filosofo 5 libera palillos 
pensando (filosofo 1)
pensando (filosofo 6)
Filosofo 1 libera palillos 
Filosofo 2 obtiene palillos comiendo (filosofo 2)
Filosofo 7 obtiene palillos comiendo (filosofo 7)
Filosofo 6 libera palillos 
pensando (filosofo 7)
pensando (filosofo 2)
Filosofo 7 libera palillos 
Filosofo 2 libera palillos 
Filosofo 3 obtiene palillos comiendo (filosofo 3)
pensando (filosofo 3)
Filosofo 3 libera palillos 
Filosofo 4 obtiene palillos comiendo (filosofo 4)
pensando (filosofo 4)
Filosofo 4 libera palillos
