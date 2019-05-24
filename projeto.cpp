#include <iostream>
#include <stdio.h>
using namespace std;
char escolha_home;

struct cadastro_usuario{

char nome[25];
int cpf;
int telefone;
char endereco[30];

};

int cadastro(){
    int num_user;
    struct cadastro_usuario reg[num_user];
        int nome,cpf,telefone,endereco;
        cout<<"Nome: ";
        cin>>reg[num_user].nome;
        fflush(stdin);
        cout<<"CPF: ";
        cin>>reg[num_user].cpf;
        fflush(stdin);
        cout<<"Telefone: ";
        cin>>reg[num_user].telefone;
        fflush(stdin);
        cout<<"Endereço: ";
        cin>>reg[num_user].endereco;
        fflush(stdin);
        num_user +1;
}


int home_page(){
cout<<"1-Cadastrar Usuario\n";
cout<<"2-Cadastrar livro\n";
cout<<"3-Emprestimo\n";
cout<<"4-Devolucao\n";
cout<<"5-Reserva\n\n";
cout<<"Escolha: ";
cin>>escolha_home;

    switch (escolha_home){

        case'1':
        cadastro();

        case'2':


        case'3':


        case'4':


        case'5':


        default:
            system("CLS");
            cout<< "Escolha uma opcao valida!\n\n";
            home_page();
        }
}

int main (){
home_page();

    system ("pause");
}
