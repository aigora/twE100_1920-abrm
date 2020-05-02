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
}Tpaciente;


int main()
{
	Tpaciente Dato;
	char comparar[N];
	char leer[N];
	
	FILE*pf;	
	pf=fopen("Datosgenerales","r+");						//ABRIMOS LA LISTA DE DATOS GENERALES PARA LEER 
	printf("Introduzca el DNI de la persona que busca ");	
	scanf("%s",&Dato.DNI);
	fflush(stdin);
	
	while (fgets(comparar, 100, pf) != NULL)									//LEER HASTA EL FINAL DEL ARCHIVO
	{
		
		fscanf(pf,"%s",comparar);					//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS
		if(strcmp(comparar,Dato.DNI)==0)					
		{
			printf("El paciente ha sido encontrado");       //SI EL STRING COINCIDE EL PACIENTE ESTA O HA ESTADO EN EL HOSPITAL
			break;
		}
		else
		{
			printf("el paciente no ha sido encontrado");
			break;
		}
	}
	
	printf("%s",comparar);
	fclose(pf);
	
	
return 304;
	
}


















/*#include <stdio.h>
#include<string.h>
#define N 100

typedef struct
{
	char nombre[N];
	char apellido1[N];
	char apellido2[N];
	char fecha;
	char DNI[10];
}TPaciente;

int Introduccion(void);
void LimpiarBufer (void);    //Esta fucnión limpia el bufer
int Menu();		      //Esta función abre el menu de opciones disponibles en la recepción
void FCierre (void);	      //Esta función se usa al finalizar el programa
int FSalir();
void FBusqueda();
void FCompararEleccion(int eleccion);

int main()
{
  int bucle=0;
  int eleccion;	
	do{
	Introduccion();
	Menu();
	eleccion=Menu();
	FCompararEleccion(eleccion);
	if(eleccion==4)
	{
		break;
	}
	}while(bucle!=0);
	
	FCierre();
	return 69;	
}

int Introduccion()
{
  printf("Buenos d%cas, se encuentra en la recepci%cn del hospital ABRM, %cQu%c desea hacer?\n",161,162,168,130);      
}

int Menu()
{
  int opcion;
  do{
  printf("1.Acceder a consulta\n");
  printf("2.Buscar datos de un paciente\n");
  printf("3.Acceder a Urgencias\n");
  printf("4.Salir\n");
  scanf("%d",&opcion);
  if(opcion!= 1 || opcion!= 2 || opcion!= 3 || opcion!= 4)
  { printf("Opcion no valida, escoja otra opcion por favor\n");}
  }while(opcion!= 1 || opcion!= 2 || opcion!= 3 || opcion!= 4);
return opcion;
}

void FCompararEleccion(int eleccion)	
{
	switch(eleccion)
	{
		case 1:
		FConsulta();
		break;
		case 2:
		FBusqueda();
		break;
		case 3:
		FUrgencias();
		break;
		case 4:
		FSalir();
		break;     
	}
}

void FBusqueda()
{
	TPaciente c;
	char a;
	printf("Dígame el DNI de la persona que busca por favor\n");
	scanf("%c",&c.dni);
	FILE* pf;
	pf = fopen("Datoshospital.txt","r");
	while(a!= EOF)
	{
		a = fgets(pf);
		if(a==c.dni)
		{
			printf("El paciente que estás buscando es %c %c %c con DNI %c y fecha de entrada %c\n",c.nombre,c.apellido1,
			       c.apellido2,c.dni,c.fecha); }
		else 
			printf("El paciente que busca no ha sido ingresado en este hospital, lo sentimos...");
	}
}
	
	
	
	
	
	
	
int FSalir()
{
	return 69;
}

void LimpiarBufer (void)
{
	char c;
	while((c = getchar())!= EOF && c!= '\n');
}

void FCierre (void)
{
//	char c;
	puts ("\n\nPulse \256retorno de carro\257 para cerrar la ventana...");
//	c = getchar ();
	getchar ();
}

*/
  
  char FRepeticion (void)
{
	char tecla;
	puts ("\n\250Desea volver a ejecutar el programa?");
	scanf ("%c", &tecla);
	fflush(stdin);
	return tecla;
}
