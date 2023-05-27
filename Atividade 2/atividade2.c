/*----------------------------------------------------------------------
 *          UNIFAL - Universidade Federal de Alfenas.
 *            BACHARELADO EM CIENCIA DA COMPUTACAO.
 * Trabalho..: Atividade 2
 * Disciplina: Programacao
 * Professor.: Luiz Eduardo da Silva
 * Aluno:....: Daniel da Costa Lima
 * Data......: 01/07/2021
----------------------------------------------------------------------*/

#include <stdio.h>

int n, piso[20][20], i, j, caneta, linha, coluna, direcao;
char comando;

int main(void) 
{
    /* Definindo a matriz piso */
    for (i = 0; i < 20; i++){       
        for (j = 0; j < 20; j++){
            piso[i][j] = '0';
        }
    }    
    
    caneta = 0;                     
    direcao = 0;
    linha = 0;
    coluna = 0;

    do {
        scanf ("%c", &comando);     //Lendo os comandos
        
        /* Definindo a direção */
        if (comando == 'r'){        
            if (direcao == 3){
                direcao = 0;                           
            }
            else{                  
                direcao++;
            }
        }

        if (comando == 'l'){    
            if (direcao == 0){
                direcao = 3;
            }
            else{
                direcao--;
            }
        }

        /* Definindo o estado da caneta */
        if (comando == 'd'){         
            caneta = 1;
        }
        if (comando == 'u'){
            caneta = 0;
        }        

        /* Definindo comando para andar */
        if (comando == 'w'){                         
         
            scanf("%d", &n);                           //Leitura dos passos

            if (n == 1){                               //Correção do comando n = 1, pq não entra na repetição
                coluna = coluna;
                linha = linha;                
                if (caneta == 1){                     //Condicional para desenhar
                    piso[linha][coluna] = '1';
                }

            }
            else{
                for (i = 1; i < n; i++){                //Repetição para andar                      
                    if (direcao == 0){                    
                        coluna++;
                    }
                    if (direcao == 1){
                        linha++;
                    }
                    if (direcao == 2){
                        coluna--;
                    }
                    if (direcao == 3){
                        linha--; 
                    }  
                    if (caneta == 1){                     //Condicional para desenhar
                        piso[linha][coluna] = '1';
                    }                                                            
                }  
            }                             
        }
        
        if (comando == 'p'){                           //Definindo comando para printar
            for (i = 0; i < 20; i++){
                for (j = 0; j < 20; j++){   
                    if (piso[i][j] == '1' || piso[i][j] == 42){         
                        piso[i][j] = 42;              //Substituindo os 1's por o e os 0's por . em cod ASCII
                    }
                    else{
                        piso[i][j] = 46;             
                    }                           
                    printf ("%2c", piso[i][j]);         //Espaçamento de 2 colunas entre as posicoes
                }    
                printf ("\n");  
            }                        
        }
    } while (comando != 'e' && comando != 'E');
    return 0;
}