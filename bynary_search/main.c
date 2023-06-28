#include "Nota.h"

int main()
{
    Apontador turma; //variavel q representa o no
    Aluno registro; //variavel q armazena os dados do aluno
    char arquivo[21]; //string para o nome do arquivo
    int i; //variavel de controle para o menu

    printf("    *************************\n");
    printf("    *  Atividade Pratica 1  *\n");
    printf("    *************************\n");

    printf("\n");
    printf(" Digite o nome do arquivo\n");
    printf(" no formato 'nome_do_arquivo.txt':\n");
    printf(" -> ");
    /* Recebe o nome do arquivo e salva em uma string */
    gets(arquivo);

    abrearquivo(&turma, arquivo, registro);

    i = 0;

    /* Menu que mostra as opcoes disponiveis para o usuario */
    while(i != 6)
    {
        printf("        *** Menu ***\n\n");
        printf("1. Exibir, em ordem decrescente da nota,\n");
        printf("   os alunos e suas matriculas;\n");
        printf("2. Exibir o numero de alunos da disciplina;\n");
        printf("3. Exibir a menor nota obtida;\n");
        printf("4. Exibiri a maior nota obtida;\n");
        printf("5. Exibir o numero de alunos com media na primeira prova.\n");
        printf("6. Sair\n");
        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &i);

        switch (i)
        {
            case 1:
                imprime(turma);
            break;
            case 2:
                printf("Total de alunos: %d\n", contaalunos(turma));
                break;
            case 3:
                menorNota(turma);
                break;
            case 4:
                maiorNota(turma);
                break;
            case 5:
                printf("Numero de aluno com media: %d\n", contamedia(turma));
                break;
            case 6:
                break;
        }
    }
    return 0;
}
