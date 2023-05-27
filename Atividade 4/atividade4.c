/*----------------------------------------------------------------------
 *          UNIFAL - Universidade Federal de Alfenas.
 *            BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO.
 * Trabalho..: Atividade 4
 * Disciplina: Programação
 * Professor.: Luiz Eduardo da Silva
 * Aluno:....: Daniel da Costa Lima
 * Data......: 26/08/2021
----------------------------------------------------------------------*/
#include <stdio.h>

void leSudoku(int n, int sudoku[16][16])
{
    char s[2];
    int i, j, dim = n * n;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            scanf("%s", s);
            if (s[0] >= '1' && s[0] <= '9')
                sudoku[i][j] = s[0] - '0';      //convertendo os números de 1 a 9 de literal para inteiro
            if (s[0] >= 'A' && s[0] <= 'G')
                sudoku[i][j] = s[0] - 'A' + 10;  //convertendo os números de 10 a 16 de literal para inteiro
        }
    }
}

void imprimeLinha(int n)
{
    int i, j;
    for (i = 0; i < n; i++){
        printf("+");
        for (j = 0; j < n; j++){
            printf("---");
        }
    }   
    printf("+\n");
}

void imprimeSudoku(int n, int sudoku[16][16])
{
    int i, j, dim = n * n;
    imprimeLinha(n);
    for (i = 0; i < dim; i++){
        printf("|");
        for (j = 0; j < dim; j++){
            int num = sudoku[i][j];
            if (num <= 9)
                printf("%2d ", num);
            else
                printf("%2c ", num - 10 + 'A');      //convertendo de inteiro para literal
            if ((j + 1) % n == 0)
                printf("|");   
        }
        printf("\n");
        if ((i + 1) % n == 0)
            imprimeLinha(n);  
    }  
}

/*----------------------------------------------------
* Função que testa uma solução do Sudoku
* Parâmetros:
*   n = dimensão das regiões;
*   sudoku - jogo preenchido;
*   lin - linha do erro (se houver);
*   col - coluna do erro (se houver).
* Retorna:
*   1 se a matriz é uma solução do sudoku;
*   0 caso o contrário, modificando os parâmetros:
*       lin e col para indicar a linha e coluna onde
*       foi detectado o problema.
*----------------------------------------------------*/
int sudokuOk(int n, int sudoku[16][16], int *lin, int *col)
{
    int v[16], ok = 1;
    int i, j, k, l, m;

    for (i = 0; i < n * n; i++){        //Preenchendo v com 0
        v[i] = 0;
    }

    /* Repetição para verificar linhas */
    for (i = 0; i < n * n && ok == 1; i++){        //Repetição para linha
        for (j = 0; j < n * n && ok == 1; j++){     //Repetição para coluna
            if (v[sudoku[i][j] - 1] == 0){
                v[sudoku[i][j] - 1] = 1;
                
            } else{
                ok = 0;
                *lin = i + 1;
                *col = j + 1;
            }
        }
        for (k = 0; k < n * n && ok == 1; k++){        //Preenchendo v com 0
            v[k] = 0;
        }
    }

    /* Repetição para verificar colunas */
    for (i = 0; i < n * n && ok == 1; i++){        //Repetição para linha
        for (j = 0; j < n * n && ok == 1; j++){     //Repetição para coluna
            if (v[sudoku[j][i] - 1] == 0){
                v[sudoku[j][i] - 1] = 1;
                
            } else{
                ok = 0;
                *lin = j + 1;
                *col = i + 1;
            }
        }
        for (k = 0; k < n * n && ok == 1; k++){        //Preenchendo v com 0
            v[k] = 0;
        }
    }
   
    /* Repetição para verificar regiões */
    for (m = 0; m < n * n; m = m + n){          //Alternando blocos na horizontal
        for (l = 0; l < n * n && ok == 1; l = l + n){       //Alternando blocos na vertical
            for (i = m; i < m + n && ok == 1; i++){         //Iniciando a verificação das regiões a partir do bloco [m][n]
                for (j = l; j < l + n && ok == 1; j++){     
                    if (v[sudoku[i][j] - 1] == 0){
                        v[sudoku[i][j] - 1] = 1;
                        
                    } else{
                        ok = 0;
                        *lin = i + 1;
                        *col = j + 1;
                    }
                }
            }
        
            for (k = 0; k < n * n && ok == 1; k++){        //Preenchendo v com 0
                v[k] = 0;
            }    
        }
    }
    return ok;
}

int main(void)
{
    int n, nlin, ncol, ok;
    int sudoku[16][16];
    scanf("%d", &n);
    leSudoku(n, sudoku);
    imprimeSudoku(n, sudoku);
    ok = sudokuOk(n, sudoku, &nlin, &ncol);
    if (ok)
        puts("Sudoku Ok!");
    else
        printf("Erro na posicao (%d,%d)\n", nlin, ncol);     
    return 0;
}