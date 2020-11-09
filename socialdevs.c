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
};

#define SAIR '0'
#define DELETAR '1'
#define LISTAR '2'
#define CONSULTAR '3'


char *menuLogin[] = {
    "\n---- MENU ----\n\n",
    "1. Ainda não possui uma conta? Cadastrar",
    "2. Já possui? Efetuar Login",
    "0. Sair",
    NULL};

char *menuMain[] = {
    "\n---- MENU ----\n\n",
    "1. Listar todos os desenvolvedores",
    "3. Consultar um desenvolvedor",
    "4. Deletar um desenvolvedor",
    "0. Sair",
    NULL};

char Menu(char *options[]){ //Necessário para selecionar as opções do menu
  int i;
  char optionChoose;

  system("clear");

  fflush(stdin);
  setbuf(stdin, NULL);

  while(1){ //pois o usuário só pode escolher uma opção
  for(i=0; options[i]!=NULL; i++){ //percorre o vetor do menu e não mostra a opção null
  printf("%s\n\n",options[i]); //mostra as opções na tela
  }

  printf("\n\nOpção escolhida: ");
  fflush(stdin);
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

    /* if (!try)
        {
            printf("Número máximo de tentativas alcançado! \n\nAperte enter ou qualquer tecla para retornar ao menu.\n");
            fflush(stdin);
            setbuf(stdin, NULL);

            scanf("%c", &t);
        }*/


    if (validate = 1)
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
    d[*code].status = 0;

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
    int i, ids, resp, n = 0;
    char t, dev[50];

    system("CLS");
    printf("\n--- CONSULTA ---\n\n");
    printf("\nDeseja consultar pelo id ou pelo nome de usu�rio?\n");
    printf("\nDigite:\n1- Id.\n2- Usu�rio\n");
    scanf("%d", &resp);
    switch (resp)
    {
    case 1: //caso escolha consultar pelo id
        system("clear");
        printf("\nInsira o id do DEV a ser consultado:\n");
        scanf("%d", &ids);
        for (i = 0; i <= *code; i++) //percorre o vetor de devs
        {
            if (ids == d[i].id)
            {
                printf("\nID: %d\nNome: %sUsuário: %sEmail: %sPassword: %sBio: %s", d[i].id, d[i].name, d[i].user, d[i].email, d[i].password, d[i].bio);
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

int main()
{
    int code = -1, i, resp, respLogin, optionMenuFirst, returnLogin;

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
           // char menu;

          // while ((menu = Menu(menuLogin)) != SAIR) {

            switch (optionMenuFirst)
            {
            case 1:
                login(devs, &code);
                break;
            case 2:
                create(devs, &code);
                break;

            default:
                printf("\nProcesso finalizado.\n");
                break;
            }
          // }
        

       returnLogin = login(devs, &code);

       if (returnLogin = 1)
        {
            char option;
            while ((option = Menu(menuMain)) != SAIR) //Enquanto o usu�rio n�o quiser sair, pois em todo final de processo/fun��o, ele pode clicar em sair.
            {
                /*printf("\n---- MENU ----\n\n");
                resp = -1;
                printf("\n1- Cadastro\n2- Remocao\n3- Listagem\n4- Consulta\n5- Atualizacao de emprestimo\n0- Sair\n");
                fflush(stdin);
                setbuf(stdin, NULL);
                scanf("%d", &resp); //Lê a função que o usuário queira que aconteça*/

                if ((option == LISTAR) || (option == CONSULTAR) || (option == DELETAR) || (option == SAIR))
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
