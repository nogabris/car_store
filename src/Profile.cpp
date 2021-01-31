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
    string IDBUY,IDCAR,IDSELLER,IDBUYER,OFFER,PRICE;
    ifstream input("purchase_database.txt");
    while(input>>IDBUY>>IDCAR>>IDSELLER>>IDBUYER>>OFFER>>PRICE)
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
    string IDBUY,IDCAR,IDSELLER,IDBUYER,PRICE,OFFER;



    srand(time(0));
    ifstream input("purchase_database.txt");
    while(input>>IDBUY>>IDCAR>>IDSELLER>>IDBUYER>>OFFER>>PRICE)
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

void updatingofferlist(int id_inp)
{
    string IDBUY,IDCAR,IDSELLER,IDBUYER,PRICE,OFFER;
    ifstream originalF;
    ofstream tempF;

    originalF.open("purchase_database.txt");
    tempF.open("tempfile.txt");
    while(originalF>>IDBUY>>IDCAR>>IDSELLER>>IDBUYER>>OFFER>>PRICE)
    {
        if(stoi(IDCAR) != id_inp)
        {
            tempF<<IDBUY<<' '<<IDCAR<<' '<<IDSELLER<<' '<<IDBUYER<<' '<<OFFER<<' '<<PRICE<<endl;
        }
    }
    originalF.close();
    tempF.close();
    remove("purchase_database.txt");
    rename("tempfile.txt","purchase_database.txt");
}

void updatingcarlist(int id_inp)
{
    string idc, ids,susr,pr,mo,br,ye,ai,doo,ex,mot,fu,st;
    ifstream originalF;
    ofstream tempF;

    originalF.open("CAR_database.txt");
    tempF.open("tempfile.txt");
    while(originalF>>idc>>ids>>susr>>pr>>mo>>br>>ye>>ai>>doo>>ex>>mot>>fu>>st)
    {
        if(stoi(idc) != id_inp)
        {
            tempF<<idc<<' '<<ids<<' '<<susr<<' '<<pr<<' '<<mo<<' '<<br<<' '<<ye<<' '<<ai<<' '<<doo<<' '<<ex<<' '<<mot<<' '<<fu<<' '<<st<<endl;
        }
    }
    originalF.close();
    tempF.close();
    remove("CAR_database.txt");
    rename("tempfile.txt","CAR_database.txt");
}

//Profile functions
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


    cout << "\nDigite seu CPF(sem tracos ou espacos): " << "\n";
    cin>>cpf;

    cout << "Digite sua idade: " << "\n";
    cin >> age;

    cout << "Digite seu genero (0 para homem | 1 para mulher ): " << "\n";
    cin >> gender;

    profiletype = 0;

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

    strcpy(profilestring,"Comprador/Vendedor");


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


void Profile:: selectprofile(int inp_id)
{
    string i,u,p,cp,ag,gd,pt;
    ifstream input("database.txt");
    while(input>>i>>u>>p>>cp>>ag>>gd>>pt)
    {
        if(inp_id == stoi(i))
        {
            id = stoi(i);
            strcpy(username,u.c_str());
            strcpy(password,p.c_str());
            strcpy(cpf,cp.c_str());
            age = stoi(ag);
            gender = stoi(gd);
            profiletype = stoi(pt);

        }

    }
    input.close();

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

    cout<<"Modelo: ";
    cin>>model;
    cout<<"Marca: ";
    cin>>brand;
    cout<<"Preco: ";
    cin>>price;
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

    cout<<"########################################################################################"<<endl;
    ifstream input("CAR_database.txt");
    while(input>>idc>>ids>>susr>>pr>>mo>>br>>ye>>ai>>doo>>ex>>mot>>fu>>st)
    {
        cout<<"ID carro: "<<idc<<" Responsavel: "<<susr<<endl;
        cout<<"Modelo: "<<mo<<" Marca: "<<br<<" Preco: RS"<<pr<<" Estado: "<<st<<endl;
        cout<<"Motor: "<<mot<<" Ano: "<<ye<<" Ar Cond: "<<ai<<" "<<doo<<"Portas"<<" Combustivel: "<<fu<<endl;
        cout<<"########################################################################################"<<endl;
    }
}

void Car:: selectcar(int inp_idcar)
{
    string idc, ids,susr,pr,mo,br,ye,ai,doo,ex,mot,fu,st;
    ifstream originalF;
    ofstream tempF;

    originalF.open("Car_database.txt");

    while(originalF>>idc>>ids>>susr>>pr>>mo>>br>>ye>>ai>>doo>>ex>>mot>>fu>>st)
    {
        if(inp_idcar == stoi(idc))
        {

            idcar = stoi(idc);

            strcpy(seller_usr, susr.c_str());


            idseller = stoi(ids);


            price = stof(pr);


            strcpy(model, mo.c_str());


            strcpy(brand, br.c_str());


            year = stoi(ye);


            airconditioner = stoi(ai);


            door = stoi(doo);


            strcpy(exchange, ex.c_str());


            strcpy(motor, mot.c_str());



            strcpy(fuel, fu.c_str());


            strcpy(state, st.c_str());

        }

    }
    originalF.close();

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
    cout<<"O seu saldo e de RS:"<<balance<<"\n\n";
}

void User:: selectuser(int inp_idperson)
{

    string id_user, b;
    ifstream originalF;
    originalF.open("balancedatabase.txt");
    while(originalF>>id_user>>b)
    {
        if(inp_idperson == stoi(id_user))
        {
            balance = stof(b);
        }

    }
    originalF.close();


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
    operator+(newdeposit);
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

float User:: getbalance()
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
    return balance;
}

User User:: operator+(float bal)
{
    balance +=  bal;
    return *this;
}

User User:: operator-(float bal)
{
    balance -=  bal;
    return *this;
}

void User:: adjustbalance(int type, float correction)
{
    if(type == 1)
    {   cout<<"Transferindo RS"<<correction<<" para sua conta"<<endl;
        operator+(correction);
    }
    else
    {
        operator-(correction);
    }
}
//End User Functions

//Purchase Functions
Purchase:: Purchase()
{
    idbuy = -1;
    active = -1;
    ID__BUY = -1;
    ID__CAR = -1;
    ID__SELLER = -1;
    ID__BUYER= -1;
    OF__FER = -1;
    PR__ICE = -1;

}

void Purchase:: neworder(Car car, User usr)
{
    int run = 1;
    int id_selected;
    float offer,bal;


    usr.selectuser(usr.person.id);
    idbuy = purchasebaseidGEN(purchasebasesize());
    cout<<"Selecione o ID do carro que deseja fazer a oferta: \n";
    cout<<"--> ";
    cin>>id_selected;
    car.selectcar(id_selected);
    cout<<"O carro selecionado foi: \n";


    while(run)
    {
        cout<<"########################################################################################"<<endl;
        cout<<"ID carro: "<<car.idcar<<" Responsavel: "<<car.seller_usr<<" ID responsavel: "<<car.idseller<<endl;
        cout<<"Modelo: "<<car.model<<" Marca: "<<car.brand<<" Preco: RS"<<car.price<<" Estado: "<<car.state<<endl;
        cout<<"Motor: "<<car.motor<<" Ano: "<<car.year<<" Ar Cond: "<<car.airconditioner<<" "<<car.door<<"Portas"<<" Combustivel: "<<car.fuel<<endl;
        cout<<"########################################################################################"<<endl;
        cout<<"Digite o valor da sua oferta: \n";
        cout<<"-->RS ";
        cin>>offer;

        bal = usr.getbalance();

        if(offer>bal)
        {
            cout<<"\n";
            cout<<"Saldo insuficiente "<<endl;
            cout<<"Valor da Proposta: RS"<<offer<<endl;
            cout<<"Saldo em conta: RS"<<bal<<endl;
            cin.get();
            cin.get();

        }
        else{run=0;}
    }


    ofstream reg("purchase_database.txt", ios::app);
    reg<<idbuy<<' '<<car.idcar<<' '<<car.idseller<<' '<<usr.person.id<<' '<<offer<<' '<<car.price<<endl;
    system("cls");
    cout<<"Nova oferta no Carro: ("<<car.model<<") realizada\nAguarde aprovacao do vendedor\n\n";

}

void Purchase:: offerlist(User usr)
{
    Car car;
    int ids, id_selected, idb;
    string IDBUY,IDCAR,IDSELLER,IDBUYER,PRICE,OFFER;
    ifstream input("purchase_database.txt");
    while(input>>IDBUY>>IDCAR>>IDSELLER>>IDBUYER>>OFFER>>PRICE)
    {
        Profile buyerPerson;
        ids = stoi(IDSELLER);
        idb = stoi(IDBUYER);
        id_selected = stoi(IDCAR);

        if(ids == usr.person.id)
        {
            buyerPerson.selectprofile(idb);
            car.selectcar(id_selected);
            cout<<"########################################################################################"<<endl;
            cout<<"ID compra: "<<IDBUY<<" Responsavel pela oferta: "<<buyerPerson.username<<" Valor da oferta: RS"<<OFFER<<endl;
            cout<<"Modelo: "<<car.model<<" Marca: "<<car.brand<<" Preco: RS"<<car.price<<endl;
            cout<<"########################################################################################"<<endl;
        }
    }
}

void Purchase:: selectpurchase(int inp_id)
{
    string IDBUY,IDCAR,IDSELLER,IDBUYER,PRICE,OFFER;
    ifstream input("purchase_database.txt");
    while(input>>IDBUY>>IDCAR>>IDSELLER>>IDBUYER>>OFFER>>PRICE)
    {
        if(stoi(IDBUY)== inp_id)
        {
            ID__BUY = stoi(IDBUY);
            ID__CAR = stoi(IDCAR);
            ID__SELLER = stoi(IDSELLER);
            ID__BUYER = stoi(IDBUYER);
            OF__FER = stof(OFFER);
            PR__ICE = stof(PRICE);
        }
    }
}


void Purchase:: confirmbuy(User seller)
{
    int id_confirm;

    Purchase original_buy;
    User buyer;

    cout<<"Insira o ID da compra que deseja aprovar";
    cout<<"->> ";
    cin>>id_confirm;
    original_buy.selectpurchase(id_confirm);

    //Getting information about SELLER and change BALANCE
    seller.selectuser(original_buy.ID__SELLER);
    seller.adjustbalance(1,original_buy.OF__FER);
    seller.attbalance();
    //Getting information about BUYER and change BALANCE
    buyer.selectuser(original_buy.ID__BUYER);
    buyer.person.selectprofile(original_buy.ID__BUYER);
    buyer.adjustbalance(-1,original_buy.OF__FER);
    buyer.attbalance();
    //Remove lines from offer list
    updatingofferlist(original_buy.ID__CAR);
    //remove lines from car list;
    updatingcarlist(original_buy.ID__CAR);

}

//End purchase functions

Basicwarnings::Basicwarnings()
{
    strcpy(message,"Insira sua mensagem");
}

void Basicwarnings::enterbtn()
{
    cout<<"Pressione ENTER";
}

void Basicwarnings:: msgtoshow(char msg[100])
{
    strcpy(message,msg);
}


Basicommands::Basicommands()
{
    btntosave = -1;
}

void Basicommands::enterbtn()
{
    cin.get();
    cin.get();
}

void Basicommands:: msgtoshow(char msg[100])
{
    cout<<msg<<endl;
    system("cls");

}







