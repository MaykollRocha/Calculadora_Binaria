/***
 * @author Maykoll Rocha & Rafael José Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (início) 2023-07-13
 * @date  (Ultima Atualização) 2023-07-14
***/
#ifndef ambiente_de_interacao_h
#define ambiente_de_interacao_h
/**
    Faz a leitura do tamanho e vai de tras para frente
    pos já foi dito como o código mensura a aplicação de bits.
**/
void printar_vetor_binario(int *vet,int tam)
{
    for(int i = tam-1; i>=0; i--)
        printf("\x1b[32m""%i""\x1b[0m",vet[i]);
}
/**
    Toda a criação visual segue a mesma linha de raciocinio sendo o maximo de 100 carcteres
    ela é responsiva de acordo com o tamanho de bites pedidos ao início do código
    problema:
        É meio que imposivel fazer com que o ponteiro volte ao local depois entra com os
    dados por conta disso as linha de sacanf não fecha logo ficara feio e pra resolver teria
    que passar para o C++ e fazer redimencinamento de ponteiro, porem estamos em C e isso torna
    inviavel ir para o C++.
        Caso você seja um desenvolvedor do futuro e estaja lendo isso fique avontade para modificar
    essa configuração e passar esse codigo para o C++.
    OBS:
        Explicarei em cada linha do print com que parte mexe e as partes iguais sem expliação seguem o mesmo racionio da anteirioe esplicada.
    Temo importante!!!
    Nos comentarios a umas parte que chamo de linha ou linha visual isso se refere as linhas de 100 caracteres que aparece em seu programa.
**/


void area_soma_op(int tam)
{
    //Primeira linha cabeçalho que informa o tipo de operação.
    printf("+");//cria a base superior
    for(int i=0; i<48; i++)printf("-");//Printa metade da linhas de visual
    printf("SOMA");//Nome da operação a ser efetuada
    for(int i=0; i<48; i++)printf("-");//Printa a outra metade da linha
    printf("+\n");//Fecha o cabeçalho

    //Assume um vetor de 2 inteiro grande por conta de que o int padrão não le o inte de 31 bits.
    long long int valor[2];
    fflush(stdin);//limpar o buffer anterior

    //Um laço para por os operandandos no vetor long long
    for(int i = 0; i<2; i++)
    {
        //Linha 2 e 3 caso não entre com nenhum erro
        printf("|");
        for(int i=0; i<35; i++)printf(" ");

        printf("Valor %i em decimal: ",i+1); //Aviso de qual valor sera posto
        do
        {
            //Um laço para tratamento de entra caso seja posto um valor inviavel.
            scanf("%lld",&valor[i]);

            if(chek_caso_invalido(valor[i],tam))//Cheka o caso de ser um valor invalido.
            {
                //Cria um espaço de 100 informando que não pode entrar com esse favalor e faz 2 linha a mais
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu numero estrapola a cacidade de bites""\x1b[0m");
                printf("                         |\n|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""sendo essa um intervalo de %lld até %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);//Mostra os valores permitidos de acordo com o tamanho do bit
                int auxt = (tam==8)?27:(tam==16)?23:13;//Reponsivo para que não fique feio pois de acord com o tamnho do bit ele gasta mais espaço dentro do 100
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);//Limpada de buffer
                printf("Tente outro valor:");//Pedido de novo valor
            }
        }
        while(chek_caso_invalido(valor[i],tam));
        fflush(stdin);
    }

    //Linha 4 que é so divisora e informa que um resutado sera posto.
    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");

    //Arrumar as variaveis em vertores de inteiro com 0 e 1;
    int *vet1,*vet2;
    vet1 = dec_to_bin(valor[0],tam);
    vet2 = dec_to_bin(valor[1],tam);


    //linha 5 ela só separa os para ter uma pix da marge superior
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n|");

    //Linha 6 expressa em bits o vetor de inteiro, e tenta centralizar o maiximo para cada tipo de entrada
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printar_vetor_binario(vet1,tam);
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printf("|\n|");

    //Linha 7 coloca o sinal da conta + - * / e depois expressa o bit que fará isso.
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("+");
    printar_vetor_binario(vet2,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");

    //Linha 8 Expressa um cadeia de  - para separa os operandos do resultado
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    for(int i=0; i<tam+2; i++)printf("-");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("|\n|");

    //linha 9 apresenta o resultado e tenta centralizalo
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printar_vetor_binario(bin_sum(vet1,vet2,tam),tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");

    //Linha 10 apresenta um pixel do fim e vira uma linha de 100 vazia.
    printf("|\n|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    //linha 11 Fecha toda a cadeia de conta
    printf("+");
    for(int i=0; i<100; i++)printf("-");
    printf("+\n");

    //Apresenta o resultado final em descimal para mostrar que ta certo
    for(int i=0; i<30; i++)printf(" ");
    printf("resultado decimal: %lld + %lld = %lld",bin_to_dec(vet1,tam),bin_to_dec(vet2,tam),bin_to_dec(bin_sum(vet1,vet2,tam),tam));

    // Por ser ponteiros limpa ponteiro.
    free(vet1);
    free(vet2);
}

/**
    As primeira parte visual até a linha visual 4 é sempre a mesma para todas as operações, so muda o nome da operação sua pixelagem continua igual
    A subtração e a soma é tudo igual visualmente falando logo não expressei aqui, porem fiz um ctrl+c ctrl+v e mudei as dimenções.
**/
void area_sub_op(int tam)
{
    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("SUBTRAÇÃO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");

    long long int valor[2];
    fflush(stdin);
    for(int i = 0; i<2; i++)
    {
        printf("|");
        for(int i=0; i<35; i++)printf(" ");
        printf("Valor %s em decimal: ",(i==0)?"íncial":"subtrator");
        do
        {
            scanf("%lld",&valor[i]);
            if(chek_caso_invalido(valor[i],tam))
            {
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu numero estrapola a cacidade de bites""\x1b[0m");
                printf("                         |\n|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""sendo essa um intervalo de -%lld até %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);
                int auxt = (tam==8)?27:(tam==16)?23:13;
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);
                printf("Tente outro valor:");
            }
        }
        while(chek_caso_invalido(valor[i],tam));
        fflush(stdin);
    }

    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");


    int *ini,*sub;
    ini = dec_to_bin(valor[0],tam);
    sub = dec_to_bin(valor[1],tam);

    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printar_vetor_binario(ini,tam);
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printf("|\n|");

    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("-");
    printar_vetor_binario(sub,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<49-(tam/2); i++)printf(" ");
    for(int i=0; i<tam+2; i++)printf("-");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printar_vetor_binario(bin_sub(ini,sub,tam),tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    printf("+");
    for(int i=0; i<100; i++)printf("-");
    printf("+\n");

    for(int i=0; i<30; i++)printf(" ");
    printf("resultado decimal: %lld - %lld = %lld",bin_to_dec(ini,tam),bin_to_dec(sub,tam),bin_to_dec(bin_sub(ini,sub,tam),tam));
    free(ini);
    free(sub);
}


//Multiplicação é a mesma até a linha visual 4
void area_mult_op(int tam)
{
   printf("+");
    for(int i=0; i<43; i++)printf("-");
    printf("MULTIPLICAÇÃO");
    for(int i=0; i<44; i++)printf("-");
    printf("+\n");

    long long int valor[2];
    fflush(stdin);
    for(int i = 0; i<2; i++)
    {
        printf("|");
        for(int i=0; i<35; i++)printf(" ");
        printf("Valor %s em decimal: ",(i==0)?"Multiplicador":"Multiplicando");
        do
        {
            scanf("%lld",&valor[i]);
            if(chek_caso_invalido(valor[i],tam))
            {
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu numero estrapola a cacidade de bites""\x1b[0m");
                printf("                         |\n|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""sendo essa um intervalo de -%lld até %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);
                int auxt = (tam==8)?27:(tam==16)?23:13;
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);
                printf("Tente outro valor:");
            }
        }
        while(chek_caso_invalido(valor[i],tam));
        fflush(stdin);
    }

    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");


    //REDIRECIMENTO DE VALORES ENTRADO
    //Por multiplcação e divisão ser mais sensíveis eu susei os veriavel
    //para armazernar resultados e depois trabalhar com bits.
    int *M,*Q,*resultado;
    M = dec_to_bin(valor[0],tam);
    Q = dec_to_bin(valor[1],tam);
    resultado = bin_mult(M,Q,tam);



    //Printar tela
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n|");

    tam = 2*tam;//Duplico o tamanho pois tudo tem tamanho maior
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printar_vetor_binario(expa_bit(Q,tam/2,tam),tam);//Expanção de bits tanto aqui quanto no Outro valor
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printf("|\n|");

    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("X");
    printar_vetor_binario(expa_bit(M,tam/2,tam),tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<49-(tam/2); i++)printf(" ");
    for(int i=0; i<tam+2; i++)printf("-");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printar_vetor_binario(resultado,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    printf("+");
    for(int i=0; i<100; i++)printf("-");
    printf("+\n");

    for(int i=0; i<30; i++)printf(" ");
    printf("resultado decimal: %lld X %lld = %lld",bin_to_dec(M,tam/2),bin_to_dec(Q,tam/2),bin_to_dec(resultado,tam));

    free(resultado);
    free(Q);
    free(M);

}


void area_div_op(int tam)
{
    printf("+");
    for(int i=0; i<45; i++)printf("-");
    printf("DIVISÃO");
    for(int i=0; i<48; i++)printf("-");
    printf("+\n");

    long long int valor[2];
    fflush(stdin);
    for(int i = 0; i<2; i++)
    {
        printf("|");
        for(int i=0; i<35; i++)printf(" ");
        printf("Valor %s em decimal: ",(i==0)?"Divisor":"Dividendo");
        do
        {
            scanf("%lld",&valor[i]);
            if(chek_caso_invalido(valor[i],tam))
            {
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu numero estrapola a cacidade de bites""\x1b[0m");
                printf("                         |\n|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""sendo essa um intervalo de -%lld até %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);
                int auxt = (tam==8)?27:(tam==16)?23:13;
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);
                printf("Tente outro valor:");
            }
        }
        while(chek_caso_invalido(valor[i],tam));
        fflush(stdin);
    }

    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");

    //AREA DE OPERAR RESULTADOS
    int *bin_div(int *M,int *Mult,int tam);

    int *M,*Q,*resultado,quociente[tam],resto[tam];
    M = dec_to_bin(valor[0],tam);
    Q = dec_to_bin(valor[1],tam);
    resultado = bin_div(M,Q,tam);
    for(int i = 0; i < tam;i++) quociente[i] = resultado[i];
    for(int i = tam,j=0; i < 2*tam;i++,j++) resto[j] = resultado[i];

    //AREA DE PRINT
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<39-(tam/2); i++)printf(" ");
    printf("Dividendo: ");
    printar_vetor_binario(Q,tam);
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printf("|\n|");

    for(int i=0; i<41-(tam/2); i++)printf(" ");
    printf("Divisor: ");
    printar_vetor_binario(M,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<49-(tam/2); i++)printf(" ");
    for(int i=0; i<tam+2; i++)printf("-");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("|\n|");


    for(int i=0; i<39-(tam/2); i++)printf(" ");
    printf("quociente: ");
    printar_vetor_binario(quociente,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");
    for(int i=0; i<43-(tam/2); i++)printf(" ");
    printf("Resto: ");
    printar_vetor_binario(resto,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    printf("+");
    for(int i=0; i<100; i++)printf("-");
    printf("+\n");

    for(int i=0; i<25; i++)printf(" ");
    printf("resultado decimal: %lld / %lld = %lld resto %lld",bin_to_dec(Q,tam),bin_to_dec(M,tam),bin_to_dec(quociente,tam),bin_to_dec(resto,tam));

    free(Q);
    free(M);
    free(resultado);
}

void config(int *tam)
{
    int bit = 0;
    char op;
    while(1)
    {
        fflush(stdin);
        printf("+------CONFIG-----+\n| "
               "\x1b[33m""'m'""\x1b[0m""Mudar Tamanho|\n| "
               "\x1b[33m""'r'""\x1b[0m""returne      |\n"
               "+------------------+\n");
        printf("       Opção: ");
        scanf("%c",&op);

        switch(op)
        {
            case 'm':
            case 'M':
                printf("    Entre com quantos bits sua calculadora vai trabalhar durantes esse processo(8,16,32): ");
                do{
                    if(bit!=0&&bit!=8 && bit!=16 && bit!=32)printf("\x1b[31m" "Você entrou com um valor diferentes dos permitidos." "\x1b[0m""\nTente Novamente: ");
                    scanf("%i",&bit);
                }while(bit!=8 && bit!=16 && bit!=32);
                *tam = bit;
                break;
            case 'r':
            case 'R':
                return;
            default:
                printf("Não entrou com uma opção valida.\n");
        }
        fflush(stdin);
    }

}
#endif
