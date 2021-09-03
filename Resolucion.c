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
 
 for(i=0; j<16; j++)
 { printf( "%d \t", j+7);
 }
 
 printf("\n");
 for(i=0; i<25; i++)
 { printf("s %d", i+1);
  for(j=0; j<16; j++)
  { printf("%d \t", anomalias[i][j]);
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
    
    // Punto 1 //
                        
     void cantprom(mat[][16], nf, nc)
       { int i, j, suma=0, cantidad;
         float prom;
         for(i=0; i<nf; i++)
         { for(j=0; j<nc; j++)
          { suma= suma + mat[i][j];
          }
         }
         cantidad= nf*nc;
         prom= suma/(float)cantidad;
         print("El promedio es de %f", prom);
         return;
         }
     
    // Punto 2 //
                        
       void cantmax(mat[][16], nf, nc)
         { int i, j, maximo=0;
           for(i=0; i<nf, i++)
           { for(j=0, j<nc, j++)
             { if(mat[i][j]> maximo)
               { maximo=mat[i][j];
               }
             }
           }
           printf("El maximo es %d y sucede en los siguientes sensores y horas \n", maximo);
           for(i=0, i<nf, i++)
           { for(j=0, j<nc, j++)
             { if( mat[i][j]==maximo)
               { printf("%d \t %d", j+7, i+1);
               }
             }
            }
           return;
          }
                        
     // Punto 3 //
                        
      void sensprom(mat[][16], nc)
         { int j, numsensor, suma=0;
           float prom;
           print("Ingrese el numero de sensor \n");
           scanf("%d", &numsensor);
           for(j=0; j<nc; j++)
           { suma= suma+mat[numsensor-1][j];
             }
           prom=suma/(float)nc;
           printf("El promedio del sensor %d es %f", numsensor, prom);
           return;
         }
                        
     // Punto 4 //
                        
      void interprom(mat[][16], nf)
         { int i, horario, suma=0;
           float prom;
           printf("Ingrese el intervalo horario \n");
           scanf("%d",&horario);
           for(i=0; i<nf; i++)
           { suma=suma+mat[i][horario-7];
           }
           prom=suma/(float)nf;
           printf("El promedio del horario %d es %f", horario, prom);
           return;
           }
                        
      // Punto 5 //
                        
       void infmax(mat[][16], nf, nc)
          { int i, j, suma=0, cantidad, maximo=0, porc1, bandera=0;
            float prom, porc2;
            // Busco promedio general //
            for(i=0; i<nf; i++)
            { for(j=0, j<nc; j++)
              { suma=suma+mat[i][j];
              }
            }
            cantidad=nf*nc;
            prom=suma/(float)cantidad;
            // Busco maximo del conjunto //
            for(i=0, i<nf, i++)
            { for(j=0, j<nc, j++)
              { if(mat[i][j]>maximo)
                { maximo= mat[i][j];
                }
              }
            }
            porc1=maximo*90;
            porc2=porc1/100.0;
            // Busco pares //
            printf("Los sensores y horas son \n");
            for(i=0; i<nf; i++)
            { if(mat[i][j] < porc2 && mat[i][j]>prom)
              { printf("%d \t %d", i+1, j+7);
                bandera++;
              }
            }
            if(bandera==0)
            { printf("No hay anomalia que cumpla las condiciones");
            }
            return;
            }
                        
       // Punto 6 //
                        
        void bajosarch(mat[][16], nf, nc)
           { FILE* archivo;
             int i, j, minimo=10000, menor[][1], k=;
             for(i=0; i<nf; i++)
             { if(mat[i][j]< minimo)
               { minimo=mat[i][j];
               }
             }
             // Hago una matriz de n filas y dos columnas, en la primer columna se menciona la hora //
             // En la segunda columna se posicionan los sensores donde se detecta el menor valor //
             // Si se repite, muestra más de un sensor por hora //
             for(i=0; i<nf; i++)
             { if(mat[i][j]==minimo)
               { menor[k][0]= j+7;
                 menor[k][1]= i+1;
                 k+1;
               }
             minimo=10000;
             }
             archivo=fopen("bajos.dat","wb");
             if(archivo==NULL)
             { perror("Error al abrir archivo");
               exit(1);
             }
             c= fwrite(menor, sizeof menor, 1, archivo);
             if(c!=1)
             { perror("Error al guardar archivo");
               exit(1);
             }
             c=fclose(archivo);
             if(c!=0)
             { perror("Error al cerrar archivo");
               exit(1);
             }
             return;
             }
                        
        // Punto 7 //
                        
         void menorsens(mat[][16], nf, nc)
            { int i, j, minimo=10000, menor[][1], k=0, limite;
              for(j=0; j<nc; j++)
              { for(i=0; i<nf; i++)
                { if(mat[i][j]<minimo)
                  { minimo=mat[i][j];
                  }
                  for(i=0; i<nf; i++)
                  { if(mat[i][j]==minimo)
                    { menor[k][0]= j+7;
                      menor[k][1]=i+1;
                      k++;
                    }
                  }
                  minimo=10000;
                  }
                  // Muestro la matriz //
                  limite=nf*nc;
                  for(i=0; i<limite; i++)
                  { for(j=0; j<2; j++)
                    { printf("%d \t", menor[i][j]);
                    }
                    print("\n");
                  }
                  return;
              }
                        
                        
