#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct opinion
{
    int code_opinion;
    char comment[50];
    int likes;
};

struct post
{
    char title[50];
    char image[50];
    char description[50];
    int code_post;
    struct opinion opinions;
};

struct data_devs
{
    char name[50];
    char user[50];
    char email[50];
    char password[50];
    int id;
    char bio[100];
    int status;
    struct post posts;
    int add[40];
};

#define SAIR '0'
#define DELETAR '1'
#define LISTAR '2'
#define CONSULTAR '3'
#define CREATEPOST '4'
#define CONSULTPOST '5'
#define UPDATEPOST '6'
#define ADDOPPINION '7'
#define CONSULTOPPINION '8'
#define UPDATEOPPINION '9'

char *menuMain[] = {
    "\n---- MENU ----\n\n",
    "1. Listar todos os desenvolvedores",
    "2. Consultar um desenvolvedor",
    "3. Deletar um desenvolvedor",
    "4. Criar um post",
    "5. Consultar post",
    "6. Atualizar post",
    "7. Criar um comentário ou dar like",
    "8. Consultar uma opinião",
    "9. Atualizar comentário",
    "0. Sair",
    NULL};

char Menu(char *options[])
{ 
    int i;
    char optionChoose;

    system("clear");

    setbuf(stdin, NULL);

    while (1)
    { 
        for (i = 0; options[i] != NULL; i++)
        {                                
            printf("%s\n\n", options[i]);
        }

        printf("\n\nOpção escolhida: ");
        setbuf(stdin, NULL);
        optionChoose = getchar(); 

        for (i = 0; options[i] != NULL; i++)
        { 
            if (*options[i] == optionChoose)
            {
                return optionChoose;
            }
        }
    }
}

int login(struct data_devs *d, int *code)
{
    int i, validate = 0,
    try
        = 5, b = 1;
    char t, email[50], password[50];

    system("clear");

    printf("\n--- LOGIN ---\n\n");

    fflush(stdin);
    setbuf(stdin, NULL);

    for (i = 0; i <= *code; i++)
    {
        do
        {

            printf("Digite seu email:");
            fgets(email, 50, stdin);
            fflush(stdin);
            setbuf(stdin, NULL);

            printf("Digite sua senha:");
            fgets(password, 50, stdin);
            fflush(stdin);
            setbuf(stdin, NULL);

            if (strcmp(email, d[i].email) == 0 && strcmp(password, d[i].password) == 0)
            {
                printf("\n\nUsuário logado!\n\n");
                validate = 1;
                b = 0;
                d[i].status = 0;
            }
            else
            {
                system("clear");
                printf("Usuário ou senha incorretos. Tente novamente! \n\n");
                try
                    --;
                b = 1;
                validate = 0;
            }
        } while (b && try); 
    }

    if (validate == 1)
    {
        Menu(menuMain);
        return 1;
    }
    system("clear");
    return 0;
}

void create(struct data_devs *d, int *code)
{
    char t; 

    system("clear");
    printf("\n--- CADASTRO DE DEVS ---\n\n");
    fflush(stdin);
    setbuf(stdin, NULL);

    (*code)++; 

    printf("\nDigite seu melhor email:\n");
    fgets(d[*code].email, 50, stdin);
    fflush(stdin);
    setbuf(stdin, NULL);

    printf("\nDigite uma senha de caracteres:\n");
    fgets(d[*code].password, 50, stdin);
    fflush(stdin);
    setbuf(stdin, NULL);

    printf("\nNome Completo:\n");
    fgets(d[*code].name, 50, stdin);
    fflush(stdin);
    setbuf(stdin, NULL);

    printf("\nUsuário:\n");
    fgets(d[*code].user, 50, stdin);
    fflush(stdin);
    setbuf(stdin, NULL);

    printf("\nFaça um pequeno resumo sobre seu trabalho:\n");
    fgets(d[*code].bio, 100, stdin);
    fflush(stdin);
    setbuf(stdin, NULL);

    d[*code].id = (*code) + 1; 

    printf("\n\nCadastro realizado com sucesso.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t); 
    system("clear");
}


void list(struct data_devs *d, int *code)
{

    int i, cod, n = 0;
    char t;
    system("clear");
    printf("\n--- LISTAGEM DE DEVS CADASTRADOS ---\n\n");

    for (i = 0; i <= *code; i++)
    {
        printf("\nID: %d\nEmail: %sNome: %sUsuário: %sBio: %s", d[i].id, d[i].name, d[i].email, d[i].user, d[i].bio);
        if (d[i].status == 0)
        {
            printf("Status: Ativo\n");
        }
        else
        {
            printf("Status: Offline\n");
        }
        printf("\nPara saber senha do usuário digite o codigo de acesso: "); //codigo de acesso � 1234.
        scanf("%i", &cod);

        if (cod == 1234)
        {
            n = 1;
            printf("\nPassword: %s", d[i].password);
        }

        if (!n)
        {
            printf("Código de acesso invalido.");
        }

        if (*code > 0)
        {
            printf("\n------------------------------");
        }
    }

    printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);
    system("clear");
}


void delete (struct data_devs *d, int *code)
{
    int i, j, idRemove;
    char t;

    system("CLS");
    system("clear");

    printf("\n--- REMOCAO DE DEV---\n\n");
    fflush(stdin);
    printf("Qual o id do dev que deseja excluir?\n");
    scanf("%d", &idRemove);

    if (*code >= 0)
    {                              
        for (i = 0; i <= *code; i++) 
        {
            if (d[i].id == idRemove)
            {  
                for (j = i; j < *code; j++) // percorre o vetor pra poder susbtituir os outros
                {
                    d[j] = d[j + 1]; //d na posição 0, recebe o d na posição 1. d[1] = d[2], pra ir substituindo no for
                    d[j].id = d[j + 1].id - 1; //pega o id da pessoa e diminui 1
                }

                (*code)--; //diminui o tamanho do vetor.
            }
        }
    }
    printf("\n\nDev removido.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);

    system("clear");
}

void consult(struct data_devs *d, int *code)
{
    int i, ids, optionChoose, n = 0;
    char t, dev[50];

    system("CLS");
    system("clear");
    printf("\n--- CONSULTAR UM(A) DEV ---\n\n");
    printf("\nDeseja consultar pelo id ou pelo nome de usu�rio?\n");
    printf("\nDigite:\n1- Id\n2- Usuário\n");
    scanf("%d", &optionChoose);
    switch (optionChoose)
    {
    case 1: 
        system("clear");
        printf("\nInsira o id do DEV a ser consultado: ");
        scanf("%d", &ids);
        for (i = 0; i <= *code; i++) 
        {
            if (ids == d[i].id)
            {
                printf("\n\nID: %d\nNome: %sUsuário: %sEmail: %sPassword: %sBio: %s", d[i].id, d[i].name, d[i].user, d[i].email, d[i].password, d[i].bio);
                n = 1;
                if (d[i].status == 0)
                {
                    printf("Status: Online");
                }
                else if (d[i].status == 1)
                {
                    printf("Status: Offline");
                }
            }
        }
        if (!n)
        {
            printf("ID inexistente.\n");
        }

        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%c", &t);
        system("clear");
        break;

    case 2: 
        system("clear");
        printf("\nInsira o nome do usuário: \n\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        fgets(dev, 50, stdin);
        for (i = 0; i <= *code; i++) 
        {
            if (strcmp(dev, d[i].user) == 0)
            {
                n = 1;
                printf("ID: %d\nNome: %sUsu�rio: %sEmail: %sPassword: %sBio: %s", d[i].id, d[i].name, d[i].user, d[i].email, d[i].password, d[i].bio);
                if (d[i].status == 0)
                {
                    printf("Status: Online");
                }
                else if (d[i].status == 1)
                {
                    printf("Status: Offline");
                }
            }
        }
        if (!n)
        {
            printf("Usu�rio inexistente.\n");
        }

        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%c", &t);
        system("clear");
        break;

    default: 
        system("CLS");
        printf("\nOpcao invalida.\n");
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%c", &t);
        system("clear");
        break;
    }
}

void create_post(struct data_devs *d, int *code, int *codePost)
{
    int i, n = 0, id;
    char t, dev[50];
    system("clear");
    printf("\n--- POST ---\n\n");
    printf("\nInsira o ID do usuário: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &id);
    (*codePost)++;
    for (i = 0; i <= *code; i++) 
    {
        if (d[i].id == id)
        {
            n = 1;
            fflush(stdin);
            setbuf(stdin, NULL);
            printf("Digite o título do post: ");
            fgets(d[i].posts.title, 10, stdin);
            printf("Digite a url da imagem a ser colocada no post: ");
            fgets(d[i].posts.image, 40, stdin);
            printf("Faça uma breve descrição sobre o post: ");
            fgets(d[i].posts.description, 100, stdin);

            d[*codePost].posts.code_post = (*codePost) + 1;
        }
    }
    if (n)
    {
        printf("\nPost publicado com sucesso!\n\n");
    }
    else
    {
        printf("ID inexistente.\n");
    }
    printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);
    system("clear");
}


void post_consult(struct data_devs *d, int *code)
{
    int i, n = 0, resp = 0, idPost;
    char t, dev[50];
    system("clear");
    printf("\n--- POST DEV ---\n\n");
    printf("\nInsira o ID do post: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &idPost);

    for (i = 0; i <= *code; i++) 
    {
        if (d[i].posts.code_post == idPost)
        {
            n = 1;
            printf("\n -Código do post: %i\n\n -Título do post: %s\n -URL da imagem: %s\n -Descrição: %s\n -Likes: %i\n -Comentário: %s\n",
                   d[i].posts.code_post,
                   d[i].posts.title,
                   d[i].posts.image,
                   d[i].posts.description,
                   d[i].posts.opinions.likes,
                   d[i].posts.opinions.comment);
        }
    }
    if (!n)
    {
        printf("ID inexistente.\n");
    }
    printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);
    system("clear");
}

void post_update(struct data_devs *d, int *code)
{
    int i, j, idPost, n;
    char t;
    system("clear");
    printf("\n--- ATUALIZAR POST ---\n\n");

    printf("\nInsira o ID do post que deseja atualizar: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &idPost);

    for (i = 0; i <= *code; i++)
    {
        if (d[i].posts.code_post == idPost)
        {
            n = 1;
            fflush(stdin);
            setbuf(stdin, NULL);
            printf("Digite o título a ser colocado no post: ");
            fgets(d[i].posts.title, 50, stdin);
            printf("Digite a url da imagem a ser colocada no post: ");
            fgets(d[i].posts.image, 50, stdin);
            printf("Faça uma breve descrição sobre o post: ");
            fgets(d[i].posts.description, 100, stdin);
        }
    }
    if (!n)
    {
        printf("ID DO POST INEXISTENTE!!");
    }
    else
    {
        printf("POST ATUALIZADO!");
    }
    printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);
    system("clear");
}


char create_opinion(struct data_devs *d, int *code, int *codeOpinion)
{
    int i, id, j, n, idPost, opinion, cont, idUser;
    char t, comment;

    system("clear");
    printf("\n--- OPINIÃO SOBRE O POST ---\n\n");

    printf("Digite o id do post que queira dar sua opinião: ");
    scanf("%i", &idPost);
    (*codeOpinion)++;

    for (i = 0; i <= *code; i++)
    {
        if (d[i].posts.code_post == idPost)
        {
            printf("\n\n1- Dar like.\n2- Comentar. \n0- Sair.\n\n");
            scanf("%i", &opinion);
            n = 1;
            

        switch (opinion)
            {
            case 1:
                  cont = cont + 1;
                  d[i].posts.opinions.likes = cont;
                printf("\nLIKE adicionado!");
                 d[*codeOpinion].posts.opinions.code_opinion = (*codeOpinion) + 1;
                break;

            case 2:
                printf("\nEscreva algo...\n");
                fflush(stdin);
                setbuf(stdin, NULL);
                fgets(d[i].posts.opinions.comment, 100, stdin);

                printf("\nComentário adicionado!");
                d[*codeOpinion].posts.opinions.code_opinion = (*codeOpinion) + 1;
                break;

            default:
                printf("Escolha uma opção");
                break;
            }
        }
    }

    if (!n)
    {
        printf("Post inexistente.\n");
    }

    printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);
    system("clear");
}

void opinion_consult(struct data_devs *d, int *code)
{
    int i, n = 0, resp = 0, idOpinion;
    char t, dev[50];
    system("clear");
    printf("\n--- OPINIÃO SOBRE O POST ---\n\n");
    printf("\nInsira o ID da opinião que queira ver: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &idOpinion);

    for (i = 0; i <= *code; i++) 
    {
        if (d[i].posts.opinions.code_opinion == idOpinion)
        {
            n = 1;
            printf("\n -Código da opinião: %i\n -Likes: %i\n -Comentário: %s\n",
                   d[i].posts.opinions.code_opinion,
                   d[i].posts.opinions.likes,
                   d[i].posts.opinions.comment);
           }
    }
    if (!n)
    {
        printf("ID inexistente.\n");
    }
    printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);
    system("clear");
}

void opinion_update(struct data_devs *d, int *code)
{
    int i, j, idOpinion, n, resp;
    char t;
    system("clear");
    printf("\n--- ATUALIZAR OPINIÃO ---\n\n");

    printf("\nInsira o ID da opinião que deseja atualizar: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &idOpinion);

    for (i = 0; i <= *code; i++)
    {
        if (d[i].posts.opinions.code_opinion == idOpinion)
        {
            n = 1;
            fflush(stdin);
            setbuf(stdin, NULL);
            printf("\nEscreva algo...\n");
            fgets(d[i].posts.opinions.comment, 100, stdin);
        }
    }
    if (!n)
    {
        printf("ID DA OPINIÃO INEXISTENTE!!");
    }
    else
    {
        printf("OPINIÃO ATUALIZADA!");
    }
    printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t);
    system("clear");
}

 void arq_open(struct data_devs *d, int *code){
    int i;
    FILE *fp;
    fp = fopen("arqdev.txt", "r+");

    if (fp == NULL){
        fp = fopen("arqdev.txt", "w+");
    }else{
        for(i=0; i<=*code; i++){
            fscanf(fp, "%i", &d[i].id);
            fgets(d[i].email, 50, fp);
            fgets(d[i].name, 50, fp);
            fgets(d[i].user, 50, fp);
            fgets(d[i].bio, 100, fp);
            fscanf(fp, "%i\n", &d[i].status);

            fscanf(fp, "%i", &d[i].posts.code_post);
            fgets(d[i].posts.title, 50, fp);
            fgets(d[i].posts.image, 50, fp);
            fgets(d[i].posts.description, 50, fp);

            fscanf(fp, "%i", &d[i].posts.opinions.code_opinion);
            fscanf(fp, "%i", &d[i].posts.opinions.likes);
            fgets(d[i].posts.opinions.comment, 50, fp);

        }
    }
  fclose(fp); 
}

 void arq_save(struct data_devs *d, int *code){
    int i;
    FILE *fp; 
    fp = fopen("arqdev.txt", "w+");
    
    for(i=0; i<=*code; i++){
            fprintf(fp, "%s","Id: ");
            fprintf(fp, "%i\n", d[i].id);

            fprintf(fp, "%s","Email: ");
            fprintf(fp, "%s", d[i].email);

            fprintf(fp, "%s","Nome: ");
            fprintf(fp, "%s", d[i].name);

            fprintf(fp, "%s","Usuário: ");
            fprintf(fp, "%s", d[i].user);

            fprintf(fp, "%s","Bio: ");
            fprintf(fp, "%s", d[i].bio);

            if(d[i].status == 0){
              fprintf(fp, "%s\n\n","Status: Ativo");
            }
            
            fprintf(fp, "%s","Código do Post: ");
            fprintf(fp, "%i\n", d[i].posts.code_post);

            fprintf(fp, "%s","Título do Post: ");
            fprintf(fp, "%s", d[i].posts.title);

            fprintf(fp, "%s","Url do Post: ");
            fprintf(fp, "%s", d[i].posts.image);

            fprintf(fp, "%s","Descrição do Post: ");
            fprintf(fp, "%s\n", d[i].posts.description);
            
            fprintf(fp, "%s","Código da opinião: ");
            fprintf(fp, "%i\n", d[i].posts.opinions.code_opinion);

            fprintf(fp, "%s","Likes: ");
            fprintf(fp, "%i\n", d[i].posts.opinions.likes);

            fprintf(fp, "%s","Comentários: ");
            fprintf(fp, "%s", d[i].posts.opinions.comment);
    }
    fclose(fp);
 }


int main()
{
    int code = -1, codePost = -1, codeOpinion = -1, i, resp, optionMenuFirst, returnLogin;

    struct data_devs devs[10000];

    printf("\n\n1- Acessar opções do menu.\n0- Sair.\n\n");
    scanf("%d", &resp);

    if (resp == 1)
    {
        system("clear");

        while (resp != 0)
        {
            printf("\n\n1-  Ainda não possui uma conta? Cadastrar. \n2- Já possui? Faça login\n0- Sair\n");
            fflush(stdin);
            setbuf(stdin, NULL);
            scanf("%i", &optionMenuFirst);

            switch (optionMenuFirst)
            {
            case 1:
                create(devs, &code);
                break;
            case 2:
                login(devs, &code);
                break;

            default:
                printf("\nProcesso finalizado.\n");
                break;
            }
         
            returnLogin = login(devs, &code);
              
            if (returnLogin == 1)
            {
                char option;

                while ((option = Menu(menuMain)) != SAIR) 
                {

                    if ((option == LISTAR) ||
                        (option == CONSULTAR) ||
                        (option == DELETAR) ||
                        (option == CREATEPOST) ||
                        (option == CONSULTPOST) ||
                        (option == UPDATEPOST) ||
                        (option == ADDOPPINION) ||
                        (option == CONSULTOPPINION) ||
                        (option == UPDATEOPPINION) ||
                        (option == SAIR))
                    {
                        switch (option)
                        {
                        case '1':
                            list(devs, &code);
                            break;
                        case '2':
                            consult(devs, &code);
                            break;
                        case '3':
                            delete (devs, &code);
                            break;
                        case '4':
                            create_post(devs, &code, &codePost);
                            break;
                        case '5':
                            post_consult(devs, &code);
                            break;
                        case '6':
                            post_update(devs, &code);
                            break;
                        case '7':
                            create_opinion(devs, &code, &codeOpinion);
                            break;
                        case '8':
                            opinion_consult(devs, &code);
                            break;
                        case '9':
                            opinion_update(devs, &code);
                            break;
                        default:
                            printf("\nProcesso finalizado.\n");
                            break;
                        }
                    }
                    else
                    {
                        printf("Erro.\n");
                    }

                }
                 arq_save(devs, &code);
                 arq_open(devs, &code); 
            }
        }
    }
   
    return 0;
}