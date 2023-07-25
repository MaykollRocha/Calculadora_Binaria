/***
 * @author Maykoll Rocha & Rafael José Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (início) 2023-07-13
 * @date  (Ultima Atualização) 2023-07-16
***/
#ifndef calc_arq_prototipacao_h
#define calc_arq_prototipacao_h

//Funções de apoio de muita utilidade
int *expa_bit(int *vet,int tam,int ntam);//Expansão de Bytes
long long int bin_to_dec(int *vet,int tam);//Transforma binários em decimal
long long int tam_max(int tam);//Calcula o tamanho dos numeros quantas casas decimais
int chek_caso_invalido(long long int num,int tam);//Faz o checape de casos inválidos
int *copy_vet(int *vet,int tam);//Copia o vetor binário

//Funções de conversão básica
int *complement_of_2(int *vet,int tam);//Faz o complemento a dois dos bits
int *dec_to_bin(int num,int tam);//Transforma o decimal em um vetor de binário

//Operações
int *bin_sum(int *vet1,int *vet2,int tam);//Soma binária
int *bin_sub(int *vet1,int *vet2,int tam);//Subtração binária
int *bin_mult(int *M,int *Mult,int tam);//Multiplicação de binário
int *bin_div(int *M,int *Mult,int tam);//Divisão de binario

//Auxiliares das áreas de print
void printar_vetor_binario(int *vet,int tam);
void gotoxy(int x, int y);
int calc_tam(int calc);

//Ambientes para trabalhar com as operações
void area_soma_op(int tam);
void area_sub_op(int tam);
void area_mult_op(int tam);
void area_div_op(int tam);
void config(int *tam);

//Funções de print específica para mostrar como foi feita as conta questão de deslocamento
void print_mult(int *Q,int *A,int *M,int Qf,int tam,char op[]);
void print_div(int *Q,int *A,int *M,int tam,char op[]);
#endif
