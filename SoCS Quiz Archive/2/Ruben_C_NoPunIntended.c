#include <stdio.h>
#include <signal.h> // Tadi buat Debugging GDB

int main(){
    char NIM[11];
    char Name[101];
    char PrefixClass;
    int ClassNumber;
    
    // Input
    scanf("%[^\n]", NIM);
    scanf("\n%[^\n]", Name);
    scanf("\n%c", &PrefixClass);
    scanf("\n%d", &ClassNumber);

    /*
    \n ditambahkan karena terdapat issue dengan Buffer (kalo kata ChatGPT) dan menurut observasi saya pribadi menggunakan GDB (Debugger GCC)
    Terdapat kebocoran Dec: 10 ASCII: \n (Line Feed) pada awal Variabel. Sehingga data terjadi "dislokasi".

    Diobservasi menggunakan GDB @ VS Code di Fedora Linux 42 WS.
    */
    
    // Rekomendasi dari Ricky, gunakan Output Formatting Width dan Flags (%-6s)
    printf("%-6s: %s\n", "Id", NIM);
    printf("%-6s: %s\n", "Name", Name);
    printf("%-6s: %c\n", "Class", PrefixClass);
    printf("%-6s: %d\n", "Num", ClassNumber);
    return 0;
}
