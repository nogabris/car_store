#define PROFILE_H

class Profile
{
    public:
        int id;
        char username[20];
        Profile();
        void changes(int i,char u[20],char p[20],char cp[12],int ag, bool gd, bool pr);
        virtual ~Profile();
        void createprofile();
        bool login();
        void showprofile();
        void selectprofile(int inp_id);



    private:
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
        int idcar;
        Car();
        virtual ~Car();
        void insertcar(Profile person);
        void listcar();
        void selectcar(int inp_idcar);
        //void neworder();

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
        //+listcar()
        //+neworder()

    protected:
        float balance;


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

class Purchase: public User, Car
{

    public:
        int idbuy;
        Purchase();
        void neworder(Car car,User usr);
        void offerlist(User usr);
        void selectpurchase(int inp_id);
        void confirmbuy(User usr);
        int active;
        int ID__BUY;
        int ID__CAR;
        int ID__SELLER;
        int ID__BUYER;
        float OF__FER;
        float PR__ICE;



    private:
        User usr;


};
