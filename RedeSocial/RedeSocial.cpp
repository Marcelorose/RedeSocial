// RedeSocial.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "LinkedLists.h"
#include "Structs.h"

void criarUsuario(ListaUsuario *minhaLista) {
	Usuario *novo = new Usuario();

	//if (minhaLista->verificarUsuario(novo)) {

		//return false;
	//}
	//else {
		ElementoUsuario *novoElemento = new ElementoUsuario(novo);
		minhaLista->adicionarUsuario(novoElemento);
		//return true;
	//}
}



void menu() {
	ListaUsuario * minhaListaUsuario;
	ListaPost * minhaListaPost;
	cout << "1 - Entrar \n2 - Criar usuário \n3 - Fechar o programa \nOpcao: ";
	int opcaoMenu;
	cin >> opcaoMenu;
	if (opcaoMenu == 1) //entrar
	{
		 
	}
	else if (opcaoMenu == 2) //criar usuario
	{
		if (minhaListaUsuario->primeiro == NULL) {
			Usuario *novo = new Usuario();
			ElementoUsuario *novoElemento = new ElementoUsuario(novo);
			minhaListaUsuario = new ListaUsuario(novoElemento);
		}
		criarUsuario(minhaListaUsuario);

	}
	else if (opcaoMenu == 3) //fechar prog;
	{
		minhaListaUsuario->mostrarElementos();
	}
	else // digitar diferente
	{

	}

}



int main()
{
	
	menu();
	
	
	
    return 0;
}

