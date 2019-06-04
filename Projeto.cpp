#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
using namespace std;
char escolha_home;
int num_user=1;

typedef struct {

    char nome[50];
    char cpf[25];
    char telefone[25];
    char endereco[50];
    char livros_ativos[5];// AVISO! O CODIGO DOS LIVROS DEVEM TER APENAS 5 DIGITOS
}Cadastro_Usuario;

typedef struct
{
    char nome[50];
    int qtd;
    int codigo;
    char fila_espera[50];

}Cadastro_Livro;


//-------------------------------------Prototipo das funções-----------------------------------------------------//

void home_page(Cadastro_Livro livro[], int& id_livro, Cadastro_Usuario usuario[]);

void cadastro(Cadastro_Usuario usuario[], int x);

void cadastro2(Cadastro_Livro liv[], int& id_livro);

void exibir_livros (Cadastro_Livro livro[], int id_livro);

void emprestimo (Cadastro_Livro livro[], int id_livro);

//----------------------------------------------------------------------------------------------------------------//

int main (){

    setlocale(LC_ALL, "portuguese");  // Comando para acentuar tudo q tiver no cout//
    int id_livro=1;
    Cadastro_Livro livro[100];
    Cadastro_Usuario usuario[100];
    home_page(livro, id_livro,usuario);
    return 0;

}

void home_page(Cadastro_Livro livro[],int& id_livro,Cadastro_Usuario usuario[]){
    int escolha_case6;

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
                    cadastro(usuario,1);
                    system("cls");
                    break;

                case'2':
                    cadastro2(livro, id_livro);
                    system("cls");
                    break;

                case'3':
                    emprestimo(livro, id_livro);
                    system("cls");
                    break;

                case'4':


                case'5':


                case'6':
                    cout << endl << "CONSULTA:\n\n";
                    cout<< "1-Livros\n2-Usuários\n\nInforme a opcão desejada: ";
                    cin>> escolha_case6;
                    if(escolha_case6==1){
                            system("cls");
                            exibir_livros(livro, id_livro);
                            system("pause");
                            system("cls");

                    }
                    else if(escolha_case6==2){
                        system("CLS");
                        cadastro(usuario,2);
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
                    cout<< "Escolha uma opcão valida!\n\n";
                }
    }while(escolha_home!= '7');
}

void cadastro(Cadastro_Usuario usuario[], int opcao){
    int contador,i,again;

    if(opcao==1){
        contador = num_user-1;
        for(;contador < num_user;contador++) {
            cout << "********** Cadastro Do Usuário **********\n\n";
            cout << "Nome: ";
            fflush(stdin);
            cin.getline(usuario[contador].nome, 50);
            cout << "CPF: ";
            fflush(stdin);
            cin.getline(usuario[contador].cpf, 25);
            cout << "Telefone: ";
            fflush(stdin);
            cin.getline(usuario[contador].telefone, 25);
            cout << "Endereço: ";
            fflush(stdin);
            cin.getline(usuario[contador].endereco, 50);
            num_user++;contador++;
            cout << "\nCadastrar outro Usuário?\n1 - SIM\n2 - NÃO\n\nInforme a opção: ";
            cin >> again;
            if (again==1) contador--,system("CLS");
        }
            system("cls");
            cout << "\n\nSalvando Dados...";
            Sleep(1500);
    }

    if (opcao==2){
            printf("********** Dados dos Usuários **********\n\n");
                for(i=1; i < num_user; i++){
                    printf("----------Usuário %d----------\n",i);
                    printf("Nome ......: %s\n", usuario[i-1].nome);
                    printf("CPF .......: %s\n", usuario[i-1].cpf);
                    printf("Telefone ..: %s\n", usuario[i-1].telefone);
                    printf("Endereço ..: %s\n", usuario[i-1].endereco);
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
            cout << "---------- Cadastro de Livros["<<id_livro<<"] -----------\n\n";
            fflush(stdin);
            do
            {
                cout << "Código do livro(deve conter 5 dígitos): ";
                cin.getline(opcao, 10);
            }while(strlen(opcao)<5);
            livro[id_livro].codigo = atoi(opcao);
            fflush(stdin);
            cout << "Nome do livro: ";
            cin.getline(livro[id_livro].nome, 50);
            fflush(stdin);
            cout << "Quantidade de exemplares: ";
            cin.getline(opcao, 10);
            livro[id_livro].qtd = atoi(opcao);
            fflush(stdin);
            id_livro++;
            cout << "\nCadastrar outro Livro?\n1 - SIM\n2 - NÃO\n\nInforme a opção: ";
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
        cout << "*********** Livros Cadastrados ***********\n\n";
        cout << endl << "\tNº\t|\tQTD\t|\tCÓDIGO\t |\tNOME\n";
        for (indice=1; indice<id_livro; indice++)
        {
            cout << endl << "\t" << indice << "\t\t" << livro[indice].qtd << "\t\t" << livro[indice].codigo << "\t\t" << livro[indice].nome;
        }
    cout << "\n\n";
}

void emprestimo (Cadastro_Livro livro[], int id_livro)
{
    int indice, codigo, qtd;

    cout << "\t\t|------------------------------|\n";
    cout << "\t\t| Biblioteca Central da Cidade |\n";
    cout << "\t\t|------------------------------|\n\n";
    cout << "LIVROS DISPONÍVEIS:\n";
    exibir_livros(livro, id_livro);
    cout << "Informe o código do livro: ";
    cin >> codigo;
    fflush(stdin);
    fix:
    for(indice=1; indice<id_livro; indice++)
    {
        if(codigo!= livro[indice].codigo)
        {
            cout << "Código Inválido.\nInforme outro código: ";
            cin >> codigo;
            goto fix;
        }
        else if(livro[indice].qtd<1)
        {
            cout << "Quantidade Indisponível.\nInforme outro código: ";
            cin >> codigo;
            goto fix;
        }
        else if(codigo==livro[indice].codigo && livro[indice].qtd>0)
        {
            livro[indice].qtd--;
            cout << "Empréstimo Realizado com Sucesso!";
            break;
        }
    }
    Sleep(1500);
}
