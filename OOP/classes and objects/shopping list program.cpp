#include<iostream>
#include<numeric>

using namespace std;

class items
{
    int tag[50];
    float price[50];
    static int count;
public:
    void add_item();
    void show_sum();
    void delete_item();
    void show_list();
};

int items :: count=0;

void items :: add_item()
{
    cout<<"Enter item tag:"<<endl;
    cin>>tag[count];

    cout<<"Enter item price:"<<endl;
    cin>>price[count];
    count++;
}
void items :: show_sum()
{
    cout<<"The sum of all the products are:"<<endl;
    cout<<accumulate(price,price+count,0.0)<<endl;
}

void items :: delete_item()
{
    cout<<"Enter tag of item you want to delete:"<<endl;
    int x;
    cin>>x;

    for(int i=0; i<count; i++){
        if(x==tag[i])
            price[i]=0;
    }
}
void items :: show_list()
{
    if(count!=0){
        cout<<"Here is the list of items:"<<endl;
        cout<<"item tag     price"<<endl;
        for(int i=0; i<count; i++){
        cout<<tag[i]<<"        "<<price[i]<<endl;
        }
    }
    else
        cout<<"Alas!There is no item."<<endl;
}

int main()
{
     int a;
    do
    {
        items ob1;

        cout<<"If you want to add item press 1."<<endl;
        cout<<"If you want to know the sum of items press 2."<<endl;
        cout<<"If you want to delete an item press 3"<<endl;
        cout<<"If you want to see the list press 4."<<endl;
        cout<<"If you want to quit press 5."<<endl;
        cout<<"Enter key:   ";
        cin>>a;
        switch(a)
        {
            case 1:ob1.add_item();
                break;
            case 2:ob1.show_sum();
                break;
            case 3:ob1.delete_item();
                break;
            case 4:ob1.show_list();
                break;
            case 5:
                cout<<"You are quitting now.Exiting......."<<endl;
                break;
            default:
                cout<<"Invalid key.press again."<<endl;
        }
        cout<<endl;
        cout<<endl;

    }while(a!=5);
}
