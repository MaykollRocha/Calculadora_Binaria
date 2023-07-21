/***
 * @author Maykoll Rocha & Rafael Jos� Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (in�cio) 2023-07-13
 * @date  (Ultima Atualiza��o) 2023-07-16
***/
#ifndef base_algs_h
#define base_algs_h

/***
    OBSERVA��ES DE PR�-C�DIGO
        Uma representa��o bin�ria vai de 0100 que � 2 s� que
    a leitura do dois para 4 bits � 0010, por�m meu programa leva em conta
    que o indice � o valor a ser elevado.
    exemplo:
        Um vetor de [0,1,0,0] = vet[0]*1+vet[1]*2�+vet[0]*2�+...+vet[n-1]*2^(n-1)
        assim fica mais f�cil realizar as opera��es.
***/

/**
    O pow da math.c tem um valor m�ximo muito baixo para 32 bits
    e acaba gerando erros no meu c�digo, por conta disso fiz uma recurs�o
    para alcan�ar o valor de desejo para 32bits.
**/

long long int tam_max(int tam)
{
    if(tam==0)
        return 1;
    return 2*tam_max(tam-1);
}

/***
    Faz a expans�o de bits caso necess�rio durante o c�digo.
***/
int *expa_bit(int *vet,int tam,int ntam)
{
    int *copia = copy_vet(vet,tam);
    copia=realloc(copia,ntam*sizeof(int));
    for(int i = tam; i<ntam; i++)
        copia[i] = copia[tam-1];
    return copia;
}

/***
    Faz uma c�pia do vetor, assim, ele consegue manter as informa��es mais seguras
    em algumas fun��es.
***/
int *copy_vet(int *vet,int tam)
{
    int *newvet = malloc(tam*sizeof(int));

    for(int i = 0; i<tam; i++)
        newvet[i] = vet[i];

    return newvet;
}

/***
    Ser� utilizado para verificar se a soma ou a subtra��o ultrapassou
    o limite de bytes necess�rios. Retorna a soma.
***/
long long int bin_to_dec(int *vet,int tam)
{
    int sum = 0;
    if(vet[tam-1]==1)
    {
        int *copia = complement_of_2(vet,tam);
        for(int i =0; i<tam; i++)
            if(copia[i])sum += pow(2,i);
        free(copia);
        return -1*sum;
    }
    for(int i =0; i<tam; i++)
        if(vet[i])
            sum += pow(2,i);

    return sum;
}

/**
    Checa os casos inv�lidos onde o valor se econtra muito grande ou muito pequeno.
    Usa-se a fun��o recursiva que calcula o m�ximo.
**/
int chek_caso_invalido(long long int num,int tam)
{
    return (num < -(tam_max(tam-1)) || num > tam_max(tam-1)-1);
}

/**
    Faz o complemento a dois de um binario que � inverter os bits e depois somar 1.
**/
int *complement_of_2(int *vet,int tam)
{
    int *compl = copy_vet(vet,tam);//Copia de seguran�a
    for(int i=0; i<tam; i++) compl[i] = !(compl[i]);//Entrega o vetor todo negativado

    //Cria o vetor bin�rio de valor 1
    int *bin1sum = dec_to_bin(1,tam);

    return bin_sum(compl,bin1sum,tam);
}

/***
        Essa parte faz a convers�o decimal para um vetor
    bin�rio de um vetor espec�fico. Seus retornos podem
    ser o vetor ou 0. O decimal n�o pode
    ser expresso com aquele tamanho do vetor predito.

***/
int *dec_to_bin(int num,int tam)
{
    int *bin;//Vetor auxilar para fazer a carregamento e depois a exporta��o de bits.
    bin = malloc(tam*sizeof(int));//Aloca dinamicamente um vetor de valor inteiro.

    int aux_comp = 0;//Auxiliar para saber se � negativo.
    //Checa se o n�mero � negativo com o bit de sinal que esta na ultima casa.
    if(num<0)
    {
        aux_comp = 1;
        num *=-1;
    }

    //Realiza o update no n�mero.
    for(int i =0; i<tam; i++)
    {
        bin[i] = num%2;
        num = num/2;
    }
    //Retorna em complemento a 2.
    if(aux_comp) return complement_of_2(bin,tam);

    return bin;
}

void print_pross(int *Q,int *A,int *M,int Qf,int tam)
{
    for(int i = tam-1; i>=0; i--)printf("%i",A[i]);
    printf(" ");
    for(int i = tam-1; i>=0; i--)printf("%i",Q[i]);
    printf(" %i ",Qf);
    for(int i = tam-1; i>=0; i--)printf("%i",M[i]);
    printf("\n");
    return;
}
#endif
