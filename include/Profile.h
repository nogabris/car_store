#define PROFILE_H

class Profile
{
    public:
        int id;
        Profile();
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
        void newcar();


    private:
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
        void showprofile();
        bool login();
        void attbalance();
        void getbalance();
        void putmoney();
        //+changeuserinfo()
        //+listcar()
        //+neworder()

    private:
        float balance;
        Profile person;

} ;

