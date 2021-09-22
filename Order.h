#include "price.h"
class Order :public price {
public:
    string model_;
    string color_;
    string accessories_;
    double order_price_;
    Order();
    Order(string, string, string , double, vector<string>, vector<string>, vector<int>, vector<int>);
    Order add(Order&, price&);
    void edit(Order&, price&);
};


