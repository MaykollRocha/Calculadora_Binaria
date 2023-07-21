#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "calc_arq_prototipacao.h"
#include "base_algs.h"
#include "alg_operacao.h"
#include "ambiente_de_interacao.h"

/***
 * @author Maykoll Rocha & Rafael José Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (início) 2023-07-13
 * @date  (Ultima Atualização) 2023-07-16
***/

/**
    Trabalho de arquitetura-2023.1
        Fazer uma calculadora com as lógicas de um computador onde usamos algoritmos de máquina
        a implemntação será feita em C.
        Usamos as formulas do livro Arquitetura e Organização de Computadores de William Stallings,
        as formulas estao na página
        Soma e Subtração    pg.259      fig 9.6
        Multiplicação       pg.253      fig 9.12
        Divisão             pg.267      fig 9.16
        Para fim de estudos, faça uma análise dos códigos na seguinte ordem.
        comece vendo o calc_arq_prototicacao.h para ter noção de como estao as cadeias.
        A seguir vá para o base_algs.h, onde faz todas as auxliares para as operações.
        Seguimos para alg_operacao.h onde temos as operações e como elas foram baseadas.
        E por fim o ambiente_de_interacao.h, é de suma importância entender que ele não mostra as contas.
        Para saber mais como era o trabalho, esta na descrição do GITHUB.
    Sobre Nos:
        Somos alunos de Engenharia de Computação fazendo a materia de Arquitura e Organização de Computadores
        E estamos no 5ºSemestre.
    Onde foi feito:
        SO: Windows 11
        IDE: CodeBlocks 20.03
        COMPILADOR VERSÂO: gcc.exe (tdm64-1) 10.3.0


**/

int main()
{
    int bit=0;
    setlocale(LC_ALL,"");
    printf("Entre com quantos bytes sua calculadora vai trabalhar durantes esse processo(4,8,16,32): ");
    do{
        if(bit!=0) printf("\x1b[31m" "Você entrou com um valor diferente do permitido." "\x1b[0m""\nTente Novamente: ");
        scanf("%i",&bit);
    }while(bit!=4 && bit!=8 && bit!=16 && bit!=32);
    system("cls");
    fflush(stdin);
    char op;
    while(1)
    {
        int c=45;//Tenta centralizar geometricamente o menu.
        gotoxy(c,2);//Cada linha com essa função centraliza em Coluna e linha.
        printf("+-------MENU-------+\n");
        gotoxy(c,3);
        printf("| ""\x1b[33m""'+'""\x1b[0m""Soma          |\n");
        gotoxy(c,4);
        printf("| ""\x1b[33m""'-'""\x1b[0m""Subtração     |\n");
        gotoxy(c,5);
        printf("| ""\x1b[33m""'*'""\x1b[0m""Multiplicação |\n");
        gotoxy(c,6);
        printf("| ""\x1b[33m""'/'""\x1b[0m""Divisão       |\n");
        gotoxy(c,7);
        printf("| ""\x1b[33m""'o'""\x1b[0m""Config        |\n");
        gotoxy(c,8);
        printf("| ""\x1b[33m""'e'""\x1b[0m""Exit          |\n");
        gotoxy(c,9);
        printf("+------------------+");
        gotoxy(c,10);
        printf("       Opção: ");
        scanf("%c",&op);
        switch(op)
        {
            case '+':
                system("cls");
                area_soma_op(bit);
                printf("\n");
                break;
            case '-':
                system("cls");
                area_sub_op(bit);
                printf("\n");
                break;
            case '*':
                system("cls");
                area_mult_op(bit);
                printf("\n");
                break;
            case '/':
                system("cls");
                area_div_op(bit);
                printf("\n");
                break;
            case 'o':
            case 'O':
                config(&bit);
                printf("\n");
                break;
            case 'e':
            case 'E':
                system("cls");
                return 1;
            default:
                gotoxy(c+3,11);
                printf("\x1b[31m""Código Inválido.\n" "\x1b[0m");
        }
        for(int i =0;i<40;i++)printf(" ");
        printf("Aperte qualquer tecla para prosseguir..");
        getch();
        system("cls");
        fflush(stdin);
    }
}
