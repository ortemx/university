#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#define st string

using namespace std;

class Product{
private:
    st name;
    st manufacturer;
    int cost;
    int shelf_life;
    int amount;
public:
    st get_name(){
        return name;
    }
    int  get_cost(){
        return cost;
    }
    int  get_shelf_life(){
        return shelf_life;
    }

    void set_name(st P_name){
        name = P_name;
    }
    void show(){
        cout<<"name:"<< name
        <<" manufacturer:" << manufacturer
        <<" cost:" << cost
        <<" shelf_life:" << shelf_life
        <<" amount:" << amount<<endl;
    }
    Product(){};
    Product(st P_name, st P_mf, int P_cost, int P_sl, int P_amount ){
        name = P_name;
        manufacturer = P_mf;
        cost = P_cost;
        shelf_life = P_sl;
        amount = P_amount;
    }
};

template <class T>
void v1(T tovar){
    //st pivot_name = "apple";
    st pivot_name;
    cout<<"введите интересующие наименование"<<endl; cin>>pivot_name;
    for ( int i=0; i<4 ; i++ ){
        if (tovar[i].get_name()== pivot_name){
            //cout<<tovar[i].get_name()<<endl;
            tovar[i].show();
        }
    }
}
template <class T>
void v2(T tovar){
    //st pivot_name = "apple";
    //int pivot_cost = 70;
    st pivot_name;
    int pivot_cost;
    cout<<"введите интересующие наименование"<<endl; cin>>pivot_name;
    cout<<"введите необходимую цену"<<endl; cin>>pivot_cost;
    for ( int i=0; i<4 ; i++ ){
        if (tovar[i].get_name() == pivot_name &&
            tovar[i].get_cost() <= pivot_cost){
            //cout<<tovar[i].get_name()<<endl;
            tovar[i].show();
        }
    }
}
template <class T>
void v3(T tovar){
    //int pivot_sl = 5;
    int pivot_sl;
    cout<<"введите необходимый срок хранения"<<endl; cin>>pivot_sl;
    for ( int i=0; i<4 ; i++ ){
        if (tovar[i].get_shelf_life() == pivot_sl){
            //cout<<tovar[i].get_name()<<endl;
            tovar[i].show();
        }
    }
}
int main()
{
    setlocale( LC_ALL,"Russian" );

    Product tovar [4] = {
        //       name    manufacturer  cost    SL amount
        Product("apple",    "russia",   60,     4, 10),
        Product("apple",    "china",    140,    5, 90),
        Product("pear",     "argentina",70,     5, 40),
        Product("pear",     "ekvador",  30,     6, 60)
    };
    //v1(tovar);
    //v2(tovar);
    v3(tovar);
return 0;
}
