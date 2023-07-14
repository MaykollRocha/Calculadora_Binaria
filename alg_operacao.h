/***
 * @author Maykoll Rocha & Rafael José Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (início) 2023-07-13
 * @date  (Ultima Atualização) 2023-07-14
***/
#ifndef alg_operacao_h
#define alg_operacao_h

/**
    SOMA:
        De acordo com o livro e um carry.
**/
int *bin_sum(int *vet1,int *vet2,int tam)
{
    //Cria o arquivo de solução com o tamanho base;
    int *solc = malloc(tam*sizeof(int));
    int carry = 0;//Um carry que começa com Zero, pois não tem nada para carregar.
    //Ele faz a conta bit a bit
    for(int i=0;i<tam;i++)
    {
        solc[i] = vet1[i]+vet2[i]+carry;//Soma os dois valores + o carry que pode ser mais que 0 em algum momento
        carry = 0;
        if(solc[i]>=2)//Quando o valor da 2 ou 3 que são os possíveis, eles tira -2 pq se for 3 contina 1 la e o carry soma 1
        {
            solc[i] -= 2;
            carry = 1;
        }
    }
    //Retorna a solução
    return solc;
}

/**
    SUBTRAÇÃO
    Complemneto a dois e depois soma, pois é exatamento como a maquina faz.
    (imagens provavelemente)
**/
int *bin_sub(int *vet1,int *vet2,int tam)
{
    int *aux = complement_of_2(vet2,tam);//Faz um complemento a dois que é uma copia dele
    return bin_sum(vet1,aux,tam);//E retonar a soma.
}

/**
    Multiplicação seguindo a ideia do algoritmo de booth onde você
    faz um delocamento da esquerda para a direta e tem um bite q-1 que é
    auxliar e usa para fazer tomadas de decissão no meio do vetor e tbem
    temos que considerar que ele vai dobrar de tamanho.

    Retorna um vetor com o dobro do tamanho com A.Q = Resultado.
**/
int *bin_mult(int *M,int *Mult,int tam)
{
    //Cria as variais de uso que é o A de auxilo
    // Qf= q-1 da imgagem proveniente do algoritmo de booth.
    int *A,Qf=0;
    int *Q = copy_vet(Mult,tam);//Faz uma copia de segurnção do multiplicando
    int cont = tam;//oconta o tamanho

    //Vetor de 0 para iniciar a auxiliar com o tamanho de bits nescessario
    A = malloc(tam*sizeof(int));
    for(int i=0;i<tam;i++) A[i] = 0;

    //print_pross(Q,A,M,Qf,tam);

    for(int i=cont;i!=0;i--)
    {
        //Faz a verificação Q0 com Q-1 e
        //varia de acondo como eles estão oposto
        if(Q[0] == 1 && Qf == 0)
        {
            A = bin_sub(A,M,tam);
        }

        if(Q[0] == 0 && Qf == 1)
        {
            A = bin_sum(A,M,tam);
        }
        //  Se eles são iguais ou não ainda sim eles
        //desloca então so desloca e é isso.
        //Deslocamento
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
        //print_pross(Q,A,M,Qf,tam);
    }

    //Armazena o reaultado numa variavele com o dobro de tamnho
    //onde comaça armazenando o Q e depois armazena o A.Qf é esquecida.
    int *result = malloc(2*tam*sizeof(int));
    for(int i=0;i<tam;i++)
        result[i] = Q[i];

    for(int i = tam,j=0; i<2*tam;i++,j++)
        result[i] = A[j];

    return result;
}


/**
    DIVISÃO com delocamento soma e subtação;
    Seguindo o slide aplicando o algoritmos da imagem.
**/
int *bin_div(int *M,int *mult,int tam)
{

    int *A;//O A é uma variavel auxiliar que segura o resto da divisão no final.
    int *Q=copy_vet(mult,tam);//Uma copia do Dividendo para não alterar o dividendo original
    int cont = tam;//Número de vezes que vai ser execultadas

    A = malloc(tam*sizeof(int));//Cria e faz uma cadeia de 0
    for(int i=0;i<tam;i++) A[i] = 0;


    //print_pross(Q,A,M,0,tam); é para mostra o passo a passo fins de interrse abre e veja

    //Ciclo de execução
    for(int i=0;i<cont;i++)
    {

        //Deslocamento de bit de direita para esquerda
        for(int i = tam-1; i>0 ;i--)
            A[i] = A[i-1];
        A[0] = Q[tam-1];
        for(int i = tam-1; i>0 ;i--)
            Q[i] = Q[i-1];
        //Subtração
        A = bin_sub(A,M,tam);

        //Esolha caso seja npositivo ou negativo
        if(A[tam-1]==1)
        {
            Q[0] = 0;
            A = bin_sum(A,M,tam);
        }else{
            Q[0] = 1;
        }
       // print_pross(Q,A,M,0,tam); para fins de observação
    }

    //Armazenar o resultado
    //Os tam primeios bit da esquerda para direta é o quociente
    int *result = malloc(2*tam*sizeof(int));
    for(int i=0;i<tam;i++)
        result[i] = Q[i];

    //Os tam bit's até 2*tam da esquerda para direta é o resto.
    for(int i = tam,j=0; i<2*tam;i++,j++)
        result[i] = A[j];

    //Retorna o resultado
    return result;
}
#endif

