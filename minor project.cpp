#include <stdlib.h>
#include <iostream>
#include <fstream>
#include<cstring>
#include<conio.h>
#include <windows.h>
#include <dos.h>
#include<ctime>
using namespace std;
void product_label();
int main();
//custom manipulator
ostream& td(ostream &os)
{
    os<<'\t';
    return os;
}
//getting current system time
void get_time()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;
}
class products
{

           protected:
                int productID,productquantity,productprice;
                char productname[50];

           public:

 void getprodata()
    {
        ifstream infile("record.dat",ios::binary);
        cout<<"\n\n";
        getagain_pro:
        cout<<td<<td<<td<<td<<"  "<<(char)249<<"Enter Product ID=";
        cin>>productID;
        /*
        int checkid=productID;
        //checking whether same product iD product already added
        while(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
        {
             if(this->productID==checkid)
             {
                 cout<<td<<td<<td<<td<<(char)175<<"Product ID already Taken"<<(char)174;
                 cout<<"\n";
                 goto getagain_pro;
                 break;
             }
             else
             {
                break;
             }
        }*/
        //checking whether same product already exist or not
         //getagain_pro2:
        cout<<td<<td<<td<<td<<"  "<<(char)249<<"Enter product Name=";
        cin>>productname;
        /*
        char checkproduct_name[50];
        strcpy(checkproduct_name,productname);


         while(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
        {
             if(strcmp(productname,checkproduct_name)==0)
             {
                 cout<<td<<td<<td<<td<<(char)175<<"Product Name already Taken"<<(char)174;
                 cout<<"\n";
                 goto getagain_pro2;
                 break;
             }
             else
             {
                break;
             }
        }
*/
    infile.close();
    int flag=0;
    do{
            if(flag!=0)
            {
               cout<<td<<td<<td<<(char)175<<"   Product quantity can't be negative"<<(char)174<<endl;
            }
        cout<<td<<td<<td<<td<<"  "<<(char)249<<"Enter product quantity=";
        cin>>productquantity;
        flag++;

    }while(productquantity<0);
        cout<<td<<td<<td<<td<<"  "<<(char)249<<"Enter product price=";
        cin>>productprice;

    }

void showprodata()
    {
        static int flag=0;
       static int sn=1;
        if(flag==0)
        {

                //system("cls");
                product_label();
                flag++;

        }
        cout<<td<<sn++<<".";
    cout<<td<<"   "<< productID;
   cout<<td<<td<<" "<<productname;
    cout<<td<<td<<td<<productquantity;
    cout<<td<<td<<td<<productprice<<endl;
}

    void writeprodata()
    {
        ofstream outfile("record.dat",ios::binary|ios::app);

        system("cls");
        cout<<"\n\n\n"<<td<<td<<td<<td<<"     A D D  N E W  P R O D U C T"<<endl;
        cout<<td<<td;
        for(int i=0;i<65;i++)
        {
            cout<<(char)176;
        }

        getprodata();
        outfile.write(reinterpret_cast<char *>(this),sizeof(*this));
        if(write)
        {

            system("cls");
            cout<<"\n\n\n\t\t\tPRODUCT SUCCESSFULLY ADDED";
        }
        outfile.close();
    }
    void displayprodata()
    {
      ifstream infile("record.dat",ios::binary);
      while(!infile.eof())
      {
          if(infile.read(reinterpret_cast<char *>(this),sizeof(*this))>0)
          {
              showprodata();
          }
      }

    }

     int num_pro()
     {
         ifstream infile("record.dat",ios::binary);
         infile.seekg(0,ios::end);
         int count=infile.tellg()/sizeof(*this);
         return(count);
     }
    void editdata()
      {
           int choice,flag=0;
        static int sn;
       ifstream infile("record.dat",ios::binary);
      while(!infile.eof())
      {
          if(infile.read(reinterpret_cast<char *>(this),sizeof(*this))>0)
          {
              showprodata();
              sn++;
          }
      }
      infile.close();

         cout<<"\n\t\t\tenter S.N. number of product you want to modify(0-"<<sn<<")...";
         cin>>choice;
          fstream file;
          file.open("record.dat",ios::binary|ios::in|ios::out);
          file.seekp((choice-1)*sizeof(*this));


          //system("cls");
        cout<<"\n\n\n"<<td<<td<<td<<td<<"       M O D I F Y  P R O D U C T"<<endl;
        cout<<td<<td;
        for(int i=0;i<65;i++)
        {
            cout<<"_";
        }

          getprodata();
          file.write(reinterpret_cast<char*>(this),sizeof(*this));
          if(!write)
          {
              cout<<"ERROR OCCUR";
          }
          else
            cout<<"PRODUCT DETAILS UPDATED";
          file.close();

      }

       void deletedata()
      {
           int choice;

       ifstream infile("record.dat",ios::binary);
      while(!infile.eof())
      {
          if(infile.read(reinterpret_cast<char *>(this),sizeof(*this))>0)
          {
              showprodata();

          }
      }
      infile.close();

         cout<<"\n\t\t\tenter ID of product you want to delete";
         cin>>choice;
          fstream fp;
          fstream fp2;
          fp.open("record.dat",ios::binary|ios::in|ios::out);
          fp2.open("temp.dat",ios::binary|ios::out);
          fp.seekg(0,ios::beg);
          while(fp.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
          {
              if(productID!=choice)
              {
                  fp2.write(reinterpret_cast<char*>(this),sizeof(*this));
              }
          }
          fp2.close();
          fp.close();
          remove("record.dat");
          rename("temp.dat","record.dat");



      }

      int retproductprice(){return(productprice);}
      int retproductid(){return(productID);}
      char* retproductname(){return(productname);}

};



void display_layout()
{
                system("cls");
                 cout<<"\n\n\n"<<td<<td<<td<<"  T C B  D E P A R T M E N T A L  S T O R E"<<endl;
                 cout<<td<<td<<td<<td<<"    DHAPAKHEL,KATHMANDU"<<endl;
            cout<<td;
            for(int i=0;i<80;i++)
            {
                cout<<(char)220;
            }
            cout<<"\n\n"<<td<<"Bill NO:"<<1251<<td<<td<<td<<td<<td<<td;
            cout<<"  DATE:";
            get_time();

            cout<<td<<"Customer Name:"<<"xyz xyz\n";
}



void product_label()
{

    cout<<td;
                for(int i=0;i<80;i++)
                {
                     cout<<(char)223;
                }
                cout<<"\n\n";
                cout<<td<<"S.N";
                cout<<td<<" product ID";
                cout<<td<<"  product name";
                cout<<td<<"    product quantity";
                cout<<td<<"   product price"<<endl;
                cout<<td;
                for(int i=0;i<80;i++)
                {
                     cout<<(char)223;
                }

                cout<<"\n";
}
class customerarea:public products

{
private:
int order_id[50],order_quan[50];
char fullname[50],address[100];


public:
    void getdata(char *name,char *addss,int order_i[50],int order_q[50])
    {
        strcpy(fullname,name);
        strcpy(address,addss);
        order_id[50]=order_i[50];
        order_quan[50]=order_q[50];
    }
int c=0,sum=0,flag=0;
    void billing();//getting user name address and calculating total
    void get_order_details();
    void shoppingcart()//getting order_id and order quantity
    {

            display_layout();//display label;
            products::displayprodata();
            cout<<td;
            for(int i=0;i<80;i++)
            {
                 cout<<(char)220;
            }

            int choice;
            char next;
            cout<<"\n";
            products p2;
            ifstream infile("record.dat",ios::binary);
                int flag=0;
            //cout<<"\ncount"<<num_pro();
             do//for gettting input for multiple time
            {
                       // enter_again:
                        ifstream infile("record.dat",ios::binary);
                        label12:
                        cout<<td<<td<<td<<" enter name of product ID you want to buy:";
                        cin>>order_id[c];
                        int search=order_id[c];
                        //cout<<"search"<<search;
                       // cout<<"\nid"<<c;
                        //user can added same product in shopping cart
                        for(int i=0;i<c;i++)
                        {
                             //cout<<"order_id"<<"["<<i<<"]"<<order_id[i]<<endl;

                            if(order_id[i]==search)
                            {

                                //cout<<"search"<<search;
                                    flag=1;
                                   break;
                            }
                        }
                        if(flag==1)
                        {
                            //if product is already again asking user for inpput
                            cout<<"\t\t\t  !!already add to cart\n";
                            goto label12;
                        }
                        else
                        {


                            products p1;
                              while(infile.read(reinterpret_cast<char*>(&p1),sizeof(p1))>0)

                              {
                                    // cout<<"id"<<p1.retproductid()<<endl;
                                     if(p1.retproductid()==order_id[c])
                                     {

                                    cout<<td<<td<<td<<"enter quantity of product";
                                    cin>>order_quan[c];
                                    c++;
                                    break;


                                     }
                              }
                              infile.close();


                 if(c<num_pro())
                 {
                cout<<td<<td<<td<<"do you want to buy another products(Y/N)";
                cin>>next;
                 }
                 else
                    break;
                        }

            }while(next=='Y'|next=='y');
                cout<<"\n\n";
               cout<<td<<td<<td<<"    "<<(char)251<<"Thank you for shopping with us..";
               Sleep(2000);


            }



            void orderdetails()
            {

                ofstream onfile("metadata.dat",ios::binary);
                get_order_details();
                onfile.write(reinterpret_cast<char*>(this),sizeof(*this));
                if(write)
                {
                    cout<<"inserted";
                }
                onfile.close();
            }
            void show_orderdetails()
            {
                ifstream infile("metadata.dat",ios::binary);
                while(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
                {
                    cout<<"name"<<fullname<<endl;
                    cout<<"address"<<address<<endl;
                }
            }

};

void customerarea::billing()
{
    system("cls");
    //getting user name and address
cout<<"\n\n\t\t\t\t\t   USER DETAILS\n";
     cout<<"\t\t\t";
     for(int i=0;i<50;i++)
            {
                 cout<<(char)220;
            }
    cout<<"\n\n\t\t\t\t ENTER YOUR FULL NAME:";
    cin>>fullname;
    cout<<"\n\t\t\t\t ENTER YOUR SHIPPING ADDRESS:";
    cin>>address;


    //fake loading screen
        system("cls");
         system("color 0a");
 cout<<"\n\n\n\n\n\n\t\t\t\t    Please wait while loading\n\n";
 char a=177, b=219;
 cout<<"\t\t\t\t\t ";
 for (int i=0;i<=15;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t\t ";
 for (int i=0;i<=15;i++)
 {
  cout<<b;
  for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
 }



            //billing area
            system("cls");
                 cout<<"\n\n\n"<<td<<td<<td<<"  T C B  D E P A R T M E N T A L  S T O R E"<<endl;
                 cout<<td<<td<<td<<td<<"    DHAPAKHEL,KATHMANDU"<<endl;
            cout<<td;
            for(int i=0;i<75;i++)
            {
                 cout<<(char)220;
            }
            cout<<"\n\n"<<td<<"Bill NO:"<<1251<<td<<td<<td<<td<<td<<td<<"  DATE:";
            get_time();
            cout<<td<<"Customer Name:"<<fullname;
            cout<<"\n";
             cout<<td;
                for(int i=0;i<75;i++)
                {
                    cout<<(char)220;
                }
                cout<<"\n\n";
                cout<<td<<"ID";
                cout<<td<<" name";
                cout<<td<<"    quantity";
                cout<<td<<"      per price";
                cout<<td<<"           Total price"<<endl;
                cout<<td;
                for(int i=0;i<75;i++)
                {
                     cout<<(char)220;
                }

                cout<<"\n";



     products p2;
        for(int x=0;x<c;x++)
        {
            ifstream infile("record.dat",ios::binary);
           // cout<<"id"<<order_id[x]<<"quantity"<<order_quan[x]<<endl;
            while(infile.read(reinterpret_cast<char *>(&p2),sizeof(p2))>0)
            {
                   if(p2.retproductid()==order_id[x])
                   {
                      // p2.showprodata();

                cout<<td<<p2.retproductid();
                cout<<td<<p2.retproductname();
                cout<<td<<td<<order_quan[x];
                cout<<td<<td<<p2.retproductprice();
                int total=order_quan[x]*p2.retproductprice();
                cout<<td<<td<<"     "<<"Rs."<<total<<endl;
                sum=sum+total;

                   }
            }
infile.close();
        }
cout<<td;
                for(int i=0;i<75;i++)
                {
                     cout<<(char)220;
                }

                cout<<"\n";

        cout<<"\tShipping address:"<<address<<"t\t\t\t\t\t\ttotal="<<"Rs."<<sum;



}

void customerarea::get_order_details()
{
    shoppingcart();//getting order_id and quantity
    billing();//getting user name .address;
}
class adminarea
{
    public:

  void adminpanel()
  {
      products p;
       customerarea c;
      int choice;

     cout<<"\n\n\n\n\n\n"<<td<<td<<td<<td<<"    A D M I N   P A N E L"<<endl;
    cout<<td<<td<<"     ";
    for(int i=0;i<55;i++)
    {
        cout<<(char)220;
    }
   // cout<<"\n"<<td<<td<<td<<td<<td<<"Choose option"<<endl;
    cout<<"\n\n"<<td<<td<<td<<td<<"       1.(+)Add new products"<<endl;
    cout<<td<<td<<td<<td<<"       2.("<<(char)240<<")Modify Product details"<<endl;
    cout<<td<<td<<td<<td<<"       3.(-)Delete product"<<endl;
      cout<<td<<td<<td<<td<<"       4.("<<(char)254<<")metadata"<<endl;
        cout<<td<<td<<td<<td<<"       3.(X)exit"<<endl;
     cout<<td<<td<<"     ";
    for(int i=0;i<55;i++)
    {
        cout<<(char)220;
    }

     cout<<"\n"<<td<<td<<td<<td<<"       Choose Option...";
      cin>>choice;
      switch(choice)
      {
          case 1:
      p.writeprodata();

      Sleep(2000);
      system("cls");
      main();
              break;
           case 2:
               system("cls");
               cout<<"\n\n\n\t\t\t   M O D I F Y   P R O D U C T   D E T A I L S"<<endl;
      p.editdata();
               break;
           case 3:
      p.deletedata();
               break;
           case 4:
    c.show_orderdetails();
     break;
            default:

            cout<<"invalid choose";

      }//switching termination

      }



};
int main()
{
    adminarea a;
    customerarea c;
    int choice;
    cout<<"\n\n\n\n\n\n"<<td<<td<<td<<td<<"    WELCOME TO SHOPPING STORE"<<endl;
    cout<<td<<td<<"     ";
    for(int i=0;i<55;i++)
    {
        cout<<(char)220;
    }
   // cout<<"\n"<<td<<td<<td<<td<<td<<"Choose option"<<endl;
    cout<<"\n\n"<<td<<td<<td<<td<<"       1.Shopping store"<<endl;
    cout<<td<<td<<td<<td<<"       2.Admin Panel"<<endl;
    cout<<td<<td<<td<<td<<"       3.Exit"<<endl;
     cout<<td<<td<<"     ";
    for(int i=0;i<55;i++)
    {
        cout<<(char)220;
    }
    cout<<"\n"<<td<<td<<td<<td<<"       Choose Option...";
    cin>>choice;
    switch(choice)
    {

    case 1:
        //visting shopping mart area
         // system("cls");
        c.get_order_details();
        break;

    case 2:
        //visting password protected admin area
          system("cls");
         a.adminpanel();
        break;
    case 3:
        //exiting from program
        break;
    default:
        cout<<"invalid choice";

    }


    return(0);
}
