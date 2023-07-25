/***
 * @author Maykoll Rocha & Rafael Jos� Leandro da Silva
 * @email <maykoll.rocha422@academico.ufgd.edu.br>
 * @email <rafael.silva488@academico.ufgd.edu.br>
 * @date  (in�cio) 2023-07-13
 * @date  (Ultima Atualiza��o) 2023-07-16
***/
#ifndef calc_arq_prototipacao_h
#define calc_arq_prototipacao_h

//Fun��es de apoio de muita utilidade
int *expa_bit(int *vet,int tam,int ntam);//Expans�o de Bytes
long long int bin_to_dec(int *vet,int tam);//Transforma bin�rios em decimal
long long int tam_max(int tam);//Calcula o tamanho dos numeros quantas casas decimais
int chek_caso_invalido(long long int num,int tam);//Faz o checape de casos inv�lidos
int *copy_vet(int *vet,int tam);//Copia o vetor bin�rio

//Fun��es de convers�o b�sica
int *complement_of_2(int *vet,int tam);//Faz o complemento a dois dos bits
int *dec_to_bin(int num,int tam);//Transforma o decimal em um vetor de bin�rio

//Opera��es
int *bin_sum(int *vet1,int *vet2,int tam);//Soma bin�ria
int *bin_sub(int *vet1,int *vet2,int tam);//Subtra��o bin�ria
int *bin_mult(int *M,int *Mult,int tam);//Multiplica��o de bin�rio
int *bin_div(int *M,int *Mult,int tam);//Divis�o de binario

//Auxiliares das �reas de print
void printar_vetor_binario(int *vet,int tam);
void gotoxy(int x, int y);
int calc_tam(int calc);

//Ambientes para trabalhar com as opera��es
void area_soma_op(int tam);
void area_sub_op(int tam);
void area_mult_op(int tam);
void area_div_op(int tam);
void config(int *tam);

//Fun��es de print espec�fica para mostrar como foi feita as conta quest�o de deslocamento
void print_mult(int *Q,int *A,int *M,int Qf,int tam,char op[]);
void print_div(int *Q,int *A,int *M,int tam,char op[]);
#endif
