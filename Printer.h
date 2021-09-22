#include"menager.h"
class Print :protected Order {
public:
    void show_price(price&);
    void show_ord(Order&); 
    void show_list(menager&, price&);
 };

