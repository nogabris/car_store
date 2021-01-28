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
    int run2;
    int choice,choice2,choice3;
    Profile custom;

    while(run)
    {
        run2 = 1;
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
                User mainusr(custom);
                switch(choice2)
                {
                    case 0:
                    {
                        if(mainusr.login() == 0)
                        {
                            mainusr.showprofile();
                            mainusr.attbalance();
                            while(run2)
                            {
                                mainusr.showprofile();
                                cout<<"Selecione a opcao que deseja realizar\n";
                                cout<<"[0]Para para realizar um novo deposito\n"<<"[1]Atualizar balanco\n"<<"[2]Sair\n"<<"[3]Inserir um veiculo\n";
                                cout<<"--> ";
                                cin>>choice3;
                                switch(choice3)
                                {
                                    case 0:
                                    {
                                       mainusr.putmoney();
                                       mainusr.attbalance();
                                       system("cls");
                                       break;

                                    }
                                    case 1:
                                    {
                                        mainusr.attbalance();
                                        system("cls");
                                        cout<<"Saldo atualizado\n";
                                        cin.get();
                                        cin.get();

                                        break;
                                    }
                                    case 2:
                                    {
                                        run2 = 0;
                                        system("cls");
                                        cout<<"Realizando Logout do perfil"<<endl;
                                        cin.get();
                                        cin.get();
                                        break;
                                    }
                                    case 3:
                                    {
                                        Car carro;
                                        system("cls");
                                        //carro.insertcar(mainusr.person);
                                        carro.listcar();
                                        cin.get();
                                        cin.get();
                                        break;

                                    }
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
                        Seller seller(custom);
                        if(seller.login() == 1)
                        {
                              while(run2)
                            {
                                seller.showprofile();
                                cout<<"Selecione a opcao que deseja realizar\n";
                                cout<<"[0]Para para realizar um novo deposito\n"<<"[1]Atualizar balanco\n"<<"[2]Sair\n"<<"[3]Inserir um veiculo\n";
                                cout<<"--> ";
                                cin>>choice3;
                                switch(choice3)
                                {
                                    case 0:
                                    {
                                       seller.putmoney();
                                       seller.attbalance();
                                       system("cls");
                                       break;

                                    }
                                    case 1:
                                    {
                                        seller.attbalance();
                                        system("cls");
                                        cout<<"Saldo atualizado\n";
                                        cin.get();
                                        cin.get();

                                        break;
                                    }
                                    case 2:
                                    {
                                        run2 = 0;
                                        system("cls");
                                        cout<<"Realizando Logout do perfil"<<endl;
                                        cin.get();
                                        cin.get();
                                        break;
                                    }
                                    case 3:
                                    {
                                        cout<<"ESSE PE ID"<<seller.id;
                                        cin.get();
                                        cin.get();
                                        break;
                                    }
                                }

                            }
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
            default:
                cout<<"Por Favor selecione uma opcao valida"<<endl;
                cin.get();
                cin.get();
                system("cls");
                break;

        }
    }

}


