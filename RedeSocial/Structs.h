#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <iostream>

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
		getline(cin, umPost);
		this->oPost = umPost;
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

	void toview() {
		cout << "Nome de Usuario: " << this->userName << " | Senha: " << this->senha << " | Senha confirmada: " << this->confirmacaoSenha <<
			" | Nome completo: " << this->nomeCompleto << " | Data de nascimento: " << this->dataDeNascimento.dia << "/" << this->dataDeNascimento.mes <<
			"/" << this->dataDeNascimento.ano << " | Genero: " << this->genero;

	}

};







#endif