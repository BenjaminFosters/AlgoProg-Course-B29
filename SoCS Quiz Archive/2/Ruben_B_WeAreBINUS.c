#include <stdio.h>

int main(){
    char teks[100];
    scanf("%[^\n]", &teks);

    printf("#include <stdio.h>\nint main()\n{\n    printf(\"%%s\\n\",\"%s\");\n    return 0;\n}\n", teks);

    /*Seperti Escaping \ (misal \n buat New Line) %% digunakan untuk menampilkan % as literal char*/

    return 0;
}