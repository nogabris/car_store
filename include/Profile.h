#define PROFILE_H

class Profile
{
    public:
        int id;
        Profile();
        void changes(int i,char u[20],char p[20],char cp[12],int ag, bool gd, bool pr);
        virtual ~Profile();
        void createprofile();
        bool login();
        void showprofile();



    private:
        char username[20];
        char password[20];
        char cpf[12];
        int age;
        bool gender;
        bool profiletype;
        bool active;

};

class Car
{
    public:
        Car();
        virtual ~Car();
        void insertcar();
        //+insertcar()
        //+neworder()
        //+changecar()
        //+listcar()


    private:
        int idcar;
        char seller_usr[20];
        int idseller[20];
        float price;
        char model[20];
        char brand[20];
        int year;
        bool airconditioner;
        int door;
        char exchange[20];
        char motor [20];
        char fuel[20];
        char state[20];

};

class User: public Profile
{
    public:
        User(Profile per);
        User();
        void showprofile();
        bool login();
        void attbalance();
        void getbalance();
        void putmoney();
        //+listcar()
        //+neworder()

    private:
        float balance;
        Profile person;

} ;

class Seller: public User
{
    public:
        Seller(Profile per);
        //+listcar()
        //+insertcar()
        //+changecar()

    private:
        User usr;

};
