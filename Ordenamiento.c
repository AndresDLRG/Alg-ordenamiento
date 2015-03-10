#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20000

/*Este programa compara diferente metodos de ordenacion*/
//Prototipos
void burbuja(int *ar,int cantidad);
void burbujaM(int *ar,int cantidad);
void crearArreglo(int *arreglo, int cantidad);
unsigned long qs(int lista[],int limite_izq,int limite_der);
void quicksort(int ar[],int cantidad);
void mostrarArreglo(int *ar, int cant);

int main(void)
{
	int arreglo[MAX];
	int opc;
	
	crearArreglo(arreglo,sizeof(arreglo)/sizeof(int));
	do{
		printf("-------------MENU---------------\n");
		printf("1-REALIZAR METODO BURBUJA\n");
		printf("2-REALIZAR METODO BURBUJA MEJORADA\n");
		printf("3-REALIZAR METODO QUICKSORT\n");
		scanf("%d",&opc);
	}while(opc < 0 && opc >3);
	switch(opc)
	{
	case 1:
		burbuja(arreglo,sizeof(arreglo)/sizeof(int));
		break;
	case 2:
		burbujaM(arreglo,sizeof(arreglo)/sizeof(int));
		break;
	case 3:
		quicksort(arreglo,sizeof(arreglo)/sizeof(int));
		break;
	
	}
	fflush(stdin);
	getchar();
	
	return 0;
}
//----------------------------------------
void burbuja(int *ar,int cantidad)
{
	int aux, i, j;
	unsigned long comparaciones = 0;
	
	clock_t inicio = clock();
	for (i = 0; i < cantidad ; i++) 
	{
	     for (j = 0; j < cantidad ; j++) 
		 {
	             if (ar[i] < ar[j]) 
				 {
	                    aux = ar[i];
	                    ar[i] = ar[j];
	                    ar[j] = aux;
	             }
	             comparaciones++;
	    }
	}
	clock_t fin = clock();
	mostrarArreglo(ar,cantidad);
	printf("\n\nMETODO BURBUJA");
	printf("\n\nEl tiempo que tardo la ordenacion fue de %Lf milisegundos\n",((double)(fin-inicio))/CLOCKS_PER_SEC*1000);
	printf("El numero de comparaciones fue %lu",comparaciones);
}
//----------------------------------------------------
void burbujaM(int *ar,int cantidad)
{
	int aux, i, j;
	unsigned long comparaciones = 0;
	
	clock_t inicio = clock();
	for (i = 0; i < cantidad ; i++) 
	{
	     for (j = i+1; j < cantidad ; j++) 
		 {
	             if (ar[i] > ar[j]) 
				 {
	                    aux = ar[i];
	                    ar[i] = ar[j];
	                    ar[j] = aux;
	             }
	             comparaciones++;
	    }
	}
	clock_t fin = clock();
	mostrarArreglo(ar,cantidad);
	printf("\n\nMETODO BURBUJA MEJORADA");
	printf("\n\nEl tiempo que tardo la ordenacion fue de %Lf milisegundos\n",((double)(fin-inicio))/CLOCKS_PER_SEC*1000);
	printf("El numero de comparaciones fue %lu",comparaciones);
}
//----------------------------------------------------
void quicksort(int ar[],int cantidad)
{
	int tam;
	unsigned long co;
	tam = sizeof(ar);
	clock_t inicio = clock();
	co = qs(ar,0,cantidad-1);
	clock_t fin = clock();
	mostrarArreglo(ar,cantidad);
	printf("\n\nMETODO QUICKSORT");
	printf("\n\nEl tiempo que tardo la ordenacion fue de %Lf milisegundos\n",((double)(fin-inicio))/CLOCKS_PER_SEC*1000);
	printf("El numero de comparaciones fue %lu",co);
}
//----------------------------------------------------

unsigned long qs(int lista[],int limite_izq,int limite_der)
{
	int izq,der,temporal,pivote;
	static int cont=0;
		
	izq=limite_izq;	
	der = limite_der;	
	pivote = lista[(izq+der)/2];	
	do{	
	    while(lista[izq]<pivote && izq<limite_der)izq++;	
	    while(pivote<lista[der] && der > limite_izq)der--;	
	    if(izq <=der)	
	    {	
	        temporal= lista[izq];	
	        lista[izq]=lista[der];	
	        lista[der]=temporal;	
	        izq++;	
	        der--;
	    }
	    cont++;
	}while(izq<=der);
	if(limite_izq<der){qs(lista,limite_izq,der);}	
	if(limite_der>izq){qs(lista,izq,limite_der);}	
	return cont;
}
//----------------------------------------------------
void crearArreglo(int *arreglo, int cantidad)
{
	int x = 0, cont = 0;
	srand((unsigned)time(NULL) );
	for(x = 0; x < cantidad; x++)
		arreglo[x] = (rand()%2001)-1000;
	printf("El orden del arreglo original es:\n");
	for(x = 0; x < cantidad; x++)
	{
		if(cont%10 == 0)
			putchar('\n');
		printf("%5d  ",arreglo[x]);
		cont++;
	}
	printf("\n\n");
}
//--------------------------------------------------
void mostrarArreglo(int *ar, int cant)
{
	int i;
	for(i = 0; i < cant; i++)
		printf("\narreglo[%d] = %d",i,ar[i]);
}
