//ID-223311207
//Name - I.S.M Rahik
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;

void menu();

class Manage_menu
{
protected:
    string userName;//hide admin name
public:
    Manage_menu()
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\t Enter Your name to Continue as an Admin: ";
        cin>>userName;
        system("cls");
        menu();
    }

};

class Customer
{
public:
    string name, gender, address;
    long long age,mobile_number, customer_id;
    char all[999];

    void get_Details();
    void show_Details();

};

class Cabs
{
public:
    int cab_choice;
    int km;
    float cab_cost;
    static float last_cab_cost;

    void cab_Details();

};

class Booking
{
public:
    int choice_hotels;
    int hotel_packages;
    static float hotel_cost;

    void hotels();

};
float Booking::hotel_cost;
float Cabs::last_cab_cost;

class Charges: public Customer, Booking, Cabs
{
public:
    void print_Bill();
    void show_Bill();
};

void menu()
{
    int main_choice;
    int in_choice;
    int goto_menu;

    system("cls");
    cout<<"\t\t      VARENDRA TRAVELS         \n"<<endl;
    cout<<"\t<----------------Main Menu-------------->"<<endl;
    cout<<"\t|_______________________________________|"<<endl;
    cout<<"\t|\t\t\t\t\t|"<<endl;
    cout<<"\t|\tCustomer Management->        1\t|"<<endl;
    cout<<"\t|\tCabs Management->            2\t|"<<endl;
    cout<<"\t|\tBooking Management->         3\t|"<<endl;
    cout<<"\t|\tCharges & Bill Management->  4\t|"<<endl;
    cout<<"\t|\tExit->                       5\t|"<<endl;
    cout<<"\t|\t\t\t\t\t|"<<endl;
    cout<<"\t|---------------------------------------|"<<endl;
    cout<<"\nEnter Your Choice: ";
    cin>>main_choice;
    system("cls");

    Customer a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if(main_choice==1)
    {
        cout<<"-----------Customers-----------\n"<<endl;
        cout<<"1. Enter new Customers"<<endl;
        cout<<"2. See Old Customers"<<endl;

        cout<<"\nEnter Choice: ";
        cin>> in_choice;

        system("cls");
        if(in_choice==1)
        {
            a2.get_Details();
        }
        else if(in_choice==2)
        {
            a2.show_Details();
        }
        else
        {
            cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
            Sleep(1100);
            system("cls");
            menu();
        }
        cout<<"\nPress 1 to Redirect main menu: ";
        cin>>goto_menu;
        system("cls");
        if(goto_menu==1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if(main_choice==2)
    {
        a3.cab_Details();
    }
    else if(main_choice==3)
    {
        cout<<"-->Book a Luxury Hotel using the system <--";
        a4.hotels();
    }
    else if(main_choice==4)
    {
        cout<<"-->Get your receipt <--"<<endl;
        a5.print_Bill();

        cout<<"Your receipt is already printed you can get it from the file path\n"<<endl;
        cout<<"to display the details of your receipt in the screen press 1: or enter another key to go back to main menu"<<endl;

        cin>>goto_menu;
        if(goto_menu==1)
        {
        system("cls");
        a5.show_Bill();
        cout<<"\nPress 1 to redirect main menu: ";
        cin>>goto_menu;
        system("cls");
        if(goto_menu==1)
        {
            menu();

        }
        else
        {
            menu();
        }
    }
    else
    {
        system("cls");
        menu();
    }
    }
    else if(main_choice==5)
    {
        cout<<"----GOOD BYE-------"<<endl;
        Sleep(999);
        system("cls");
        exit(0);
    }
    else
    {
        cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
        Sleep(1100);
        system("cls");
        menu();
    }


};
int main()
{
    system("Color 03");
    Manage_menu obj;


  return 0;
}
void Customer::get_Details()
{
    ofstream out("old-customers.txt",ios::app);
    {
    cout<<"Enter customer ID: ";
    cin>>customer_id;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Mobile Number: ";
    cin>>mobile_number;
    cout<<"Enter Address: ";
    cin>>address;
    cout<<"Enter Gender: ";
    cin>>gender;
    }
   out<<"\nCustomer Id: "<<customer_id<<"\nName: "<<name<<"\nAge: "<<age<<"\nMobile Number: "<<mobile_number<<"\nAddress: "<<address<<"\nGender: "<<gender<<endl;
   out.close();
   cout<<"\nSAVED \nNOTE: We have saved your details for future purposes\n" <<endl;

}
void Customer::show_Details()
{
    ifstream in("old-customers.txt");
    if(!in)
    {
        cout<<"File Error!"<<endl;
    }
    while(!(in.eof()))
    {
        in.getline(all,999);
        cout<< all <<endl;
    }
    in.close();
}

void Cabs::cab_Details()
{
    cout<<"We collaborated with fastest, safest and smartest cab service around the city" <<endl;
    cout<<".........................ABC Cabs..........................\n"<<endl;
    cout<<"1. Rent a standard cab - Tk.20 for 1KM"<<endl;
    cout<<"2. Rent a luxury cab - Tk.40 per 1KM"<<endl;

    cout<<"\nTo calculate the cost for your journey: "<<endl;
    cout<<"Enter which kind of cabs you need: "<<endl;
    cin>>cab_choice;
    cout<<"Enter kilometers you want to travel: ";
    cin>>km;

    int hire_cab;

    if(cab_choice ==1)
    {
        cab_cost=km*20;
        cout<<"\nYour tour cost: "<<cab_cost<< "Taka for a Standard Cab"<<endl;
        cout<<"Press 1 to hire this cab: or";
        cout<<"Press 2 to select another cab: ";
        cin>>hire_cab;
        system("cls");
        if(hire_cab==1)
        {
            last_cab_cost= cab_cost;
            cout<<"\nYou successfully hired a Standard cab" <<endl;
            cout<<"\nGoto Menu and take your receipt "<<endl;
        }
        else if(hire_cab==2)
        {
            cab_Details();

        }
        else
        {
            cout<<"\nInvalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
            Sleep(999);
            system("cls");
            cab_Details();
        }
    }
    else if(cab_choice==2)
    {
        cab_cost=km*40;
        cout<<"\nYour tour cost: "<<cab_cost<< "Taka for a Standard Cab"<<endl;
        cout<<"Press 1 to hire this cab: or";
        cout<<"Press 2 to select another cab: ";
        cin>>hire_cab;
        system("cls");
        if(hire_cab==1)
        {
            last_cab_cost= cab_cost;
            cout<<"\nYou successfully hired a Standard cab" <<endl;
            cout<<"\nGoto Menu and take your receipt "<<endl;
        }
        else if(hire_cab==2)
        {
            cab_Details();

        }
        else
        {
            cout<<"\nInvalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
            Sleep(1100);
            system("cls");
            cab_Details();
        }
    }
    else
    {
            cout<<"\nInvalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
            Sleep(1100);
            system("cls");
            menu();

    }
    cout<<"\nPress 1 to Redirect to Main menu: ";
    cin>>hire_cab;
    system("cls");
    if(hire_cab==1)
    {
        menu();
    }
    else
    {
        menu();
    }

}
void Booking::hotels()
{
    string hotel_no[]={"Grand Riverview", "Dalas" , "Hotel X"};
    for(int i=0; i<3; i++)
    {
        cout<<endl<<(i+1)<<".Hotel"<<hotel_no[i]<<endl;
    }
    cout<<"\nCurrently we collaborated with the above hotels!"<<endl;

    cout<<"Press any key to back or \nEnter number of the hotel you want to book: ";
    cin>>choice_hotels;

    system("cls");

    if(choice_hotels==1)
    {
        cout<<"----------WELCOME TO HOTEL GRAND REIVERVIEW-----------\n"<<endl;

        cout<<"The best view of the Padma River that you can enjoy. Stay cool and get chilled in the summer sun with our unique beverages."<<endl;
        cout<<"Packages offered by  GRAND RIVERVIEW:\n"<<endl;

        cout<<"1. Standard Pack"<<endl;
        cout<<"\tAll basic facilities you need just for: Taka.5000.00"<<endl;
        cout<<"2. Premium Pack"<<endl;
        cout<<"\tEnjoy Premium at Taka.10000.00 "<<endl;
        cout<<"3. Luxury Pack"<<endl;
        cout<<"\tLive a luxury at GRAND RIVERVIEW for only Taka.20000.00"<<endl;

        cout<<"\nPress another key to back or \nPackage number you want to book: ";
        cin>>hotel_packages;

        if(hotel_packages==1)
        {
            hotel_cost=5000.00;
            cout<<"\nYou have successfully booked Standard Pack at GRAND RIVERVIEW"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else if(hotel_packages==2)
        {
            hotel_cost=10000.00;
            cout<<"\nYou have successfully booked Premium Pack at GRAND RIVERVIEW"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else if(hotel_packages==3)
        {
            hotel_cost=20000.00;
            cout<<"\nYou have successfully booked Luxury Pack at GRAND RIVERVIEW"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else
        {
            cout<<"Invalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
            Sleep(1100);
            system("cls");
            hotels();

        }
        int gotomenu;
        cout<<"\nPress 1 to redirect to main menu: ";
        cin>> gotomenu;
        if(gotomenu==1)
        {
            menu();
        }
        else
        {
            menu();
        }

    }
    else if(choice_hotels==2)
    {
        cout<<"----------WELCOME TO DALAS INTERNATIONAL-----------\n"<<endl;

        cout<<"Based at the center of the city. 5 star feel at a 3 star"<<endl;
        cout<<"Packages offered by DALAS INTERNATIONAL:\n"<<endl;

        cout<<"1. Standard Pack"<<endl;
        cout<<"\tAll basic facilities you need just for: Taka.3000.00"<<endl;
        cout<<"2. Premium Pack"<<endl;
        cout<<"\tEnjoy Premium at Taka.7000.00 "<<endl;
        cout<<"3. Luxury Pack"<<endl;
        cout<<"\tLive a luxury at DALAS INTERNATIONAL for only Taka.12000.00"<<endl;

        cout<<"\nPress another key to back or \nPackage number you want to book: ";
        cin>>hotel_packages;

        if(hotel_packages==1)
        {
            hotel_cost=3000.00;
            cout<<"\nYou have successfully booked Standard Pack at DALAS INTERNATIONAL"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else if(hotel_packages==2)
        {
            hotel_cost=7000.00;
            cout<<"\nYou have successfully booked Premium Pack at DALAS INTERNATIONAL"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else if(hotel_packages==3)
        {
            hotel_cost=12000.00;
            cout<<"\nYou have successfully booked Luxury Pack at DALAS INTERNATIONAL"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else
        {
            cout<<"Invalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
            Sleep(1100);
            system("cls");
            hotels();

        }
        int gotomenu;
        cout<<"\nPress 1 to redirect to main menu: ";
        cin>> gotomenu;
        if(gotomenu==1)
        {
            menu();
        }
        else
        {
            menu();
        }

    }
    else if(choice_hotels==3)
    {
        cout<<"----------WELCOME TO HOTEL X-----------\n"<<endl;

        cout<<"Don't get confused by the name. We are the best in Rajshahi"<<endl;
        cout<<"Packages offered by HOTEL X:\n"<<endl;

        cout<<"1. Standard Pack"<<endl;
        cout<<"\tAll basic facilities you need just for: Taka.4000.00"<<endl;
        cout<<"2. Premium Pack"<<endl;
        cout<<"\tEnjoy Premium at Taka.9000.00 "<<endl;
        cout<<"3. Luxury Pack"<<endl;
        cout<<"\tLive a luxury at HOTEL X for only Taka.15000.00"<<endl;

        cout<<"\nPress another key to back or \nPackage number you want to book: ";
        cin>>hotel_packages;

        if(hotel_packages==1)
        {
            hotel_cost=4000.00;
            cout<<"\nYou have successfully booked Standard Pack at HOTEL X"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else if(hotel_packages==2)
        {
            hotel_cost=9000.00;
            cout<<"\nYou have successfully booked Premium Pack at HOTEL X"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else if(hotel_packages==3)
        {
            hotel_cost=15000.00;
            cout<<"\nYou have successfully booked Luxury Pack at HOTEL X"<<endl;
            cout<<"Goto menu and take the receipt"<<endl;
        }
        else
        {
            cout<<"Invalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
            Sleep(1100);
            system("cls");
            hotels();

        }
        int gotomenu;
        cout<<"\nPress 1 to redirect to main menu: ";
        cin>> gotomenu;
        if(gotomenu==1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
}
void Charges::print_Bill()
{
    ofstream outf("receipt.txt");
    {
    outf<<"--------------VARENDRA Travel Agency---------------------"<<endl;
    outf<<"----------------------Receipt--------------------------"<<endl;
    outf<<"_______________________________________________________"<<endl;
    outf<<"Customer ID: "<<Customer::customer_id<<endl<<endl;
    outf<<"Description\t\t Total"<<endl;
    outf<<"Hotel Cost:\t\t "<<fixed << setprecision(2)<<Booking::hotel_cost<<endl;
    outf<<"Travel (Cab) Cost:\t\t "<<fixed<<setprecision(2)<<Cabs::last_cab_cost<<endl;
    outf<<"_____________________________________________________"<<endl;
    outf<<"Total Charge:\t\t "<<fixed<<setprecision(2)<<Booking::hotel_cost+Cabs::last_cab_cost<<endl;
    outf<<"_______________________________________________________"<<endl;
    outf<<"---------------------THANK YOU--------------------------"<<endl;
    }
    outf.close();
}
void Charges::show_Bill()
{
    ifstream inf("receipt.txt");
    {
        if(!inf)
        {
            cout<<"Error opening File!"<<endl;
        }
        while(inf.eof())
        {
            inf.getline(all,999);
            cout<<all<<endl;
        }
        inf.close();
    }
}





















