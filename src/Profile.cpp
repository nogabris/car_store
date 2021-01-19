#include "Profile.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

Profile::Profile()
{
    strcpy(username,"Insira o nome");
    strcpy(password, "Insira a senha");
    strcpy(cpf, "12345678901");
    active = false;
    age = 0;
    /*TRUE = WOMAM / FALSE = MAN*/
    gender = true;
    /*TRUE = user / FALSE = seller*/
    profiletype = true;
}

Profile::~Profile(){}

void Profile:: createprofile()
{
    int i = 0;
    int ENTER = 13;
    int TAB = 9;
    int BKSP = 8;
	char ch;
	char pwd[20];

    cout << "Digite seu nome usuario : " << "\n";
    cin>>username;

    cout << "Digite sua senha: " << "\n";
	cout << "Senha: " ;
	while(1){
		ch = getch();

		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BKSP){
			if(i > 0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
    strcpy(password,pwd);


    cout << "\nDigite seu CPF(sem tracos ou espacos) : " << "\n";
    cin>>cpf;

    cout << "Digite sua idade: " << "\n";
    cin >> age;

    cout << "Digite seu genero (0 para homem | 1 para mulher ): " << "\n";
    cin >> gender;

    cout << "Digite seu perfil (0 para comprador | 1 para vendedor) " << "\n";
    cin >> profiletype;

    ofstream reg("database.txt", ios::app);
    reg<<username<<' '<<password<<' '<<cpf<<' '<<age<<' '<<gender<<' '<<profiletype<< endl;
    system("cls");
    cout<<"Usuario: ("<<username<<") criado com sucesso\n\n";
}

void Profile:: login()
{
    int count;
    string user,pass,u,p,cp,ag,gd,pt;
    system("cls");
    cout<<"Por favor insira as informacoes abaixo"<<endl;
    cout<<"Nome de usuario :";
    cin>>user;
    cout<<"Senha: ";
    cin>>pass;

    ifstream input("database.txt");
    while(input>>u>>p>>cp>>ag>>gd>>pt)
    {
        /*cout<<"VALOR U: "<<u<<"VALOR DE P:"<<p<<"VALOR cp: "<<cp<<"VALOR DE ag:"<<ag<<"VALOR gd: "<<gd<<"VALOR DE pt:"<<pt<<"\n";*/
        if(u==user && p==pass)
        {
            strcpy(username,u.c_str());
            strcpy(password,p.c_str());
            strcpy(cpf, cp.c_str());
            active = true;
            age = stoi(ag);
            gender = stoi(gd);
            profiletype = stoi(pt);
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\nHello "<<user<<"\nSeu Login foi realizado com sucesso\n";
        cin.get();
        cin.get();
    }

    else
    {
        cout<<"\nLOGIN ERROR\nPor favor verifique suas credenciais\n";

    }
}

void Profile:: showprofile()
{
    system("cls");
    char genderstring[20];
    char profilestring[20];


    if(gender==0)
    {
        strcpy(genderstring,"Masculino");
    }
    else{strcpy(genderstring,"Feminino");}

    if(profiletype==0)
    {
        strcpy(profilestring,"Usuario/(a)");
    }
    else{strcpy(profilestring,"Vendedor/(a)");}



    if(active)
    {
        cout<<"\n";
        cout<<"Nome de Usuario: "<<username<<"\n";
        cout<<"Numero de CPF: "<<cpf<<"\n";
        cout<<"Idade: "<<age<<"\n";
        cout<<"Genero: "<<genderstring<<"\n";
        cout<<"Tipo de perfil: "<<profilestring<<"\n\n";
    }
    else{cout<<"Realize Login antes\n\n";}
}

Car::Car()
{

    strcpy(model,"Modelo");
    strcpy(brand,"Marca");
    year = 0;
    airconditioner = false;
    door = 0;
    strcpy(exchange,"Cambio");
    strcpy(motor,"motor");
    strcpy(fuel,"Combustivel");
    strcpy(state,"estado");
}
Car::~Car(){}

void Car:: newcar()
{
    cout<<"Insira informacoes abaixo sobre o veiculo\n";

    cout<<"Modelo: ";
    cin>>model;
    cout<<"Marca: ";
    cin>>brand;
    cout<<"Ano: ";
    cin>>year;
    cout<<"Ar condiocionado: ";
    cin>>airconditioner;
    cout<<"Portas: ";
    cin>>door;
    cout<<"Cambio: ";
    cin>>exchange;
    cout<<"Motor: ";
    cin>>motor;
    cout<<"Combustivel: ";
    cin>>fuel;
    cout<<"Estado: ";
    cin>>state;

    ofstream reg("CAR_database.txt", ios::app);
    reg<<model<<' '<<brand<<' '<<year<<' '<<airconditioner<<' '<<door<<' '<<exchange<<' '<<motor<<' '<<fuel<<' '<<state<<endl;
    system("cls");
    cout<<"Carro: ("<<model<<" " << brand<<") inserido com sucesso\n\n";

}
