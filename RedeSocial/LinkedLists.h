#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <string>
#include <iostream>


using namespace std;


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

	bool verificarUsuario(Usuario *novoUsuario) {
		ElementoUsuario *atual = this->primeiro; \
			while (atual != NULL) {
				if (novoUsuario->userName == atual->usuario->userName) {
					return true;
					break;
				}
				atual = atual->proximoElemento;
			}
		return false;
	}

	void entrarUsuario(string userName, string senha) {
		ElementoUsuario *atual = this->primeiro;

		while (atual != NULL) {
			if (atual->usuario->userName == userName)
			{
				if (atual->usuario->senha == senha)
				{
					cout << "Logado\n";
					return;
				}
				cout << "Errou a senha chefia\n";
				return;
			}

			atual = atual->proximoElemento;
		}
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

};
















#endif
