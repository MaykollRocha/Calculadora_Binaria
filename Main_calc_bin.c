#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include "calc_arq_prototipacao.h"
#include "base_algs.h"
#include "alg_operacao.h"
#include "ambiente_de_interacao.h"

/***
 * @author Maykoll Rocha & Rafael Jos� Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (in�cio) 2023-07-13
 * @date  (Ultima Atualiza��o) 2023-07-16
***/

/**
    Trabalho de arquitetura-2023.1
        Fazer uma calculadora com as logicas de um computador onde usamos algoritmos de maquina
        a implemnta��o sera feita em C.
        Usamos as formulas do livro Arquitetura e Organiza��o de Computadores de William Stallings,
        as formulas est�o na pagina
        Soma e Subtra��o    pg.259      fig 9.6
        Multiplica��o       pg.253      fig 9.12
        Divisores           pg.267      fig 9.16
        Para fim de estudos fa�a uma analise dos codigos na seguinte ordem,
        come�e vendo o calc_arq_prototicacao.h para ter no��o de como ta as cadeias
        depois v� para o base_algs.h la ele faz todas as auxliares para opera��es.
        depois vai para alg_operacao.h onde temos as opera��es e como elas foram baseadas.
        E por fim i ambiente_de_interacao.h � de suma importancia entender que ele n�o mostra o as contas
        est�o assim elas so est�o daqui para frente vai de suas analise.
        Para saber mais como era o trabalho ta na descri��o do GITHUB.
    Sobre Nos:
        Somos alunos de Engenharia de Computa��o fazendo a materia de Arquitura e Organiza��o de Computadores
        E estamos no 5�Semestre.
    Onde foi feito:
        SO: Windons 11
        IDE: CodeBlocs 20.03
        COMPILADOR VERS�O: gcc.exe (tdm64-1) 10.3.0


**/

int main()
{
    int bit=0;
    setlocale(LC_ALL,"");
    printf("Entre com quantos bits sua calculadora vai trabalhar durantes esse processo(8,16,32): ");
    do{
        if(bit!=0) printf("\x1b[31m" "Voc� entrou com um valor diferentes dos permitidos." "\x1b[0m""\nTente Novamente: ");
        scanf("%i",&bit);
    }while(bit!=8 && bit!=16 && bit!=32);
    system("cls");
    fflush(stdin);
    char op;
    while(1)
    {
        int c=45;//Tenta centralizar geometricamente o menu
        gotoxy(c,2);//cada linha com essa fun��o centraliza em Coluna e linha foi
        printf("+-------MENU-------+\n");
        gotoxy(c,3);
        printf("| ""\x1b[33m""'+'""\x1b[0m""soma          |\n");
        gotoxy(c,4);
        printf("| ""\x1b[33m""'-'""\x1b[0m""subtra��o     |\n");
        gotoxy(c,5);
        printf("| ""\x1b[33m""'*'""\x1b[0m""multiplica��o |\n");
        gotoxy(c,6);
        printf("| ""\x1b[33m""'/'""\x1b[0m""divis�o       |\n");
        gotoxy(c,7);
        printf("| ""\x1b[33m""'o'""\x1b[0m""config        |\n");
        gotoxy(c,8);
        printf("| ""\x1b[33m""'e'""\x1b[0m""exit          |\n");
        gotoxy(c,9);
        printf("+------------------+");
        gotoxy(c,10);
        printf("       Op��o: ");
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
                printf("\x1b[31m""Codigo invalido.\n" "\x1b[0m");
        }
        for(int i =0;i<40;i++)printf(" ");
        printf("Aperte qualquer coisa para continua.");
        getch();
        system("cls");
        fflush(stdin);
    }
}
