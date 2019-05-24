#include <iostream>
#include <stdio.h>
using namespace std;
int escolha_home;

struct Cadastro_usuario{

char nome[25];
int cpf;
int telefone;
char endereco[30];

};

int home_page(){
cout<<"1-Cadastrar Usuario\n";
cout<<"2-Cadastrar livro\n";
cout<<"3-Emprestimo\n";
cout<<"4-Devolucao\n";
cout<<"5-Reserva\n\n";
cout<<"Escolha: ";
scanf("%d",&escolha_home);
}

int acoes(){
    switch (escolha_home){
        case'1':


        case'2':


        case'3':


        case'4':


        case'5':


        default:
            system("CLS");
            cout<< "Escolha uma opcao valida!\n";
            home_page();
        }
}

int main (){
home_page();

    system ("pause");
}
