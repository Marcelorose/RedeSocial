// RedeSocial.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


struct Usuario {
	string ID;
	string senha;
	string confirmacaoSenha;
	string nome;
	string dataDeNascimento;
	string genero;
	int idade;

	Usuario() {
		string umaID;
		string umaSenha;
		string umaConfirmacaoSenha;
		string umNome;
		string umaDataDeNascimento;
		string umGenero;
		int umaIdade;
		cout << "Nome de Usuário: ";
		cin >> umaID;
		cout << "Senha: ";
		cin >> umaSenha;
		cout << "Confirme sua senha: ";
		cin >> umaConfirmacaoSenha;
		cout << "Nome Completo: ";
		cin >> umNome;
		cout << "Data de nascimento: ";
		cin >> umaDataDeNascimento;
		cout << "Genero: ";
		cin >> umGenero;
		cout << "Idade: ";
		cin >> umaIdade;
	}

};

struct ElementoUsuario {
	Usuario *meuUsuario;
	ElementoUsuario *proximo;

	ElementoUsuario(Usuario *usu) {
		this->meuUsuario = usu;
		this->proximo = NULL;
	}

};

struct ListaUsuario {
	ElementoUsuario *primeiro;

	ListaUsuario(ElementoUsuario *primeiro) {
		this->primeiro = primeiro;
	}

	void adicionarUsuario(ElementoUsuario *novo) {
		ElementoUsuario *temp = this->primeiro;
		while (temp != NULL)
		{
			if (temp->proximo == NULL)
			{
				temp->proximo = novo;
				break;
			}
			temp = temp->proximo;
		}
	}

	void mostrarLista() {
		ElementoUsuario *temp = this->primeiro;
		while (temp != NULL)
		{
			cout << temp->meuUsuario->nome << endl;
			cout << temp->meuUsuario->senha << endl;
			cout << temp->meuUsuario->idade << endl;
			temp = temp->proximo;
		}
	}

};

int main()
{
	
	

    return 0;
}

