#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
using namespace std;
char escolha_home;
int num_user=1;

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


//-------------------------------------Prototipo das fun��es-----------------------------------------------------//

void home_page(Cadastro_Livro livro[], int& id_livro);

void cadastro(int x);

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
    int escolha_case6;
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
                    cadastro(1);
                    system("cls");
                    break;

                case'2':
                    cadastro2(livro, id_livro);
                    system("cls");
                    break;

                case'3':


                case'4':


                case'5':


                case'6':
                    cout<< "1-Livros\n2-Usu�rios\n\nInforme a opc�o desejada: ";
                    cin>> escolha_case6;
                    if(escolha_case6==1){
                            exibir_livros(livro, id_livro);

                    }
                    else if(escolha_case6==2){
                        system("CLS");
                        cadastro(2);
                    }
                    else{
                        cout<< "Escolha invalida!\n\n";
                        break;
                    }

                case'7':
                    exit;
                    break;

                default:
                    system("CLS");
                    cout<< "Escolha uma opc�o valida!\n\n";
                }
    }while(escolha_home!= '7');
}

void cadastro(int opcao){
    int contador,i,again;
    struct Cadastro_Usuario usuario[100];

    if(opcao==1){
        contador = num_user-1;
        for(;contador < num_user;contador++) {
            cout << "********** Cadastro Do Usu�rio **********\n\n";
            cout << "Nome: ";
            fflush(stdin);
            cin.getline(usuario[contador].nome, 50);
            cout << "CPF: ";
            fflush(stdin);
            cin.getline(usuario[contador].cpf, 25);
            cout << "Telefone: ";
            fflush(stdin);
            cin.getline(usuario[contador].telefone, 25);
            cout << "endere�o: ";
            fflush(stdin);
            cin.getline(usuario[contador].endereco, 50);
            num_user++;contador++;
            cout << "\nCadastrar outro Usu�rio?\n1-SIM\n2-N�O\nEscolha: ";
            cin >> again;
            if (again==1) contador--,system("CLS");
        }
    }

    if (opcao==2){
            printf("********** Dados dos Usu�rios **********\n\n");
                for(i=1; i < num_user; i++){
                    printf("----------Usu�rio %d----------\n",i);
                    printf("Nome ......: %s\n", usuario[i-1].nome);
                    printf("CPF .......: %s\n", usuario[i-1].cpf);
                    printf("Telefone ..: %s\n", usuario[i-1].telefone);
                    printf("Endere�o ..: %s\n", usuario[i-1].endereco);
                }
            system("pause");
            system("CLS");
    }
}

void cadastro2(Cadastro_Livro livro[], int& id_livro)
{
        int aux;
        char opcao[10];

        do
        {
            cout << "\n---------- Cadastro de Livros["<<id_livro<<"] -----------\n\n\n";
            fflush(stdin);
            cout << "C�digo do livro: ";
            cin.getline(livro[id_livro].codigo, 10);
            fflush(stdin);
            cout << "Nome do livro: ";
            cin.getline(livro[id_livro].nome, 50);
            fflush(stdin);
            cout << "Quantidade de exemplares: ";
            cin.getline(livro[id_livro].qtd, 10);
            fflush(stdin);
            id_livro++;
            cout << "\nQuer fazer outro cadastro?\n1 - Sim\n2 - N�o\n\nInforme a op��o: ";
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
            cout << endl << "C�digo do Livro: " << livro[indice].codigo;
            cout << endl << "Nome do Livro: " << livro[indice].nome;
            cout << endl << "Qauntidade de Exemplares: " << livro[indice].qtd;
        }
    cout << "\n\n";
    system("pause");
    system("cls");
}
