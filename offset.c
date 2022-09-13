#include <stdio.h>
#include <windows.h>


// Obtenemos el offset de una funcion

typedef VOID (*MYPROC)(LPTSTR);

int main (int argc, char **argv) {
    char dll[100];
    char funcion[100];

    HINSTANCE libreria;
    MYPROC procadd;

    if (argc != 3){
        printf ("Introduce 2 argumentos como se explica mas arriba!!!\n");
        return 1;
        }

    memset(dll,0,sizeof(dll));
    memset(funcion,0,sizeof(funcion));

    memcpy (dll, argv[1], strlen(argv[1]));
    memcpy (funcion, argv[2], strlen(argv[2]));

    libreria = LoadLibrary(dll);
    procadd = (MYPROC)GetProcAddress (libreria,funcion);

    return 0;

}
//restultado de ejecutar offset.exe msvcrt.dll system -> 77c293c7
