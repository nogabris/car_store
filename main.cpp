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
    int choice,choice3;
    Profile custom;
    Basicwarnings *pvirtual;
    Basicommands command;

    pvirtual = &command;

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
                cout<<"Inicializando sistema, realize o login e aguarde\n";
                pvirtual->enterbtn();
                User mainusr(custom);
                mainusr.login();
                mainusr.showprofile();
                mainusr.attbalance();
                while(run2)
                {
                    mainusr.showprofile();
                    cout<<"Selecione a opcao que deseja realizar\n";
                    cout<<"[0]Para para realizar um novo deposito\n";
                    cout<<"[1]Atualizar balanco\n";
                    cout<<"[2]Lista de carros\n";
                    cout<<"[3]Inserir um veiculo\n";
                    cout<<"[4]Realizar uma nova compra\n";
                    cout<<"[5]Propostas recebidas\n";
                    cout<<"[6]Confirmar proposta\n";
                    cout<<"[7]Logout\n";
                    cout<<"--> ";
                    cin>>choice3;
                    switch(choice3)
                    {
                        case 0://putmoney
                        {
                           mainusr.putmoney();
                           mainusr.attbalance();
                           system("cls");
                           break;

                        }
                        case 1://attbalance
                        {
                            mainusr.attbalance();
                            system("cls");
                            cout<<"Saldo atualizado\n";
                            pvirtual->enterbtn();

                            break;
                        }
                        case 2://Car list
                        {
                            Car carro;
                            system("cls");
                            carro.listcar();
                            pvirtual->enterbtn();
                            break;

                        }
                        case 3://Insert car
                        {
                            Car carro;
                            system("cls");
                            carro.insertcar(mainusr.person);
                            pvirtual->enterbtn();
                            break;

                        }
                        case 4://New buy
                        {
                            Car carro;
                            Purchase compra;
                            system("cls");
                            compra.neworder(carro,mainusr);
                            pvirtual->enterbtn();
                            break;
                        }
                        case 5://Offer list
                        {
                            Purchase compra;
                            system("cls");
                            compra.offerlist(mainusr);
                            pvirtual->enterbtn();
                            break;
                        }
                        case 6://Confirm Buy
                        {
                            Purchase compra;
                            system("cls");
                            compra.confirmbuy(mainusr);
                            pvirtual->enterbtn();
                            break;

                        }
                         case 7://Exit
                        {
                            run2 = 0;
                            system("cls");
                            cout<<"Realizando Logout do perfil"<<endl;
                            pvirtual->enterbtn();
                            break;
                        }

                    }

                }

                break;



            }
                break;
            case 3:
            {
                Car carro;
                system("cls");
                carro.listcar();
                pvirtual->enterbtn();
                break;;
            }
            case 4:
            {
                system("cls");
                run = 0;
                break;

            }
            default:
                cout<<"Por Favor selecione uma opcao valida"<<endl;
                pvirtual->enterbtn();
                system("cls");
                break;

        }
    }

}


