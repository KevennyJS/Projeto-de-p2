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


//-------------------------------------Prototipo das funções-----------------------------------------------------//

void home_page(Cadastro_Livro livro[], int& id_livro);

void cadastro(Cadastro_Usuario usu);

void cadastro2(Cadastro_Livro liv[], int& id_livro);

void exibir_livros (Cadastro_Livro livro[], int id_livro);

//----------------------------------------------------------------------------------------------------------------//

int main (){

    setlocale(LC_ALL, "portuguese");  // Comando para acentuar tudo q tiver no cout//
    int id_livro=1;
    Cadastro_Livro livro[100];

    home_page(livro, id_livro);
    return 0;

}

void home_page(Cadastro_Livro livro[],int& id_livro){
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
        cout << "3- Empréstimo\n";
        cout << "4- Devolução\n";
        cout << "5- Reserva\n";
        cout << "6- Consultar Usuário ou Livro\n";
        cout << "7- Sair\n\n";
        cout << "Informe a opcao desejada: ";
        cin >> escolha_home;
        system("cls");

            switch (escolha_home){

                case'1':
                    cadastro(usuario);
                    system("cls");
                    break;

                case'2':
                    cadastro2(livro, id_livro);
                    system("cls");
                    break;

                case'3':


                case'4':


                case'5':


                case'6':// Estou resolvendo isso Ass: Kevenny
                    cout<< "1-Livros\n2-Usuarios\n\nInforme a opcao desejada: ";
                    cin>> escolha_case6;
                    if(escolha_case6==1){
                            exibir_livros(livro, id_livro);

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

void cadastro2(Cadastro_Livro livro[], int& id_livro)
{
        int aux;
        char opcao[10];

        do
        {
            cout << "\n---------- Cadastro de Livros["<<id_livro<<"] -----------\n\n\n";
            fflush(stdin);
            cout << "Código do livro: ";
            cin.getline(livro[id_livro].codigo, 10);
            fflush(stdin);
            cout << "Nome do livro: ";
            cin.getline(livro[id_livro].nome, 50);
            fflush(stdin);
            cout << "Quantidade de exemplares: ";
            cin.getline(livro[id_livro].qtd, 10);
            fflush(stdin);
            id_livro++;
            cout << "\nQuer fazer outro cadastro?\n1 - Sim\n2 - Não\n\nInforme a opção: ";
            cin.getline(opcao, 10);
            aux = atoi(opcao);
            system("cls");
        }while(aux==1);
            cout << "\n\nSalvando Dados...";
            Sleep(1500);
}

void exibir_livros (Cadastro_Livro livro[], int id_livro)
{
    int indice;
        for (indice=1; indice<id_livro; indice++)
        {
            cout << "\n\nLivro["<<indice<<"]\n";
            cout << endl << "Código do Livro: " << livro[indice].codigo;
            cout << endl << "Nome do Livro: " << livro[indice].nome;
            cout << endl << "Qauntidade de Exemplares: " << livro[indice].qtd;
        }
    cout << "\n\n";
    system("pause");
    system("cls");
}
