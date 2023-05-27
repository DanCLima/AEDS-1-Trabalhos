/*----------------------------------------------------------------------
 *          UNIFAL - Universidade Federal de Alfenas.
 *            BACHARELADO EM CIENCIA DA COMPUTACAO.
 * Trabalho..: Atividade 3
 * Disciplina: Programacao
 * Professor.: Luiz Eduardo da Silva
 * Aluno:....: Daniel da Costa Lima
 * Data......: 01/07/2021
----------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------
* Calcula o comprimento do string
* Recebe o string(s)
* Retorna o comprimento de s
----------------------------------------------------------------------*/
int strlength(char *s)
{
    int i;
    for ( i = 0; s[i]; i++)
        ;
    return i;
}

/*----------------------------------------------------------------------
* Lê um string
* Parâmetros:
*   s = string a ser lido
*   len = tamanho máximo da leitura (contar o \0 e \n)
----------------------------------------------------------------------*/
void strread(char *s, int len)
{
    fgets(s, len, stdin);
    s[strlength(s) - 1] = '\0';
}

/*----------------------------------------------------------------------
* Mostra os elementos do vetor string em modo texto
* Parâmetros:
*   s = string
*   name = nome do string
----------------------------------------------------------------------*/
void strshow(char *s, char *name)
{
    int i;
    for (i = 0; s[i]; i++)
        printf("%3d ", i);
    printf("%3d\n", i);
    for (i = 0; s[i]; i++)
        printf("+---");
    printf("+---+\n");
    for (i = 0; s[i]; i++)
        printf("| %c ", s[i]);
    printf("| \\0| %s\n", name);
    for (i = 0; s[i]; i++)
        printf("+---");
    printf("+---+\n");  
}

/*----------------------------------------------------------------------
* Insere um substring num string na posição especificada
* Parâmetros:
*   pos = posição onde inserir (0 é a primeira posição)
*   sub = substring que será inserido em s
*   s = string onde inserir sub
----------------------------------------------------------------------*/
void strinsert(int pos, char *sub, char *s)                                
{
    int i, j, k, l, m, n;
        for (i = 0; s[i]; i++){           //Contabilizar as casas da string
        ;
    }
        for (j = 0; sub[j]; j++){           //Contabilizar as casas da sub
        ;
    }

    k = i + j;      //Última posição do string
    s[k] = '\0';    //Indicando o fim da string

    if (pos > i){   //Tratando a posição maior do que a string
        pos = i;
        for (l = 0; l < j; l++, pos++){
            s[pos] = sub[l];
        }
    }
    else{
        for (l = i; l >= pos; l--, k--){
            s[k - 1] = s[l - 1];                
        }
        for (m = j; m > 0; m--, k--){     
            s[k] = sub[m - 1];
        }
    }    
}

/*----------------------------------------------------------------------
* transforma um literal em inteiro
* o literal pode ter sinal (+ ou -) seguido de digitos
----------------------------------------------------------------------*/
int str2int(char *s)
{
    int j;
    if (s[1]){
        if (s[0] == '+') {
            j = (s[1] - 48);        
        }

        else if (s[0] == '-'){
            j = -1;
        }
        else if (s[0] != '+' && s[0] != '-'){
            j = ((s[0] - 48) * 10) + (s[1] - 48);
        }
    }
    else {
        j = (s[0] - 48);
    }
    return j;
}

int main(void)
{
    char string[100];
    char substring[100];
    char posstr[4];
    int posicao;
    do
    {
        strread(posstr, 4);
        posicao = str2int(posstr);
        printf("\nPosicao = %d\n", posicao);
        if (posicao >= 0)
        {
            strread(substring, 30);
            strshow(substring, "substr.");
            strread(string, 70);
            strshow(string, "string");
            strinsert(posicao, substring, string);
            strshow(string, "result.");
        }
    } while (posicao >= 0);
}