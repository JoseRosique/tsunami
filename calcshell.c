#include <stdio.h>
#include <windows.h>

/*
 * This code is made in assembler, in it we load the libraries stdio. h and windows.h.
 * We can see two parts in the code, in the first part we are loading the library "msvcrt.dll" and in the second we run "calc.exe"
 * 
 * The second memory address is obtained using the offset. c, which we will give as parameters the library and the function we are looking for
 * The first address is where LoadLibrary is located in Windows XP SP3, can be found on the internet or by running offset.exe kernel32.dll LoadLibraryA
 * When you run the offset.exe (we get it by doing the command "cl" to offset.c) and give the parameters "msvcrt.dll" system we will get the second memory address, which is the offset needed to run programs with the system function
 * Basically the first part loads the msvcrt.dll library and the second part runs the calculator, these two files are written in hexadecimal on the mov byte lines and the sub esp is used to give space to the bytes needed to write it
 * the xor is used in this case to create a value 0 that will be used as a line end
 * */
int main()
{
	_asm
	{
		push ebp
		mov ebp,esp
		xor edi,edi
		push edi
		sub esp,0ch
		mov byte ptr [ebp-0bh],6Dh
		mov byte ptr [ebp-0ah],73h
		mov byte ptr [ebp-09h],76h
		mov byte ptr [ebp-08h],63h
        mov byte ptr [ebp-07h],72h
        mov byte ptr [ebp-06h],74h
        mov byte ptr [ebp-05h],2Eh
        mov byte ptr [ebp-04h],64h
        mov byte ptr [ebp-03h],6Ch
		mov byte ptr [ebp-02h],6Ch
		lea eax,[ebp-0bh]
		push eax
		mov ebx,0x7c801d7b
		call ebx
		
		push ebp
		mov ebp,esp
		xor edi,edi
		push edi
		sub esp,08h
		mov byte ptr [ebp-09h],63h
		mov byte ptr [ebp-08h],61h
        mov byte ptr [ebp-07h],6Ch
        mov byte ptr [ebp-06h],63h
        mov byte ptr [ebp-05h],2Eh
        mov byte ptr [ebp-04h],65h
        mov byte ptr [ebp-03h],78h
		mov byte ptr [ebp-02h],65h
		lea eax,[ebp-09h]
		push eax
		mov ebx,0x77c293c7
		call ebx
	}

}