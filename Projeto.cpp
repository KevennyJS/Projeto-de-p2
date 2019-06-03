#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
using namespace std;
char escolha_home;
int num_user=1;

struct Cadastro_Usuario{

    char nome[50];
    char cpf[25];
    char telefone[25];
    char endereco[50];
    char livros_ativos[5];// AVISO! O CODIGO DOS LIVROS DEVEM TER APENAS 5 DIGITOS
};

typedef struct
{
    char nome[50];
    int qtd;
    int codigo;
    char fila_espera[50];

}Cadastro_Livro;


//-------------------------------------Prototipo das fun��es-----------------------------------------------------//

void home_page(Cadastro_Livro livro[], int& id_livro);

void cadastro(int x);

void cadastro2(Cadastro_Livro liv[], int& id_livro);

void exibir_livros (Cadastro_Livro livro[], int id_livro);

void emprestimo (Cadastro_Livro livro[], int id_livro);

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
                    emprestimo(livro, id_livro);
                    system("cls");
                    break;

                case'4':


                case'5':


                case'6':
                    cout << endl << "CONSULTA:\n\n";
                    cout<< "1-Livros\n2-Usu�rios\n\nInforme a opc�o desejada: ";
                    cin>> escolha_case6;
                    if(escolha_case6==1){
                            system("cls");
                            exibir_livros(livro, id_livro);
                            system("pause");
                            system("cls");

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
            cout << "Endere�o: ";
            fflush(stdin);
            cin.getline(usuario[contador].endereco, 50);
            num_user++;contador++;
            cout << "\nCadastrar outro Usu�rio?\n1 - SIM\n2 - N�O\n\nInforme a op��o: ";
            cin >> again;
            if (again==1) contador--,system("CLS");
        }
            system("cls");
            cout << "\n\nSalvando Dados...";
            Sleep(1500);
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
            cout << "---------- Cadastro de Livros["<<id_livro<<"] -----------\n\n";
            fflush(stdin);
            cout << "C�digo do livro: ";
            cin.getline(opcao, 10);
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
            cout << "\nCadastrar outro Livro?\n1 - SIM\n2 - N�O\n\nInforme a op��o: ";
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
        cout << "*********** Dados dos Livros ***********\n\n";
        for (indice=1; indice<id_livro; indice++)
        {
            cout << "----------Livro " << indice << "----------\n";
            cout << endl << "Quantidade..: " << livro[indice].qtd;
            cout << endl << "C�digo......: " << livro[indice].codigo;
            cout << endl << "Nome........: " << livro[indice].nome << endl;
        }
    cout << "\n\n";
}

void emprestimo (Cadastro_Livro livro[], int id_livro)
{
    int indice, codigo, qtd;

    cout << "\t\t|------------------------------|\n";
    cout << "\t\t| Biblioteca Central da Cidade |\n";
    cout << "\t\t|------------------------------|\n\n";
    cout << "LIVROS DISPON�VEIS:\n";
    exibir_livros(livro, id_livro);
    cout << "Informe o c�digo do livro: ";
    cin >> codigo;
    fflush(stdin);
    fix:
    for(indice=1; indice<id_livro; indice++)
    {
        if(codigo!= livro[indice].codigo)
        {
            cout << "C�digo Inv�lido.\nInforme outro c�digo: ";
            cin >> codigo;
            goto fix;
        }
        else if(livro[indice].qtd<1)
        {
            cout << "Quantidade Indispon�vel.\nInforme outro c�digo: ";
            cin >> codigo;
        }
        else if(codigo==livro[indice].codigo && livro[indice].qtd>0)
        {
            livro[indice].qtd--;
            cout << "Empr�stimo Realizado com Sucesso!";
            break;
        }
    }
    Sleep(1500);
}
