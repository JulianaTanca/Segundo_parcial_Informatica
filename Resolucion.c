#include <stdlib.h>
#include <stdio.h>
void cantprom(intmat[][16],int,int); //1//
void cantmax(intmat[][16],int,int); //2//
void interprom(intmat[][16],int,int); //3//
void infmax(intmat[][16],int,int); //4//
void bajosarch(intmat[][16],int,int); //5//
void menorsens(intmat[][16],int,int); //6//
main ()
{ int opcion, c, anomalias[25][16], i, j;
 FILE*arch; 
 // Punto A //
 
 arch= fopen("monitoreo.dat","rb");
 if( arch==NULL )
   { perror("Error al leer archivo");
  exit(1);
 }
 
 c= fread(anomalias, sizeof anomalias, 1, arch);
 if( c!=1 )
   { perror("Error al leer archivo");
  exit(1);
 }
 
 c= fclose(arch);
 if( c!=0 )
   { perror("Error al leer archivo");
  exit(1);
 }
 
 // Punto B //
 printf("sensor/hora");
 
 for(i=0, j<16, j++)
 { printf( "%d \t", j+7);
 }
 
 printf("\n");
 for(i=0, i<25, i++)
 { printf("s %d", i+1);
  for(j=0, j<16, j++)
  {printf("%d \t", anomalias[i][j]);
  }
  printf("\n");
 }
 
 // Punto C //
 
 do{
   printf("Elija una opcion \n");
   printf("1. Cantidad promedio general de todas las anomalias \n 2. Maxima cantidad de anomalias junto con sensor y hora en que se produjo \n 3. Promedio diario de anomalias para un intervalo horario \n 5. Sensor y hora de anomalias menores al 90% del maximo del conjunto y superiores al promedio general \n 6. Guardar los datos de la opcion 7 en un archivo \n 7. Mostrar el sensor que tomo el menor registro de anomlias, por hora \n 8. Salir del programa \n");
   scanf("%d", &opcion);
   switch(opcion)
   {   //1//
       case1: cantprom(anomalias, 25, 16);
              break;
       //2//
       case2: cantmax(anomalias, 25, 16);
              break;
       //3//
       case3: sensprom(anomalias, 16);
              break;
       //4//
       case4: interprom(anomalias, 25;
              break;
       //5//
       case5: infmax(anomalias, 25, 16);
              break;
       //6//
       case6: bajosarch(anomalias, 25, 16);
              break;
       //7//
       case7: menorsens(anomalias, 25, 16);
              break;
       //8//
       case8: break;
       default printf("Elija una opcion valida");
    }} while(opcion !=8);
     return 0;
    }
                     
       
