#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Characteristics{
        int Health;
        int Damage;
        int Heal;
}Characteristics;

char name[50], name2[50];
int compare;

main(){

        srand(time(NULL));
        int character, fight, action, round, repeat;
        Characteristics yourCharacteristics, otherCharacteristics;
        
        do{

        system("cls");

        printf(
        "\t\t---- POKEMON GAME ----                       \n"
        "\t _ __   ___ | | _____ _ __ ___   ___  _ __ \n"
        "\t| '_ \ / _ \| |/ / _ \ '_ ` _ \ / _ \| '_  \n"
        "\t| |_) | (_) |   <  __/ | | | | | (_) | | | |\n"
        "\t| .__/ \___/|_|\_\___|_| |_| |_|\___/|_| |_|\n"
        "\t|_|                                         \n"
        "\t\t---- POKEMON GAME ----\n\n                     ");

        printf("Escolha o seu personagem:\n1 - Charmander\n2 - Charizard\n3 - Lugia\n");
        
        do{
                character = 0; // para nao bugar no looping

        scanf("%i", &character);
        fflush(stdin);

        switch (character){
        case 1:
        strcpy(name, "Charmander");
        yourCharacteristics.Health = 400;
        yourCharacteristics.Damage = 1 + rand() % 100;
        yourCharacteristics.Heal = 1 + rand() % 70;
        break;

        case 2:
        strcpy(name, "Charizard");
        yourCharacteristics.Health = 300;
        yourCharacteristics.Damage = 1 + rand() % 100;
        yourCharacteristics.Heal = 1 + rand() % 70;
        break;

        case 3:
        strcpy(name, "Lugia");
        yourCharacteristics.Health = 200;
        yourCharacteristics.Damage = 1 + rand() % 100;
        yourCharacteristics.Heal = 1 + rand() % 70;
        break;
        
        default:
        system("cls");
        pokemonAscii();

        printf("\nEscolha um personagem valido!\n\n");
        printf("Escolha o seu personagem:\n1 - Charmander\n2 - Charizard\n3 - Lugia\n");
        }

        }while(character != 1 && character != 2 && character !=3);

        system("cls");
        pokemonAscii();
        printf("\nVoce ira jogar com: %s\n\n", name);
        printf("Escolha com qual personagem vai lutar:\n1 - Charmander\n2 - Charizard\n3 - Lugia\n");

        do{
                fight = 0; // para n bugar no looping

                scanf("%i", &fight);
                fflush(stdin);

        switch(fight){
                case 1:
                strcpy(name2, "Charmander");
                otherCharacteristics.Health = 400;
                otherCharacteristics.Damage = 1 + rand() % 100;
                otherCharacteristics.Heal = 1 + rand() % 70;

               if (comparation() == 0){ // se for verdadeiro, executa essa funcao 
                }

                else{
                        result(); // resultado da luta
                }
                break;
        // --------------------------------------------------------------------- //

                case 2:
                strcpy(name2, "Charizard");
                otherCharacteristics.Health = 300;
                otherCharacteristics.Damage = 1 + rand() % 100;
                otherCharacteristics.Heal = 1 + rand() % 70;

                if(comparation() == 0){
                }

                else{
                        result();
                }
                break;
        // --------------------------------------------------------------------- //

                case 3:
                strcpy(name2, "Lugia");
                otherCharacteristics.Health = 200;
                otherCharacteristics.Damage = 1 + rand() % 100;
                otherCharacteristics.Heal = 1 + rand() % 70;

                if(comparation() == 0){
                }

                else{
                        result();
                }
                break;
        // --------------------------------------------------------------------- //

                default:
                system("cls");
                pokemonAscii();

                printf("\nEscolha um personagem valido!\n\n");
                printf("Escolha o seu personagem:\n1 - Charmander\n2 - Charizard\n3 - Lugia\n");
        }

        }while(comparation() == 0 || fight != 1 && fight != 2 && fight != 3);

        printf("\nSua vida atual: %i\nVida atual do inimigo: %i\n", yourCharacteristics.Health, otherCharacteristics.Health);

        do{
                action = 0; // reseta para nao bugar o looping

                printf("\nEscolha uma acao:\n1 - Atacar\n2 - Curar\n");
                scanf("%i", &action);
                fflush(stdin);

                system("cls");
                fightAscii();

                yourCharacteristics.Damage = 1 + rand() % 100; // pros numeros SEMPRE forem aleatorios no LOOPING - Damage
                otherCharacteristics.Damage = 1 + rand() % 100; // - Damage
                yourCharacteristics.Heal = 1 + rand() % 70; // - Heal
                round = 1 + rand() % 7; // Round aleatorio para critico

        switch(action){
                case 1:
                printf("\nVoce escolheu atacar!\n");

                // numero qualquer entre 1 e 7 - Critico
                if(round == 5){ 
                        printf("\nDANO CRITICO APLICADO !!!\nDano comum: %i\n\n", yourCharacteristics.Damage); // SEM Critico
                
                        yourCharacteristics.Damage *= 1.50; // APLICANDO Critico
                        printf("Dano com Critico: %i\nDano recebido: %i\n", yourCharacteristics.Damage, otherCharacteristics.Damage);
                        // 50% do DANO de critico
                }
                
                else{
                        printf("Dano causado: %i\nDano recebido: %i\n", yourCharacteristics.Damage, otherCharacteristics.Damage);
                }

                        // valor total dos danos  
                yourCharacteristics.Health -= otherCharacteristics.Damage;
                otherCharacteristics.Health -= yourCharacteristics.Damage;

                printf("\nSua vida atual apos o ataque: %i\n", yourCharacteristics.Health);
                printf("Vida do inimigo apos o ataque: %i\n", otherCharacteristics.Health);

                break;

                case 2:
                printf("\nVoce escolheu curar!\nCura recebida: %i\n", yourCharacteristics.Heal);
                
                // valor total da cura
                yourCharacteristics.Health += yourCharacteristics.Heal;

                printf("Vida apos a cura: %i\n\n", yourCharacteristics.Health);
                printf("Dano recebido: %i", otherCharacteristics.Damage);

                yourCharacteristics.Health = yourCharacteristics.Health - otherCharacteristics.Damage; // vida APOS a Cura MENOS o Dano !!

                printf("\nSua vida atual apos o ataque inimigo: %i\n", yourCharacteristics.Health);
                printf("Vida atual do inimigo: %i\n", otherCharacteristics.Health);

                break;

                default:
                printf("\nAcao invalida! Digite apenas entre 1 e 2!\n");
        }
                // usar && ou || para conectar com outras variaveis
        }while(action != 1 && action != 2 || yourCharacteristics.Health >0 && otherCharacteristics.Health >0);

        if(yourCharacteristics.Health <= 0 && otherCharacteristics.Health >0){
                lose();
                printf("\nVoce perdeu! Seu personagem morreu!");
        }

        if(otherCharacteristics.Health <=0 && yourCharacteristics.Health >0){
                win();
                printf("\nVoce ganhou! Inimigo derrotado!");
        }

        if(yourCharacteristics.Health <=0 && otherCharacteristics.Health <=0){
                draw();
                printf("\nEmpate! Os dois personagens morreram!");
        }

        repeat = 0; // reseta o repeat na VOLTA do looping(para n bugar quando digitar para sair)

        printf("\n\nVoce quer jogar novamente?\nSim - 1\nNao - Qualquer outra tecla\n");
        scanf("%i", &repeat);
        fflush(stdin);
        }while(repeat == 1);

        printf("\nVoce escolheu sair!\nJogo fechado.");
}

void fightAscii(){
        printf(
"\t    |\                     /)\n"
"\t    /\_\\__               (_//\n"
"\t    |   `>\-`     _._       //`)\n"
"\t    \ /` \\  _.-`:::`-._  //\n"
"\t    \|`    :::    `|/\n" 
"\t        |     :::     |\n"
"\t        |.....:::.....|\n"
"\t        |:::::::::::::|              %s x %s\n"
"\t        |     :::     |              LUTEM !!!!        \n"
"\t        \     :::     /\n"
"\t          \    :::    /\n"
"\t           `-. ::: .-'\n"
"\t            //`:::`\\\n"
"\t           //   '   \\\n"
"\t          |/         \\\n", name, name2);
}

void comparation(){
        compare = strcmp(name,name2);
        if(compare == 0){ // se forem iguais
        system("cls");
        pokemonAscii();
        printf("\nNao e' possivel lutar contra voce mesmo!\nTente novamente.\n\n");
        printf("Seu personagem: %s. Nao repita o mesmo.\n", name);
        printf("\nEscolha com qual personagem vai lutar:\n1 - Charmander\n2 - Charizard\n3 - Lugia\n");
        return 0;
        }
}

void result(){
        system("cls");
        printf("Seu personagem: %s\n", name);
        printf("Voce escolheu lutar contra: %s!\n", name2);
        printf("\nIniciando a luta...\n\n");
        fightAscii();
        return 0;
}

void pokemonAscii(){
        printf(
        "\t\t---- POKEMON GAME ----                       \n"
        "\t _ __   ___ | | _____ _ __ ___   ___  _ __ \n"
        "\t| '_ \ / _ \| |/ / _ \ '_ ` _ \ / _ \| '_  \n"
        "\t| |_) | (_) |   <  __/ | | | | | (_) | | | |\n"
        "\t| .__/ \___/|_|\_\___|_| |_| |_|\___/|_| |_|\n"
        "\t|_|                                         \n"
        "\t\t---- POKEMON GAME ----\n                     ");
}

void win(){
        printf(
" __        _____ _   _\n"
" \ \      / /_ _| \ | |\n"
"  \ \ /\ / / | ||  \| |\n"
"   \ V  V /  | || |\  |\n"
"    \_/\_/  |___|_| \_|\n");
}

void lose(){
        printf(
"  _     ___  ____  _____\n"
" | |   / _ \/ ___|| ____|\n"
" | |  | | | \___ \|  _|\n"  
" | |__| |_| |___) | |___\n"
" |_____\___/|____/|_____|\n");
}

void draw(){
        printf(
"  ____  ____      ___        __\n"
" |  _ \|  _ \    / \ \      / /\n"
" | | | | |_) |  / _ \ \ /\ / /\n"
" | |_| |  _ <  / ___ \ V  V /\n"  
" |____/|_| \_\/_/   \_\_/\_/\n");
}