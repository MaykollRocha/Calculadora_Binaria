/***
 * @author Maykoll Rocha & Rafael José Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (início) 2023-07-13
 * @date  (Ultima Atualização) 2023-07-16
***/
#ifndef base_algs_h
#define base_algs_h

/***
    OBSERVAÇÕES DE PRÉ-CÓDIGO
        Uma representação binária vai de 0100 que é 2 só que
    a leitura do dois para 4 bits é 0010, porém meu programa leva em conta
    que o indice é o valor a ser elevado.
    exemplo:
        Um vetor de [0,1,0,0] = vet[0]*1+vet[1]*2¹+vet[0]*2²+...+vet[n-1]*2^(n-1)
        assim fica mais fácil realizar as operações.
***/

/**
    O pow da math.c tem um valor máximo muito baixo para 32 bits
    e acaba gerando erros no meu código, por conta disso fiz uma recursão
    para alcançar o valor de desejo para 32bits.
**/

long long int tam_max(int tam)
{
    if(tam==0)
        return 1;
    return 2*tam_max(tam-1);
}

/***
    Faz a expansão de bits caso necessário durante o código.
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
    Faz uma cópia do vetor, assim, ele consegue manter as informações mais seguras
    em algumas funções.
***/
int *copy_vet(int *vet,int tam)
{
    int *newvet = malloc(tam*sizeof(int));

    for(int i = 0; i<tam; i++)
        newvet[i] = vet[i];

    return newvet;
}

/***
    Será utilizado para verificar se a soma ou a subtração ultrapassou
    o limite de bytes necessários. Retorna a soma.
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
    Checa os casos inválidos onde o valor se econtra muito grande ou muito pequeno.
    Usa-se a função recursiva que calcula o máximo.
**/
int chek_caso_invalido(long long int num,int tam)
{
    return (num < -(tam_max(tam-1)) || num > tam_max(tam-1)-1);
}

/**
    Faz o complemento a dois de um binario que é inverter os bits e depois somar 1.
**/
int *complement_of_2(int *vet,int tam)
{
    int *compl = copy_vet(vet,tam);//Copia de segurança
    for(int i=0; i<tam; i++) compl[i] = !(compl[i]);//Entrega o vetor todo negativado

    //Cria o vetor binário de valor 1
    int *bin1sum = dec_to_bin(1,tam);

    return bin_sum(compl,bin1sum,tam);
}

/***
        Essa parte faz a conversão decimal para um vetor
    binário de um vetor específico. Seus retornos podem
    ser o vetor ou 0. O decimal não pode
    ser expresso com aquele tamanho do vetor predito.

***/
int *dec_to_bin(int num,int tam)
{
    int *bin;//Vetor auxilar para fazer a carregamento e depois a exportação de bits.
    bin = malloc(tam*sizeof(int));//Aloca dinamicamente um vetor de valor inteiro.

    int aux_comp = 0;//Auxiliar para saber se é negativo.
    //Checa se o número é negativo com o bit de sinal que esta na ultima casa.
    if(num<0)
    {
        aux_comp = 1;
        num *=-1;
    }

    //Realiza o update no número.
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
