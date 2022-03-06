#include <stdio.h>

struct reg{

		int num;
		char cad[10];
		char car;
			};
int crear_fichero()
{	FILE *fich;
	int i, er_dev = 0;
	struct reg r;

	if ((fich =fopen("fichreg.dat","wb")) == NULL)
		{ printf("Error de apertura del archivo para escribir\n");
		er_dev=1;
		}
		
	else {
			for (i=0; i<5;i++)
			{	
				r.num= i;
				r.car='a' +1;
				printf("De un nombre ");
				gets(r.cad);
				fwrite(&r, sizeof(r), 1 , fich);
			}
		
			return er_dev;

	int leer_fichero()
		{
			FILE *fich;
			struct reg r;
			int er_dev =0;
			if((fich = fopen("fichreg.dat" , "rb"))) == NULL
			 {
				printf("Error en apertura de archivo para lectura \n" );
				er_dev =1 ; }
			
			else 
			{ fread(&r, sizeof(r), 1,fich);
			while (!feof(fich))
				{
					printf("%d: %s: %c\n" , r.num, r.cad,r.car);
					fread(&r,sizeof(r), 1,fich);
				}
				fclose(fich);
			}
			return er_dev;

		int main(void)	
		{	int error;
			error = crear_archivo();
			if(!error) leer_fichero();
		}
