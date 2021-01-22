#include "Profile.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main()
{
    int run = 1;
    int choice,choice2;
    Profile custom;

    while(run)
    {
        cout<<"Selecione a opcao que deseja realizar\n";
        cout<<"[1]Para criar um novo perfil\n"<< "[2]Para realizar Login\n" << "[3]Lista de carros\n"<<"[4]Para sair\n";
        cout<<"--> ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                system("cls");
                Profile pessoa;
                pessoa.createprofile();
                break;
            }
            case 2:
            {
                system("cls");
                cout<<"[0]Para logar como comprador\n"<<"[1]Para logar como vendedor\n";
                cout<<"--> ";
                cin>>choice2;
                switch(choice2)
                {
                    case 0:
                    {
                        User usuario(custom);
                        if(usuario.login() == 0)
                        {
                            usuario.showprofile();
                        }
                        else
                        {
                            cout<<"Infelizmente o perfil logado nao e de comprador.\nVoce sera direcionado ao menu principal\n\n";
                            break;
                        }
                        break;
                    }
                    case 1:
                    {

                        break;
                    }
                }
            }
                break;
            case 3:
            {
                system("cls");
                cout<<"Lista de carros\n";
                break;
            }
            case 4:
            {
                system("cls");
                run = 0;
                break;

            }

        }
    }

}


