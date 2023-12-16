#include<iostream>
#include<vector>
#include<array>
#include<typeinfo>

using namespace std;

class AccountingSystem{
private:
    vector<array<string, 4>> sale;
    double total_capital;
public:
    double total_amount_sold;
    AccountingSystem(){
        std::array<std::string, 4> arr = {"fine", "", "", ""};
        this->sale.push_back(arr);
        /* USED TO TEST UPDATESALESDB
        std::vector<std::array<std::string, 4>> testSale;
        std::array<std::string, 4> arr1 = {"fine", "", "great", ""};
        std::array<std::string, 4> arr2 = {"fine", "ok", "", "hello"};

        testSale.push_back(arr1);
        testSale.push_back(arr2);

        this->updateSalesDb(testSale);
        */
    }

    void updateSalesDb(vector<array<string, 4>> (&arrayPointer)) {
        cout << arrayPointer.size() << endl;
        for(int i=0; i<arrayPointer.size(); i++){
            this->sale.push_back(arrayPointer[i]);
        }

    }
    vector<array<string, 4>>* getDbValues(){
        /*
        // HOW TO ACCESS GETDBVALUES
        vector<array<string, 4>>* cpy;
        cpy = as.getDbValues();
        for(int i=0; i<(*test).size(); i++){
            for(int j=0; j<4; j++){
                cout << (*test)[i][j] << "\t";
            } cout << endl;
        }
        */
        return &this->sale;
    };
    void DisplayDbValues(){
        for(int i=0; i<this->sale.size(); i++){
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
        this->promotions = 0;
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
            this->promotions = value/100;
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
    StoreManagingSystem(int s, string sa, string sn,AccountingSystem* as_r):store_id(s),store_address(sa),seller_name(sn), AS_REF(as_r) {
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

    int getStoreId(){
        return this->store_id;
    };
    /*void setStoreId(int value){
        this->store_id = value;
    };
    */
    Product* getProduct(int pid){
        for(int i=0; i<products.size(); i++){
            if(products[i].getProductId() == pid){
                return &this->products[i];
            }
        }
    };
    void setProduct(){
        string b, c, p, q;
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
                            Product newProd(this->products.size(), b, c, std::stod(p), std::stoi(q));
                            this->products.push_back(newProd);
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
        for(int i=0; i<this->products.size(); i++){
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
        int pid;
        double bill = 0.0;
        vector<int> product_list;
        vector<double> quantity_list;
        char ch;
        do{
            system("cls");
            this->checkStockCount;
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
            for(int i=0; i<product_list.size(); i++){
                bill += this->products[i].getPrice()*quantity_list[i]*this->products[i].getPromotions();
            }
            cout << "\n\t "<< (*prod).getBrand() << " -- " << (*prod).getCategory() << "\n"
                 << "PID\tBRAND\tCATEGORY PRICE\t  QUANTITY PROMOTIONS\n";

            for(int i=0; i<product_list.size(); i++){
                prod = this->getProduct(product_list[i]);
                if(prod == nullptr){
                    continue;
                }
                cout << (*prod).getProductId()
                     << "\t" <<(*prod).getBrand()
                     << "\t" << (*prod).getCategory()
                     << "\t " << (*prod).getPrice()
                     << "\t  " << quantity_list[i]
                     << "\t   " << (*prod).getPromotions()*100
                     << endl;
            }
            cout << "\n\n\t\tBill: " << bill << endl;
            cout << "\t\tFinish(y/n)? ";
            if(ch == 'y'){
                return true;
            }
        }
    };
    bool getProductDetails(){
        int pid;
        char ch;
        Product* prod;
        do{
            system("cls");
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
            for(int i=0; i<this->products.size(); i++){
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
    void runStore (){  };
};



int main(){

    AccountingSystem as;

    StoreManagingSystem sms(1, "Funcha Junction", "Ngum Lili", &as);


    //  TEST FOR GETPRODUCTDETAILS
    sms.getProductDetails();

    /*
     TEST FOR GETPRODUCT
    Product* prod;
    prod = sms.getProduct(1);
    cout << (*prod).getCategory()<< endl;
    */
    cout << "\nWorking!";
    return 0;
}
