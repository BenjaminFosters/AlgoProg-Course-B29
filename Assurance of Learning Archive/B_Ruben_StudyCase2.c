#include <stdio.h>
#include <string.h>

struct apartmentData
{
    char locationA[18];
    char locationB[18];
    int price;
    int room;
    int bathroom;
    int parking;
    char type[11];
    char furnish[12];
} apartments[10000];

int readFile(FILE *data){
    fscanf(data, "%*[^\n]\n");

    int i = 0;
    while (fscanf(
        data,
        // FIX UNTUK CRLF (\r\n) (Windows Newline), UNIX pakai LF (\n)
        // Tested on Fedora Linux 43 KDE Plasma Edition
        " %25[^,],%25[^,],%d,%d,%d,%d,%25[^,],%25[^\r\n]",
        apartments[i].locationA,
        apartments[i].locationB,
        &apartments[i].price,
        &apartments[i].room,
        &apartments[i].bathroom,
        &apartments[i].parking,
        apartments[i].type,
        apartments[i].furnish
    ) == 8 ) {
        i++;
    }
    return i;
}

int lowerCaseIt(char text[]){
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i]+32;
        }
    }
}

int menuSubsystem() {
    int choice;
    
    printf("What do you want to do?\n");
    printf("1. Display Data\n");
    printf("2. Search Data\n");
    printf("3. Sort Data\n");
    printf("4. Export Data\n");
    printf("5. Exit\n");
    
    printf("Your Choice: ");
    scanf("%d", &choice);
    
    return choice;
}

void printList(int lengthData) {
    for (int i = -1; i < lengthData; i++) {
        if (i < 0) {
            printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
            "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
            for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                printf("-");
            }
            printf("\n");
        } else {
            printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
            apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
        }
    }
}
void listingSubsystem(int lengthData) {
    int row;

    do {
        printf("Number of Rows (up to %d): ", lengthData);
        scanf("%d", &row);

        if (row > lengthData || row < 1) {
            printf("Invalid option, try again!\n\n");
        }
    } while (row > lengthData || row < 1);

    printf("\n");
    printList(row);
}

// Find Data System
void findDataSubsystem(int lengthData) {
    int interlock = 1;
    int counter = 0;
    char choice[18], tempComp[18];
    int choiceNumber;

    
    do {
        printf("Choose Column: ");
        scanf("%s", choice);
        lowerCaseIt(choice);
        
        if (!strcmp(choice, "location")) {
            printf("Enter Desired Location: ");
            scanf("%s", choice);
            lowerCaseIt(choice);
            for (int i = -1; i < lengthData; i++) {
                if (i < 0) {
                    printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
                    "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                        printf("-");
                    }
                    printf("\n");
                } else {
                    strcpy(tempComp, apartments[i].locationA);
                    lowerCaseIt(tempComp);
                    if (!strcmp(tempComp, choice)) {
                        printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
                        apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
                        counter++;
                    }
                }
            }

            if (counter == 0) {
                printf("No Data Found\n");
            }
        } else if (!strcmp(choice, "city")) {
            printf("Enter Desired City: ");
            scanf("%s", choice);
            lowerCaseIt(choice);
            for (int i = -1; i < lengthData; i++) {
                if (i < 0) {
                    printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
                    "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                        printf("-");
                    }
                    printf("\n");
                } else {
                    strcpy(tempComp, apartments[i].locationB);
                    lowerCaseIt(tempComp);
                    if (!strcmp(tempComp, choice)) {
                        printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
                        apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
                        counter++;
                    }
                }
            }

            if (counter == 0) {
                printf("No Data Found\n");
            }
        } else if (!strcmp(choice, "price")) {
            printf("Enter Price: ");
            scanf("%d", &choiceNumber);
            for (int i = -1; i < lengthData; i++) {
                if (i < 0) {
                    printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
                    "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                        printf("-");
                    }
                    printf("\n");
                } else {
                    if (choiceNumber == apartments[i].price) {
                        printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
                        apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
                        counter++;
                    }
                }
            }

            if (counter == 0) {
                printf("No Data Found\n");
            }
        } else if (!strcmp(choice, "room")) {
            printf("Enter Room Total: ");
            scanf("%d", &choiceNumber);
            for (int i = -1; i < lengthData; i++) {
                if (i < 0) {
                    printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
                    "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                        printf("-");
                    }
                    printf("\n");
                } else {
                    if (choiceNumber == apartments[i].room) {
                        printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
                        apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
                        counter++;
                    }
                }
            }

            if (counter == 0) {
                printf("No Data Found\n");
            }
        } else if (!strcmp(choice, "carpark")) {
            printf("Enter Carpark Amount: ");
            scanf("%d", &choiceNumber);
            for (int i = -1; i < lengthData; i++) {
                if (i < 0) {
                    printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
                    "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                        printf("-");
                    }
                    printf("\n");
                } else {
                    if (choiceNumber == apartments[i].parking) {
                        printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
                        apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
                        counter++;
                    }
                }
            }

            if (counter == 0) {
                printf("No Data Found\n");
            }
        } else if (!strcmp(choice, "type")) {
            printf("Enter Desired Type: ");
            scanf("%s", choice);
            lowerCaseIt(choice);
            for (int i = -1; i < lengthData; i++) {
                if (i < 0) {
                    printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
                    "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                        printf("-");
                    }
                    printf("\n");
                } else {
                    strcpy(tempComp, apartments[i].type);
                    lowerCaseIt(tempComp);
                    if (!strcmp(tempComp, choice)) {
                        printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
                        apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
                        counter++;
                    }
                }
            }

            if (counter == 0) {
                printf("No Data Found\n");
            }
        } else if (!strcmp(choice, "furnish")) {
            printf("Enter Desired Furnish: ");
            scanf("%s", choice);
            lowerCaseIt(choice);
            for (int i = -1; i < lengthData; i++) {
                if (i < 0) {
                    printf("%-25s%-25s%-10s%-7s%-10s%-10s%-10s%s\n",
                    "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    for (int j = 0; j < 25+25+10+7+10+10+10+12; j++) {
                        printf("-");
                    }
                    printf("\n");
                } else {
                    strcpy(tempComp, apartments[i].furnish);
                    lowerCaseIt(tempComp);
                    if (!strcmp(tempComp, choice)) {
                        printf("%-25s%-25s%-10d%-7d%-10d%-10d%-10s%s\n",
                        apartments[i].locationA, apartments[i].locationB, apartments[i].price, apartments[i].room, apartments[i].bathroom, apartments[i].parking, apartments[i].type, apartments[i].furnish);
                        counter++;
                    }
                }
            }

            if (counter == 0) {
                printf("No Data Found\n");
            }
        } else {
            printf("Umm, Wrong Column!\n");
            interlock = 0;
        }
    } while (interlock == 0);
}

// Sort System (Assisted with GPT 5)
int cmpString(const char *a, const char *b, int order) {
    char ta[50], tb[50];
    strcpy(ta, a);
    strcpy(tb, b);
    lowerCaseIt(ta);
    lowerCaseIt(tb);
    return order * strcmp(ta, tb);
}
int cmpInt(int a, int b, int order) {
    return order * (a - b);
}
void sortApartments(int lengthData, const char *column, int order) {
    for (int i = 0; i < lengthData - 1; i++) {
        for (int j = 0; j < lengthData - i - 1; j++) {
            int swap = 0;

            if (!strcmp(column, "location"))
                swap = cmpString(apartments[j].locationA, apartments[j+1].locationA, order) > 0;

            else if (!strcmp(column, "city"))
                swap = cmpString(apartments[j].locationB, apartments[j+1].locationB, order) > 0;

            else if (!strcmp(column, "price"))
                swap = cmpInt(apartments[j].price, apartments[j+1].price, order) > 0;

            else if (!strcmp(column, "room"))
                swap = cmpInt(apartments[j].room, apartments[j+1].room, order) > 0;

            else if (!strcmp(column, "bathroom"))
                swap = cmpInt(apartments[j].bathroom, apartments[j+1].bathroom, order) > 0;

            else if (!strcmp(column, "carpark"))
                swap = cmpInt(apartments[j].parking, apartments[j+1].parking, order) > 0;

            else if (!strcmp(column, "type"))
                swap = cmpString(apartments[j].type, apartments[j+1].type, order) > 0;

            else if (!strcmp(column, "furnish"))
                swap = cmpString(apartments[j].furnish, apartments[j+1].furnish, order) > 0;

            if (swap) {
                struct apartmentData tmp = apartments[j];
                apartments[j] = apartments[j+1];
                apartments[j+1] = tmp;
            }
        }
    }
}
void sortItemSubsystem(int lengthData) {
    char column[18];
    char orderText[5];

    while (true) {
        printf("Choose Column: ");
        scanf("%s", column);
        lowerCaseIt(column);

        if (!strcmp(column, "location") ||
        !strcmp(column, "city") ||
        !strcmp(column, "price") ||
        !strcmp(column, "room") ||
        !strcmp(column, "rooms") ||
        !strcmp(column, "bathroom") ||
        !strcmp(column, "carpark") ||
        !strcmp(column, "type") ||
        !strcmp(column, "furnish")) {
            break;
        }
    }

    
    while (true)
    {
        printf("Sort *asc*ending or *des*cending: ");
        scanf("%s", orderText);
        lowerCaseIt(orderText);

        if (!strcmp(orderText, "asc")) {
            sortApartments(lengthData, column, 1);
            break;
        } else if (!strcmp(orderText, "des")) {
            sortApartments(lengthData, column, -1);
            break;
        }
    }
    printf("Data Sorted (Top 10 Data):\n");
    printList(10);
}

void exportItemSubsystem(int lengthData) {
    FILE *write;
    char filename[25];
    
    do
    {
        printf("FIle Name: ");
        scanf(" %[^\n]", filename);
        
        if (strlen(filename) > 20) {
            printf("That's more than 20 Characters, sorry.\n");
        } else if (strlen(filename) > 20) {
            printf("That's no file name, sorry.\n");
        }
    } while (strlen(filename) > 20 || strlen(filename) == 0);
    
    sprintf(filename, "%s%s", filename, ".csv");

    write = fopen(filename, "a");

    for (int i = 0; i < lengthData; i++) {
        if (i == lengthData-1) {
            fprintf(write,
                "%s,%s,%d,%d,%d,%d,%s,%s",
                apartments[i].locationA,
                apartments[i].locationB,
                apartments[i].price,
                apartments[i].room,
                apartments[i].bathroom,
                apartments[i].parking,
                apartments[i].type,
                apartments[i].furnish
            );
        } else {
            fprintf(write,
                "%s,%s,%d,%d,%d,%d,%s,%s\n",
                apartments[i].locationA,
                apartments[i].locationB,
                apartments[i].price,
                apartments[i].room,
                apartments[i].bathroom,
                apartments[i].parking,
                apartments[i].type,
                apartments[i].furnish
            );
        }
    }
}

int main(){
    FILE *data;
    int choice;

    data = fopen("data.csv", "r");
    int lengthData = readFile(data);
    fclose(data);

    do {
        choice = menuSubsystem();

        switch (choice) {
            case 1:
                listingSubsystem(lengthData);
                break;

            case 2:
                findDataSubsystem(lengthData);
                break;

            case 3:
                sortItemSubsystem(lengthData);
                break;

            case 4:
                exportItemSubsystem(lengthData);
                break;

            case 5:
                printf("Hey, Thank you! See you later!\n");
                break;
            
            default:
                printf("Invalid Choice, try again!\n\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}