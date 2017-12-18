#ifndef FUNCOESDOMENU_H
#define FUNCOESDOMENU_H



void criarUsuario(ListaUsuario *&minhaLista) {
	Usuario *novo = new Usuario();
	ElementoUsuario *novoElemento = new ElementoUsuario(novo);
	minhaLista->verificarUsuario(novo);
	minhaLista->adicionarUsuario(novoElemento);
}

void criarPost(ListaPost *minhaListaPost, string criadorPost) {
	Post *novo = new Post();
	novo->criadorPost = criadorPost;
	ElementoPost *novoPost = new ElementoPost(novo);
	minhaListaPost->adicionarPost(novoPost);


}

void exibirTimeline(string userLogado, ListaPost *minhaListaPost) {
	cout << "Logado como: @" << userLogado;
	cout << "\n\n---- Timeline ----\n\n";
	minhaListaPost->mostrarElementos();
	cout << "\n------------------\n\n";
}

string entrar(ListaUsuario *minhaListaUsuario, ListaPost *minhaListaPost) {
	string userName, senha;
	cout << "---- LOGIN ---- \n\nUsername: ";
	cin >> userName;
	cout << "Senha: ";
	cin >> senha;
	string userLogado = minhaListaUsuario->entrarUsuario(userName, senha);
	system("cls");
	//exibirTimeline(userLogado, minhaListaPost);
	return userLogado;
}

void criarPostUser(ListaPost *minhaListaPost, string userLogado) {
	cout << "---- CRIACAO DO POST ---- \n\nPost: ";
	criarPost(minhaListaPost, userLogado);
	system("cls");
	exibirTimeline(userLogado, minhaListaPost);
}

//MENU

int menu(ListaUsuario *&minhaListaUsuario, ListaPost *&minhaListaPost) {

	cout << "---- MENU ---- \n\n1 - Entrar \n2 - Criar usuario \n3 - Mostrar usuarios e posts \n4 - Fechar Programa \n\nOpcao: ";
	int opcaoMenu;
	cin >> opcaoMenu;
	if (opcaoMenu == 1) //entrar
	{
		system("cls");
		string userLogado = entrar(minhaListaUsuario, minhaListaPost);
		int opcao;
		do
		{
			exibirTimeline(userLogado, minhaListaPost);
			cout << "1 - Criar um post \n2- Logout \n\nOpcao: ";
			cin >> opcao;
			system("cls");
			if (opcao == 1)
			{
				criarPostUser(minhaListaPost, userLogado);
				system("cls");
			}
			else if (opcao == 2)
			{
				menu(minhaListaUsuario, minhaListaPost);
			}

		} while (opcao != 2);



	}
	else if (opcaoMenu == 2) //criar usuario
	{
		system("cls");
		cout << "---- CRIAR USUARIO ----\n\n";
		criarUsuario(minhaListaUsuario);
		system("cls");
		menu(minhaListaUsuario, minhaListaPost);

	}
	else if (opcaoMenu == 3)
	{
		system("cls");
		minhaListaUsuario->mostrarElementos();
		cout << endl;
		minhaListaPost->mostrarElementos();
		cout << endl << "PRESSIONE UMA TECLA PARA VOLTAR AO MENU\n";
		system("pause");
		system("cls");
		menu(minhaListaUsuario, minhaListaPost);
	}
	else if (opcaoMenu == 4) //fechar prog;
	{
		return 0;
	}
	else // digitar diferente
	{
		system("cls");
		cout << "Digito invalido\n";
		menu(minhaListaUsuario, minhaListaPost);
	}

}




#endif
