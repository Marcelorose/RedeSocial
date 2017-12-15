#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;


struct Data {
	int dia;
	int mes;
	int ano;
};

struct Post {
	string criadorPost;
	string oPost;
	int numCaracteres;

	Post() {
		string umPost;
		cin >> umPost;
		this->oPost = umPost;
	}

	void toView() {
		cout << "@" << this->criadorPost << "\n\n" << this->oPost << "\n_________________";
	}
};

struct Usuario {
	string userName;
	string senha;
	string confirmacaoSenha;
	string nomeCompleto;
	Data dataDeNascimento;
	string genero;
	string post;

	Usuario() {
		//Usuario *novo = new Usuario;
		string umUserName;
		string umaSenha;
		string umaConfirmacaoSenha;
		string umNomeCompleto;
		Data umaDataDeNascimento;
		string umGenero;
		cout << "Nome de Usuario: ";
		cin >> umUserName;
		cout << "Senha: ";
		cin >> umaSenha;
		cout << "Confirme sua senha: ";
		cin >> umaConfirmacaoSenha;
		while (umaConfirmacaoSenha != umaSenha)
		{
			cout << "\nAs senhas nao batem, digite a confirmacao de novo \nConfirmacao senha: ";
			cin >> umaConfirmacaoSenha;
			system("cls");
		}
		cout << "Nome Completo: ";
		cin >> umNomeCompleto;
		cout << "Data de nascimento: \nDia: ";
		cin >> umaDataDeNascimento.dia;
		cout << "Mes: ";
		cin >> umaDataDeNascimento.mes;
		cout << "Ano: ";
		cin >> umaDataDeNascimento.ano;
		cout << "Genero: ";
		cin >> umGenero;
		this->userName = umUserName;
		this->senha = umaSenha;
		this->confirmacaoSenha = umaConfirmacaoSenha;
		this->nomeCompleto = umNomeCompleto;
		this->dataDeNascimento.dia = umaDataDeNascimento.dia;
		this->dataDeNascimento.mes = umaDataDeNascimento.mes;
		this->dataDeNascimento.ano = umaDataDeNascimento.ano;
		this->genero = umGenero;
	}

	void toView() {
		cout << "Nome de Usuario: " << this->userName << " | Senha: " << this->senha << " | Senha confirmada: " << this->confirmacaoSenha <<
			" | Nome completo: " << this->nomeCompleto << " | Data de nascimento: " << this->dataDeNascimento.dia << "/" << this->dataDeNascimento.mes <<
			"/" << this->dataDeNascimento.ano << " | Genero: " << this->genero;

	}

};


struct ElementoUsuario {
	Usuario *usuario;
	ElementoUsuario *proximoElemento;

	ElementoUsuario(Usuario *meuUsuario) {
		this->usuario = meuUsuario;
		this->proximoElemento = NULL;
	}

};

struct ListaUsuario {
	ElementoUsuario *primeiro;

	ListaUsuario(ElementoUsuario *primeiro) {
		this->primeiro = primeiro;
	}

	ListaUsuario() {
		this->primeiro = NULL;
	}

	void mostrarElementos() {
		ElementoUsuario *atual = this->primeiro;

		while (atual != NULL) {
			atual->usuario->toView();
			cout << endl;
			atual = atual->proximoElemento;
		}

	}

	void adicionarUsuario(ElementoUsuario *novoUsuario) {

		if (this->primeiro == NULL) {
			this->primeiro = novoUsuario;
		}
		else {
			ElementoUsuario *atual = this->primeiro;
			while (atual != NULL) {
				if (atual->proximoElemento == NULL) {
					atual->proximoElemento = novoUsuario;
					break;
				}
				atual = atual->proximoElemento;
			}
		}
	}

	void verificarMaioridade(Usuario *Usuario) {
		char dateStr[9];
		_strdate_s(dateStr);

		int dia;
		int mes;
		int ano;

		if (dateStr[0] == '0')
		{
			mes = 0;
		}
		else if (dateStr[0] == '1')
		{
			mes = 10;
		}
		if (dateStr[1] == '0')
		{
			mes += 0;
		}
		else if (dateStr[1] == '1')
		{
			mes += 1;
		}
		else if (dateStr[1] == '2')
		{
			mes += 2;
		}
		if (dateStr[3] == '0')
		{
			dia = 0;
		}
		else if (dateStr[3] == '1')
		{
			dia = 10;
		}
		else if (dateStr[3] == '2')
		{
			dia = 20;
		}
		else if (dateStr[3] == '3')
		{
			dia = 30;
		}
		if (dateStr[4] == '0')
		{
			dia += 0;
		}
		else if (dateStr[4] == '1')
		{
			dia += 1;
		}
		else if (dateStr[4] == '2')
		{
			dia += 2;
		}
		else if (dateStr[4] == '3')
		{
			dia += 3;
		}
		else if (dateStr[4] == '4')
		{
			dia += 4;
		}
		else if (dateStr[4] == '5')
		{
			dia += 5;
		}
		else if (dateStr[4] == '6')
		{
			dia += 6;
		}
		else if (dateStr[4] == '7')
		{
			dia += 7;
		}
		else if (dateStr[4] == '8')
		{
			dia += 8;
		}
		else if (dateStr[4] == '9')
		{
			dia += 9;
		}
		if (dateStr[6] == '0')
		{
			ano = 0;
		}
		else if (dateStr[6] == '1')
		{
			ano = 10;
		}
		else if (dateStr[6] == '2')
		{
			ano = 20;
		}
		else if (dateStr[6] == '3')
		{
			ano = 30;
		}
		else if (dateStr[6] == '4')
		{
			ano = 40;
		}
		else if (dateStr[6] == '5')
		{
			ano = 50;
		}
		else if (dateStr[6] == '6')
		{
			ano = 60;
		}
		else if (dateStr[6] == '7')
		{
			ano = 70;
		}
		else if (dateStr[6] == '8')
		{
			ano = 80;
		}
		else if (dateStr[6] == '9')
		{
			ano = 90;
		}
		if (dateStr[7] == '0')
		{
			ano += 0;
		}
		else if (dateStr[7] == '1')
		{
			ano += 1;
		}
		else if (dateStr[7] == '2')
		{
			ano += 2;
		}
		else if (dateStr[7] == '3')
		{
			ano += 3;
		}
		else if (dateStr[7] == '4')
		{
			ano += 4;
		}
		else if (dateStr[7] == '5')
		{
			ano += 5;
		}
		else if (dateStr[7] == '6')
		{
			ano += 6;
		}
		else if (dateStr[7] == '7')
		{
			ano += 7;
		}
		else if (dateStr[7] == '8')
		{
			ano += 8;
		}
		else if (dateStr[7] == '9')
		{
			ano += 9;
		}

		ano += 2000;

		if (Usuario->dataDeNascimento.ano >= 2000)
		{
			if (Usuario->dataDeNascimento.ano - ano < 18)
			{
				cout << "Menor de idade!";
			}
		}
		
	}

	void verificarUsuario(Usuario *novoUsuario) {
		ElementoUsuario *atual = this->primeiro;
		string nomeUsuario;
			verificarMaioridade(novoUsuario);
			for (int i = 0; i < 15; i++)
			{
				while (atual != NULL) {
					if (novoUsuario->userName == atual->usuario->userName) {
						do
						{
							cout << "\nUsername ja usado\n\nNome de Usuario: ";
							cin >> nomeUsuario;
							novoUsuario->userName = nomeUsuario;
						} while (novoUsuario->userName == atual->usuario->userName);
					}
					atual = atual->proximoElemento;
				}
			}
	}

	string entrarUsuario(string userName, string senha) {
		ElementoUsuario *atual = this->primeiro;
		

		while (atual != NULL) {
			if (atual->usuario->userName == userName)
			{
				if (atual->usuario->senha == senha)
				{
					cout << "Logado\n";
					system("cls");
					return userName;
				}
				else
				{
					do
					{
						cout << "Senha errada! Tente novamente \nSenha: ";
						cin >> senha;
					} while (atual->usuario->senha != senha);
					cout << "Logado\n";
					return userName;
				}	
			}
			atual = atual->proximoElemento;
		}
		cout << "Usuario nao existe! Tente novamente \nUsername: ";
			cin >> userName;
			entrarUsuario(userName, senha);
	}

};


struct ElementoPost {
	Post *post;
	ElementoPost *proximoElemento;

	ElementoPost(Post *meuPost) {
		this->post = meuPost;
		this->proximoElemento = NULL;
	}

};

struct ListaPost {
	ElementoPost *primeiro;

	ListaPost(ElementoPost *primeiro) {
		this->primeiro = primeiro;
	}

	ListaPost() {
		this->primeiro = NULL;
	}

	void adicionarPost(ElementoPost *novoPost) {

		if (this->primeiro == NULL) {
			this->primeiro = novoPost;
		}
		else {
			ElementoPost *atual = this->primeiro;
			while (atual != NULL) {
				if (atual->proximoElemento == NULL) {
					atual->proximoElemento = novoPost;
					break;
				}
				atual = atual->proximoElemento;
			}
		}
	}

	void mostrarElementos() {
		ElementoPost *atual = this->primeiro;

		if (atual == NULL)
		{
			cout << "Nao existe nenhum post ainda\n\n";
		}

		while (atual != NULL) {
			atual->post->toView();
			cout << endl;
			atual = atual->proximoElemento;
		}

	}

};
















#endif
