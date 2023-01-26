#include <iostream>
#include <iomanip>
using namespace std;

class product{
    string name;
    string manufacturer;
    int price;
    int shelf_life;
    int in_stock;
public :
    product(){}
    product(string name, string manufacturer, int price, int shelf_life, int in_stock){
        this->name = name;
        this->manufacturer = manufacturer;
        this->price = price;
        this->shelf_life = shelf_life;
        this->in_stock = in_stock;
    }
    void show (){
        cout << "\nname: \t\t" << name;
        cout << "\nmanufacturer: \t"  << manufacturer;
        cout << "\nprice: \t\t" <<  price;
        cout << "\nshelf life: \t" << shelf_life;
        cout << "\nin stock: \t" << in_stock;
    }
    string getName(){ return this->name;}
    int getPrice(){ return this->price;}
    int getShelf_life(){ return this->shelf_life;}
    void setName(string name){this->name = name;}
    void setManufacturer(string manufacturer){this->manufacturer = manufacturer;}
    void setPrice(int price){this->price = price;}
    void setShelf_life(int shelf_life){this->shelf_life = shelf_life;}
    void setNumber_in_stock(int in_stock){this->in_stock = in_stock;}
    ~product(){}
};
int main(){
    int n;
    cout << "enter number of products "; cin >> n;
    product* products = new product[n];
//    products[0] = product("yabloko", "DarKubani", 84, 90, 10800);
//    products[1] = product("yabloko", "DarRostova", 65, 100, 10800);
//    products[2] = product("pechenie", "Sladkoezhka", 84, 90, 10800);
//    products[3] = product("dub", "lesaSibiri", 150000, 400, 10800);
//    products[4] = product("dub", "Ogonek", 120000, 300, 10800);
    string temp_s;
    int temp_i;
    for (int i = 0; i < n; i++){
        cout << "enter product's name "; cin >> temp_s; products[i].setName(temp_s);
        cout << "enter product's manufacturer "; cin >> temp_s; products[i].setManufacturer(temp_s);
        cout << "enter product's price "; cin >> temp_i; products[i].setPrice(temp_i);
        cout << "enter product's shelf life "; cin >> temp_i; products[i].setShelf_life(temp_i);
        cout << "enter number in stock "; cin >> temp_i; products[i].setNumber_in_stock(temp_i);
    }
    for (int i = 0; i < n; i++){ products[i].show();}
    string product_name;
    cout << "enter product's name "; cin >> product_name;
    for (int i = 0; i < n; i++){
        if (products[i].getName() == product_name){
            products[i].show();
        }
    }
    int price;
    cout << "\n\nenter product's name "; cin >> product_name;
    cout << "enter product's price "; cin >> price;
    bool f = true;
    for (int i = 0; i < n; i++){
        if (products[i].getName() == product_name){
            if (products[i].getPrice() <= price){
                products[i].show();
                f = false;
            }
        }
    }
    if (f) cout << "\nno found";

    int shelf_life;
    cout << "\n\nenter product's shelf life "; cin >> shelf_life;
    for (int i = 0; i < n; i++){
        if (products[i].getShelf_life() > shelf_life){
            products[i].show();
        }
    }
    return 0;
}
