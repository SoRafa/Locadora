#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sys/time.h>

struct  cadastro_filme{
    char nomefilme[50];
    float preco;
    int statusfilme;
    int alugado;
};

struct cadastro_cliente{
    char nomecliente[50];
    int statuscliente;
};

struct  aluguel{
    char aluga_filme;
    int multa;
    struct timeval tv;
};

int main() {
    struct cadastro_filme tfilme[1000];
    struct cadastro_cliente tcliente[1000];
    struct aluguel taluguel[40];
    int op;
    char consulta_filme[40];
    char consulta_cliente;
    char cliente[100];
    int preco;
    int j=1;
    int i;
    int aux = 0;
    FILE *txt_filmes;
    FILE *txt_clientes;
    FILE *txt_aluguel;

    memset (tcliente, 0, sizeof(tcliente));
    memset (tfilme, 0, sizeof(tfilme));
    memset (taluguel, 0, sizeof(taluguel));

    txt_clientes=fopen("clientes.txt", "r");
    txt_filmes=fopen("filmes.txt", "r");
    txt_aluguel=fopen("aluguel.txt", "r");

    if(txt_filmes != NULL){
        fread(tfilme, sizeof(struct cadastro_filme), 1000, txt_filmes);
    }

    if(txt_clientes != NULL){
        fread(tcliente, sizeof(struct cadastro_cliente), 1000, txt_clientes);
    }

        if(txt_aluguel != NULL){
        fread(taluguel, sizeof(struct aluguel), 40, txt_aluguel);
    }

while (j==1){
    printf ("---------------Loca-Loca Locadora---------------\n");
    printf ("\n 1 - Cadastrar um novo cliente");
    printf ("\n 2 - Cadastrar um novo filme");
    printf ("\n 3 - Listar filmes registrados");
    printf ("\n 4 - Listar usuarios registrados");
    printf ("\n 5 - Consultar Filme");
    printf ("\n 6 - Alugar um filme");
    printf ("\n 7 - Gerar relatorio");
    printf ("\n 8 - Gerar relatorio em PDF");
    printf ("\n 0 - Sair da loca-loca locadora\n");
    printf (" digite a sua opcao: ");
    scanf("%d", &op);


    switch(op)
    {
        default:
            printf ("Valor invalido!\n");
            break;

        case 1: /* cadastrar cliente */
            system("cls");
            for(i=0;i<1000;i++){
            if(tcliente[i].statuscliente == 0){
                printf("Digite o nome do cliente: ");
                fflush(stdin);
                fgets(tcliente[i].nomecliente, 40, stdin);
                printf("cliente registrado sobre o nome de %s! ",tcliente[i].nomecliente);
                tcliente[i].statuscliente=1;
                txt_clientes=fopen("clientes.txt", "w");
                fwrite (tcliente, sizeof (struct  cadastro_cliente),1000,txt_clientes);
                fclose(txt_clientes);

            printf("Se deseja cadastrar novo cliente digite 0, se quiser voltar ao menu digite 1:\n");
            scanf("%d",&j);
            if(j==1)
            break;
        }
    }
    system("cls");
    break;

        case 2: /* cadastrar filme */
            system("cls");
            for(i=0;i<1000;i++)
                if(tfilme[i].statusfilme == 0){
                    printf("Digite o nome do filme: ");
                    fflush(stdin);
                    fgets(tfilme[i].nomefilme, 40, stdin);
                    printf("Digite o preco do filme: ");
                    scanf("%f", &tfilme[i].preco);
                    printf("filme %s registrado sobre o valor de %.2f\n",tfilme[i].nomefilme,tfilme[i].preco);
                    tfilme[i].statusfilme = 1;
                    tfilme[i].alugado = 0;

                txt_filmes=fopen("filmes.txt", "w");
                fwrite (tfilme, sizeof (struct  cadastro_filme),1000,txt_filmes);
                fclose(txt_filmes);
            break;
        }
            printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
            scanf ("%d", &j);
            system("cls");
            break;

        case 3: /* Listar filmes */
            system("cls");
            if(txt_filmes == NULL){
                printf("\nFalha ao abrir arquivo!");
                exit(1);
            }else{
            for(i=0;i<1000;i++ ){
             if(tfilme[i].statusfilme==0)
                continue;
                printf("%s",tfilme[i].nomefilme);
            }
        }
        break;

        case 4: /* listar clientes */
            system("cls");
            if(txt_clientes == NULL){
                printf("\nFalha ao abrir arquivo!");
                exit(1);
            }else{
            for(i=0;i<1000;i++ ){
             if(tcliente[i].statuscliente==0)
                continue;
                printf("%s",tcliente[i].nomecliente);
            }}
        break;

        case 5: /* consultar filme */
            system("cls");
            if(txt_filmes == NULL){
                printf("\nFalha ao abrir arquivo!");
                exit(1);
            }else{
                printf("Digite o nome do filme desejado:\n");
                scanf("\n%[^\n]", &consulta_filme);
            for(i = 0; i < 1000; i++){
                if (strstr(tfilme[i].nomefilme,consulta_filme) == NULL)
                    continue;

            printf("filme encontrado %s\n", tfilme[i].nomefilme);

            if( tfilme[i].alugado == 1) {
                printf("filme alugado\n");
                continue;
            }else{
                printf("filme disponivel pelo preco de %.2f Reais\n\n",tfilme[i].preco);
                continue;
            }
        }
        printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
        scanf ("%d", &j);
        }
        system("cls");
        break;

        case 6: /* alugar filme */
            system("cls");
            if(txt_filmes == NULL){
                printf("\nFalha ao abrir arquivo!");
                exit(1);
        }else{
            printf("Digite o nome do filme que deseja alugar:\n");
            scanf("\n%[^\n]", &consulta_filme);
            for(i = 0; i < 1000; i++){

                if (strstr(tfilme[i].nomefilme,consulta_filme) == NULL)
                    continue;

                if( tfilme[i].alugado == 1) {
                    printf("filme alugado\n");
                break;
            }
            else{
                printf("Filme %s disponivel pelo preço de %.2f .\n Se deseja alugar digite 1, se deseja voltar ao menu digite 0\n",tfilme[i].nomefilme,tfilme[i].preco);
                scanf ("%d", &aux);

            if(aux==1){
            tfilme[i].alugado = 1;
            gettimeofday(&taluguel[i].tv, NULL);
            } else if(aux != 1){
                break;
            }}

            txt_filmes=fopen("filmes.txt", "w");
            fwrite (tfilme, sizeof (struct  cadastro_filme),1000,txt_filmes);
            fclose(txt_filmes);
            break;
        }
            printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
            scanf ("%d", &j);}
            system("cls");
        break;

                case 7: /* Devolver um Filme */
        system("cls");
            printf("Digite o nome do filme que deseja devolver:\n");
            scanf("\n%[^\n]", &consulta_filme);
            for(i = 0; i < 1000; i++){

                if (strstr(tfilme[i].nomefilme,consulta_filme) == NULL)
                    continue;

                if( tfilme[i].alugado == 0) {
                    printf("O filme já está disponível\n");
                break;
            }
            else{
                printf("Filme %s encontrado!\n Se deseja devolve-lo, digite 1, se deseja voltar ao menu digite 0\n",tfilme[i].nomefilme,tfilme[i].preco);
                scanf ("%d", &aux);

            if(aux==1){
            tfilme[i].alugado = 0;
            gettimeofday(&taluguel[i].tv, NULL);
            } else if(aux != 1){
                break;
            }}

            txt_filmes=fopen("filmes.txt", "w");
            fwrite (tfilme, sizeof (struct  cadastro_filme),1000,txt_filmes);
            fclose(txt_filmes);
            break;
        }
            printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
            scanf ("%d", &j);
            system("cls");
        break;

        case 8:
        break;

         case 0:
            system("cls");
            printf ("Obrigado pela preferencia!\n");
            return 0;
            break;

        }
    }
}
