// RedeSocial.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "LinkedLists.h"
#include "Structs.h"
#include <conio.h>

void criarUsuario(ListaUsuario *&minhaLista) {
	Usuario *novo = new Usuario();
	ElementoUsuario *novoElemento = new ElementoUsuario(novo);
	if (minhaLista->verificarUsuario(novo)) {
		minhaLista->adicionarUsuario(novoElemento);
		
	}
	else {
		
		minhaLista->adicionarUsuario(novoElemento);
	}
} 
	
	void criarPost(ListaPost *minhaListaPost, string criadorPost) {
	Post *novo = new Post();
	novo->criadorPost = criadorPost;
	ElementoPost *novoPost = new ElementoPost(novo);
	minhaListaPost->adicionarPost(novoPost);


}

void menu(ListaUsuario *&minhaListaUsuario, ListaPost *&minhaListaPost) {
	
	cout << "---- MENU ---- \n\n1 - Entrar \n2 - Criar usuario \n3 - Fechar o programa \n\nOpcao: ";
	int opcaoMenu;
	cin >> opcaoMenu;
	if (opcaoMenu == 1) //entrar
	{
		system("cls");
		string userName, senha;
		cout << "---- LOGIN ---- \n\nUsername: ";
		cin >> userName;
		cout << "Senha: ";
		cin >> senha;
		minhaListaUsuario->entrarUsuario(userName, senha);
		cout << "---- Timeline ----\n\n";
		minhaListaPost->mostrarElementos();
		cout << "-----------\n\n";
		cout << "1 - Criar um post \n2- Voltar ao menu \nOpcao: ";
		int opcao;
		cin >> opcao;
		if (opcao == 1)
		{
			system("cls");
			cout << "---- CRIACAO DO POST ---- \n\nPost: ";
			criarPost(minhaListaPost, userName);
			minhaListaPost->mostrarElementos();
			system("PAUSE");
			menu(minhaListaUsuario, minhaListaPost);
		}
		else if (opcao == 2)
		{
			menu(minhaListaUsuario, minhaListaPost);
		}
		
		
	}
	else if (opcaoMenu == 2) //criar usuario
	{
		system("cls");
		cout << "---- CRIAR USUARIO ----\n\n";
		criarUsuario(minhaListaUsuario);
		system("cls");
		menu(minhaListaUsuario, minhaListaPost);

	}
	else if (opcaoMenu == 3) //fechar prog;
	{
		minhaListaUsuario->mostrarElementos();
		minhaListaPost->mostrarElementos();
		//return 0;
	}
	else // digitar diferente
	{

	}

}



int main()
{
	ListaUsuario *minhaListaUsuario = new ListaUsuario();
	ListaPost *minhaListaPost = new ListaPost();
	menu(minhaListaUsuario, minhaListaPost);
	/**/
	
	


    return 0;
}

