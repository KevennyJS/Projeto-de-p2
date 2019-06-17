#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
using namespace std;
int num_user=1,NDU;

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

Data data1, data2; // data1 e variavel para emprestimo e data2 para devolução... ambas fazem parte do mesmo struct DATA

typedef struct {

    char nome[50];
    int cpf;
    char telefone[25];
    char endereco[50];
    int livros_ativos[100];
    int num_livros_ativos;
    int num_livros_reser;
    int livros_reserv[100];
    int dia;
    int mes;
    int ano;

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

void cadastro(Cadastro_Usuario usuario[]); // SOBRECARGA

void cadastro(Cadastro_Livro liv[], int& id_livro); //SOBRECARGA

void exibir (Cadastro_Livro livro[], int id_livro); //SOBRECARGA

void exibir (Cadastro_Usuario usuario[]); //SOBRECARGA

void emprestimo (Cadastro_Livro livro[], int id_livro, Cadastro_Usuario usuario[], Data data1);

void Devolucao (Cadastro_Livro livro[], int id_livro, Cadastro_Usuario usuario[], Data data1, Data data2);

int verificar_usuario (Cadastro_Usuario usuario[], int cpf);

int verificar_livro (Cadastro_Usuario usuario[]);

int verificar_codigo(Cadastro_Livro livro[], int id_livro, int codigo, int& aux2);

void Reserva (Cadastro_Usuario usuario[], Cadastro_Livro livro[], int id_livro);

void reserva_livro(Cadastro_Usuario usuario[], Cadastro_Livro livro[], int id_livro);

void exibir_reserva(Cadastro_Usuario usuario[], Cadastro_Livro livro[], int id_livro);

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
    char escolha_home;

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
                    cadastro(livro, id_livro);
                    system("cls");
                    break;

                case'3':
                    emprestimo(livro, id_livro,usuario, data1);
                    system("cls");
                    break;

                case'4':
                    Devolucao(livro, id_livro, usuario, data1, data2);
                    system("cls");
                    break;

                case'5':
                    Reserva(usuario, livro, id_livro);
                    system("cls");
                    break;

                case'6':
                    cout << endl << "CONSULTA:\n\n";
                    cout<< "1-Livros\n2-Usuários\n\nInforme a opcão desejada: ";
                    cin>> escolha_case6;
                    if(escolha_case6==1){
                            system("cls");
                            exibir(livro, id_livro);
                            system("pause");
                            system("cls");

                    }
                    else if(escolha_case6==2){
                        system("CLS");
                        exibir(usuario);
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

void cadastro(Cadastro_Usuario usuario[]){
    int contador,again,aux;
    char cpf[15];

        contador = num_user-1;
        for(;contador < num_user;contador++) {
            cout << "********** Cadastro Do Usuário **********\n\n";
            cout << "Nome: ";
            fflush(stdin);
            cin.getline(usuario[contador].nome, 50);
            cout << "CPF: ";
            fflush(stdin);
            cin.getline(cpf, 15);
            usuario[contador].cpf = atoi(cpf);
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

void exibir(Cadastro_Usuario usuario[])
{
    int i, cont1, cont2;
            printf("********** Dados dos Usuários **********\n\n");
                for(i=1; i < num_user; i++){
                    printf ("\n");
                    printf("----------Usuário %d----------\n",i);
                    printf("Nome ......: %s\n", usuario[i-1].nome);
                    printf("CPF .......: %d\n", usuario[i-1].cpf);
                    printf("Telefone ..: %s\n", usuario[i-1].telefone);
                    printf("Endereço ..: %s\n", usuario[i-1].endereco);
                    printf ("Livros Ativos: ");
                    for(cont1=1;cont1<=usuario[i-1].num_livros_ativos;cont1++){
                        printf("%d, ", usuario[i-1].livros_ativos[cont1]);
                    }
                }
            printf ("\n");
            system("pause");
            system("CLS");
}

void cadastro(Cadastro_Livro livro[], int& id_livro)
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
                if (strlen(opcao)<5 || strlen(opcao)>5) cout << "Não é possivel cadastrar esse codigo, Tente Outro\n";
            }while(strlen(opcao)<5 || strlen(opcao)>5);
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

void exibir (Cadastro_Livro livro[], int id_livro)
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

void emprestimo (Cadastro_Livro livro[], int id_livro, Cadastro_Usuario usuario[], Data data1){

    int indice, codigo, qtd, cont1, cpf, aux, aux2;

    cout << "\t\t|------------------------------|\n";
    cout << "\t\t| Biblioteca Central da Cidade |\n";
    cout << "\t\t|------------------------------|\n\n";
    cout << "Informe o CPF do Usuário: ";
    cin >> cpf;
    if (verificar_usuario(usuario,cpf)==0){
        cout << "O Usuário não está cadastrado!\n";
        system("pause");
    }
    else if (verificar_usuario(usuario,cpf)==1){
        cout << "Usuário valido!\n\n";
    Sleep(1500);
    exibir(livro, id_livro);
    cout << "Informe a data do empréstimo: ";
    cin >> usuario[NDU].dia >> usuario[NDU].mes >> usuario[NDU].ano;
    cout << usuario[NDU].dia << usuario[NDU].mes << usuario[NDU].ano;
    cout << "Informe o código do livro: ";
    cin >> codigo;
    fflush(stdin);
    fix:
    if (verificar_codigo(livro, id_livro, codigo, aux2)==1)
    {
        for(indice=1; indice<=id_livro; indice++){
            if(aux2==0)
            {
                cout << "Quantidade Indisponível. Informe outro código: ";
                cin >> codigo;
                goto fix;
            }
            else if(codigo==livro[indice].codigo && livro[indice].qtd>0)
            {
                for(cont1=0 ;cont1<num_user;cont1++){
                    if (usuario[cont1].cpf == cpf){
                        aux=usuario[cont1].num_livros_ativos+1;
                        usuario[cont1].livros_ativos[aux] = codigo;
                        livro[indice].qtd--;
                        usuario[cont1].num_livros_ativos++;
                        break;
                    }
                }

                cout << "Empréstimo Realizado com Sucesso!";
                break;
            }
        }
    }
    else
    {
        cout << "Código Inválido. Informe outro código: ";
        cin >> codigo;
        goto fix;
    }
    Sleep(1500);
    }
}

void Devolucao (Cadastro_Livro livro[], int id_livro, Cadastro_Usuario usuario[], Data data1, Data data2)
{
    int cpf,indice;

    cout << "\t\t|------------------------------|\n";
    cout << "\t\t| Biblioteca Central da Cidade |\n";
    cout << "\t\t|------------------------------|\n\n";
    cout << "Informe o CPF do usuário: ";
    cin >> cpf;
    fflush(stdin);
    if (verificar_usuario(usuario, cpf)==0){
        cout << "O Usuário não está cadastrado!\n";
        system("pause");
        exit;
    }
    else if (verificar_usuario(usuario, cpf)==1){
        cout << "Usuário válido!\n\n";
        cout << "PROCESSANDO...\n\n";
        Sleep(2000);
        if (verificar_livro(usuario)==0)
        {
            cout << "O usuário não possui livros ativos\n";
            system("pause");
        }
            else if (verificar_livro(usuario)==1)
            {
                for (indice=0; indice<=num_user;indice++)
                {
                    if(cpf==usuario[indice].cpf)
                        exibir(usuario);
                }
                Sleep(1500);
                system("pause");
            }
        }
}

void Reserva (Cadastro_Usuario usuario[], Cadastro_Livro livro[], int id_livro)
{
    char opcao;

    cout << "\t\t|------------------------------|\n";
    cout << "\t\t| Biblioteca Central da Cidade |\n";
    cout << "\t\t|------------------------------|\n\n";
    cout << "1 - Reservar um Livro" << endl;
    cout << "2 - Consultar Fila de Espera" << endl;
    cout << "3 - Sair" << endl;
    cout << "Informe a opção desejada: ";
    cin >> opcao;
    switch(opcao)
    {
        case'1':
        system("cls");
        reserva_livro(usuario, livro, id_livro);
        system("cls");
        system("pause");
        break;

        case'2':
        exibir_reserva(usuario, livro, id_livro);
        system("cls");
        system("pause");
        break;

        case'3':
        exit;
        break;
    }

}

void reserva_livro(Cadastro_Usuario usuario[], Cadastro_Livro livro[], int id_livro)
{
    int cpf, codigo, i, j, aux;

    cout << "\t\t|------------------------------|\n";
    cout << "\t\t| Biblioteca Central da Cidade |\n";
    cout << "\t\t|------------------------------|\n\n";
    cout << "Informe o CPF do usuario: ";
    cin >> cpf;
    if (verificar_usuario(usuario,cpf)==0){
        cout << "O Usuário não está cadastrado!\n";
        system("pause");
    }
    else if (verificar_usuario(usuario,cpf)==1){
        cout << "Usuário valido!\n\n";
        Sleep(1500);
        exibir(livro, id_livro);
        cout << "Informe o codigo do livro: ";
        cin >> codigo;
            for (i=1; i<=id_livro; i++)
            {
                if(codigo==livro[i].codigo && livro[i].qtd>0)
                {
                    for(j=0 ;j<num_user;j++){
                    if (usuario[j].cpf == cpf){
                        aux=usuario[j].num_livros_reser+1;
                        usuario[j].livros_ativos[aux] = codigo;
                        usuario[j].num_livros_reser++;
                        break;
                        }
                    }
                cout << "Reserva realizada com sucesso!!";
                break;
                }

            }
    }
}

void exibir_reserva(Cadastro_Usuario usuario[], Cadastro_Livro livro[], int id_livro)
{
    int i, j;

        for(i=1; i<=num_user; i++)
        {
            cout << endl << i << "\t\t" << usuario[i-1].cpf << "\t\t";
                for(j=1;j<=usuario[i-1].num_livros_reser;j++){
                    cout << usuario[i-1].livros_reserv[j];
                }
        }
}

int verificar_usuario (Cadastro_Usuario usuario[], int cpf){
    int indice;
        for (indice=0; indice<=num_user; indice++){
            if(cpf==usuario[indice].cpf){
                NDU=indice;
                return 1;
                break;
            }
        }
    return 0;
}

int verificar_livro (Cadastro_Usuario usuario[])
{
    int indice;
        for (indice=0; indice<num_user; indice++)
        {
            if (usuario[indice].num_livros_ativos>0)
                return 1;
                break;
        }
    return 0;
}

int verificar_codigo(Cadastro_Livro livro[], int id_livro, int codigo, int& aux2)
{
    int indice;                                     // A PASSAGEM FOI POR REFERÊNCIA PRA FAZER O TRATAMENTO DA QTD DE LIVROS LOGO
        for (indice=1; indice<=id_livro; indice++)  // AÍ NAO PRECISA CRIAR OUTRA FUNÇÃO PARA ISSO... VEJA LÁ EM EMPRÉSTIMO
        {
            if(codigo==livro[indice].codigo)
            {
                aux2 = livro[indice].qtd;
                return 1;
                break;
            }
        }
        return 0;
}
