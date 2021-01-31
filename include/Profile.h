#define PROFILE_H

class Basicwarnings
{
    public:
        Basicwarnings();
        virtual void enterbtn();
        virtual void msgtoshow(char msg[100]);
    private:
        char message[100];
};

class Basicommands: public Basicwarnings
{
    public:
        Basicommands();
        void enterbtn();
        void msgtoshow(char msg[100]);
    private:
        int btntosave;

};

class Profile
{
    public:
        int id;
        char username[20];
        Profile();
        virtual ~Profile();
        void createprofile();
        bool login();
        void showprofile();
        void selectprofile(int inp_id);



    private:
        char password[20];
        char cpf[20];
        int age;
        bool gender;
        bool profiletype;
        bool active;

};

class Car
{
    public:
        int idcar;
        Car();
        virtual ~Car();
        void insertcar(Profile person);
        void listcar();
        void selectcar(int inp_idcar);


        char seller_usr[20];
        int idseller;
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

    private:

};

class User: public Profile
{
    public:
        Profile person;
        User(Profile per);
        User();
        void showprofile();
        void selectuser(int inp_idperson);
        bool login();
        void attbalance();
        float getbalance();
        void putmoney();
        void adjustbalance(int type, float correction);
        User operator+(float bal);
        User operator-(float bal);


    protected:
        float balance;


} ;


class Purchase: public User, Car
{

    public:
        int idbuy;
        int active;
        int ID__BUY;
        int ID__CAR;
        int ID__SELLER;
        int ID__BUYER;
        float OF__FER;
        float PR__ICE;

        Purchase();
        void neworder(Car car,User usr);
        void offerlist(User usr);
        void selectpurchase(int inp_id);
        void confirmbuy(User usr);


    private:
        User usr;

};


