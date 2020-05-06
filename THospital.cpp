//TRABAJO RECEPCION DE HOSPITAL
//PARTICIPANTES: Mario Sánchez García (55452), Brian Tomico Fernández (55487), Raul Ricaldi Esquivel (55423), Andres Torrejón Palomo (55489).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 600


typedef struct
{
	char nombre[N];
	char apellido1[N];
	char apellido2[N];
	char DNI[14];
}TPaciente;


void FIntroduccion();
int FMenu();
int FConsulta();
char FConsultaBuscar();
int FBuscar();
int FRepeticion();
void LimpiarBufer();

int main()
{	
int bucle=1;
int eleccion;
int busqueda=0;
	
	FIntroduccion();

	while(bucle==1)
	{	if(busqueda!=2)
		eleccion=FMenu();
	
	switch (eleccion)
	{
		case 1:
			FConsulta();
			busqueda=0;                                      //esto es para cuando se accede a consulta atraves de busqueda
			break;
		case 2:
			busqueda = FBuscar();
			if(busqueda == 2)
				eleccion=1;
			if(busqueda == 0)
			{	
			break;
			}
			break;
			
		case 3:
			printf("\n Entrar a urgencias\n");
			break;
	}
	if(busqueda==2)
	{
		bucle=1;
	}
	else
	{
		bucle=FRepeticion();
	}
	
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
int FConsulta()
{
	TPaciente paciente;
	char Fechaentrada[N];
	char Fechasalida[N];
	char Diagnostico[M];
	char Dni;

	printf("\nIntroduzca su nombre\n");
	scanf("%s",paciente.nombre);
	fflush(stdin);
	printf("\nIntroduzca su primer apellido\n");
	scanf("%s",paciente.apellido1);
	fflush(stdin);
	printf("\nIntroduzca su segundo apellido\n");
	scanf("%s",paciente.apellido2);
	fflush(stdin);
	Dni=FConsultaBuscar();
	//hay que verlo
	
	
	printf("\nFecha de hoy\n");
	scanf("%s",Fechaentrada);
	fflush(stdin);
	printf("\nDiagnostico:\n");
	gets(Diagnostico);
	fflush(stdin);
	printf("\nFecha de salida\n");
	scanf("%s",Fechasalida);
	fflush(stdin);
	
	
	FILE*pac;
	pac=fopen(strcat(paciente.DNI,".txt"),"a");
	fprintf(pac,"%s\n",paciente.nombre);
	fprintf(pac,"%s\n",paciente.apellido1);
    fprintf(pac,"%s\n",paciente.apellido2);   
	fprintf(pac,"%s\n",paciente.DNI);	
	fprintf(pac,"%s\n",Fechaentrada);	
	fprintf(pac,"%s\n",Diagnostico);
	fprintf(pac,"%s\n",Fechasalida);
	
	fclose(pac);
	

}

char FConsultaBuscar()
{
	TPaciente Dato;
	char comparar[N];
	char tecla;
	
	FILE*pf;	
	pf=fopen("Datosgenerales","r+");						//ABRIMOS LA LISTA DE DATOS GENERALES PARA LEER 
	printf("Introduzca su DNI");	
	scanf("%s", comparar);
	fflush(stdin);
	
									
	while (!feof (pf))         //LEER HASTA EL FINAL DEL ARCHIVO
	{
		
			
		fscanf(pf,"%s %s %s %s", Dato.nombre, Dato.apellido1, Dato.apellido2, Dato.DNI);
		fflush(stdin);
		
		if(strcmp(Dato.DNI,comparar)==0)					//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
		{
			printf("El paciente ya ha estaedo en el centro y este es el historial");   //SI EL STRING COINCIDE EL PACIENTE ESTA O HA ESTADO EN EL HOSPITAL
			return Dato.DNI;												//	Aqui hay que abrir la ficha del paciente encontrado y mostrar las fechas de entrada y/o salida
			break;
		}
			
	}
	if(strcmp(Dato.DNI,comparar)!=0)	
	{																//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
			printf("Esta es la primera vez que el paciente acude a este hospital \n"); 
			return Dato.DNI;     										
	}
	fclose(pf);	
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
