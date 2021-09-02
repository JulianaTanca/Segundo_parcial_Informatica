# Enunciado
Una empresa produce un equipamiento de automatización electrónica, que genera un archivo 
"monitoreo.dat" donde están almacenadas las anomalías registradas por 25 sensores (S1 a S25)
de una planta farmacéutica desde las 7 hasta las 22hs, lo que conforma una matriz de 25 
filas y 16 columnas. Se pide que el programa realice las siguientes tareas:

a- Leer el archivo en una matriz de 25x16.

b- Mostrar en forma mínimamente organizada todos los datos leídos.

c- Presentar un menú repetitivo con las siguientes opciones:

1- Mostrar cantidad promedio gral. de anomalías, tomando todos los registros.

2- Mostrar máxima cantidad de anomalías detectadas en toda la planta.
Indicar cantidad, sensor y a qué hora se produjo dicho registro.

3- Mostrar promedio diario para un cierto sensor (ej. S3).

4- Mostrar promedio diario de anomalías sensor por sensor para un intervalo horario 
determinado (ej. de 12 a 15 hs).

5- Indicar pares sensor/hora cuyas cantidades de anomalías sean inferiores al 90% del 
máximo del conjunto, y superiores al promedio general.

6- Generar un archivo "bajos.dat" con la información del punto 7.

7- Mostrar número de sensor que tomó el menor registro de anomalías, hora por hora (es
decir, son 16 valores).

8- Fin del menú.

IMPORTANTE! Implementar las opciones del menú que correspondan como funciones.
