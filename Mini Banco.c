#include <stdio.h>
#include <string.h>

typedef struct{

    char name[100];
    char country[50];
    int age;

}user;

typedef struct{

    user user;
    char bank[50];
    int balance, deposit, withdrawn;

}bank;

bank getInformation();
void readInformation();
void options();

main(){

    bank info;

    info = getInformation();
    readInformation(info);

}

bank getInformation(){

    bank get;
    int option;

    printf("Choose your bank:\n1 - Inter\n2 - Nubank\n3 - Santander\n");

    do{
    scanf("%i", &option);
    fflush(stdin);

    switch(option){
        case 1:
        printf("\nYou chose the Inter bank!\n");
        strcpy(get.bank, "Inter");
        break;

        case 2:
        printf("\nYou chose the Nubank bank!\n");
        strcpy(get.bank, "Nubank");
        break;
        
        case 3:
        printf("\nYou chose the Santander bank!\n");
        strcpy(get.bank, "Santander");
        break;

        default:
        system("cls");
        printf("\nInvalid option! Try again.\n\nChoose your bank:\n1 - Inter\n2 - Nubank\n3 - Santander\n");
    }
    }while(option != 1 && option != 2 && option != 3);

    printf("\nWrite your name:\n");
    scanf(" %[^\n]", &get.user.name);

    printf("\nWrite your country:\n");
    scanf(" %[^\n]", &get.user.country);

    printf("\nWrite your age:\n");
    scanf("%i", &get.user.age);

    return get;
}

void readInformation(bank info){

    info.balance = 0;
    int option;

    system("cls");
    printf("\t----BANK: %s ---\n", info.bank);
    printf("\n\tUSER:\nName: %s\nCountry: %s\nAge: %i\n", info.user.name, info.user.country, info.user.age);
    printf("\nChoose an option:\n\n0 - Exit\n1 - Check the balance\n2 - To deposit\n3 - To withdrawn\n");

    do{
        scanf("%i", &option);
        fflush(stdin);
    
    switch(option){

        case 0:
        printf("\nYou chose to exit!\nAccount disconnected.");
        break;

        case 1:
        system("cls");
        printf("\nYou chose check the balance!\n\nBalance: %i\n", info.balance);
        options();
        break;

        case 2:
        system("cls");
        printf("\nYou chose to deposit!\n\nAmount to deposit:\n");
        scanf("%i", &info.deposit);
        info.balance += info.deposit;
        options();
        break;

        case 3:
        system("cls");
        printf("\nYou chose to withdrawn!\n\nAmount to withdrawn:\n");
        scanf("%i", &info.withdrawn);

        if((info.balance - info.withdrawn) < 0){ // Condição para o RESULTADO de uma Operação 
            printf("Invalid balance!\n");
            
        }

        else if(info.withdrawn == 0){
            printf("Withdrawal just greater than 0! \n");
        }

        else{
            printf("Withdrawn!\n");
            info.balance -= info.withdrawn;
        }
        options();
        break;

        default:
        system("cls");
        printf("\nInvalid option! Try again.\n\n0 - Exit\n1 - Check the balance\n2 - To deposit\n3 - To withdrawn\n");
    }
    }while(option == 1 || option == 2 || option == 3 || option != 0 && option != 1 && option != 2 && option != 3 );

    return option;
}

void options(){
    printf("\n0 - Exit\n1 - Check the balance\n2 - To deposit\n3 - To withdrawn\n");
}