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
    int status;
    char title[50];
    char image[50];
    char description[50];
    int code_post;
    int likes;
    int dislikes;
    int add[40];
};

#define SAIR '0'
#define DELETAR '1'
#define LISTAR '2'
#define CONSULTAR '3'
#define CREATEPOST '4'
#define CONSULTPOST '5'
#define UPDATEPOST '6'
#define ADDCONNECTION '7'
#define CONSULTCONNECTION '8'


char *menuLogin[] = {
    "\n---- MENU ----\n\n",
    "1. Ainda não possui uma conta? Cadastrar",
    "2. Já possui? Efetuar Login",
    "0. Sair",
    NULL};

char *menuMain[] = {
    "\n---- MENU ----\n\n",
    "1. Listar todos os desenvolvedores",
    "2. Consultar um desenvolvedor",
    "3. Deletar um desenvolvedor",
    "4. Criar um post",
    "5. Consultar post",
    "6. Atualizar post",
    "7. Criar uma conexão",
    "8. Listar conexões",
    "0. Sair",
    NULL};

char Menu(char *options[]){ //Necessário para selecionar as opções do menu
  int i;
  char optionChoose;

  system("clear");

  setbuf(stdin, NULL);

  while(1){ //pois o usuário só pode escolher uma opção
  for(i=0; options[i]!=NULL; i++){ //percorre o vetor do menu e não mostra a opção null
  printf("%s\n\n",options[i]); //mostra as opções na tela
  }

  printf("\n\nOpção escolhida: ");
  setbuf(stdin, NULL);
  optionChoose = getchar(); //le a opção
 
  
  for(i=0; options[i]!= NULL; i++){ //percorre o vetor 
  if(options[i][0]==optionChoose){
    return optionChoose;
    }
   }
  }
  
}


int login(struct data_devs *d, int *code)
{
    int i, validate = 0,try= 5, b = 1;
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
                try--;
                b = 1;
                validate = 0;
            }
        } while (b && try); //diferente de 0
    }

    if (validate == 1)
    {
         Menu(menuMain);
         return 1;
    }
    system("clear");
}

void create(struct data_devs *d, int *code)
{
    char t; //s�o pra definir uma tecla de atalho

    system("clear");
    printf("\n--- CADASTRO DE DEVS ---\n\n");
    fflush(stdin);
    setbuf(stdin, NULL);


    (*code)++; //pega a posi��o do dev

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

    d[*code].id = (*code) + 1; //soma 1 pra n�o pegar o mesmo numero anterior

    printf("\n\nCadastro realizado com sucesso.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%c", &t); //le a tecla que o usu�rio digitar
    system("clear");
}

void delete (struct data_devs *d, int *code)
{
    int i, j, idRemove;
    char t;

    //system("CLS");
    system("clear");

    printf("\n--- REMOCAO DE DEV---\n\n");
    fflush(stdin);
    printf("Qual o id do dev que deseja excluir?\n");
    scanf("%d", &idRemove);

    if (*code >= 0)
    {                                //se existir devs cadastrados
        for (i = 0; i <= *code; i++) //percorre o vetor de devs para achar o c�digo
        {
            if (d[i].id == idRemove)
            { //se o código da vez que estiver no for, for igual ao c�digo que o usu�rio digitou
                for (j = i; j < *code; j++)
                {
                    d[j] = d[j + 1];
                    d[j].id = d[j + 1].id - 1; //serve para atualizar o codigo dos devs op��es um ser removido, para não dar problema com o cadastro de novos devs depois
                }

                (*code)--; //pra ir diminuindo no for
            }
        }
    }
    printf("\n\nDev removido.\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
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
    case 1: //caso escolha consultar pelo id
        system("clear");
        printf("\nInsira o id do DEV a ser consultado: ");
        scanf("%d", &ids);
        for (i = 0; i <= *code; i++) //percorre o vetor de devs
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

    case 2: //caso escolha consultar pelo usu�rio;
        system("clear");
        printf("\nInsira o nome do usuário: \n\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        fgets(dev, 50, stdin);
        for (i = 0; i <= *code; i++) //percorre o vetor de devs
        {
            if (strcmp(dev, d[i].user) == 0)
            {
                n = 1;
                printf("ID: %d\nNome: %sUsu�rio: %sEmail: %sPassword: %sBio: %s",  d[i].id, d[i].name, d[i].user, d[i].email, d[i].password, d[i].bio);
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

    default: //caso n�o escolha nenhuma das op��es.
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

void create_post(struct data_devs *d, int *code, int *codePost){
        int i, n = 0, id;
        char t, dev[50];
        system("clear");
        printf("\n--- POST ---\n\n");
        printf("\nInsira o ID do usuário: \n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%i", &id);
        for (i = 0; i <= *code; i++) //percorre o vetor de devs
        {
            if (d[i].id == id)
            {  
               n = 1;
               fflush(stdin);
               setbuf(stdin, NULL);
               printf("Digite o título do post: ");
               fgets(d[i].title, 10, stdin); 
               printf("Digite a url da imagem a ser colocada no post: ");
               fgets(d[i].image, 40, stdin);
               printf("Faça uma breve descrição sobre o post: ");
               fgets(d[i].description, 100, stdin);
               
               d[*codePost].code_post = (*codePost) + 1;

            }
        }
        if (n)
        {
            printf("\nPost publicado com sucesso!\n\n");
        }else{
            printf("ID inexistente.\n");
        }
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%c", &t);
        system("clear");
}

int likes(struct data_devs *d, int *code, int *codePost){
      int i, cont=0, idPost, n; 
      char t; 
      system("clear");
       /* printf("\nInsira codigo do post: \n\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%i", &idPost);
        for (i = 0; i <= *code; i++) //percorre o vetor de devs
        {
            if (idPost==d[i].code_post)
            {
               n=1; */
               cont=cont+1;
             /*}
            }
        
        if (!n)
        {
            printf("Post inexistente.\n");
        }*/

        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%c", &t);
        system("clear");
        return cont; 
}

int dislikes(struct data_devs *d, int *code, int *codePost){
    int i,  n, cont2=0;
    char t; 
    system("clear");
        /*printf("\nInsira o codigo do post: \n\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%i", &codePost); 
        for (i = 0; i <= *code; i++) //percorre o vetor de devs
        {
            if (idPost==d[i].code_post)
            {
                n=1;*/
               cont2=cont2+1; 
            /*}
        }
        if (!n)
        {
            printf("Post inexistente.\n");
        }*/

        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%c", &t);
        system("clear");
        return cont2;
}

void post_consult(struct data_devs *d, int *code, int like, int dislike){
        int i, n = 0,resp=0, id;
        char t, dev[50];
        system("clear");
        printf("\n--- POST DEV ---\n\n");
        printf("\nInsira o ID do dev: \n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%i", &id);
        for (i = 0; i <= *code; i++) //percorre o vetor de devs
        {
            if (d[i].id == id)
            { 
              n=1;                
              printf("\n -Código do post: %i\n\n -Título do post: %s\n -URL da imagem: %s\n -Descrição: %s\n -Likes: %i\n\n -Deslikes: %i\n\n",  d[i].code_post, d[i].title, d[i].image, d[i].description, d[i].likes, d[i].dislikes);
              printf("O que achou do post?"); 
              printf("\n\n1-Like\n\n2-Deslike\n");
              scanf("%i", &resp); 
              if(resp==1){
                 d[i].likes = like;
              }else if(resp==2){
                 d[i].dislikes = dislike;   
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
}

void post_update(struct data_devs *d, int *code){
   int i, j, idPost, n;
   char t;
    system("clear");
    printf("\n--- ATUALIZAR POST ---\n\n");

    printf("\nInsira o ID do post que deseja atualizar: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &idPost);

    for(i=0; i <= *code; i++){
      if(d[i].code_post == idPost){
            n=1;
            fflush(stdin);
            setbuf(stdin, NULL);
            printf("Digite o título a ser colocado no post: ");
            fgets(d[i].title, 50, stdin);
            printf("Digite a url da imagem a ser colocada no post: ");
            fgets(d[i].image, 50, stdin);
            printf("Faça uma breve descrição sobre o post: ");
            fgets(d[i].description, 100, stdin);
      }
    }
      if(!n){
        printf("ID DO POST INEXISTENTE!!");
      }else{
        printf("POST ATUALIZADO!");
      }
      printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
      fflush(stdin);
      setbuf(stdin, NULL);
      scanf("%c", &t);
      system("clear");
}

void create_connection(struct data_devs *d, int *code){
   int i, id,j, n;
   char t;
    system("clear");
    printf("\n--- CRIAR UMA CONEXÃO ---\n\n");

    printf("\nInsira o ID do dev que deseja criar uma conexão: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &id);
   for(i=0; i<=*code; i++){
       if(d[i].id == id){
           for(j=0; j<40; j++){
               n=1;
             d[i].add[j] = id;
           }
       }
   }

   if(!n){
       printf("Id inexistente");
   }else{
      printf("Conexão adicionada!!");
   }

      printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
      fflush(stdin);
      setbuf(stdin, NULL);
      scanf("%c", &t);
      system("clear");
}

void consult_connection(struct data_devs *d, int *code){
    int i, j, id, n;
    char t;

    printf("\nInsira o ID do dev que deseja ver a conexão: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%i", &id);

    for(i=0; i<=*code; i++){
        for(j=0; j<40; j++){
            if(d[i].add[j] == id){
                n=1;
               printf("Nome: %s Usuário: %s Bio: %s Status: %i", d[i].name, d[i].user, d[i].bio, d[i].status);
               /* name=d[i].name;
                user=d[i].user;
                bio=d[i].bio;*/
            }
        }
    }

    if(!n){
           printf("Id inexistente");   
    }

     printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
      fflush(stdin);
      setbuf(stdin, NULL);
      scanf("%c", &t);
      system("clear");
} 

int main()
{
    int code = -1, codePost = -1, i, resp, respLogin, optionMenuFirst, returnLogin, like, dislike;

    struct data_devs devs[10000];

    printf("\n\n1- Acessar opções do menu.\n0- Sair.\n\n");
    scanf("%d", &resp);

    if (resp == 1) //1 = Acessa menu
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
           
            while ((option = Menu(menuMain)) != SAIR) //Enquanto o usu�rio n�o quiser sair, pois em todo final de processo/fun��o, ele pode clicar em sair.
            {
             
                if ((option == LISTAR) || 
                (option == CONSULTAR) || 
                (option == DELETAR) ||
                (option == CREATEPOST)|| 
                (option == CONSULTPOST) || 
                (option == UPDATEPOST) ||
                (option == ADDCONNECTION) ||
                (option == CONSULTCONNECTION) ||
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
                    create_post (devs, &code, &codePost); 
                    break;
                 case '5':
                     post_consult(devs, &code, like=likes(devs, &code, &codePost), dislike=dislikes(devs, &code, &codePost));
                     break;
                case '6':
                     post_update(devs, &code);
                     break;
                 case '7':
                     create_connection(devs, &code);
                     break;
                  case '8':
                     consult_connection(devs, &code);
                     break;
                default:
                    printf("\nProcesso finalizado.\n");
                    break;
                }
               }
                else
                {
                    printf("Erro.\n");
                    system("PAUSE");
                    getchar();
                }
            }
        }
      }
    }

    return 0;
}
