/***
 * @author Maykoll Rocha & Rafael José Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (início) 2023-07-13
 * @date  (Ultima Atualização) 2023-07-14
***/
#ifndef calc_arq_prototipacao_h
#define calc_arq_prototipacao_h

//Funções de apoio de de muita utilidade.
int *expa_bit(int *vet,int tam,int ntam);
long long int bin_to_dec(int *vet,int tam);
int chek_caso_invalido(long long int num,int tam);
int *copy_vet(int *vet,int tam);

//Funções de conversão básica
int *complement_of_2(int *vet,int tam);
int *dec_to_bin(int num,int tam);

// Operações
int *bin_sum(int *vet1,int *vet2,int tam);
int *bin_sub(int *vet1,int *vet2,int tam);
int *bin_mult(int *M,int *Mult,int tam);
int *bin_div(int *M,int *Mult,int tam);


//ambientes para trabalhar com as operações
void printar_vetor_binario(int *vet,int tam);
void area_soma_op(int tam);
void area_sub_op(int tam);
void area_mult_op(int tam);
void area_div_op(int tam);
void config(int *tam);

//funções de print específica para mostrar como foi feita as conta questão de deslocamento.
void print_pross(int *Q,int *A,int *M,int Qf,int tam);
#endif
