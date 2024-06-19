#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
#include "destination.h"
#include <map>
#include <windows.h>
#include <unistd.h>


using namespace std;
void Driver_menu()
{
    system("cls");
    cout<<"*************************************************Driver Menu*******************************************************\n\n";
                 cout<<"1.REGISTER"<<endl;
                cout<<"2.Login"<<endl;

}
void Passenger_menu()
{
    system("cls");
    cout<<"*************************************************Passenger Menu*******************************************************\n\n";
                cout<<"1.REGISTER"<<endl;
                cout<<"2.Login"<<endl;

}
int Driver_sub_menu()
{
    Driver_menu();
    int i;
    cout<<"Enter your choice: ";
    cin>>i;
    return i;

}
int pass_sub_main()
{
    Passenger_menu();
    int i;
    cout<<"Enter your choice: ";
    cin>>i;
    return i;

}

map<string,double>Destination;
void initializedestination()
{
    //assuming Shahid Minar as the center
    Destination["dairy gate"]=1;
    Destination["tsc"]=0.5;
    Destination["bottola"]=1.5;
    Destination["transport"]=2;
    Destination["prantik gate"]=3;
    Destination["murad chottor"]=0.3;
    Destination["18 no hall"]=0.9;
    Destination["cse department"]=1;

}
map<string,double>pickup;
void initializepick()
{
    //assuming Shahid Minar as the center
    pickup["dairy gate"]=1;
    pickup["prantik gate"]=2;
    pickup["cse department"]=1;
}

double searchdist(string n)
{

    if(Destination.find(n)!=Destination.end())
    {
        return Destination[n];
    }
    else
        return 0;

}
double searchpick(string a)
{

    if(pickup.find(a)!=pickup.end())
    {
        return pickup[a];
    }
    else
        return 0;

}
void showtotal(string a,string b,double c)
{
    system("cls");
        cout<<"\n\t\t***************************Payment slip***************************************************\n\n";
        cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        cout << "\t\t	| Destination :"<<"----------------------"<<setw(10)<<a<<endl;
        cout << "\t\t	| Pickup Point :"<<"----------------------"<<setw(10)<<b<<endl;
        cout << "\t\t	| Total Fare :"<<"----------------------"<<setw(10)<<c<<endl;
        cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;

}


void Destination_menu()
{
    cout<<"\nDairy Gate\nPrantik Gate \nBottola \nMurad chottor\nTransport\n18 no Hall\nTSC\nCSE Department";

}
void pickup_menu()
{
    cout<<"\nCSE Department\nDairy Gate\nPrantik Gate\n";
}


void passenger_sub_menu()
{

    cout<<"1.Account Information"<<endl;
    cout<<"2.Recharge your account"<<endl;
    cout<<"3.Make a ride"<<endl;
    cout<<"\n\n\n";

}
class Userr
{
public:
    char username[20],password[10];
    int account_number;
    Userr()
    {
        strcpy(username," ");
        strcpy(password," ");
        srand(time(0));
        account_number=rand()%1001;
    }
    virtual void registration()=0;
    virtual void login()=0;
};
class Driver: public Userr
{
protected:
        char name[20];
    char rickshaw_number[20];
    char dresscode[10];
    int amount;
public:
    Driver():Userr(),amount(0)
{
    strcpy(name," ");
    strcpy(rickshaw_number," ");
    strcpy(dresscode," ");


}
      void account_detail()
    {
        system("cls");
        cout<<"\\\\\\                         Account Information              \\\\\\\\\\\\n\n";
        cout<<"Name: "<<(*this).name<<endl;
        cout<<"Rickshaw number: "<<(*this).rickshaw_number<<endl;
        cout<<"Account Number: "<<(*this).account_number<<endl;
        cout<<"Balance: "<<(*this).amount<<endl;
    }
void registration()
{
            system("cls");
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter rickshaw number: ";
        cin>>rickshaw_number;
        cout<<"Enter Dress code: ";
        cin>>dresscode;

        cout<<"Set an username :";
        cin>>username;
        cout<<"\nSet the password :";
        cin>>password;
        ofstream in;
        in.open("Driver_database.DAT",ios::app | ios::binary);

        in.write((char*)this,sizeof(*this));
        in.close();


        system("cls");
        cout<<"\nRegistration Sucessful!!\n\n\n";
        account_detail();

}

    char * getrickshaw()
    {
        return rickshaw_number;
    }
    void updatebalance(double a)
    {
        amount+=a;
    }



    void login()
    {
        char text1[20],text2[10];
        strcpy(text1," ");
        strcpy(text2," ");
        cout<<"Enter Username : ";
        cin>>text1;
        cout<<"Enter password : ";
        cin>>text2;
        isLog(text1,text2);

    }
    void isLog(char *t1,char *t2)
    {
        ifstream fu;
        int ct=0;
        fu.open("Driver_database.DAT",ios::in | ios::binary);
        fu.seekg(0);
        if(!fu)
            cout<<"\nFile not found\n";
        else
        {
            fu.read((char*)this,sizeof(*this));
            while(!fu.eof())
            {
                if(!(strcmp(t1,username) && strcmp(t2,password)))

                {
                    system("cls");
                    cout<<"Login Successful\n";
                    fu.read((char*)this,sizeof(*this));
                    break;



                    ct++;
                }
                fu.read((char*)this,sizeof(*this));
            }
            if(ct==0)
            {
                cout<<"Login Error!\nTry again!"<<endl;

            }
            fu.close();
            account_detail();
    }



}

};

class Passenger:public Userr
{
protected:
    char name[20];
    int amount;

public:
    Passenger():Userr(),amount(0)
    {
        strcpy(name," " );

    }

    void registration()
    {

        system("cls");
        cout<<"**************************************Registration**************************************\n";
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Set an username :";
        cin>>username;
        cout<<"\nSet the password :";
        cin>>password;

        ofstream infile;
        infile.open("Passenger.DAT",ios::app | ios::binary);

        infile.write((char*)this,sizeof(*this));
        infile.close();


        system("cls");
        cout<<"\nRegistration Sucessful!!\n\n\n";
        option();



    }


    void operator +=(int a)
    {
        amount+=a;
    }
void option()
 {
            system("cls");
            passenger_sub_menu();
            int choice;
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                account_detail();
                break;
            case 2:
                recharge();
                break;
            case 3:
                make_a_ride();
                break;
            default:
                cout<<"Wrong Choice!"<<endl;
            }
 }
    void login()
    {
        cout<<"**************************************Login**************************************\n";
        char text1[20],text2[10];
        strcpy(text1," ");
        strcpy(text2," ");
        cout<<"Enter Username : ";
        cin>>text1;
        cout<<"Enter password : ";
        cin>>text2;
        isLog(text1,text2);

    }
    void isLog(char *t1,char *t2)
    {
        ifstream fun;
        int ct=0;
        fun.open("Passenger.DAT",ios::in | ios::binary);
        fun.seekg(0);
        if(!fun)
            cout<<"\nFile not found\n";
        else
        {
            fun.read((char*)this,sizeof(*this));
            while(!fun.eof())
            {
                if(!(strcmp(t1,username) && strcmp(t2,password)))

                {
                    system("cls");

                    cout<<"Login Successful\n";



                    ct++;
                }
                fun.read((char*)this,sizeof(*this));
            }
            if(ct==0)
            {
                cout<<"Login Error!\nTry again!"<<endl;

            }
            fun.close();

            option();
            }



        }


    int getamount()
{
    return amount;
}
    void account_detail()
    {
        system("cls");
        cout<<"\\\\\\                         Account Information              \\\\\\\\\\\\n\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Account Number: "<<account_number<<endl;
        cout<<"Balance: "<<amount<<endl;
        sleep(5);
        option();
    }
    void recharge()
    {
        char num[15];
        int aaa;
        system("cls");
        cout<<"**************************************Recharge Page**************************************\n";
        cout<<"Digital Payment Method(Bkash/Nagad/Rocket)"<<endl;
        cout<<"Enter your number: ";
        cin>>num;
        cout<<"Enter amount: ";
        int aa;
        cin>>aa;
        (*this)+=aa;
        cout<<"Recharge Successful"<<endl;
        cout<<"Your current balance is"<<amount<<endl;
        sleep(5);
        option();


    }
     void operator -=(double a)
    {
        amount-=a;
    }

    void make_a_ride()
    {
        system("cls");
        initializedestination();
        cout<<"\n  ***************        View Destination        ****************** ";
        Destination_menu();
        cout<<"\nType your Destination: ";
        string answer1;
        getline(cin>>ws,answer1);
        system("cls");
        double finn1=searchdist(answer1);
        if(finn1==0)
        {
            system("cls");
            cout<<"Sorry! Ride can't  take place other than the listed place\n";
            sleep(3);
            Destination_menu();
        }
        else
        {
            initializepick();
            cout<<"**************************************Pickup Page**************************************\n";
            pickup_menu();
            cout<<"Type pickup location: ";
            string answer2;
            getline(cin>>ws,answer2);
            double finn2=searchpick(answer2);
            if(finn2==0)
                {cout<<"Your pickup location is out of reach\n";
                    sleep(3);
                    pickup_menu();
                }

           else  if(answer1==answer2)
                cout<<"Can't make ride.Pickup and Destination is same place\n";
            else
            {

                double total=finn1+finn2;

                double fair=total*(10);//assuming per kilometer 10 tk
                showtotal(answer1,answer2,fair);

                cout<<"Do you want to confirm?(y or n): ";
                char a;
                cin>>a;
                if(a=='y')
                {
                    int c=getamount();
                    if(c<fair)
                    {

                        cout<<"Your account balance is less than fare.Please Recharge First!";
                        sleep(2);
                        option();
                    }
                    else
                    {
                            (*this)-=fair;
                           makepayment(fair);
                    }


                }
                else
                {
                    cout<<"Hope you will travel with us soon\n";
                }
            }

        }
    }

void makepayment(double f)
{

    cout<<"\n\t\t***************************Payment slip***************************************************\n\n";
    cout<<"Enter Driver's rickshaw number: ";
    char answer[20];
    cin>>answer;

    Driver d1;
    finddriver(d1,answer,f);





}
void  finddriver(Driver d1,char *t1,double a)
{
        ifstream f1;
        int ct=0;
        f1.open("Driver_database.DAT",ios::in | ios::binary | ios:: out);
        f1.seekg(0);
        if(!f1)
            cout<<"\nFile not found\n";
        else
        {
            f1.read(reinterpret_cast<char*>(&d1),sizeof(Driver));
            while(!f1.eof())
            {
                if(!(strcmp(t1,d1.getrickshaw())))

                {
                    system("cls");
                    cout<<"Payment Successful\nDriver is on the way!\n";

                    ct++;}
                  f1.read(reinterpret_cast<char*>(&d1),sizeof(Driver));
            }
            if(ct==0)
            {
                cout<<"Wrong information"<<endl;
            }
            f1.close();

        }
}

};
 Passenger *p1[100];
Driver * d[100];
int i=0,j=0;
void main_menu()
{
        cout<<"              ***********************************************************************\n\n";
        cout<<"                                       Khali Mama,Jaben?                               \n\n\n";
        cout<<"                                      Welcome to Login page                               \n\n\n";
        cout<<"                    *****************        MENU        ************************\n\n";
        cout<<"Login/Register as: "<<endl;
        cout<<"1.Driver"<<endl;
        cout<<"2.Passenger"<<endl;
}
void sub_main_menu()
{
    system("cls");
    main_menu();
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    system("cls");
    if(choice==1)
    {

        d[i]=new Driver();
        int x=Driver_sub_menu();
        switch(x)
        {
        case 1:
            d[i]->registration();
            break;
        case 2:
            d[i]->login();
        default:
            cout<<"Wrong Choice"<<endl;
        }
        i++;


    }
     else if(choice==2)
    {

        p1[j]=new Passenger();
        int y=pass_sub_main();
        switch(y)
        {
        case 1:
            p1[j]->registration();
            break;
        case 2:
            p1[j]->login();
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
        j++;

    }


}

int main()
{

        sub_main_menu();

}





