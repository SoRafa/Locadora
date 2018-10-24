#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main() {
    int op;
    char cliente[100];
    char filme[1000];
    int preco;
    int j=1;
    FILE *fp;
    FILE *nomes;
    int cod;
    char lista[1000];
    int multa;

while (j==1){
    printf ("---------------Loca-Loca Locadora---------------\n");
    printf ("\n\n1 - Cadastrar um novo cliente");
    printf ("\n2 - Cadastrar um novo filme");
    printf ("\n3 - Listar filmes registrados");
    printf ("\n4 - Listar usuarios registrados");
    printf ("\n5 - Consultar Filme");
    printf ("\n6 - Alugar um filme");
    printf ("\n7 - Gerar relatorio");
    printf ("\n8 - Gerar relatorio em PDF");
    printf ("\n0 - Sair da loca-loca locadora\n");
    scanf("%d", &op);


    switch(op)
    {
        case 0:

            system("cls");
            printf ("Obrigado pela preferencia!");
            return 0;
            break;

        case 1:

            system("cls");
            printf("Digite o nome do cliente:\n");
            scanf("\n%[^\n]", &cliente);
            printf ("Cliente %s registrado!\n", cliente);
            nomes=fopen("clientes.txt", "a");
            fprintf (nomes, "%s\n", cliente);
            fclose(nomes);
            printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
            scanf ("%d", &j);
            system("cls");
            break;

        case 2:

            system("cls");
            printf("Digite o nome do filme:\n");
            scanf("\n%[^\n]",filme);
            printf ("Digite o preco do aluguel em reais:\n");
            scanf ("%d", &preco);
            printf ("Digite o codigo do filme:\n");
            scanf ("%d", &cod);
            printf ("Digite a multa do filme em reais:\n");
            scanf ("%d", &multa);
            system("cls");
            printf("Filme %s registrado pelo preco de %d reais!\n", filme, preco);

            fp=fopen("filmes.txt", "a");
            fprintf (fp, "Filme: %s | Preco: %d reais | Codigo: %d | Multa: %d reais\n", filme, preco, cod, multa);
            fclose(fp);
            printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
            scanf ("%d", &j);
            system("cls");
            break;


        case 3:

        system ("cls");
        fp=fopen ("filmes.txt", "r");
        while (fgets(lista,1000,fp) != NULL){
        printf ("%s", lista);
}
        fclose(fp);
        printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
        scanf ("%d", &j);
        system ("cls");
        break;

        case 4:

        system ("cls");
        nomes=fopen ("clientes.txt", "r");
        while (fgets(cliente,1000,nomes) != NULL){
        printf ("%s", cliente);
}
        fclose(nomes);
        printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
        scanf ("%d", &j);
        system ("cls");
        break;

        default :
            printf ("Valor invalido!\n");
            break;
    }
}
}
