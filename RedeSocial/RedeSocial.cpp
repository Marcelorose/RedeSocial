// RedeSocial.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "LinkedLists.h"
#include <conio.h>
#include "FuncoesDoMenu.h"


	





int main()
{
	ListaUsuario *minhaListaUsuario = new ListaUsuario();
	ListaPost *minhaListaPost = new ListaPost();
	menu(minhaListaUsuario, minhaListaPost);
	
	
	

    return 0;
}

