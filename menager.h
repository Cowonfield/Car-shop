#include"Order.h"

    class menager :protected Order {
    public:
        vector<Order> z_m;
        menager();
        menager(vector<Order> , string, string , string , double , vector<string>, vector<string>, vector< int>, vector<int>);
        void save(Order&);

        void find_ord(menager&, price&);
        vector<Order> dell_ord(menager&);
        void save_f(menager&, price&, string);
        void load(string);
    };
    


