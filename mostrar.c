#include <stdio.h>

int main( int argc , char** argv)
{
	FILE *datos = fopen("datos.bin", "rb");

	if(!datos) {
	printf("No he podido abrir el archivo");
	return 1;
	}

	do {
	int leido = fgetc(datos);// devuelve un int
																	//lseek()-> mover cursor a donde queramos
	if(!feof(datos)) {
	printf("%c",(char) leido);
	}
		}
	while(!feof(datos));

	fclose(datos);
	
}
