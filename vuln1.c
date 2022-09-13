#include <stdio.h>

// Programa vulnerable a buffer overflow. No comprueba longitud del argumento y usa la función strcpy que no limita la longitud de caracteres copiados

int	main (int argc, char **argv)
{
	char buffer[64];

	strcpy (buffer, argv[1]); //se prodcude el desbordamiento
	return 0;
}
