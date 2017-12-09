// RedeSocial.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Data {
	int dia;
	int mes;
	int ano;
};


struct Usuario {
	string userName;
	string senha;
	string confirmacaoSenha;
	string nomeCompleto;
	Data dataDeNascimento;
	string genero;

	Usuario() {
		//Usuario *novo = new Usuario;
		string umUserName;
		string umaSenha;
		string umaConfirmacaoSenha;
		string umNomeCompleto;
		Data umaDataDeNascimento;
		string umGenero;
		cout << "Nome de Usuário: ";
		cin >> umUserName;
		cout << "Senha: ";
		cin >> umaSenha;
		cout << "Confirme sua senha: ";
		cin >> umaConfirmacaoSenha;
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

	void toview(){
		cout << "Nome de Usuário: " << this->userName << "| Senha: " << this->senha << "| Senha confirmada: " << this->confirmacaoSenha <<
			"| Nome completo: " << this->nomeCompleto << "| Data de nascimento: " << this->dataDeNascimento.dia << "/" << this->dataDeNascimento.mes <<
			"/" << this->dataDeNascimento.ano << "| Genero: " << this->genero;
			
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

	void mostrarElementos() {
		ElementoUsuario *atual = this->primeiro;

		while (atual != NULL) {
			atual->usuario->toview();
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

};

bool criarUsuario(ListaUsuario *minhaLista) {
	Usuario *novo = new Usuario();
	novo->userName;
	if (minhaLista->verificarUsuario(novo)) {
		return false;
	}
	else {
		minhaLista->inserir(novo);
		return true;
	}
}

int main()
{
	//Usuario *novo = new Usuario();
	ListaUsuario *minhaLista = new ListaUsuario(new ElementoUsuario(new Usuario()));
	minhaLista->mostrarElementos();

    return 0;
}

