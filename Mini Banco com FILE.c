#include <stdio.h>
#include <string.h>

    // define's da Função hidePassword !
#define ENTER 13
#define TAB 9
#define BCKSPC 8

typedef struct{

    char user[100], password[100];
    char inputRegisterUser[100], inputRegisterPassword[100];
    char inputLoginUser[100], inputLoginPassword[100];
    int statusRegister, statusLogin;

}db;

char loggedUser[100];
int accountOption;

void bankAscii();
void hidePassword();

db registerAccount();
db loginAccount(); // Assim pq RETORNA um Valor (statusLogin, no caso) = FUNÇÃO !
db bankActions();

main(){

    char fileName[100] = {"sistemaLogin.txt"};
    char bankInfo[100] = {"bankInfo.txt"};
    
    db login;

    printf("Escolha uma das opcoes:\n0 - Sair\n1 - Registrar\n2 - Logar\n");

    do{
    accountOption = 3;
    scanf("%i", &accountOption);
    fflush(stdin);
    printf("\n");

        // Register or Login 
    switch(accountOption){
        case 0:
        printf("Voce escolheu sair!\nSistema fechado.");
        break;

        case 1:
        login = registerAccount(fileName); // diferente do loginAccount pq pela lógica do FILE o retorno PRECISA ser dentro da Função !
        break;
        
        case 2:
        login = loginAccount(fileName); // a Struct db com nome login recebe o retorno da Função loginAccount

        if(login.statusLogin == 1){
            printf("\nLogged.");
        }

        else{
            system("cls");
            bankAscii();
            printf("Incorrect login!\nAccess denied.\n\nEscolha uma das opcoes:\n0 - Sair\n1 - Registrar\n2 - Logar\n");
        }

        break;

        default:
        system("cls"); // por algum motivo o compilador ta demorando pra limpar a tela ??
        bankAscii();
        printf("Opcao invalida!\n\nEscolha uma das opcoes:\n0 - Sair\n1 - Registrar\n2 - Logar\n");
    }
    }while(accountOption != 0 && login.statusRegister != 1 && login.statusLogin != 1);
    
    if(login.statusLogin == 1){
        strcpy(loggedUser, login.inputLoginUser);
        system("cls");
        bankAscii();
        login = bankActions(bankInfo);
    }

}

db registerAccount(char file[]){
    FILE *newFile;
    newFile = fopen(file, "a+"); // para Adicionar mais Conteúdo no FINAL do Arquivo (esse + porque além de Escrever, tb permite LER !)

    db login;

    if(newFile){

        system("cls");
        bankAscii();

        printf("Usuario:\n");
        scanf("%100[^\n]", login.inputRegisterUser);

        printf("\nSenha:\n");
        hidePassword(login.inputRegisterPassword);

        while(fscanf(newFile, " %100[^\n]\n%s", login.user, login.password) != -1){
            if(strstr(login.user, login.inputRegisterUser)){
                login.statusRegister = 0;
                accountOption = 3;
                break;
            }

            else{
                login.statusRegister = 1; 
            } // por algum motivo nao precisa do break
        }

            strcpy(login.user, login.inputRegisterUser);
            strcpy(login.password, login.inputRegisterPassword);
        
        if(login.statusRegister == 1){ // quando o Arquivo n tem NENHUM dado, buga e tem que por != 1 ou Escrever no Arquivo com 2 Enter final !
            printf("\nConta cadastrada com sucesso!");
        fprintf(newFile, "%s\n%s\n", login.user, login.password);
        fputc('\n', newFile);
        }

        else{
            system("cls");
            bankAscii();
            printf("\nUsuario ja existe!\nTente novamente.\n\nEscolha uma das opcoes:\n0 - Sair\n1 - Registrar\n2 - Logar\n");
        }
        
        return login;
        
        fclose(newFile);
    }

    else{
        printf("Nao foi possivel abrir o arquivo!");
    }
}

db loginAccount(char file[]){
    FILE *newFile;
    newFile = fopen(file, "r");

    db login;

    if(newFile){

        login.statusLogin = 0; // para não bugar nos If's

        system("cls");
        bankAscii();

        printf("Usuario:\n");
        scanf("%100[^\n]", login.inputLoginUser);
        fflush(stdin);

        printf("\nSenha:\n");
        hidePassword(login.inputLoginPassword);
        printf("\n");

        while(fscanf(newFile, " %100[^\n]\n%s", login.user, login.password) != -1){
            if((strcmp(login.inputLoginUser, login.user) == 0) && (strcmp(login.inputLoginPassword, login.password) == 0)){
                printf("Login successful !");
                login.statusLogin = 1;
                break;
            }
            
            else if((strcmp(login.inputLoginUser, login.user) == 0) && (strcmp(login.inputLoginPassword, login.password) != 0)){
                login.statusLogin = 0;
                break;
            }

                // PARA NAO PERMITIR SENHAS IGUAIS COM USUARIOS DIFERENTES!
            // else if((strcmp(login.inputLoginUser, login.user) != 0) && (strcmp(login.inputLoginPassword, login.password) == 0)){
            //     printf("Incorrect login!"); // ARRUMAR ISSO --- lewa / cesar112
            //     login.statusLogin = 0;
            //     break;
            // }
        }

        return login;
        
        fclose(newFile);
    }

    else{
        printf("Nao foi possivel abrir o arquivo!");
    }
}

db bankActions(char file[]){
    FILE *newFile;
    newFile = fopen(file, "a+");

    db login;

    int balance = 0;
    int bankOption;
    int withdraw;
    int deposit;

    if(newFile){
        
        printf("\t--- BANK SYSTEM ---\n");

        do{
            bankOption = 4;

            printf("\n0 - Sair\n1 - Ver saldo\n2 - Depositar\n3 - Sacar\n");
            scanf("%i", &bankOption);
            fflush(stdin);
    
        switch(bankOption){
            case 0:
            printf("\nAccount disconnected.\n");
            break;

            case 1:
            system("cls");
            bankAscii();
            printf("Seu saldo atual e': %i\n", balance);
            break;

            case 2:
            system("cls");
            bankAscii();
            printf("Escolha uma quantia para depositar em sua conta:\n");
            scanf("%i", &deposit);
            balance += deposit;
            break;

            case 3:
            system("cls");
            bankAscii();
            printf("Escolha uma quantia para sacar:\n");
            scanf("%i", &withdraw);
            balance -= withdraw;
            break;

            default:
            system("cls");
            bankAscii();
            printf("Escolha uma opcao valida!\n");
        }
        }while(bankOption != 0);

    
        fprintf(newFile, "%s\n%i\n", loggedUser, balance);
        fputc('\n', newFile);

        return login;

        fclose(newFile);

    }

    else{
        printf("Nao foi possivel abrir o arquivo!");
    }
}

void hidePassword(char varPass[50]){
	int i = 0;
	char ch;
	while(1){
		ch = _getch();
		if(ch == ENTER || ch == TAB){
			varPass[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			varPass[i++] = ch;
			printf("* \b");
		}
	}
}

void bankAscii(){
    printf(
"\t.______        ___      .__   __.  __  ___\n" 
"\t|   _  \      /   \     |  \ |  | |  |/  /\n" 
"\t|  |_)  |    /  ^  \     |   \|  | |  '  /\n"  
"\t|   _  <    /  /_\  \   |  . `  | |    <\n"   
"\t|  |_)  |  /  _____  \  |  |\   | |  .  \ \n"
"\t|______/  /__/     \__\ |__| \__| |__|\__\ \n\n");
}