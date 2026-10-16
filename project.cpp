 #include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
using namespace std;
int less_amount(int money,int price)
{
    while(money<price){
        int more;
        int diff = price-money;
        cout <<"Please deposit another "<< diff<<"Rupees!\nIf you want to cancel please enter 0\n";
        cin >> more;
        if(more==0)
            {
                cout<<"Returning your money :< ["<<money<<" Rupees] \n";
                cin.get() >> more;
                return 0;
            }
        money = money + more;}
    return money;
}
int main()
{
        unordered_map<string, int> menu;
        menu.insert({"Mango Juice",50});
        menu.insert({"Sprite",80});
        menu.insert({"Dew",80});
        menu.insert({"Fanta",100});
        menu.insert({"Coke",80});
        menu.insert({"Nescafe Latte",150});
        menu.insert({"Red Bull",200});
        int x;
        start:
        int i=1;
            cout << "Please select one of the following\n";
            for(const auto& pair : menu)
            {
                cout<<i<<". "<<pair.first<<"[Rs. "<<pair.second<<"]\n";
                i++;
            }
            cin >> x;
            if (0>x || x>7){
                cout<<"Invalid Choice\n";
                cin.get() >>x;
                goto start;
            }
            int money;
            i=1;
            for(const auto& pair : menu)
            {
                if (i == x)
                {
                    cout<<"Please Deposit "<<pair.second<<"\n(Type in the value)\n";
                    cin>>money;
                    if(money<pair.second)
                        { money = less_amount(money,pair.second);
                        if(money==0){goto stop;}}
                    if(money>pair.second)
                        { 
                            int change = money-pair.second;
                            cout <<"Here is your change [Rs. "<<change<<"]\n";
                        }
                    break;
                }
                else
                {
                    i=i+1;
                }
            }
            cin.get()>>x;
            cout<<"Enjoy your drink!";
            stop:
                cin.get()>>x;
            cout<<"Do you want to buy another drink?\ny or n\n";
            char option;
            cin.get(option);
            if (option=='y')
            {goto start;}
            else if (option=='n'){
                cout<<"Have a Good Day!";
                cin.get()>>x;
                return 0;
            }
            else {
                cout<<"Congratulations! You are off superior intellect.";
                cin.get(option);
                return 0;
            }
//hello
//wazzup
//update
}