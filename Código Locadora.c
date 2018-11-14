#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct  cadastro_filme{
    char nomefilme[50];
    float preco;
    int statusfilme;
};

struct cadastro_cliente{
    char nomecliente[50];
    int statuscliente;
};

int main() {
    struct cadastro_filme tfilme[1000];
    struct cadastro_cliente tcliente[1000];
    int op;
    char cliente[100];
    int preco;
    int j=1;
    int i;
    FILE *txt_filmes;
    FILE *txt_clientes;
    memset (tcliente, 0, sizeof(tcliente));
    memset (tfilme, 0, sizeof(tfilme));

    txt_clientes=fopen("clientes.txt", "r");
    txt_filmes=fopen("filmes.txt", "r");
    if(txt_filmes != NULL){
        fread(tfilme, sizeof(struct cadastro_filme), 1000, txt_filmes);
    }

    if(txt_clientes != NULL){
        fread(tcliente, sizeof(struct cadastro_cliente), 1000, txt_clientes);
    }

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

        default:

            printf ("Valor invalido!\n");
            break;


         case 1:

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
        case 2:

            system("cls");
           for(i=0;i<1000;i++)
                    if(tfilme[i].statusfilme == 0){
           printf("Digite o nome do filme: ");
           fflush(stdin);
           fgets(tfilme[i].nomefilme, 40, stdin);
           printf("Digite o preço do filme: ");
           scanf("%f", &tfilme[i].preco);
           printf("filme %s registrado sobre o valor de %.2f\n",tfilme[i].nomefilme,tfilme[i].preco);
           tfilme[i].statusfilme = 1;

            txt_filmes=fopen("filmes.txt", "w");
            fwrite (tfilme, sizeof (struct  cadastro_filme),1000,txt_filmes);
            fclose(txt_filmes);
            break;
             }
            printf ("Caso queira retornar, digite 1, caso queira fechar o programa, digite 2\n");
            scanf ("%d", &j);
            system("cls");

            break;

        case 3:

            system("cls");
            for(i=0;i<1000;i++ ){
             if(tfilme[i].statusfilme==0)
                continue;
                printf("%s",tfilme[i].nomefilme);

            }
             break;
 case 4:

            system("cls");
            for(i=0;i<1000;i++ ){
             if(tcliente[i].statuscliente==0)
                continue;
                printf("%s",tcliente[i].nomecliente);

            }
             break;



 case 0:


            system("cls");
            printf ("Obrigado pela preferencia!\n");
            return 0;
            break;

    }
}
}
