//TRABAJO RECEPCION DE HOSPITAL
//PARTICIPANTES: Mario Sánchez García (55452), Brian Tomico Fernández (55487), Raul Ricaldi Esquivel (55423), Andres Torrejón Palomo (55489).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100


typedef struct
{
	char nombre[N];
	char apellido1[N];
	char apellido2[N];
	char DNI[14];
}TPaciente;

void FIntroduccion();
int FMenu();
int FBuscar();
int FRepeticion();
void LimpiarBufer();

int main()
{	
int bucle=1;
int eleccion;
int busqueda;
	
	FIntroduccion();

	while(bucle==1)
	{	eleccion=FMenu();
	
	switch (eleccion)
	{
		case 1:
			printf("\nentrar a consulta\n");
			break;
		case 2:
			busqueda = FBuscar();
			if(busqueda == 2)
				eleccion=1;
			if(busqueda == 0)
			{	
			break;
			}
		case 3:
			printf("\n Entrar a urgencias\n");
			break;
	}
	
	bucle=FRepeticion();
}

return 69;
	
}

void FIntroduccion()
{
  printf("Buenos d%cas, se encuentra en la recepci%cn del hospital ABRM, %cQu%c desea hacer?\n",161,162,168,130);      
}

int FMenu()							//ESTA FUNCION ABRE EL MENU
{
  int opcion;
  do{
  printf("1.Acceder a consulta\n");
  printf("2.Buscar datos de un paciente\n");
  printf("3.Acceder a Urgencias\n");
  
  scanf("%d",&opcion);
  fflush(stdin);
  
  if(opcion<1||opcion>3)				//Esto es un filtro para que la fucnion no devuelva opciones no validas
  { 
  	printf("Opcion no valida, escoja otra opcion por favor\n");
  }
  }while(opcion<1||opcion>3);
  
return opcion;
}

int FBuscar()									//ESTA FUCNION BUSCA PACIENTES
{
	TPaciente Dato;
	char comparar[N];
	char tecla;
	
	FILE*pf;	
	pf=fopen("Datosgenerales","r+");						//ABRIMOS LA LISTA DE DATOS GENERALES PARA LEER 
	printf("Introduzca el DNI de la persona que busca ");	
	scanf("%s", comparar);
	fflush(stdin);
	
									
	while (!feof (pf))         //LEER HASTA EL FINAL DEL ARCHIVO
	{
		
			
		fscanf(pf,"%s %s %s %s", Dato.nombre, Dato.apellido1, Dato.apellido2, Dato.DNI);
		fflush(stdin);
		
		if(strcmp(Dato.DNI,comparar)==0)					//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
		{
			printf("El paciente ha sido encontrado \n");   //SI EL STRING COINCIDE EL PACIENTE ESTA O HA ESTADO EN EL HOSPITAL
			return 1;												//	Aqui hay que abrir la ficha del paciente encontrado y mostrar las fechas de entrada y/o salida
			break;
		}
			
	}
	if(strcmp(Dato.DNI,comparar)!=0)	
	{																//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
			printf("No ha sido encontrado \n"); 
			puts ("\n\250Desea usted pasar a consulta?");
			scanf ("%c", &tecla);
			fflush(stdin);
	
			if(tecla=='S'||tecla=='s')
			return 2;
			else
			return 0;     											//SI EL STRING NO COINCIDE LO DICE
	}
	fclose(pf);	
}



int FRepeticion (void) 			//ESTA FUNCION DA LA OPCIOND DE VOLVER AL MENU
{
	char tecla;
	int bucle;
	puts ("\n\250Desea volver a ejecutar el programa?");
	scanf ("%c", &tecla);
	fflush(stdin);
	
	if(tecla=='S'||tecla=='s')
	bucle=1;
	else
	bucle=0;
	
	return bucle;
}

void LimpiarBufer (void)
{
	char c;
	while((c = getchar())!= EOF && c!= '\n');
}	
