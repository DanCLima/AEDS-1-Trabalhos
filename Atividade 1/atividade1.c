/*----------------------------------------------------------------------
 *          UNIFAL - Universidade Federal de Alfenas.
 *            BACHARELADO EM CIENCIA DA COMPUTACAO.
 * Trabalho..: Atividade 1
 * Disciplina: Programacao
 * Professor.: Luiz Eduardo da Silva
 * Aluno:....: Daniel da Costa Lima
 * Data......: 01/07/2021
----------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{ 
    int idade, id, somaidades = 0, qtdpessoas = 0, qtdfem = 0, qtdmasc = 0, qtdoutros = 0, maioridade = 0, idmaioridade, menoridade = 1000, idmenoridade;
    char sexo;
    float mediaidades;

    do 
    {
        printf("Digite o ID, sexo e idade\n");
        scanf("%d %c %d", &id, &sexo, &idade);
            if (id != 0 && sexo != 'x' && idade != 0)
            {   
                somaidades = somaidades + idade;
                qtdpessoas++;

                if (sexo == 'm' || sexo == 'M')
                {   
                    qtdmasc++;
                }
                else
                {
                    if (sexo == 'f' || sexo == 'F')
                    {   
                        qtdfem++;
                    }
                    else 
                    {   
                        qtdoutros++;
                    } 
                }  
                if (maioridade <= idade)
                {   
                    maioridade = idade;  
                    idmaioridade = id;
                }
                if (menoridade >= idade)
                {   
                    menoridade = idade;
                    idmenoridade = id;
                }
            }

    } while (id != 0 && sexo != 'x' && idade != 0);

    mediaidades = (float)somaidades/qtdpessoas;

    printf("+------------------+--------+\n");
    printf("| Soma das idades  |%7d |\n", somaidades);
    printf("| Total pessoas    |%7d |\n", qtdpessoas);
    printf("| Media de idades  |%7.1f |\n", mediaidades);
    printf("| Homens           |%7d |\n", qtdmasc);
    printf("| Mulheres         |%7d |\n", qtdfem);
    printf("| Outros           |%7d |\n", qtdoutros);
    printf("| Maior idade      |%7d |\n", maioridade);
    printf("| ID do mais velho |%7d |\n", idmaioridade);
    printf("| Menor idade      |%7d |\n", menoridade);
    printf("| ID do mais novo  |%7d |\n", idmenoridade);
    printf("+------------------+--------+");
    return 0;
}