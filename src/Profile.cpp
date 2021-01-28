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

//Profile Functions;
int databasesize()
{
    int counter=0;
    string i,u,p,cp,ag,gd,pt;
    ifstream input("database.txt");
    while(input>>i>>u>>p>>cp>>ag>>gd>>pt)
    {
        counter++;

    }
    input.close();
    return counter;
}

int databaseidGEN(int sizearray)
{
    int id__;
    int slidearray;
    int counter = 0;
    int arrayid[sizearray];
    string i,u,p,cp,ag,gd,pt;



    srand(time(0));
    ifstream input("database.txt");
    while(input>>i>>u>>p>>cp>>ag>>gd>>pt)
    {
        arrayid[counter] = stoi(i);
        counter++;
    }
    do
    {
        id__ = rand() % 100 + 1;
        slidearray = 0;

        for(int i = 0; i < sizearray; ++i)
        {
            if(arrayid[i] != id__)
            {
                slidearray++;
            }
            else{break;}
        }
    } while (slidearray < sizearray-1);


    input.close();
    return id__ ;
}

int balancebasesize()
{
    int counter=0;
    string i,b;
    ifstream input("balancedatabase.txt");
    while(input>>i>>b)
    {
        counter++;

    }
    input.close();
    return counter;
}

int balancexists(int sizearray, int id__)
{
    int slidearray;
    int counter = 0;
    int arrayid[sizearray];
    string i,b;


    srand(time(0));
    ifstream input("balancedatabase.txt");
    while(input>>i>>b)
    {
        arrayid[counter] = stoi(i);
        counter++;
    }
    do
    {
        slidearray = 0;

        for(int i = 0; i < sizearray; ++i)
        {
            if(arrayid[i] != id__)
            {
                slidearray++;
            }
            else{return id__ ;}
        }
    } while (slidearray < sizearray-1);

    input.close();
    return -1 ;
}

int carbasesize()
{
    int counter=0;
    string idc, ids,susr,pr,mo,br,ye,ai,doo,ex,mot,fu,st;
    ifstream input("CAR_database.txt");
    while(input>>idc>>ids>>susr>>pr>>mo>>br>>ye>>ai>>doo>>ex>>mot>>fu>>st)
    {
        counter++;

    }
    input.close();
    return counter;
}

int carbaseidGEN(int sizearray)
{
    int id__;
    int slidearray;
    int counter = 0;
    int arrayid[sizearray];
    string idc, ids,susr,pr,mo,br,ye,ai,doo,ex,mot,fu,st;


    srand(time(0));
    ifstream input("CAR_database.txt");
    while(input>>idc>>ids>>susr>>pr>>mo>>br>>ye>>ai>>doo>>ex>>mot>>fu>>st)
    {
        arrayid[counter] = stoi(idc);
        counter++;
    }
    do
    {
        id__ = rand() % 100 + 1;
        slidearray = 0;

        for(int i = 0; i < sizearray; ++i)
        {
            if(arrayid[i] != id__)
            {
                slidearray++;
            }
            else{break;}
        }
    } while (slidearray < sizearray-1);


    input.close();
    return id__ ;
}

int purchasebasesize()
{
    int counter=0;
    string IDBUY,IDCAR,IDSELLER,PRICE,VALIDATE;
    ifstream input("database.txt");
    while(input>>IDBUY>>IDCAR>>IDSELLER>>PRICE>>VALIDATE)
    {
        counter++;

    }
    input.close();
    return counter;
}

int purchasebaseidGEN(int sizearray)
{
    int id__;
    int slidearray;
    int counter = 0;
    int arrayid[sizearray];
    string IDBUY,IDCAR,IDSELLER,PRICE,VALIDATE;



    srand(time(0));
    ifstream input("database.txt");
    while(input>>IDBUY>>IDCAR>>IDSELLER>>PRICE>>VALIDATE)
    {
        arrayid[counter] = stoi(IDBUY);
        counter++;
    }
    do
    {
        id__ = rand() % 100 + 1;
        slidearray = 0;

        for(int i = 0; i < sizearray; ++i)
        {
            if(arrayid[i] != id__)
            {
                slidearray++;
            }
            else{break;}
        }
    } while (slidearray < sizearray-1);


    input.close();
    return id__ ;
}

Profile::Profile()
{
    id=-1;
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

void Profile::changes(int i,char u[20],char p[20],char cp[12],int ag, bool gd, bool pr)
{
    id=i;
    strcpy(username,u);
    strcpy(password, p);
    strcpy(cpf, cp);
    active = false;
    age = ag;
    /*TRUE = WOMAM / FALSE = MAN*/
    gender = gd;
    /*TRUE = user / FALSE = seller*/
    profiletype = pr;
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

    id = databaseidGEN(databasesize());

    ofstream reg("database.txt", ios::app);
    reg<<id<<' '<<username<<' '<<password<<' '<<cpf<<' '<<age<<' '<<gender<<' '<<profiletype<< endl;
    system("cls");
    cout<<"Usuario: ("<<username<<") criado com sucesso\n\n";
}

 bool Profile:: login()
{
    int cont = 0;
    int ENTER = 13;
    int TAB = 9;
    int BKSP = 8;
	char ch;
	char pwd[20];
	char pass[20];
    int count;
    string user,i,u,p,cp,ag,gd,pt;
    system("cls");
    cout<<"Por favor insira as informacoes abaixo"<<endl;
    cout<<"Nome de usuario: ";
    cin>>user;
	cout << "Senha: " ;
	while(1){
		ch = getch();

		if(ch == ENTER || ch == TAB){
			pwd[cont] = '\0';
			break;
		}else if(ch == BKSP){
			if(cont > 0){
				cont--;
				printf("\b \b");
			}
		}else{
			pwd[cont++] = ch;
			printf("* \b");
		}
	}
    strcpy(pass,pwd);

    ifstream input("database.txt");
    while(input>>i>>u>>p>>cp>>ag>>gd>>pt)
    {
        if(u==user && p==pass)
        {
            id = stoi(i);
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
        cout<<"Seja bem vindo "<<user<<"\nSeu Login foi realizado com sucesso\n"<<"Pressione ENTER para continuar\n";
        cin.get();
        cin.get();
    }

    else
    {
        cout<<"\nLOGIN ERROR\nPor favor verifique suas credenciais\n";

    }

    return profiletype;
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
        strcpy(profilestring,"Comprador/(a)");
    }
    else{strcpy(profilestring,"Vendedor/(a)");}



    if(active)
    {
        cout<<"ID: "<<id<<"\n";
        cout<<"Nome de Usuario: "<<username<<"\n";
        cout<<"Numero de CPF: "<<cpf<<"\n";
        cout<<"Idade: "<<age<<"\n";
        cout<<"Genero: "<<genderstring<<"\n";
        cout<<"Tipo de perfil: "<<profilestring<<"\n";
    }
    else{cout<<"Realize Login antes\n\n";}
}

//Car Functions
Car::Car()
{

    idcar = -1;
    strcpy(seller_usr,"Nome do usuario");
    idseller = -1;
    price = 0;
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

void Car:: insertcar(Profile person)
{
    idcar = carbaseidGEN(carbasesize());
    idseller = person.id;
    strcpy(seller_usr, person.username);
    cout<<"Insira informacoes abaixo sobre o veiculo\n";

    cout<<"Preco: ";
    cin>>price;
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
    reg<<idcar<<' '<<idseller<<' '<<seller_usr<<' '<<price<<' '<<model<<' '<<brand<<' '<<year<<' '<<airconditioner<<' '<<door<<' '<<exchange<<' '<<motor<<' '<<fuel<<' '<<state<<endl;
    system("cls");
    cout<<"Carro: ("<<model<<" " << brand<<") inserido com sucesso\n\n";

}

void Car:: listcar()
{
    string idc, ids,susr,pr,mo,br,ye,ai,doo,ex,mot,fu,st;

    cout<<"###################################################"<<endl;
    ifstream input("CAR_database.txt");
    while(input>>idc>>ids>>susr>>pr>>mo>>br>>ye>>ai>>doo>>ex>>mot>>fu>>st)
    {
        cout<<"ID carro: "<<idc<<" Responsavel: "<<susr<<endl;
        cout<<"Modelo: "<<mo<<" Marca: "<<br<<" Preco: RS"<<pr<<" Estado: "<<st<<endl;
        cout<<"Motor: "<<mot<<" Ano: "<<ye<<" Ar Cond: "<<ai<<" "<<doo<<"Portas"<<" Combustivel: "<<fu<<endl;
        cout<<"###################################################"<<endl;
    }
}

//User Functions
User::User()
{
    balance = 3000;
}

User::User(Profile per)
{
    balance = 0;
    person = per;
}

bool User::login()
{
    return person.login();
}

void User:: showprofile()
{
    getbalance();
    //person.showprofile();
    cout<<"O seu saldo e de RS:"<<balance<<"\n\n";
}

void User:: attbalance()
{
    int verifyexists;
    string i,b;

    verifyexists = balancexists(balancebasesize(), person.id);
    if(verifyexists == -1)
    {
        ofstream reg("balancedatabase.txt", ios::app);
        reg<<person.id<<' '<<balance<<endl;
        reg.close();
    }

    else
    {
        ifstream originalF;
        ofstream tempF;

        originalF.open("balancedatabase.txt");
        tempF.open("tempfile.txt");
        while(originalF>>i>>b)
        {
            if(person.id == stoi(i))
            {
                tempF<<i<<' '<<balance<<endl;
            }
            else{tempF<<i<<' '<<b<<endl;}
        }
        originalF.close();
        tempF.close();
        remove("balancedatabase.txt");
        rename("tempfile.txt","balancedatabase.txt");

    }


}

void User:: putmoney()
{
    int cont = 0;
    int ENTER = 13;
    int TAB = 9;
    int BKSP = 8;
	char ch;
	char pwd[20];
    float newdeposit;

    getbalance();
    cout<<"\nQuanto voce deseja depositar: "<<endl;
    cin>>newdeposit;
    balance += newdeposit;
    cout << "Por favor confirme sua senha: " ;
	while(1){
		ch = getch();

		if(ch == ENTER || ch == TAB){
			pwd[cont] = '\0';
			break;
		}else if(ch == BKSP){
			if(cont > 0){
				cont--;
				printf("\b \b");
			}
		}else{
			pwd[cont++] = ch;
			printf("* \b");
		}
	}
	cout<<"\nDeposito de: RS"<<newdeposit<<" confirmado\n";
	cout<<"Seu novo saldo e de: RS"<<balance<<endl;
	cin.get();
	cin.get();

}

void User:: getbalance()
{
     string i,b;
    person.showprofile();
    ifstream reg("balancedatabase.txt", ios::app);
         while(reg>>i>>b)
            {
                if(person.id == stoi(i))
                {
                    balance = stof(b);
                }
            }
            reg.close();
}
//End User Functions

//Seller Functions
Seller:: Seller(Profile per)
{
    User user_aux(per);
    usr = user_aux;
}
//End Seller Functions

Purchase:: Purchase()
{
    idbuy = -1;
    active = -1;
}

void Purchase:: neworder(Car car, Profile per)
{

    idbuy = purchasebaseidGEN(purchasebasesize());
    ofstream reg("purchase_database.txt", ios::app);
    reg<<idbuy<<' '<<car.idcar<<' '<<per.id<<' '<<car.price<<' '<<"0"<<endl;
    system("cls");
    cout<<"Nova oferta no Carro: ("<<car.id<<") realizada\nAguarde aprovacao do vendedor\n\n";


}
