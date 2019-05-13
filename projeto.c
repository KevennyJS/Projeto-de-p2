#include <stdio.h>

int escolha_home;
int home_page(){
printf("1-Cadastrar Usuario\n");
printf("2-Cadastrar livro\n");
printf("3-Emprestimo\n");
printf("4-Devolucao\n");
printf("5-Reserva\n\n");
printf("Escolha: ");
scanf("%d",&escolha_home);
}

void acoes(){
    if(escolha_home==1){

    }
    else if(escolha_home==2){

    }
    else if(escolha_home==3){

    }
    else if(escolha_home==4){

    }
    else if(escolha_home==5){

    }
}

int main (){
home_page();
acoes();
    return 0;
}
