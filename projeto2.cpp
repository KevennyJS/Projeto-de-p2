#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
using namespace std;
char escolha_home;
int num_user;

struct Cadastro_Usuario{

    char nome[50];
    char cpf[25];
    char telefone[25];
    char endereco[50];
};

typedef struct
{
    char nome[50];
    char qtd[10];
    char codigo[10];
}Cadastro_Livro;

Cadastro_Usuario usuario[100];
Cadastro_Livro livro[100];

//-------------------------------------Prototipo das fun��es-----------------------------------------------------//

void home_page();

void cadastro(Cadastro_Usuario usu);

void cadastro2(Cadastro_Livro liv);

//----------------------------------------------------------------------------------------------------------------//

int main (){

    setlocale(LC_ALL, "portuguese");  // Comando para acentuar tudo q tiver no cout//
    home_page();
    return 0;

}

void home_page(){
    Cadastro_Usuario user;
    Cadastro_Livro book;
    char opcao;
    int escolha_case6,contador;
    struct Cadastro_Usuario usuario;

    do
    {
        cout << "\t\t|------------------------------|\n";
        cout << "\t\t| Biblioteca Central da Cidade |\n";
        cout << "\t\t|------------------------------|\n\n";
        cout << "1- Cadastrar Usuario\n";
        cout << "2- Cadastrar livro\n";
        cout << "3- Empr�stimo\n";
        cout << "4- Devolu��o\n";
        cout << "5- Reserva\n";
        cout << "6- Consultar Usu�rio ou Livro\n";
        cout << "7- Sair\n\n";
        cout << "Informe a opcao desejada: ";
        cin >> escolha_home;
        system("cls");

            switch (escolha_home){

                case'1':
                    cadastro(user);
                    system("cls");
                    break;

                case'2':
                    cadastro2(book);
                    system("cls");
                    break;

                case'3':


                case'4':


                case'5':


                case'6':// Estou resolvendo isso Ass: Kevenny
                    cout<< "1-Livros\n2-Usuarios\nInforme a opcao desejada: ";
                    cin>> escolha_case6;
                    if(escolha_case6==1){

                    }
                    else if(escolha_case6==2){
                        for(contador=1;contador<=num_user;contador++){
                            printf("----------Usuario %d----------\n",contador);
                            printf("Nome ...........: %s\n", usuario.nome);
                            printf("CPF .....: %s\n", usuario.cpf);
                            printf("Telefone ...: %s\n" , usuario.telefone);
                            printf("Endereco do usuario ...: %s\n" , usuario.endereco);
                        }
                    }
                    else{
                        cout<< "Escolha invalida!\n\n";
                        break;
                    }

                case'7':
                    break;

                default:
                    system("CLS");
                    cout<< "Escolha uma opcao valida!\n\n";
                }
    }while(opcao!= '7');
}

void cadastro(Cadastro_Usuario usuario){
int contador;
        for (contador=1; contador<=1; contador++)
        {
              printf("\n---------- Cadastro de usuario -----------\n\n\n");
              //fgets(variavel, tamanho da string, entrada)
              fflush(stdin);
              printf("Nome do usuario: ");
              gets(usuario.nome);
              fflush(stdin);
              printf("CPF: ");
              gets(usuario.cpf);
              fflush(stdin);
              printf("Telefone: ");
              gets(usuario.telefone);
              fflush(stdin);
              printf("Endereco do usuario: ");
              gets(usuario.endereco);
              fflush(stdin);
              num_user++;
        }
        cout << "\n\nSalvando Dados...";
        Sleep(1500);
}

void cadastro2(Cadastro_Livro liv)
{
    int indice;
        for(indice=1; indice<=2; indice++)
        {
            fflush(stdin);
            cout << "Atribua um codigo para o livro: ";
            cin.getline(livro[indice].codigo, 10);
            cout << "Informe o nome do livro: ";
            cin.getline(livro[indice].nome, 50);
            cout << "Informe a quantidade de exemplares: ";
            cin.getline(livro[indice].qtd, 10);
        }
        cout << "\n\nSalvando Dados...";
        Sleep(1500);
}
