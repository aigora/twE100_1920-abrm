//TRABAJO RECEPCION DE HOSPITAL
//PARTICIPANTES: Mario Sánchez García (55452), Brian Tomico Fernández (55487), Raul Ricaldi Esquivel (55423), Andres Torrejón Palomo (55489).

#include <stdio.h>

int Introduccion(void);
void LimpiarBufer (void);    //Esta fucnión limpia el bufer
int Menu();		      //Esta función abre el menu de opciones disponibles en la recepción
void FCierre (void);	      //Esta función se usa al finalizar el programa
int FSalir();

int main()
{
  int bucle=0;
  int eleccion;	
	do{
	Introduccion();
	Menu();
	eleccion=Menu();
		
	if(eleccion==3){
		bucle=Salir();
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
  char opcion;
  do{
  printf("A.Acceder a consulta\n");
  printf("B.Buscar datos de un paciente\n");
  printf("C.Acceder a Urgencias\n");
  printf("D.Salir\n");
  scanf("%c",&opcion);

  switch(opcion)//En este switch se elige la opcion que se desea
  {
    case'A':case'a':
      return 0;
  break;
  case'B':case'b':
      return 1;
  break;
  case'C':case'c':
      return 2;
  break;
  case'D':case'd':
      return 3;
  break;
  default:
     printf("Escoja una opci%cn v%clida",162,160);
  }
  }while(opcion!='A' || opcion!='a' || opcion!='B' || opcion!='b' || opcion!='C' || opcion!='c' || opcion!='D' || opcion!='d');
}

float CompararEleccion (int eleccion)
{
switch(eleccion)
{
	case 0:
	FConsulta();
	break;
	case 1:
	FHistorial();
	break;
	case 2:
	FUrgencias();
	break;
	case 3:
	FSalir();
	break;
}}
	
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


  
  
