#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <math.h>

typedef struct
{
    char region [30] ;
    char prov [30];
    int tipo_basura;
    float tonelada;
} basura;
int P[5] = {30000, 4000, 250000, 7000, 0}; //Precio del tipo de basura
int B[5] = {57, 35, 302, 41, 41};
float A[6][6];
int i;
int j;
int k;
int t;
float max;
int resgi;
int op;
int bas;
int canttonxbas = 35000; //cantidad de toneladas por basural
char rta[2];

void MOSTRAR_MENU(){
  printf("\n----------------------MENU---------------------- \n");
  printf("\nSeleccione la opci%cn que desee\n", 162);
  printf("\t1 ------> Regi%cn con la mayor cantidad de basura de tipo 1 y 3 \n",162);
  printf("\t2 ------> Monto total que se obtiene con la venta de basura de un tipo a ingresar \n");
  printf("\t3 ------> %cCu%cl fue la region con mayor cantidad de basura no reciclable? \n",168,160);
  printf("\t4 ------> %cCu%cntas familias se pueden sostener aumentando el reciclaje? \n",168,160);
  printf(">");
}

void encerar()
{
	for (i=0; i<=5; i++){
		for (j=0; j<=5; j++) {
			A[i][j] = 0;
		}
	}
}
void carga()
{
    FILE *arch;
    arch=fopen("Basura.dat","rb");
    if (arch==NULL)
        exit(1);
    basura info;
    fread(&info, sizeof(basura), 1, arch);
    while(!feof(arch))
    {
	    if (strcmp(info.region, "Noroeste")== 0){
			i = 0;
		} else {
			if (strcmp(info.region, "Nordeste")== 0){
				i = 1;
			} else {
				if (strcmp(info.region, "Pampeana")== 0){
					i = 2;
				} else {
					if (strcmp(info.region, "Cuyo")== 0){
						i = 3;
					} else {
						if (strcmp(info.region, "Patagonia")== 0){
							i = 4;
						}
					}
				}
			}
		}
		j = (info.tipo_basura) - 1;
		A[i][j] = A[i][j] + info.tonelada;
		A[5][j] = A[5][j] + info.tonelada;
		A[i][5] = A[i][5] + info.tonelada;
		A[5][5] = A[5][5] + info.tonelada;
	    fread(&info, sizeof(basura), 1, arch);
    }
    fclose(arch);
}

void mayortipo1y3() {
	for (i=0; i<=4; i++) {
		if (((A[i][0] + A[i][2])/ (A[i][5]) * 100)>max) {
			max = (A[i][0] + A[i][2]) / (A[i][5]) * 100;
			resgi = i;
		}
	}
	printf("La regi%cn ", 162);
	switch (resgi) {
		case 0: printf("Noroeste");
		break;
		case 1: printf("Nordeste");
		break;
		case 2: printf("Pampeana");
		break;
		case 3: printf("Cuyo");
		break;
		case 4: printf("Patagonia");
		break;
	}
	printf(" es la que mayor porcentaje (%5.2f%%) representa de basura de tipo papel, \ncart%cn, envases y pl%cstico sobre su total, a nivel pa%cs\n",max,162,160,161);
	max = 0;
}

void ventatipo() {
	printf("Ingrese el tipo de basura que desea saber su monto de venta\n");
	printf("1-Papel y Cart%cn\n2-Vidrio\n3-Envases y pl%csticos\n4-Org%cnico\n>",162,160,160);
	scanf("%d", &bas);
	for (i=0; i<=5; i++) {
		switch (i) {
			case 0: printf("En la regi%cn Noroeste",162);
			break;
			case 1: printf("En la regi%cn Nordeste",162);
			break;
			case 2: printf("En la regi%cn Pampeana",162);
			break;
			case 3: printf("En la regi%cn Cuyo",162);
			break;
			case 4: printf("En la regi%cn Patagonia",162);
			break;
			case 5: printf("\nEn total");
			break;
		}
		printf(" el monto de venta si se vende la basura de dicho tipo ser%c de: %c%5.0f\n",160,36, A[i][bas-1] * P[bas]);
	}
}

void regnorec() {
	for (i=0; i<=4; i++) {
		if (A[i][5]>max) {
			max = A[i][5];
			resgi = i;
		}
	}
	printf("La regi%cn ", 162);
	switch (resgi) {
		case 0: printf("Noroeste");
		break;
		case 1: printf("Nordeste");
		break;
		case 2: printf("Pampeana");
		break;
		case 3: printf("Cuyo");
		break;
		case 4: printf("Patagonia");
		break;
	}
	printf(" es la que mayor cantidad de basura no reciclable presenta, con un total de %5.2f toneladas\n", max);
	printf("Se necesitar%can %.0f cantidad de basurales para esta cantidad de toneladas\n",161, max/canttonxbas);
	if (B[resgi]<round(max/canttonxbas)) {
		printf("%cALERTA! se necesitan %.0f basurales extras para la regi%cn",173, (max/canttonxbas - B[resgi]),162);
	}else {
		printf("Esta posee %d basurales, por lo que se encuentra cubierta la demanda de basurales en esta regi%cn\n",B[resgi], 162);
	}
	max = 0;
}
void familias (){
	printf("Si se reciclara el doble de lo que se recicla:\n");
	for (i=0; i<=5; i++) {
		switch (i) {
			case 0: printf("-> En la regi%cn Noroeste\n",162);
			break;
			case 1: printf("-> En la regi%cn Nordeste\n",162);
			break;
			case 2: printf("-> En la regi%cn Pampeana\n",162);
			break;
			case 3: printf("-> En la regi%cn Cuyo\n",162);
			break;
			case 4: printf("-> En la regi%cn Patagonia\n",162);
			break;
			case 5: printf("\n-> En total");
			break;
		}
		printf(" pasar%ca de reciclarse %.1f toneladas de basura, a reciclarse %.1f toneladas, lo que implicar%ca que se sostendr%can econ%cmicamente %.0f familias m%cs\n",161,A[i][5]/4*0.15,A[i][5]/4 *0.3,161,161,162,((A[i][5]/4 *0.3) - (A[i][5]/4 *0.15)) / 20,160);
	}
}

void opcion() {
	MOSTRAR_MENU();
	scanf("%d", &op);
	switch (op) {
		case 1: mayortipo1y3();
		break;
		case 2: ventatipo();
		break;
		case 3: regnorec();
		break;
		case 4: familias();
		break;
		default: system ("CLS"); printf("Ingrese un numero valido\n"); opcion();
	}
}

int main() {
	max = 0;
	encerar();
	carga();
	do {
	opcion();
		do {
			printf ("\n%cDesea realizar otra operaci%cn?\n Si/No \n>", 168, 162);
		    scanf ("%s" , &rta);
		}while (strcmp(rta, "Si")!= 0 && strcmp(rta, "No")!= 0);
		system ("CLS");
	}while (strcmp(rta, "Si")== 0);
	printf("Gracias por usar el programa\n");
}
