#include<iostream>
#include<vector>
#include<array>
#include<typeinfo>
#include <fstream>
#include <set>
#include <sstream>
#include <iterator>

using namespace std;
	void displayStockDatabase(const string& filename);
	vector<string>splitString(const string& str, char delimiter);


class AccountingSystem{
private:
    vector<array<string, 4>> sale;
    double total_capital;
public:
    double total_amount_sold;
    AccountingSystem(){
        // creates an array of 4 empty strings
        std::array<std::string, 4> arr = {"fine", "", "", ""};
        this->sale.push_back(arr);

        std::vector<std::array<std::string, 4>> testSale;
        std::array<std::string, 4> arr1 = {"itel", "phone", "50000", "5"};
        std::array<std::string, 4> arr2 = {"iphone", "charger", "12000", "12"};

        testSale.push_back(arr1);
        testSale.push_back(arr2);

        this->updateSalesDb(testSale);

    }

    bool updateSalesDb(vector<array<string, 4>> (&arrayPointer)) {
        for(int unsigned i=0; i<arrayPointer.size(); i++){
            this->sale.push_back(arrayPointer[i]);
        }
        return true;
    }
    vector<array<string, 4>>* getDbValues(){
        return &this->sale;
    };
    void DisplayDbValues(){
        for(int unsigned i=0; i<this->sale.size(); i++){
            for(int j=0; j<4; j++){
                cout << this->sale[i][j] << "\t";
            } cout << endl;
        }
    };

};

class Product{
private:
    int product_id;
    string brand;
    string category;
    double price;
    int quantity;
    double promotions;
    double profitperproduct;
public:
    Product(int pid, string b , string c, double pr , int qtt):product_id(pid), brand(b), category(c), price(pr), quantity(qtt) {
        this->promotions = 1;
    }
    int getProductId(){
        return this->product_id;
    }
    string getBrand(){
        return this->brand;
    }
    void setBrand(string value){
        this->brand = value;
    }
    string getCategory(){
        return this->category;
    }
    void setCategory(string value){
        this->category = value;
    }
    int getPrice(){
        return this->price;
    }
    void setPrice(int value){
        this->price = value;
    }
    int getQuantity(){
        return this->quantity;
    }
    void updateQuantityBy(int value){
        this->quantity += value;
    }
    double getPromotions(){
        return this->promotions;
    }
    void setPromotions(double value){
        if(value >= 0 && value <= 100){
            this->promotions = this->promotions - value/100;
        } else {
            cout << "VALUE MUST BE BETWEEN 0 AND 100";
        }
    }
    double getProfit(){
        return this->profitperproduct;
    }
    void setProfit(double value){
        this->profitperproduct = value;
    }

};

class StoreManagingSystem{
private:
    int store_id;
    string store_address;
    string seller_name;
    vector<Product> products;
    AccountingSystem* AS_REF;
public:
    StoreManagingSystem(int s, string sa,AccountingSystem* as_r):store_id(s),store_address(sa), AS_REF(as_r) {
        Product prod(1, "store", "store", 0, 0);
        this->products.push_back(prod);
        Product newProd1(2, "store", "Charger", 50000, 5);
        Product newProd2(3, "itel", "Phone", 50000, 5);
        Product newProd3(4, "dell", "Laptop", 50000, 5);
        Product newProd4(5, "headphone", "Miscellaneous", 50000, 5);
        this->products.push_back(newProd1);
        this->products.push_back(newProd2);
        this->products.push_back(newProd3);
        this->products.push_back(newProd4);
    }

    void setSellerName(string value){
        this->seller_name = value;
    }
    string getSellerName(string value){
        return this->seller_name;
    }
    int getStoreId(){
        return this->store_id;
    };
    Product* getProduct(int pid){
        for(int unsigned i=0; i<products.size(); i++){
            if(products[i].getProductId() == pid){
                return &this->products[i];
            }
        } return nullptr;
    };
    void setProduct(){
        string b, c, p, q;
        bool check;
        do {
            cout << "Continue? Enter [exit] if done\n";
            cout << "Enter Product Brand: ";
            cin >> b;
            if (b != "exit") {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Enter Product Category: ";
                cin >> c;
                if (c != "exit") {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Enter Product Price: ";
                    cin >> p;
                    if (p != "exit") {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Enter Product Quantity: ";
                        cin >> q;
                        if (q != "exit") {
                            cin.clear();
                            cin.ignore(100, '\n');
                            for(int unsigned i=0; i<this->products.size(); i++){
                                if(this->products[i].getBrand() == b, this->products[i].getCategory() == c){
                                    this->products[i].updateQuantityBy(std::stoi(q));
                                    this->products[i].setPrice(std::stoi(p));
                                    check = true;
                                }
                            }
                            if(!check){
                                Product newProd(this->products.size(), b, c, std::stod(p), std::stoi(q));
                                this->products.push_back(newProd);
                            } else {
                                check = false;
                            }
                        } else {
                            break; // Exit the loop when "exit" is entered
                        }
                    } else {
                        break; // Exit the loop when "exit" is entered
                    }
                } else {
                    break; // Exit the loop when "exit" is entered
                }
            } else {
                break; // Exit the loop when "exit" is entered
            }
        } while (true);
        system("cls");
        this->checkStockCount();
    }
    void checkStockCount(){
        cout << "\n\t All PRODUCTS \n"
             << "PID\tBRAND\tCATEGORY PRICE\t  QUANTITY PROMOTIONS\n";
        for(int unsigned i=0; i<this->products.size(); i++){
            cout << this->products[i].getProductId()
                 << "\t" <<this->products[i].getBrand()
                 << "\t" << this->products[i].getCategory()
                 << "\t " << this->products[i].getPrice()
                 << "\t  " << this->products[i].getQuantity()
                 << "\t   " << this->products[i].getPromotions()
                 << endl;
        }
    };
    void chooseProducts(){
        int pid, q;
        double bill(0.0);
        vector<int> product_list;
        vector<int> quantity_list;
        vector<array<string, 4>> sl;
        Product* prod;
        char ch;
        do{
            system("cls");
            this->checkStockCount();
            cout << "Choose Product(by Product Number): ";
            cin >> pid;
            cout << "Quantity: ";
            cin >> q;
            product_list.push_back(pid);
            quantity_list.push_back(q);
            pid=0;
            cout << "Add Product(y, n): ";
            cin >> ch;
            if(ch != 'y'){
                break;
            }
        } while(true);
        if(product_list.size() != 0){
            for(int unsigned i=0; i<product_list.size(); i++){
                bill += this->products[product_list[i]].getPrice()*quantity_list[i]*this->products[i].getPromotions();
            }
            cout << "\n\t LIST OF PRODUCTS -- " << this->store_address << "\n"
                 << "BRAND\tCATEGORY PRICE\t  QUANTITY PROMOTIONS\n";

                cout<< "ok";
            for(int unsigned i=0; i<product_list.size(); i++){
                prod = this->getProduct(product_list[i]);
                if(prod == nullptr){
                    continue;
                }
                cout <<(*prod).getBrand()
                     << "\t" << (*prod).getCategory()
                     << "\t " << (*prod).getPrice()
                     << "\t  " << quantity_list[i]
                     << "\t   " << (*prod).getPromotions()
                     << endl;
            }
            cout << "\n\t\tBill: " << bill << endl;
            cout << "\t\tFinish(y/n)? ";
            cin >> ch;
            if(ch == 'y'){
                for(int unsigned i=0; i<product_list.size(); i++){
                    this->products[product_list[i]].updateQuantityBy(0-quantity_list[i]);
                    sl.push_back({this->products[product_list[i]].getBrand(),this->products[product_list[i]].getCategory(), std::to_string(this->products[product_list[i]].getPrice()), std::to_string(quantity_list[i])});
                }

                // stores sales data to the database
                if(this->AS_REF->updateSalesDb(sl)){
                    cout << "\n Successful\n";
                } else {
                    cout << "\n Redo";
                    this->chooseProducts();
                }
            }
        }
    };
    bool getProductDetails(){
        int pid;
        char ch;
        Product* prod;
        do{
            system("cls");
            this->checkStockCount();
            cout << "Enter Product Number: ";
            cin >> pid;
            prod = this->getProduct(pid);
            if(prod == nullptr){
                return false;
            }
            cout << "\n\t "<< (*prod).getBrand() << " -- " << (*prod).getCategory() << "\n"
                 << "PID\tBRAND\tCATEGORY PRICE\t  QUANTITY PROMOTIONS\n"
                 << (*prod).getProductId()
                 << "\t" <<(*prod).getBrand()
                 << "\t" << (*prod).getCategory()
                 << "\t " << (*prod).getPrice()
                 << "\t  " << (*prod).getQuantity()
                 << "\t   " << (*prod).getPromotions()
                 << endl;
            // Implement such that each product has details pertaining to it
            //cout << this->products[i].getDescription();
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nContinue(y/n)? ";
            cin >> ch;
            if(ch != 'y'){
                break;
            }
        } while(true);
        return true;
    };
    void applyPromotions (){
        int pid;
        double newPromotion;
        char ch;
        bool success;
        do{
            system("cls");
            this->checkStockCount();
            cout << "Enter Product number: ";
            cin >> pid;
            cout << "Enter New Discount: ";
            cin >> newPromotion;
            for(int unsigned i=0; i<this->products.size(); i++){
                if(this->products[i].getProductId() == pid){
                    this->products[i].setPromotions(newPromotion);
                    success = true;
                    break;
                }
            }
            if(success){
                cout << "\nSuccessful!";
                success = false;
            } else {
                cout << "\nProduct not found!";
            }
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nContinue(y/n)? ";
            cin >> ch;
            if(ch != 'y'){
                break;
            }
        } while(true);
    };

    bool runStore (){
        int i;
        do{
            cout << "\t\t" <<this->store_address << endl;
            cout << "\n1. Buy Products\n2. Add Products\n3. Check Product Details\n4.Logout\n\tChoice: ";
            cin >> i;
            system("cls");
            switch(i){
                case 1:{
                    this->chooseProducts();
                    system("cls");
                    break;
                } case 2:{
                    this->setProduct();
                    system("cls");
                    break;
                } case 3:{
                    if(!this->getProductDetails()){
                        system("cls");
                        cout << "ERR - NO SUCH PRODUCT FOUND\n";
                    } else {
                        system("cls");
                    }

                    break;
                } case 4:{
                    return true;
                    break;
                } default:{
                    system("cls");
                    continue;
                }
            }
        } while(true);
    };
};



int main(){
    int i, sid, p, pin(1234);
    string sn, ch;
    AccountingSystem as;

    StoreManagingSystem sms1(1, "Mobile", &as);
    
    

    do{
        cout << "\n1. Operations Manager Account\n2. Seller Account\n3. Exit\n\tChoice: ";
        cin >> i;
        switch(i){
            case 1:{
                cout << "Enter Seller ID: ";
                cin >> sid;
                cout << "Enter Name: ";
                cin >> sn;
                switch(sid){
                    case 1:{
                        sms1.setSellerName(sn);
                        sms1.runStore();
                        system("cls");
                        break;
                    }
                    default:{
                        system("cls");
                        cout << "\nNOT A SELLER\n";
                    }
                }
                break;
            } case 2:{
                cout << "Enter PIN: ";
                cin >> p;
                if(p == pin){
                    cout << "Select Store\n1. Mobile\nExtra\n2. Check Store Inventory\n3. Apply Promotions\tChoice: ";
                    cin >> i;
                    switch(i){
                        case 1:{
                            system("cls");
                            sms1.runStore();
                            break;
                        }
                        case 2:{
                            system("cls");
                            as.DisplayDbValues();

                            break;
                        }
                        case 3:{
                            sms1.applyPromotions();
                            break;
                        }
                    }
                }

                break;
            } case 3:{
                exit(0);
            }
        }
    } while(true);
    cout << "\nWorking!";
    return 0;
}