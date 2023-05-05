#include <stdio.h>
#include <windows.h>

/*
 * This function gives the offset of a function in your library
*/
typedef VOID (*MYPROC)(LPTSTR);

int main (int argc, char **argv) {
    char dll[100];
    char funcion[100];

    HINSTANCE libreria;
    MYPROC procadd;

    printf ("Look for offsets. Enter the name of the DLL as the first argument,\n");
    printf ("and as the second argument the function within that DLL\n");
    printf ("For example %s msvcrt.dll system\n\n", argv[0]);

    if (argc != 3){
        printf ("Insert 2 arguments as explained above please\n");
        return 1;
        }

    memset(dll,0,sizeof(dll));
    memset(funcion,0,sizeof(funcion));

    memcpy (dll, argv[1], strlen(argv[1]));
    memcpy (funcion, argv[2], strlen(argv[2]));

    libreria = LoadLibrary(dll);
    procadd = (MYPROC)GetProcAddress (libreria,funcion);

    printf ("Offset de %s en la DLL %s es %x", funcion, dll, procadd);

    return 0;

}
//It results in running offset.exe msvcrt.dll system -> 77c293c7