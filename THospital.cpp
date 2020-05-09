//TRABAJO RECEPCION DE HOSPITAL
/*
PARTICIPANTES: Mario Sánchez García (55452) 
	       Brian Tomico Fernández (55487) 
	       Raul Ricaldi Esquivel (55423) 
	       Andres Torrejón Palomo (55489)
*/
//Es necesario tener un documento de texto llamado "Datosgenerales" para que funcione correctamente

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
int FConsultaBuscar();
void FMostrarDatos();
int FBuscar();
void FListado();
int FRepeticion();


int main()
{	
	int bucle=1;
	int eleccion;
	int busqueda=0;
	
	FIntroduccion();

	while(bucle==1)
	{	
		if(busqueda!=2)
		eleccion=FMenu();
	
	switch (eleccion)
	{
		case 1:
			FConsulta();
			busqueda=0;                     //esto es para cuando se accede a consulta atraves de busqueda
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
			FListado();
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

//FUNCION INTRODUCCION
void FIntroduccion()
{
  printf("Buenos d%cas, se encuentra en la recepci%cn del hospital ABRM, %cQu%c desea hacer?\n\n",161,162,168,130);      
}

//FUNCION MENU PRINCIPAL
int FMenu()							
{
  int opcion;
  do{
  printf("1. Acceder a consulta\n");
  printf("2. Buscar datos de un paciente\n");
  printf("3. Mostrar listado de pacientes\n\n");
  
  scanf("%d",&opcion);
  fflush(stdin);
  
  if(opcion<1||opcion>3)				//Esto es un filtro para que la fucnion no devuelva opciones no validas
  { 
  	printf("Opcion no v%clida, escoja otra opci%cn por favor\n",160,162);
  }
  }while(opcion<1||opcion>3);
  
return opcion;
}
//FIN F.MENU

//FUNCION CONSULTA: OPCION 1
int FConsulta()
{
	TPaciente paciente;
	char Fechaentrada[N];
	char Fechasalida[N];
	char Diagnostico[M];
	char Dni;
	int contador;

	printf("\nIntroduzca su DNI:\n");
	scanf("%s",paciente.DNI);				//esto comprueba si el paciente ya ha estado ingresado
	printf("\n");
	contador = FConsultaBuscar(paciente.DNI);	
	if(contador==0)
	{
	printf("\nIntroduzca su nombre:\n");			//esto es para tomar los datos del paciente y crear los dos ficheros
	scanf("%s",paciente.nombre);
	fflush(stdin);
	printf("\nIntroduzca su primer apellido:\n");
	scanf("%s",paciente.apellido1);
	fflush(stdin);
	printf("\nIntroduzca su segundo apellido:\n");
	scanf("%s",paciente.apellido2);
	fflush(stdin);	
	}	
	printf("\nFecha de hoy:\n");
	scanf("%s",Fechaentrada);
	fflush(stdin);
	printf("\nDiagn%cstico:\n",162);
	gets(Diagnostico);
	fflush(stdin);
	printf("\nFecha de salida:\n");
	scanf("%s",Fechasalida);
	fflush(stdin);
	
	FILE*pac;                     //crea ficha individual de cada paciente 
	pac=fopen(paciente.DNI,"a");
	if(contador!=0)
	{
		fprintf(pac,"\n");
	}
	
	if(contador==0)
	{
	fprintf(pac,"%s\n",paciente.nombre);
	fprintf(pac,"%s\n",paciente.apellido1);
    fprintf(pac,"%s\n",paciente.apellido2);   
	fprintf(pac,"%s\n",paciente.DNI);
	}
	fprintf(pac,"%s\n",Fechaentrada);	
	fprintf(pac,"%s\n",Diagnostico);
	fprintf(pac,"%s",Fechasalida);
	
	fclose(pac);
	
	FILE*general;
	general=fopen("Datosgenerales.txt","a");
	if(contador==0)
	{
	fprintf(general,"\n");
	fprintf(general,"%s ",paciente.nombre);
	fprintf(general,"%s ",paciente.apellido1);
    fprintf(general,"%s ",paciente.apellido2);   
	fprintf(general,"%s",paciente.DNI);	
	}
	fclose(general);
}
//FIN F. DE CONSULTA

//FUNCION AUXILIAR DE CONSULTA, comprueba si ha estado o no
int FConsultaBuscar(char DNI[N])
{
	TPaciente Dato;
	char comparar[N];
	char tecla;
	int mostrar=1;    //esto es para que cuando se llame a la funcion desde aqui no muestre los datos y solo muestre el diagnostico
	
	FILE*pf;	
	pf=fopen("Datosgenerales.txt","r+");						//ABRIMOS LA LISTA DE DATOS GENERALES PARA LEER 
	fflush(stdin);
	
									
	while (!feof (pf))         //LEER HASTA EL FINAL DEL ARCHIVO
	{
		
			
		fscanf(pf,"%s %s %s %s", Dato.nombre, Dato.apellido1, Dato.apellido2, Dato.DNI);
		fflush(stdin);
		
		if(strcmp(DNI,Dato.DNI)==0)					//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
		{
			printf("El paciente ya ha estado en el centro y este es el historial: \n");   //SI EL STRING COINCIDE EL PACIENTE ESTA O HA ESTADO EN EL HOSPITAL												//	Aqui hay que abrir la ficha del paciente encontrado y mostrar las fechas de entrada y/o salida
			FMostrarDatos(DNI,mostrar);
			return 1;
			break;
		}
			
	}
	if(strcmp(DNI,Dato.DNI)!=0)	
	{																//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
			printf("Esta es la primera vez que el paciente acude a este hospital \n"); 
			return 0;    										
	}
	fclose(pf);	
}
//FIN F.AUXILIAR DE CONSULTA

//FUNCION MOSTRAR DATOS DE SU HISTORIAL
void FMostrarDatos(char NombreFichero[N],int mostrar)
{
	TPaciente Dato;
	char Fechaentrada[N];
	char Diagnostico[N];
	char Fechasalida[N];
	int contador=0;
	
	FILE*Fichapac;	
	Fichapac=fopen(NombreFichero,"r+");
		while (!feof (Fichapac))        //LEER HASTA EL FINAL DEL ARCHIVO 
	{
		if(contador==0)
		{
		fgets(Dato.nombre,M,Fichapac);			
		fflush(stdin);
		fgets(Dato.apellido1,M,Fichapac);
		fflush(stdin);
		fgets(Dato.apellido2,M,Fichapac);
		fflush(stdin);
		fgets(Dato.DNI,M,Fichapac);
		}
		fflush(stdin);
		fgets(Fechaentrada,M,Fichapac);
		fflush(stdin);
		fgets(Diagnostico,M,Fichapac);
		fflush(stdin);
		fgets(Fechasalida,M,Fichapac);
		fflush(stdin);
	
		
	if(contador+mostrar==0)        //esto hace que cuando se llama a la funcion desde fconsultabuscar no muestre los datos o que cuando haya estado mas de una vez tampoco
	{
	printf("El paciente con nombre: %s",Dato.nombre);	
	printf("Primer apellido: %s",Dato.apellido1);
	printf("Segundo apellido: %s",Dato.apellido2);	
	printf("Con DNI:%s",Dato.DNI);		
	}
	printf("Fue ingresado el: %s",Fechaentrada);	
	printf("Con motivo: %s",Diagnostico);
	printf("Se le concedi%c el alta el: %s\n",162,Fechasalida);
	contador++;
	}
		fclose(Fichapac);
	}
//FIN F.MOSTRAR DATOS

//FUNCION BUSCAR PACIENTE: OPCION 2
int FBuscar()									
{
	TPaciente Dato;
	char comparar[N];
	char tecla;
	int mostrar=0; 		//esta variable es para que muestre el nombre etc al llamar a fmostrardatos
	int	repetir=0;		
	
	FILE*pf;	
	pf=fopen("Datosgenerales.txt","r+");						//ABRIMOS LA LISTA DE DATOS GENERALES PARA LEER 
	printf("Introduzca el DNI de la persona que busca: ");	
	scanf("%s", comparar);
	fflush(stdin);
	
									
	while (!feof (pf))         //LEER HASTA EL FINAL DEL ARCHIVO
	{
		
			
		fscanf(pf,"%s %s %s %s", Dato.nombre, Dato.apellido1, Dato.apellido2, Dato.DNI);
		fflush(stdin);
		
		if(strcmp(Dato.DNI,comparar)==0)					//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
		{
			printf("El paciente ha sido encontrado y esta es su ficha: \n");   //SI EL STRING COINCIDE EL PACIENTE ESTA O HA ESTADO EN EL HOSPITAL
			FMostrarDatos(Dato.DNI,mostrar);
			return 1;												//	Aqui hay que abrir la ficha del paciente encontrado y mostrar las fechas de entrada y/o salida
		}
			
	}
	if(strcmp(Dato.DNI,comparar)!=0)	
	{				
													//COMPARAMOS EL STRING INTRODUCIDO CON LOS DE LA LISTA DE DATOS	
			printf("No ha sido encontrado \n"); 
			while(repetir==0){
			
			puts ("\n\250Desea usted pasar a consulta?");
			scanf ("%c", &tecla);
			fflush(stdin);
	
			if(tecla=='S'||tecla=='s'){
			return 2;
			repetir=1;
			}
			else
			{
				if(tecla=='N'||tecla=='n')
				{
				return 0;
				repetir=1;
				}
				else
				{
					repetir=0;
				}
			}
			}
		     											//SI EL STRING NO COINCIDE LO DICE
	}
	fclose(pf);	
}
//FIN FUNCION BUSQUEDA DE PACIENTES

//FUNCION MOSTRAR LISTADO DE PACIENTES: OPCION 3
void FListado()
{
	TPaciente Datos;
	printf("\nEl listado de pacientes es el siguiente:\n");
	FILE*Listado;
	Listado=fopen("Datosgenerales.txt","r+");
	while(!feof(Listado))
	{
		fscanf(Listado,"%s %s %s %s",Datos.nombre,Datos.apellido1,Datos.apellido2,Datos.DNI);
		printf("%s %s %s DNI: %s \n",Datos.nombre,Datos.apellido1,Datos.apellido2,Datos.DNI);
	}	
	fclose(Listado);
}
//FIN F.LISTADO

//FUNCION REPETICION DE PROGRAMA, volver al menú
int FRepeticion (void) 			
{
	char tecla;
	int bucle;
	int repetir=0;
	while(repetir==0)
	{
	printf("\n%cDesea volver a recepci%cn?",168,162);
	scanf ("%c", &tecla);
	fflush(stdin);

	if(tecla=='S'||tecla=='s')
	{	
		bucle=1;
		repetir=1;
	}
	else
	{
		if(tecla=='N'||tecla=='n')
		{
		bucle=0;
		repetir=1;
		}
		else
		repetir=0;
	}
	}
	return bucle;
}
//FIN F.REPETICION + PROGRAMA
