#include <stdio.h>
#include <string.h>

void allocateUnGuestSeating(char name[][21]) {
    for (int i = 0; i < 50; i++) {
        strcpy(name[i], "UNALLOCATED");
    }
}

int readData(FILE *data, char name[][21]) {
    char nameTemp[21];
    int seatTemp, i = 0;

    while (fscanf(data, "%[^#]#%d\n", nameTemp, &seatTemp) != EOF){
        strcpy(name[seatTemp-1], nameTemp);
        i++;
    }
    
    return i;
}

void printName(char name[][21]){
    printf("Daftar Pelanggan\n%-20s%-5s\n", "Nama", "Kursi");
    for (int i = 0; i < 20+5; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 50; i++) {
        if (strcmp(name[i], "UNALLOCATED")) {
            printf("%-20s%-5d\n", name[i], i+1);
        }
    }
    printf("\n");
}

int mainMenuSubsystem(char name[][21]) {
    int choice;
    printName(name);

    printf("Reservasi Online\n");
    printf("--------------------\n");
    printf("1. Buat Reservasi\n");
    printf("2. Batalkan Reservasi\n");
    printf("3. Urutkan Berdasarkan Nama\n");
    printf("4. Simpan dan Keluar\n");
    printf("Pilihanmu [1-4]: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

void reserveChairMenuSubsystem(char name[][21]) {
    char tempName[21]; 
    int tempChair;
    for (int i = 0; i < 50; i++) {
        if (strcmp(name[i], "UNALLOCATED")) {
            printf("[ X] ");
        } else {
            printf("[%2d] ", i+1);
        }

        if (((i+1) % 10) == 0) {
            printf("\n");
        }
    }

    do {
        printf("\nMasukkan Nama [Max 20 Character]: ");
        scanf(" %[^\n]", tempName);
        if (strlen(tempName) > 20) {
            printf("Namanya kepanjangan, limit 20 character, terima kasih!\n");
        }
    } while (strlen(tempName) > 20);
    
    do {
        printf("\nMasukkan Nomor Kursi [1-50]: ");
        scanf("%d", &tempChair);
        tempChair--;
        if (strcmp(name[tempChair], "UNALLOCATED")) {
            printf("Kursinya sudah direservasi, silahkan pilih kursi lain, terima kasih!\n");
        } else if (tempChair < 0 || tempChair > 20) {
            printf("Nomor tidak valid! Terima kasih!\n");
        }
    } while (strcmp(name[tempChair], "UNALLOCATED"));

    strcpy(name[tempChair], tempName);
}

void deleteRecord(char name[][21]) {
    int tempChair;
    printf("Pilih nomor kursi yang akan dibatalakn: ");
    scanf("%d", &tempChair);

    tempChair--;
    
    if (strcmp(name[tempChair], "UNALLOCATED")) {
        strcpy(name[tempChair], "UNALLOCATED");
        printf("Kursi sudah dibatalkan!\n");
    } else {
        printf("Kursi kosong!\n");
    }
}

int main(){
    FILE *data;
    char name[50][21];
    int dataSize, choice, interlock = 1;

    allocateUnGuestSeating(name);
    
    data = fopen("data_in.txt", "r");
    
    dataSize = readData(data, name);

    while (interlock) {
        choice = mainMenuSubsystem(name);

        switch (choice)
        {
        case 1:
            reserveChairMenuSubsystem(name);
            break;

        case 2:
            deleteRecord(name);
            break;
        
        case 4:
            interlock = 0;
            printf("Sampai Jumpa!\n");
            break;

        default:
            printf("Maaf, opsi invalid! Silahkan dicoba kembali!\n\n");
            break;
        }
    }

    return 0;
}