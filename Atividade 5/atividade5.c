/*----------------------------------------------------------------------
 *          UNIFAL - Universidade Federal de Alfenas.
 *            BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO.
 * Trabalho..: Atividade 5
 * Disciplina: Programação
 * Professor.: Luiz Eduardo da Silva
 * Aluno:....: Daniel da Costa Lima
 * Data......: 03/09/2021
----------------------------------------------------------------------*/

#include <stdio.h>

/* Converte string para literal */
void lit_int (char v1[10]){
    int i;
    for (i = 0; i < 9; i++){    
        v1[i] = v1[i] - 48;
    }
}

/* Realiza as somas parciais */
void parciais (char v1[10], int soma[2][9]){
    int i;
    soma[0][0] = v1[0];         //Definindo o primeiro valor das parciais
    soma[1][0] = v1[0];

    for (i = 1; i < 9; i++){        //Repetição para preencher a matriz soma com as parciais
        soma[0][i] = soma[0][i - 1] + v1[i];        
        soma[1][i] = soma[1][i - 1] + soma[0][i];
    }
}

/* Conta os zeros de uma string */
int zeros_string (char v1[10]){
    int qtde = 0, i;
    for (i = 0; i < 10; i++){
        if (v1[i] == 48){       
            qtde++;
        }
    }   
    return qtde;
}

/* Retorna o dígito verificador */
int isbn_dv (int soma[2][9], int mult[5][9]){
    int lin, ok = 0, dig, i, j;
    if (soma[1][8] < 100){      //Condição que orienta qual linha da matriz de multiplos de 11 começar a buscar
        lin = 0;
    } else if (soma[1][8] > 100 && soma[1][8] < 200){
        lin = 1;
    } else if (soma[1][8] > 200 && soma[1][8] < 300){
        lin = 2;
    } else if (soma[1][8] > 300 && soma[1][8] < 400){
        lin = 3;
    } else {
        lin = 4;
    }

    do {
        for (i = lin; i < 5 && ok != 1; i++){       //Repetição para percorrer a matriz de múltiplos de 11
            for (j = 0; j < 9 && ok != 1; j++){
                if (mult[i][j] - soma[1][8] > soma[0][8]){      //Condição para verificar o menor dígito para o ISBN
                    dig = mult[i][j] - (soma[0][8] + soma[1][8]);
                    ok = 1;
                } 
            }  
        }        
    } while (ok != 1);

    return dig;
}

int main(void)
{
    char v1[10];        //String que guarda a entrada
    int mult[5][9] = {{11, 22, 33, 44, 55, 66, 77, 88, 99}, {110, 121, 132, 143, 154, 165, 176, 187, 198}, {209, 220, 231, 242, 253, 264, 275, 286, 
297}, {308, 319, 330, 341, 352, 363, 374, 385, 396}, {407, 418, 429, 440, 451, 462, 473, 484, 495}};//Cada linha sinaliza a centena onde buscar o dig
    int soma[2][9];     //Matriz para guardar as somas parciais
    int i, j;

    for (i = 0; i < 2; i++){        //Inicializando a matriz com zeros
        for (j = 0; j < 9; j++){
            soma[i][j] = 0;
        }   
    }
    
    scanf("%s", v1);       //Leitura da entrada que será guardada como string 

    while (i = zeros_string(v1) < 9){

        lit_int(v1);        //Convertendo de literal para inteiro
        parciais(v1, soma);     //Somas parciais na matriz

        for (i = 0; i < 9; i++){        //String que exibe a entrada
            printf("%d", v1[i]);
        }

        i = isbn_dv(soma, mult);        
        if ( i == 10){              //Condição para atribuir "-X" ao dígito verificador caso seja "10"
            printf("-X\n"); 
        }   else{                   //Se o dígito verificador não for 10, então ele recebe o próprio "i"
                printf("-%d\n", i); 
        }

        for (i = 0; i < 2; i++){        //Inicializando a matriz soma com zeros
            for (j = 0; j < 9; j++){
                soma[i][j] = 0;
            }   
        } 

        scanf("%s", v1);       //Leitura da próxima string   
    }
    return 0;   
}