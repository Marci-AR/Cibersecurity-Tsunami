#include <stdio.h>
#include <windows.h>

int main()
{
	_asm
	{
		// se carga libreria msvcrt.dll
		push ebp
		mov ebp,esp
		xor edi,edi
		push edi
		sub esp,0Ch
		mov byte ptr [ebp-0bh],6Dh	//m	
		mov byte ptr [ebp-0ah],73h	//s
		mov byte ptr [ebp-09h],76h	//v
		mov byte ptr [ebp-08h],63h	//c
        mov byte ptr [ebp-07h],72h	//r
        mov byte ptr [ebp-06h],74h	//t
        mov byte ptr [ebp-05h],2Eh	//.
        mov byte ptr [ebp-04h],64h	//d
        mov byte ptr [ebp-03h],6Ch	//l
		mov byte ptr [ebp-02h],6Ch	//l
		lea eax,[ebp-0Bh]	//ultima posicion
		push eax
		mov ebx,0x7c801d7b	//direccion de loadlibrary
		call ebx

		// se cargar calc.exe
		push ebp
		mov ebp,esp
		xor edi,edi
		push edi
		sub esp,08h
		mov byte ptr [ebp-09h],63h	//c
		mov byte ptr [ebp-08h],61h	//a
        mov byte ptr [ebp-07h],6Ch	//l
        mov byte ptr [ebp-06h],63h	//c
        mov byte ptr [ebp-05h],2Eh	//.
        mov byte ptr [ebp-04h],65h	//e
        mov byte ptr [ebp-03h],78h	//x
		mov byte ptr [ebp-02h],65h	//e
		lea eax,[ebp-09h]	//ultima posicion
		push eax
		mov ebx,0x77c293c7	//direccion libreria system
		call ebx
	}

}
