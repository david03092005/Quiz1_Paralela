# Quiz1_Paralela

## 4.

### Tiempo de CPU y real.

El primer valor corresponde a los segundos de la CPU y el segundo son los segundos reales.

| tosses/threads | 1     | 2     | 4     | 8     | 32    | 64    |
|---------------|-------|-------|-------|-------|-------|-------|
| 1.000.000    | 1-2   | 2-1   | 3-1   | 4-1   | 4-1   | 4-1   |
| 10.000.000   | 14-14 | 21-10 | 28-7  | 42-5  | 43-5  | 45-5  |
| 100.000.000  | 142-141 | 201-101 | 295-74 | 520-70 | 525-65 | 505-64 |

Se puede observar que el tiempo de CPU aumenta con la cantidad de hilos, esto pasa porque se suman los tiempos de los hilos.

### Error respecto al valor de π

| tosses/threads | 1      | 2      | 4      | 8      | 32     | 64     |
|---------------|--------|--------|--------|--------|--------|--------|
| 1.000.000    | 0.0015 | 0.0019 | 0.0010 | 0.0048 | 0.0027 | 0.0012 |
| 10.000.000   | 0.0007 | 0.0011 | 0.0011 | 0.0009 | 0.0001 | 0.0017 |
| 100.000.000  | 0.0003 | 0.0002 | 0.0002 | 0.0007 | 0.0007 | 0.0006 |

El error se ve afectado por la cantidad de tiradas que se ejecutan, entre más tiradas más pequeño es el error, pero no hay una relación entre el error y la cantidad de hilos que se están usando.
