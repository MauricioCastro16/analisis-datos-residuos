#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>


typedef struct
{
    char region [30] ;
    char prov [30];
    int tipo_basura;
    float tonelada;
} basura;

int B[24] = {}; //Cant basurales por provincia
int P[4] = {}; //Precio del tipo de basura

char rta[2]; //Si desea continuar o no
int op; //opcion del menu
char temp; //auxiliar
int au; //automatico, contador de reps
int i; //es i flaco, un capo el chabon este
int j;

void provareg(char a[30], char b[30])
{
	if (strcmp(a, "Jujuy") == 0||strcmp(a, "Salta") == 0||strcmp(a, "Catamarca") == 0||strcmp(a, "Tucuman") == 0||strcmp(a, "Santiago del Estero") == 0) {
  			strcpy(b, "Noroeste");
  		} else {
  			if (strcmp(a, "Formosa") == 0||strcmp(a, "Chaco") == 0||strcmp(a, "Corrientes") == 0||strcmp(a, "Misiones") == 0) {
  				strcpy(b, "Nordeste");
  			} else {
  				if (strcmp(a, "Santa Fe") == 0||strcmp(a, "Entre Rios") == 0||strcmp(a, "Cordoba") == 0||strcmp(a, "La Pampa") == 0||strcmp(a, "Buenos Aires") == 0||strcmp(a, "CABA") == 0) {
  					strcpy(b, "Pampeana");
  				} else {
  					if (strcmp(a, "La Rioja") == 0||strcmp(a, "San Juan") == 0||strcmp(a, "San Luis") == 0||strcmp(a, "Mendoza") == 0) {
  					  strcpy(b, "Cuyo");
  					} else {
  						if (strcmp(a, "Neuquen") == 0||strcmp(a, "Rio Negro") == 0||strcmp(a, "Chubut") == 0||strcmp(a, "Santa Cruz") == 0||strcmp(a, "Tierra del Fuego") == 0) {
  							strcpy(b, "Patagonia");
  						}
  					}
  				}
  			}
  		}
}
void crear()
{
    FILE *arch;
    arch=fopen("Basura.dat","wb");
    if (arch==NULL)
        exit(1);
    fclose(arch);
}

void cargar()
{
    FILE *arch;
    arch=fopen("Basura.dat","ab");
    if (arch==NULL)
        exit(1);
    basura info;
    do {
	    printf("Por favor ingrese la provincia: ");
	    scanf("%c", &temp); //limpiar el buffer para que [^/n] no deje guardada su info en stdin (problemas al reseatearlo)
	    scanf("%[^\n]", info.prov); // se usa [^\n] para leer lo ingresado hasta el salto de linea (enter) porque hay provincias con un espacio de por medio
  	}while(strcmp(info.prov, "Jujuy")!= 0
  	&&strcmp(info.prov, "Salta")!= 0
  	&&strcmp(info.prov, "Catamarca") != 0
  	&&strcmp(info.prov, "Tucuman") != 0
  	&&strcmp(info.prov, "Santiago del Estero") != 0
  	&&strcmp(info.prov, "Formosa") != 0
  	&&strcmp(info.prov, "Chaco") != 0
  	&&strcmp(info.prov, "Corrientes") != 0
  	&&strcmp(info.prov, "Misiones") != 0
  	&&strcmp(info.prov, "La Rioja") != 0
  	&&strcmp(info.prov, "San Juan") != 0
  	&&strcmp(info.prov, "San Luis") != 0
  	&&strcmp(info.prov, "Mendoza") != 0
  	&&strcmp(info.prov, "Neuquen") != 0
  	&&strcmp(info.prov, "Rio Negro") != 0
  	&&strcmp(info.prov, "Chubut") != 0
  	&&strcmp(info.prov, "Santa Cruz") != 0
  	&&strcmp(info.prov, "Tierra del Fuego")
  	&&strcmp(info.prov, "Santa Fe") != 0
  	&&strcmp(info.prov, "Entre Rios") != 0
  	&&strcmp(info.prov, "Cordoba") != 0
  	&&strcmp(info.prov, "La Pampa") != 0
    &&strcmp(info.prov, "Buenos Aires") != 0
    &&strcmp(info.prov, "CABA") != 0);

  	provareg(info.prov, info.region);

	do {
	    printf("Ingrese tipo de basura: \n1: papel y cart%cn\n2: vidrio\n3: envases y pl%csticos\n4: organico\n5: otros restos\n> ",162,160);
	    scanf("%d",&info.tipo_basura);
	}while (info.tipo_basura < 1 || info.tipo_basura > 5);

    printf ("Ingrese las toneladas de ese tipo de basura: ");
    scanf ("%f", &info.tonelada);

    fwrite(&info, sizeof(basura), 1, arch);

	printf ("%cContinuar?\n Si/No \n>", 168);
    scanf ("%s" , &rta);
    while (strcmp(rta, "Si") == 0) {

        cargar () ;
	}
    fclose(arch);
}

void aleatorio()
{
	FILE *arch;
    arch=fopen("Basura.dat","ab");
    if (arch==NULL)
        exit(1);
    basura info;
    printf("Por favor, ingrese la cantidad de ingresos de basura a automatizar\n>");
    scanf("%d", &au);
    for (i = 0; i < au; i++){

    	switch (rand() % 50) //Se agregaron cases para aumentarle la frecuencia a algunas provincias
		{
          	case 0:
			  strcpy(info.prov, "Jujuy");
          	break;
          	case 1:
          	case 23:
			  strcpy(info.prov, "Salta");
          	break;
          	case 2:
			  strcpy(info.prov, "Catamarca");
          	break;
          	case 3:
          	case 24:
			  strcpy(info.prov, "Tucuman");
          	break;
          	case 4:
          	case 25:
			  strcpy(info.prov, "Santiago del Estero");
          	break;
          	case 5:
			  strcpy(info.prov, "Formosa");
          	break;
          	case 6:
          	case 26:
			  strcpy(info.prov, "Chaco");
          	break;
          	case 7:
          	case 27:
			  strcpy(info.prov, "Corrientes");
          	break;
          	case 8:
          	case 28:
			  strcpy(info.prov, "Misiones");
          	break;
          	case 9:
          	case 29:
          	case 30:
          	case 31:
			  strcpy(info.prov, "Santa Fe");
          	break;
          	case 10:
          	case 32:
			  strcpy(info.prov, "Entre Rios");
          	break;
          	case 11:
          	case 33:
          	case 34:
          	case 35:
          	case 36:
			  strcpy(info.prov, "Cordoba");
          	break;
          	case 12:
			  strcpy(info.prov, "La Pampa");
          	break;
          	case 13:
          	case 37:
          	case 38:
          	case 39:
          	case 40:
          	case 41:
          	case 42:
          	case 43:
          	case 44:
          	case 45:
          	case 46:
          	case 47:
			  strcpy(info.prov, "Buenos Aires");
          	break;
          	case 14:
			  strcpy(info.prov, "La Rioja");
          	break;
          	case 15:
			  strcpy(info.prov, "San Juan");
          	break;
          	case 16:
			  strcpy(info.prov, "San Luis");
          	break;
          	case 17:
          	case 48:
          	case 49:
			  strcpy(info.prov, "Mendoza");
          	break;
          	case 18:
			  strcpy(info.prov, "Neuquen");
          	break;
          	case 19:
			  strcpy(info.prov, "Rio Negro");
          	break;
          	case 20:
			  strcpy(info.prov, "Chubut");
          	break;
          	case 21:
			  strcpy(info.prov, "Santa Cruz");
          	break;
          	case 22:
			  strcpy(info.prov, "Tierra del Fuego");
          	break;
        }
        provareg(info.prov, info.region);
        switch(rand() % 10)
        {
          case 0:
          case 1:
		  case 2:
		  	info.tipo_basura = 1;
		  break;
		  case 3:
		  case 4:
		  	info.tipo_basura = 2;
		  break;
		  case 5:
		  case 6:
		  	info.tipo_basura = 3;
		  break;
		  case 7:
		  case 8:
		  	info.tipo_basura = 4;
		  break;
		  case 9:
		  	info.tipo_basura = 5;
		  break;
		}
		info.tonelada = (float)(rand() % 5000) / 100 + 1; //Para que nunca cargue 0 toneladas
        fwrite(&info, sizeof(basura), 1, arch);
    }

    printf("Archivo generado aleatoriamente de forma exitosa");
    fclose(arch);

}

void mostrar()
{
    FILE *arch;
    arch=fopen("Basura.dat","rb");
    if (arch==NULL)
        exit(1);
    basura info;
    fread(&info, sizeof(basura), 1, arch);
    j = 1;
    while(!feof(arch))
    {
        printf("%d-. %s %s %d %5.2f \n", j, info.region, info.prov, info.tipo_basura, info.tonelada);
        j++;
        fread(&info, sizeof(basura), 1, arch);
    }
    fclose(arch);
}

int menu()
{
	system ("CLS");
	printf("%cQu%c desea hacer?\n1-Crear/reiniciar el archivo\n2-Cargar archivo manualmente\n3-Cargar el archivo autom%cticamente (solo para pruebas)\n4-Mostrar archivo\n>", 168, 130, 160);
    scanf("%d", &op);
	switch(op) {
		case 1:
			crear();
			printf("Archivo creado con %cxito\n", 130);
			break;
    	case 2:
			cargar();
			break;
		case 3:
			aleatorio();
			break;
		case 4:
			mostrar();
			break;
	}
	printf("\n");
	do {
		printf ("%cDesea realizar otra operaci%cn?\n Si/No \n>", 168, 162);
	    scanf ("%s" , &rta);
	}while (strcmp(rta, "Si")!= 0 && strcmp(rta, "No")!= 0);
    if (strcmp(rta, "Si") == 0) {
        menu() ;
	}
}

int main()
{
	printf("Bienvenidos al programa de proceso estad%csticos sobre basurales\n\n", 161);
	srand(time(NULL));
	menu();
	printf("Gracias por utilizar este programa");
}
