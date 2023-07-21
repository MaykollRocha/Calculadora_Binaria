/***
 * @author Maykoll Rocha & Rafael Jos� Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (in�cio) 2023-07-13
 * @date  (Ultima Atualiza��o) 2023-07-16
***/
#ifndef ambiente_de_interacao_h
#define ambiente_de_interacao_h
/**
    Faz a leitura do tamanho e vai de tr�s para frente
    pois como j� foi dito, o c�digo mensura a aplica��o de bits.
**/
void printar_vetor_binario(int *vet,int tam)
{
    for(int i = tam-1; i>=0; i--)
        printf("\x1b[32m""%i""\x1b[0m",vet[i]);
}

/**
    Inspira��o: site https://www.clubedohardware.com.br/forums/topic/729087-ajuda-com-a-fun��o-gotoxyxy/
    Usado para mexer o curso dentro do programa.
**/
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

/**
    Calcula o tamanho do inteiro em casas.
**/
int calc_tam(int calc)
{
        return (calc<0)?calc_tam(-1*calc)+1:(calc/10 >= 1 || calc==10)?calc_tam(calc/10)+1:1;
}

/**
    Toda a cria��o visual segue a mesma linha de raciocinio sendo o m�ximo de 100 caracteres.
    Ela � responsiva de acordo com o tamanho de bytes pedidos ao in�cio do c�digo.
    OBS:
        Explicarei em cada linha do print qual parte ser� mexida e as partes iguais sem explica��o seguem o mesmo racioc�nio da anteirior explicada.
    Tema importante!!!
    Nos coment�rios h� partes que chamo de linha ou linha visual, isso refere-se as linhas de 100 caracteres que aparece em seu programa.
**/

void area_soma_op(int tam)
{
    int m = 8;
    //Primeira linha cabe�alho que informa o tipo de opera��o.
    for(int i=0;i<m;i++)printf(" ");//Move 10 linhas para centralizar mais.
    printf("+");//Cria a base superior.
    for(int i=0; i<48; i++)printf("-");//Printa a primeira metade da linhas de visual.
    printf("SOMA");//Nome da opera��o a ser efetuada.
    for(int i=0; i<48; i++)printf("-");//Printa a seguda metade da linha.
    printf("+\n");//Fecha o cabe�alho.

    //Assume um vetor de 2 inteiros grandes pois, o int padr�o n�o l� o int de 31 bits.
    long long int valor[2];
    fflush(stdin);//limpar o buffer anterior.
    int l=0;
    //Um la�o para por os operandos no vetor 'long long'.
    for(int i = 0; i<2; i++)
    {
        //Linha 2 e 3, caso n�o entre com nenhum erro.
        for(int i=0;i<m;i++)printf(" ");
        printf("|",l);
        for(int i=0; i<35; i++)printf(" ");

        printf("Valor %i em decimal: ",i+1); /*Aviso de qual valor ser�
        adicionado que pode vir a ocorrer.*/
        do
        {
            //Um la�o para tratamento de entrada caso seja inserido um valor invi�vel.
            scanf("%lld",&valor[i]);
            gotoxy(56+calc_tam(valor[i])+m,1+i+l);
            for(int j=0; j<45-calc_tam(valor[i]); j++)printf(" ");
            printf("|\n");
            if(chek_caso_invalido(valor[i],tam))//Analisa caso seja um valor inv�lido.
            {
                //Cria um espa�o de 100char informando que n�o pode entrar com esse valor e faz 2 linhas a mais.
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu n�mero extrapola a capacidade de bytes""\x1b[0m");
                printf("                       |\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""Sendo essa um intervalo de -%lld at� %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);//Mostra os valores permitidos de acordo com o tamanho do bit.
                int auxt = (tam==4)?30:(tam==8)?26:(tam==16)?22:12;//Responsivo para que n�o fique feio. Pois, de acordo com o tamanho do bit ele gasta mais espa�o dentro do 100char.
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);//Limpeza de buffer.
                printf("Tente outro valor: ");//Pedido de novo valor.
                l+=3;
            }
        }
        while(chek_caso_invalido(valor[i],tam));
    }
    //Linha 4, apenas divis�o e informa que um resultado ser� inserido.
    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");

    //Arruma as vari�veis em vetores de inteiro com 0 e 1;
    int *vet1,*vet2;
    vet1 = dec_to_bin(valor[0],tam);
    vet2 = dec_to_bin(valor[1],tam);


    //linha 5, separa a divis�o em um pixel entre as bordas para dar mais destaque e centralizar melhor.
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    //Linha 6, expressa em bytes o vetor de inteiro e tenta centralizar o m�ximo para cada tipo de entrada.
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printar_vetor_binario(vet1,tam);
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printf("|\n");

    //Linha 7, coloca o sinal da conta '+ - * /' e depois expressa o byte que far� isso.
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("+");
    printar_vetor_binario(vet2,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n");

    //Linha 8, expressa uma cadeia de ' - ' para separar os operandos do resultado.
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    for(int i=0; i<tam+2; i++)printf("-");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("|\n");

    //linha 9, apresenta o resultado e tenta centraliza-lo.
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printar_vetor_binario(bin_sum(vet1,vet2,tam),tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n");

    //Linha 10, caso ocorra um overflow.
    if(bin_to_dec(bin_sum(vet1,vet2,tam),tam)!= (valor[0]+valor[1]))
    {
            if((valor[0]+valor[1])<0)
            {
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<45; i++)printf(" ");
                printf("\x1b[31m""UNDERFLOW""\x1b[0m");
                for(int i=0; i<46; i++)printf(" ");
            }else{
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<46; i++)printf(" ");
                printf("\x1b[31m""OVERFLOW""\x1b[0m");
                for(int i=0; i<46; i++)printf(" ");
            }
            printf("|\n");
    }

    //Linha 10, apresenta um pixel do fim e vira uma linha de 100char vazia.
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    //linha 11, fecha toda a cadeia de conta.
    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<100; i++)printf("-");
    printf("+\n");

    //Apresenta o resultado final em decimal para mostrar que est� correto.
    for(int i=0; i<35+m; i++)printf(" ");
    printf("Resultado Decimal: %lld + %lld = %lld",bin_to_dec(vet1,tam),bin_to_dec(vet2,tam),bin_to_dec(bin_sum(vet1,vet2,tam),tam));

    //Por ser ponteiros, limpa ponteiro.
    free(vet1);
    free(vet2);
}

/**
    As primeira parte visual at� a linha 4 � sempre a mesma para todas as opera��es, so muda o nome da opera��o e sua pixelagem continua igual.
    A subtra��o e a soma s�o id�nticas visualmente falando, logo, n�o expressei aqui, porem fiz um ctrl+c ctrl+v e mudei as dimens�es.
**/
void area_sub_op(int tam)
{
    int m = 8;

    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("SUBTRA��O");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");

    long long int valor[2];
    fflush(stdin);
    int l=0;
    for(int i = 0; i<2; i++)
    {
        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<35; i++)printf(" ");

        printf("Valor %s em Decimal: ",(i==0)?"inicial":"subtrator");
        do
        {
            int aux = (i==0)?62:64;
            scanf("%lld",&valor[i]);
            gotoxy(aux+calc_tam(valor[i])+m,1+i+l);
            aux = (i==0)?39:37;
            for(int j=0; j<aux-calc_tam(valor[i]); j++)printf(" ");
            printf("|\n");
            if(chek_caso_invalido(valor[i],tam))
            {
                 for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu n�mero extrapola a capacidade de bytes""\x1b[0m");
                printf("                       |\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""Sendo essa um intervalo de -%lld at� %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);
                int auxt = (tam==4)?30:(tam==8)?26:(tam==16)?22:12;
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);
                printf("Tente outro valor: ");
                l+=3;
            }
        }
        while(chek_caso_invalido(valor[i],tam));
        fflush(stdin);
    }

    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");

    //C�lculos
    int *ini,*sub;
    ini = dec_to_bin(valor[0],tam);
    sub = dec_to_bin(valor[1],tam);


    //Print
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printar_vetor_binario(ini,tam);
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printf("|\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("-");
    printar_vetor_binario(sub,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    for(int i=0; i<tam+2; i++)printf("-");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("|\n");



    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printar_vetor_binario(bin_sub(ini,sub,tam),tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n");


    if(bin_to_dec(bin_sub(ini,sub,tam),tam)!= (valor[0]-valor[1]))
       {

            if((valor[0]-valor[1])<0)
            {
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<45; i++)printf(" ");
                printf("\x1b[31m""UNDERFLOW""\x1b[0m");
                for(int i=0; i<46; i++)printf(" ");
            }else{
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<46; i++)printf(" ");
                printf("\x1b[31m""OVERFLOW""\x1b[0m");
                for(int i=0; i<46; i++)printf(" ");
            }
            printf("|\n");
       }


    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<100; i++)printf("-");
    printf("+\n");

    for(int i=0; i<35+m; i++)printf(" ");
    printf("resultado decimal: %lld - %lld = %lld",bin_to_dec(ini,tam),bin_to_dec(sub,tam),bin_to_dec(bin_sub(ini,sub,tam),tam));
    free(ini);
    free(sub);
}


//Multiplica��o � a mesma at� a linha visual 4.
void area_mult_op(int tam)
{
    int m = 8;

    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<43; i++)printf("-");
    printf("MULTIPLICA��O");
    for(int i=0; i<44; i++)printf("-");
    printf("+\n");

    long long int valor[2];
    fflush(stdin);
    int l=0;
    for(int i = 0; i<2; i++)
    {
        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<35; i++)printf(" ");
        printf("Valor %s em decimal: ",(i==1)?"Multiplicador":"Multiplicando");

        do{
            scanf("%lld",&valor[i]);
            gotoxy(68+calc_tam(valor[i])+m,1+i+l);
            for(int j=0; j<33-calc_tam(valor[i]); j++)printf(" ");
            printf("|\n");
            if(chek_caso_invalido(valor[i],tam))
            {
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu n�mero extrapola a capacidade de bytes""\x1b[0m");
                printf("                       |\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""Sendo essa um intervalo de -%lld at� %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);
                int auxt = (tam==4)?30:(tam==8)?26:(tam==16)?22:12;
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);
                printf("Tente outro valor: ");
                l+=3;
            }
        }
        while(chek_caso_invalido(valor[i],tam));
        fflush(stdin);
    }


    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");


    //REDIRECIONAMENTO DE VALORES INSERIDOS
    /*A multiplica��o e divis�o s�o sens�veis a altera��o de mem�ria
    por isso foi necess�rio utilizar vari�veis para armazernar os resultados e depois trabalhar com bytes.*/
    int *M,*Q,*resultado;
    M = dec_to_bin(valor[0],tam);
    Q = dec_to_bin(valor[1],tam);
    resultado = bin_mult(M,Q,tam);



    //Printar tela.
    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    tam = 2*tam;//Duplicar o tamanho pois tudo tem tamanho maior.
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printar_vetor_binario(expa_bit(Q,tam/2,tam),tam);//Expans�o de bits em ambos valores.
    for(int i=0; i<50- (tam/2); i++)printf(" ");
    printf("|\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("X");
    printar_vetor_binario(expa_bit(M,tam/2,tam),tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n");


    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    for(int i=0; i<tam+2; i++)printf("-");
    for(int i=0; i<49-(tam/2); i++)printf(" ");
    printf("|\n");


    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printar_vetor_binario(resultado,tam);
    for(int i=0; i<50-(tam/2); i++)printf(" ");
    printf("|\n");

    if(bin_to_dec(resultado,tam)!= (valor[0]*valor[1]))
    {
        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        if((valor[0]/valor[1])<0)
        {
            for(int i=0; i<45; i++)printf(" ");
            printf("\x1b[31m""UNDERFLOW""\x1b[0m");
            for(int i=0; i<46; i++)printf(" ");
        }else{
            for(int i=0; i<46; i++)printf(" ");
            printf("\x1b[31m""OVERFLOW""\x1b[0m");
            for(int i=0; i<46; i++)printf(" ");
        }
        printf("|\n");
    }

    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<100; i++)printf("-");
    printf("+\n");

    for(int i=0; i<35+m; i++)printf(" ");
    printf("Resultado Decimal: %lld X %lld = %lld",bin_to_dec(M,tam/2),bin_to_dec(Q,tam/2),bin_to_dec(resultado,tam));

    free(resultado);
    free(Q);
    free(M);

}


void area_div_op(int tam)
{
    int m = 8;

    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<45; i++)printf("-");
    printf("DIVIS�O");
    for(int i=0; i<48; i++)printf("-");
    printf("+\n");

    long long int valor[2];
    fflush(stdin);
    int l=0;
    for(int i = 0; i<2; i++)
    {
        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<35; i++)printf(" ");
        printf("Valor %s em Decimal: ",(i==0)?"Divisor":"Dividendo");
        do
        {
            int aux = (i==0)?62:64;
            scanf("%lld",&valor[i]);

            gotoxy(aux+calc_tam(valor[i])+m,1+i+l);
            aux = (i==0)?39:37;
            for(int j=0; j<aux-calc_tam(valor[i]); j++)printf(" ");
            printf("|\n");

            if(chek_caso_invalido(valor[i],tam))
            {
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m" "Seu n�mero extrapola a capacidade de bytes""\x1b[0m");
                printf("                       |\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                printf("\x1b[31m""Sendo essa um intervalo de -%lld at� %lld""\x1b[0m",tam_max(tam-1),tam_max(tam-1)-1);
                int auxt = (tam==4)?30:(tam==8)?26:(tam==16)?22:12;
                for(int i=0; i<auxt; i++)printf(" ");
                printf("|\n");
                for(int i=0;i<m;i++)printf(" ");
                printf("|");
                for(int i=0; i<35; i++)printf(" ");
                fflush(stdin);
                printf("Tente outro valor: ");
                l+=3;
            }
        }
        while(chek_caso_invalido(valor[i],tam));
        fflush(stdin);
    }

    for(int i=0;i<m;i++)printf(" ");
    printf("+");
    for(int i=0; i<46; i++)printf("-");
    printf("RESULTADO");
    for(int i=0; i<45; i++)printf("-");
    printf("+\n");

    for(int i=0;i<m;i++)printf(" ");
    printf("|");
    for(int i=0; i<100; i++)printf(" ");
    printf("|\n");

    if(valor[0]!=0)
    {
        //�REA DE OPERAR RESULTADOS
        int *bin_div(int *M,int *Mult,int tam);

        int *M,*Q,*resultado,quociente[tam],resto[tam];
        M = dec_to_bin(valor[0],tam);
        Q = dec_to_bin(valor[1],tam);
        resultado = bin_div(M,Q,tam);
        for(int i = 0; i < tam;i++) quociente[i] = resultado[i];
        for(int i = tam,j=0; i < 2*tam;i++,j++) resto[j] = resultado[i];

        //�REA DE PRINT
        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<39-(tam/2); i++)printf(" ");
        printf("Dividendo: ");
        printar_vetor_binario(Q,tam);
        for(int i=0; i<50- (tam/2); i++)printf(" ");
        printf("|\n");

        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<41-(tam/2); i++)printf(" ");
        printf("Divisor: ");
        printar_vetor_binario(M,tam);
        for(int i=0; i<50-(tam/2); i++)printf(" ");
        printf("|\n");

        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<49-(tam/2); i++)printf(" ");
        for(int i=0; i<tam+2; i++)printf("-");
        for(int i=0; i<49-(tam/2); i++)printf(" ");
        printf("|\n");

        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<39-(tam/2); i++)printf(" ");
        printf("Quociente: ");
        printar_vetor_binario(quociente,tam);
        for(int i=0; i<50-(tam/2); i++)printf(" ");
        printf("|\n");

        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<43-(tam/2); i++)printf(" ");
        printf("Resto: ");
        printar_vetor_binario(resto,tam);
        for(int i=0; i<50-(tam/2); i++)printf(" ");
        printf("|\n");

        if(bin_to_dec(quociente,tam)!= (int)(valor[1]/valor[0]) || bin_to_dec(resto,tam)!= (valor[1]%valor[0]))
        {
            for(int i=0;i<m;i++)printf(" ");
            printf("|");
            if((valor[1]/valor[0])<0)
            {

                for(int i=0; i<45; i++)printf(" ");
                printf("\x1b[31m""UNDERFLOW""\x1b[0m");
                for(int i=0; i<46; i++)printf(" ");
            }else{
                for(int i=0; i<46; i++)printf(" ");
                printf("\x1b[31m""OVERFLOW""\x1b[0m");
                for(int i=0; i<46; i++)printf(" ");
            }
            printf("|\n");
        }

        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<100; i++)printf(" ");
        printf("|\n");

        for(int i=0;i<m;i++)printf(" ");
        printf("+");
        for(int i=0; i<100; i++)printf("-");
        printf("+\n");

        for(int i=0; i<35+m; i++)printf(" ");
        printf("Resultado Decimal: %lld / %lld = %lld resto %lld",bin_to_dec(Q,tam),bin_to_dec(M,tam),bin_to_dec(quociente,tam),bin_to_dec(resto,tam));

        free(Q);
        free(M);
        free(resultado);
    }else{
        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<34; i++)printf(" ");
        printf("\x1b[31m""N�o � permitido divis�o por Zero""\x1b[0m");
        for(int i=0; i<34; i++)printf(" ");
        printf("|\n");
        for(int i=0;i<m;i++)printf(" ");
        printf("|");
        for(int i=0; i<100; i++)printf(" ");
        printf("|\n");

        for(int i=0;i<m;i++)printf(" ");
        printf("+");
        for(int i=0; i<100; i++)printf("-");
        printf("+\n");
    }

}

void config(int *tam)
{
    int bit = 0;
    char op;
    while(1)
    {
        int c=45;
        int l= 12;
        fflush(stdin);
        gotoxy(c,l);
        printf("+------CONFIG-----+\n");
        l++;
        gotoxy(c,l);
        printf("| ""\x1b[33m""'m'""\x1b[0m""Mudar Tamanho|\n");
        l++;
        gotoxy(c,l);
        printf("| ""\x1b[33m""'r'""\x1b[0m""returne      |\n");
        l++;
        gotoxy(c,l);
        printf("+-----------------+\n");
        l++;
        gotoxy(c,l);
        printf("       Op��o: ");
        scanf("%c",&op);
        switch(op)
        {
            case 'm':
            case 'M':
                l++;
                gotoxy(c-12,l);
                printf("    Entre com quantos bits sua calculadora\n");
                l++;
                gotoxy(c-12,l);
                printf("vai trabalhar durantes esse processo(8,16,32): ");
                do{
                    if(bit!=8 && bit!=16 && bit!=32 && bit!=4){
                        gotoxy(c+34,l);
                        for(int i=0;i<100;i++)printf(" ");
                    }
                    gotoxy(c+34,l);
                    scanf("%i",&bit);
                }while(bit!=8 && bit!=16 && bit!=32);
                *tam = bit;
                gotoxy(c-12,l);
                for(int i=0;i<100;i++)printf(" ");
                gotoxy(c-12,l-1);
                for(int i=0;i<100;i++)printf(" ");
                break;
            case 'r':
            case 'R':
                return;
            default:
                l++;
                gotoxy(c-12,l);
                printf("N�o entrou com uma op��o valida.\n");
        }
        fflush(stdin);
    }

}
#endif
