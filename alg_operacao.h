/***
 * @author Maykoll Rocha & Rafael Jos� Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (in�cio) 2023-07-13
 * @date  (Ultima Atualiza��o) 2023-08-06
***/
#ifndef alg_operacao_h
#define alg_operacao_h

/**
    SOMA:
        De acordo com o livro e um carry.
    Retorno:
        O vetor de bin�rio da soma de dois bin�rio.
**/
int *bin_sum(int *vet1,int *vet2,int tam)
{
    //Cria o arquivo de solu��o com o tamanho base;
    int *solc = malloc(tam*sizeof(int));
    int carry = 0;//Um carry que come�a com Zero, pois n�o tem nada para carregar.
    //Faz a conta bit a bit
    for(int i=0;i<tam;i++)
    {
        solc[i] = vet1[i]+vet2[i]+carry;//Soma os dois valores + o carry, que pode ser mais que 0 em algum momento.
        carry = 0;
        if(solc[i]>=2)//Quando o valor da 2 ou 3 que s�o os poss�veis, eles tiram -2 porque se for 3 continua 1 e o carry soma 1.
        {
            solc[i] -= 2;
            carry = 1;
        }
    }
    //Retorna a solu��o
    return solc;
}

/**
    SUBTRA��O:
        Complemento a dois e depois soma, pois � exatamente como a m�quina faz.
        (imagens provavelemente)
    Retorno:
        A soma do primeiro bin�rio com o complemento a dois do segundo bin�rio.
**/
int *bin_sub(int *vet1,int *vet2,int tam)
{
    int *aux = complement_of_2(vet2,tam);//Faz um complemento a dois que � uma copia dele.
    return bin_sum(vet1,aux,tam);//E retonar a soma.
}


void print_mult(int *Q,int *A,int *M,int Qf,int tam,char op[])
{
    for(int i = 0;i<8;i++)printf(" ");
    printf("|");
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    for(int i = tam-1; i>=0; i--)printf("%i",A[i]);
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    printf("|");
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    for(int i = tam-1; i>=0; i--)printf("%i",Q[i]);
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    printf("|%i|",Qf);
    if(op==" ")
    {
        for(int i = 0;i<16-(tam/2);i++)printf(" ");
        for(int i = tam-1; i>=0; i--)printf("%i",M[i]);
        for(int i = 0;i<16-(tam/2);i++)printf(" ");
    }else{
        int t = strlen(op);
        int p2 = (t%2)?15:16;
        for(int i = 0;i<16-(t/2);i++)printf(" ");
        for(int i = 0; i<t; i++)printf("%c",op[i]);
        for(int i = 0;i<p2-(t/2);i++)printf(" ");

    }
    printf("|\n");
    return;
}
/**
    Multiplica��o seguindo a ideia do algoritmo de booth onde voc�
    faz um deslocamento da esquerda para a direta e tem um byte q-1 que �
    auxliar e usa para fazer tomadas de decis�o no meio do vetor e tamb�m
    temos que considerar que ele vai dobrar de tamanho.

    Retorna um vetor com o dobro do tamanho com A.Q = Resultado.
**/
int *bin_mult(int *M,int *Mult,int tam)
{
    //Cria as vari�veis de uso que � o A de aux�lio.
    // Qf= q-1 da imagem proveniente do algoritmo de booth.
    int *A,Qf=0;
    int *Q = copy_vet(Mult,tam);//Faz uma c�pia de seguran�a do multiplicando
    int cont = tam;//Conta o tamanho.

    //Vetor de 0 para iniciar a auxiliar com o tamanho de bytes necess�rios
    A = malloc(tam*sizeof(int));
    for(int i=0;i<tam;i++) A[i] = 0;

    //Aver� um print por etapa sendo essas organizadas com os valores nessa ordem
    for(int i = 0;i<8;i++)printf(" ");
    printf("|");
    for(int i = 0;i<15;i++)printf(" ");
    printf("A");
    for(int i = 0;i<16;i++)printf(" ");
    printf("|");
    for(int i = 0;i<15;i++)printf(" ");
    printf("Q");
    for(int i = 0;i<16;i++)printf(" ");
    printf("|Qf|",Qf);
    for(int i = 0;i<14;i++)printf(" ");
    printf("M");
    for(int i = 0;i<16;i++)printf(" ");
    printf("|\n");

    for(int i = 0;i<8;i++)printf(" ");
    printf("+");
    for(int i = 0;i<100;i++)(i==32||i==65||i==67)?printf("+"):printf("-");
    printf("+\n");


    print_mult(Q,A,M,Qf,tam," ");

    for(int i = 0;i<8;i++)printf(" ");
    printf("+");
    for(int i = 0;i<100;i++)(i==32||i==65||i==67)?printf("+"):printf("-");
    printf("+\n");

    for(int i=0;i<cont;i++)
    {
        /*Faz a verifica��o Q0 com Q-1 e
        varia de acordo como eles est�o opostos.*/
        if(Q[0] == 1 && Qf == 0)
        {
            A = bin_sub(A,M,tam);
            print_mult(Q,A,M,Qf,tam,"Soma A <- A + M");
        }

        if(Q[0] == 0 && Qf == 1)
        {
            A = bin_sum(A,M,tam);
            print_mult(Q,A,M,Qf,tam,"Subtrai A <- A - M");
        }
        /*Independente se s�o iguais ou n�o, ainda sim eles se
        deslocam.*/
        //Deslocamento.
        Qf = Q[0];
        for(int i = 0;i < tam-1;i++)
        {
            Q[i] = Q[i+1];
        }
        Q[tam-1] = A[0];

        for(int i = 0;i < tam-1;i++)
        {
            A[i] = A[i+1];
        }
        print_mult(Q,A,M,Qf,tam,"Deslocamento para direita");

        //Mostra que foi o fim do ciclo X das N etapas.
        for(int i = 0;i<8;i++)printf(" ");
        printf("+");
        for(int i = 0;i<45;i++)(i==32)?printf("+"):printf("-");
        printf("EXECU��O %i",i+1);
        if(i<9){
            for(int i = 0;i<45;i++)(i==10 || i==12)?printf("+"):printf("-");
        }else{
            for(int i = 0;i<44;i++)(i==9 || i==11)?printf("+"):printf("-");
        }
        printf("+\n");
    }

    /*Armazena o resultado numa vari�vel com o dobro de tamanho
    onde come�a armazenando o Q e depois armazena o A. Qf � esquecida.*/
    int *result = malloc(2*tam*sizeof(int));
    for(int i=0;i<tam;i++)
        result[i] = Q[i];

    for(int i = tam,j=0; i<2*tam;i++,j++)
        result[i] = A[j];

    return result;
}



void print_div(int *Q,int *A,int *M,int tam,char op[])
{
    for(int i = 0;i<8;i++)printf(" ");
    printf("|");
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    for(int i = tam-1; i>=0; i--)printf("%i",A[i]);
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    printf("|");
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    for(int i = tam-1; i>=0; i--)printf("%i",Q[i]);
    for(int i = 0;i<16-(tam/2);i++)printf(" ");
    printf(" | ");
    if(op==" ")
    {
        for(int i = 0;i<16-(tam/2);i++)printf(" ");
        for(int i = tam-1; i>=0; i--)printf("%i",M[i]);
        for(int i = 0;i<16-(tam/2);i++)printf(" ");
    }else{
        int t = strlen(op);
        int p2 = (t%2)?15:16;
        for(int i = 0;i<16-(t/2);i++)printf(" ");
        for(int i = 0; i<t; i++)printf("%c",op[i]);
        for(int i = 0;i<p2-(t/2);i++)printf(" ");

    }

    printf("|\n");
}
/**
    DIVIS�O com deslocamento soma e subta��o;
    Seguindo o slide, aplicando o algoritmos da imagem.

    Retono: o vetor de A*Q onde A � o resto e Q o valor;
**/
int *bin_div(int *M,int *mult,int tam)
{

    int *A;//O A � uma vari�vel auxiliar que segura o resto da divis�o no final.
    int *Q=copy_vet(mult,tam);//Faz uma copia do Dividendo para n�o alterar o dividendo original.
    int cont = tam;//N�mero de vezes que vai ser execultado o c�digo.

    A = malloc(tam*sizeof(int));//Cria e faz uma cadeia de 0.
    for(int i=0;i<tam;i++) A[i] = 0;

     for(int i = 0;i<8;i++)printf(" ");
    printf("|");
    for(int i = 0;i<15;i++)printf(" ");
    printf("A");
    for(int i = 0;i<16;i++)printf(" ");
    printf("|");
    for(int i = 0;i<15;i++)printf(" ");
    printf("Q");
    for(int i = 0;i<16;i++)printf(" ");
    printf(" | ");
    for(int i = 0;i<15;i++)printf(" ");
    printf("M");
    for(int i = 0;i<16;i++)printf(" ");
    printf("|\n");
    for(int i = 0;i<8;i++)printf(" ");
    printf("+");
    for(int i = 0;i<100;i++){
            if(i==32 || i==66){
                printf("+");
            }else{
                printf("-");
            }
    }
    printf("+\n");

    print_div(Q,A,M,tam," ");//� para mostrar o passo a passo. A fim de interesse abra e veja.

    for(int i = 0;i<8;i++)printf(" ");
    printf("+");
    for(int i = 0;i<100;i++){
            if(i==32 || i==66){
                printf("+");
            }else{
                printf("-");
            }
    }
    printf("+\n");

    //Ciclo de execu��o.
    for(int i=0;i<cont;i++)
    {

        //Deslocamento de bit da direita para esquerda.
        for(int i = tam-1; i>0 ;i--)
            A[i] = A[i-1];
        A[0] = Q[tam-1];


        for(int i = tam-1; i>0 ;i--)
            Q[i] = Q[i-1];
        Q[0] = 0;
        print_div(Q,A,M,tam,"Desloca para esquerda");

        //Subtra��o
        A = bin_sub(A,M,tam);
        print_div(Q,A,M,tam,"Subtrai A <- A - M");

        //Esolha caso seja positivo ou negativo
        if(A[tam-1]==1)
        {
            Q[0] = 0;
            print_div(Q,A,M,tam,"Resteura Q0 = 1");
            A = bin_sum(A,M,tam);
            print_div(Q,A,M,tam,"Soma A <- A + M");
        }else{
            Q[0] = 1;
            print_div(Q,A,M,tam,"Restaura Q0 = 0");

        }
        for(int i = 0;i<8;i++)printf(" ");
        printf("+");
        for(int i = 0;i<45;i++)(i==32)?printf("+"):printf("-");
        printf("EXECU��O %i",i+1);
        if(i<9){
            for(int i = 0;i<45;i++)(i==11)?printf("+"):printf("-");
        }else{
            for(int i = 0;i<44;i++)(i==10)?printf("+"):printf("-");
        }
        printf("+\n");
    }

    /*Armazena o resultado.
    Os 'tam' primeiros bit da esquerda para direta � o quociente.*/
    int *result = malloc(2*tam*sizeof(int));
    for(int i=0;i<tam;i++)
        result[i] = Q[i];

    //Os tam bits at� 2*tam da esquerda para direta � o resto.
    for(int i = tam,j=0; i<2*tam;i++,j++)
        result[i] = A[j];

    //Retorna o resultado
    return result;
}
#endif
