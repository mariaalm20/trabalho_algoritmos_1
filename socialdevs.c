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

void create(struct data_devs *d, int *code)
{
    char t; //são pra definir uma tecla de atalho

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

    printf("\nUsuÃ¡rio:\n");
    fgets(d[*code].user, 50, stdin); 
    fflush(stdin);
    setbuf(stdin,NULL);

    printf("\nFaÃ§a um pequeno resumo sobre seu trabalho:\n");
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
            if(d[i].id == idRemove){  //se o cÃ³digo da vez que estiver no for, for igual ao código que o usuário digitou
                for (j = i; j < *code; j++)
                {
                    d[j] = d[j+1];
                    d[j].id=d[j+1].id-1;  //serve para atualizar o codigo dos devs opções um ser removido, para nÃ£o dar problema com o cadastro de novos devs depois
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
}

void list(struct data_devs *d, int *code){
	
	int i,cod,n=0;
	char t;
	system("clear");
    printf("\n--- LISTAGEM DE DEVS CADASTRADOS ---\n\n");
    
    for(i=0; i<= *code; i++)
	{
    	printf("\n\tNome: %s\n\Usuário: %s\n\tEmail: %s\n\tBio: %s\n", d[i].name, d[i].user, d[i].id, d[i].email, d[i].password, d[i].bio);
    	 if(d[i].status==0)
		 {
    	 	printf("Status: Ativo\n");
		 }else{
		 	printf("Status: Offline\n");
		 }
		 printf("Para saber o id e a senha de cada usuário digite o codigo de acesso: "); //codigo de acesso é 1234.
		 scanf("%i", &cod);
		 n=1;
    	 if(cod==1234)
		 {
    	 	printf("\n\tID: %i\n\tPassword: %s", d[i].id, d[i].password);
		 }
	}
	     if(!n)
		 {
	     	printf("Codigo de acesso invalido.");
		 }
	printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
    fflush(stdin);
    setbuf(stdin,NULL);
    scanf("%c",&t);
	system("clear");
	
}

void consult(struct data_devs *d, int *code)
{
    int i, ids, resp, n=0;
    char t, dev[50];

    system("CLS");
    printf("\n--- CONSULTA ---\n\n");
    printf("\nDeseja consultar pelo id ou pelo nome de usuário?\n");
    printf("\nDigite:\n1- Id.\n2- Usuário\n");
    scanf("%d", &resp);
    switch(resp){
    case 1: //caso escolha consultar pelo id
        system("clear");
        printf("\nInsira o id do DEV a ser consultado:\n\n");
        scanf("%d", &ids);
        for(i=0; i <= *code; i++) //percorre o vetor de devs
        {
            if(ids == d[i].id) 
            {   
                printf("\n\tNome: %s\n\Usuário: %s\n\tID: %d\n\tEmail: %s\n\tPassword: %i\n\tBio:\n\t", d[i].name, d[i].user, d[i].id, d[i].email, d[i].password, d[i].bio);
                n=1; 
                if(d[i].status==0) 
                {
                    printf("Status: Online");
                }
                else if (d[i].status==1)
                {
                    printf("Status: Offline");
                }
            }
	    }
	    if(!n){
        	printf("ID inexistente.\n");
			
		}
       
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%c", &t);
        system("clear");
    break;

    case 2: //caso escolha consultar pelo usuário;
        system("clear");
        printf("\nInsira o nome do usuário apenas em letras minusculas: \n\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        fgets(dev, 50, stdin);
        for(i=0; i <= *code; i++) //percorre o vetor de devs
        {
            if(strcmp(dev, d[i].user) == 0) 
            {
            	n=1;
                printf("\n\tNome: %s\n\Usuário: %s\n\tID: %d\n\tEmail: %s\n\tPassword: %i\n\tBio:\n\t", d[i].name, d[i].user, d[i].id, d[i].email, d[i].password, d[i].bio);
                if(d[i].status == 0) 
                {
                    printf("Status: Online");
                }
                else if (d[i].status == 1)
                {
                    printf("Status: Offline");
                }
            }
        }
        if (!n){ 
            printf("Usuário inexistente.\n");
        }
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%c", &t);
        system("clear");
    break;

    default://caso não escolha nenhuma das opções. 
        system("CLS");
        printf("\nOpcao invalida.\n");
        printf("\n\nAperte enter ou qualquer tecla seguida por enter para retornar ao menu.\n");
        fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%c", &t);
        system("clear");
    break;
    }
	
}


int main(){
    int code = -1, i, resp;

    struct data_devs devs[10000];


    printf("\n\n1- Acessar opÃ§Ãµes do menu.\n0- Sair.\n\n");
    scanf("%d", &resp);

    if (resp == 1) //1 = Acessa menu
    {
        system("clear");
        while(resp != 0) //Enquanto o usuário não quiser sair, pois em todo final de processo/função, ele pode clicar em sair.
        {
            printf("\n---- MENU ----\n\n");
            resp = -1;
            printf("\n1- Cadastro\n2- Remocao\n3- Listagem\n4- Consulta\n5- Atualizacao de emprestimo\n0- Sair\n");
            fflush(stdin);
            setbuf(stdin,NULL);
            scanf("%d", &resp); //LÃª a funÃ§Ã£o que o usuÃ¡rio queira que aconteÃ§a

            if ((resp == 1) || (resp == 2) || (resp == 3) || (resp == 4) || (resp == 5) || (resp == 0))
            {
                switch(resp){
                case 1:
                    create(devs, &code); //se for cadastro. Livro Ã© equivalente ao ponteiro l e cont ao ponteiro cont. Precisa passar eles como parametro
                break;
                case 2:
                    delete(devs, &code); //mesma coisa que o de cima
                break;
                case 3:
                    list(devs, &code);
                break;
                case 4:
                    consult(devs, &code);
                break;
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
