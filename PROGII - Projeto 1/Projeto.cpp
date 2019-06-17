#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "Funções.h"
using namespace std;

int main (){

    setlocale(LC_ALL, "portuguese");
    int id_livro=1;
    int num_user=1;
    Cadastro_Livro livro[100];
    Cadastro_Usuario usuario[100];
    home_page(livro, id_livro,usuario, num_user);
    return 0;
}
