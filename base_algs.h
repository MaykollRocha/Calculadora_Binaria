/***
 * @author Maykoll Rocha & Rafael Jos� Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (in�cio) 2023-07-13
 * @date  (Ultima Atualiza��o) 2023-07-14
***/
#ifndef base_algs_h
#define base_algs_h

/***
    OBSERVA��ES DE PR� C�DIGO
        uma representa��o bin�ria vai de 0100 que � 2 so que
    a leitura do dois para 4 bits � 0010 so que meu programa leva em conta
    que o indice � o valor a ser elevado.
    exemplo:
        Um vetor de [0,1,0,0] = vet[0]*1+vet[1]*2�+vet[0]*2�+...+vet[n-1]*2^(n-1)
        assim fica mais facil fazer as opera��es.
***/

/**
    O pow da math.c tem um valor maximo muito baixo para 32 bits
    e acaba gerando erros no meu c�digo por conta disso fiz uma recurs�o
    para alcan�ar o valor de desejo para 32bits.
**/
long long int tam_max(int tam)
{
    if(tam==0)
        return 1;
    return 2*tam_max(tam-1);
}

/***
    Faz a expanss�o de bits caso nescessario durante o codigo.
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
    Faz uma copia do vetor assim ele consegue mater mais seguro as informa��es
    em algumas
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
    o limite de bits nescessario.retorna a soma.
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
    Checa os casos invalidos onde o valor se econtra muito grande ou muito pequeno;
    Usase a fun��o recursiva que calcula o maximo.
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
        Essa parte faz a convers�o de decimal para um vetor
    binario de um vetor expecifico seus retornos podem
    ser o vetor ou 0 representando o decimal n�o pode
    ser expresso com aquele tanho do vetor predito

***/
int *dec_to_bin(int num,int tam)
{
    int *bin;//Vetor auxilar para fazer a carregamento e depois a exporta��o de bit's..
    bin = malloc(tam*sizeof(int));//Aloca dinamicamento um vetor de valor inteiro.

    int aux_comp = 0;//auxiliar para saver se � negativo
    //Checa se o n�mero � negativo com o bit de sinal que esta na ultima casa.
    if(num<0)
    {
        aux_comp = 1;
        num *=-1;
    }

    //faz o upadate no numero
    for(int i =0; i<tam; i++)
    {
        bin[i] = num%2;
        num = num/2;
    }
    //retorna em complemento a 2.
    if(aux_comp) return complement_of_2(bin,tam);

    return bin;
}

/**
    Essa fun��o n�o tem uso para quem ta querendo se divertir com os bin�rios
    � mais para quem quer ver funcinando a ideia de como foi feita a documenta��o
    e se segue o ensinado pelo livro na parte da divis�o e multiplica��o.
**/

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
