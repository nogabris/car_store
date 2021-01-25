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
    int choice,choice2,choice3;
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
                        User buyer(custom);
                        if(buyer.login() == 0)
                        {
                            buyer.showprofile();
                            buyer.attbalance();
                            cout<<"Selecione a opcao que deseja realizar\n";
                            cout<<"[0]Para para realizar um novo deposito\n"<<"[1]Atualizar balanco\n"<<"[2]Sair\n";
                            cout<<"--> ";
                            cin>>choice3;
                            switch(choice3)
                            {
                                case 0:
                                {
                                   buyer.putmoney();
                                   buyer.attbalance();
                                   system("cls");
                                   //Verificar como voltar para o menu normal
                                }
                                case 1:
                                {
                                    buyer.attbalance();
                                }
                                case 2:
                                {
                                    break;
                                }

                            }
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
                        User seller(custom);
                        if(seller.login() == 1)
                        {
                            seller.showprofile();
                            seller.attbalance();

                        }
                        else
                        {
                            cout<<"Infelizmente o perfil logado nao e de vendedor.\nVoce sera direcionado ao menu principal\n\n";
                            break;
                        }
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


