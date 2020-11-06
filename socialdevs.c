
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_devs
{
    char name[50];
    char user[50];
    char email[50];
    char password[50];
    int id;
    char bio[100];
};


void cadastro(struct data_devs *d, int *code)
{
    char t; //só pra definir uma tecla de atalho

    system("clear");
    printf("\n--- CADASTRO DE DEVS ---\n\n");

    (*code)++; //pega a posição do dev

    fflush(stdin);
    setbuf(stdin,NULL);

    printf("\nDigite seu melhor email:\n");
    fgets(d[*code].email, 50, stdin); 
    fflush(stdin);
    setbuf(stdin,NULL);

    printf("\nDigite uma senha de caracteres:\n");
    fgets(d[*code].password, 50, stdin);
    fflush(stdin);
    setbuf(stdin,NULL);

    printf("\nNome Completo:\n");
    fgets(d[*code].name, 50, stdin); 
    fflush(stdin);
    setbuf(stdin,NULL);

    printf("\nUsuário:\n");
    fgets(d[*code].user, 50, stdin); 
    fflush(stdin);
    setbuf(stdin,NULL);

    printf("\nFaça um pequeno resumo sobre seu trabalho:\n");
    fgets(d[*code].bio, 100, stdin); 
    fflush(stdin);
    setbuf(stdin,NULL);


    d[*code].id=(*code)+1; //soma 1 pra não pegar o mesmo numero anterior

    printf("\n\nCadastro realizado com sucesso.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin,NULL);

    scanf("%c", &t); //le a tecla que o usuário digitar
    system("clear");
}

void delete(struct data_devs *d, int *code)
{
    int i, j, idRemove;
    char t;

    //system("CLS");
    system("clear");

    printf("\n--- REMOCAO DE DEV---\n\n");
    fflush(stdin);
    printf("Qual o id do dev que deseja excluir?\n");
    scanf("%d", &idRemove);

    if (*code>=0){ //se existir devs cadastrados
        for (i=0; i<=*code; i++) //percorre o vetor de devs para achar o código
        {
            if(d[i].id == idRemove){  //se o código da vez que estiver no for, for igual ao código que o usuário digitou
                for (j = i; j < *code; j++)
                {
                    d[j] = d[j+1];
                    d[j].id=d[j+1].id-1;  //serve para atualizar o codigo dos devs após um ser removido, para não dar problema com o cadastro de novos devs depois
                }

                (*code)--; //pra ir diminuindo no for
            }
        }
    }
    printf("\n\nDev removido.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin,NULL);
    scanf("%c", &t);

    system("clear");
    system("CLS");
}


int main(){
    int code = -1, i, resp;

    struct data_devs devs[10000];


    printf("\n\n1- Acessar opções do menu.\n0- Sair.\n\n");
    scanf("%d", &resp);

    if (resp == 1) //1 = Acessa menu
    {
        system("CLS");
        while(resp != 0) //Enquanto o usuário não quiser sair, pois em todo final de processo/função, ele pode clicar em sair.
        {
            printf("\n---- MENU ----\n\n");
            resp = -1;
            printf("\n1- Cadastro\n2- Remocao\n3- Listagem\n4- Consulta\n5- Atualizacao de emprestimo\n0- Sair\n");
            fflush(stdin);
            setbuf(stdin,NULL);
            scanf("%d", &resp); //Lê a função que o usuário queira que aconteça

            if ((resp == 1) || (resp == 2) || (resp == 3) || (resp == 4) || (resp == 5) || (resp == 0))
            {
                switch(resp){
                case 1:
                    cadastro(devs, &code); //se for cadastro. Livro é equivalente ao ponteiro l e cont ao ponteiro cont. Precisa passar eles como parametro
                break;
                case 2:
                    delete(devs, &code); //mesma coisa que o de cima
                break;
                /*
                case 3:
                    listagem(livro, &cont);
                break;
                case 4:
                    consulta(livro, &cont);
                break;
                */
                default:
                    printf("\nProcesso finalizado.\n");
                break;
                }
            }
                else{
                    printf("Erro.\n");
                    system("PAUSE");
                    getchar();
                }
        }
    }

    return 0;
}