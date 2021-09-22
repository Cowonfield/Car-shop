#include"Printer.h"

    void Print::show_price(price& p) {
        for (int i = 0; i < p.m_.size() && i < p.car_price_.size(); i++)
        {
            cout << p.m_[i] << "\t" << p.car_price_[i] << "grn" << endl;
        }
        cout << endl;
        SetColor(1, 15);
        cout << "ACCESSORIES:\n";
        SetColor(0, 15);
        for (int i = 0; i < p.a_.size() && i < p.acces_price_.size(); i++)
        {
            cout << setw(17) << p.a_[i] << "\t" << p.acces_price_[i] << "grn" << endl;
        }
    }
    void Print::show_ord(Order& ord) {
        SetColor(1, 15);
        cout << "Your order :\n";
        cout << "MODEL\t" << "COLOR\t" << "ACCESSORIES\t" << "PRICE" << endl;
        SetColor(0, 15);
        cout << ord.model_ << "\t" << ord.color_ << "\t" << ord.accessories_ << ord.order_price_ << "grn" << endl;
    }

    void Print::show_list(menager& m, price& p)
    {
        SetColor(1, 15);
        cout << "#\t" << "MODEL\t\t" << "COLOR\t" << "ACCESSORIES\t" << "PRICE" << endl;
        SetColor(0, 15);
        for (int i = 0; i < m.z_m.size(); i++)
        {
            cout << i + 1 << "\t" << m.z_m[i].model_ << "\t" << m.z_m[i].color_ << "\t" << m.z_m[i].accessories_ << "\t" << m.z_m[i].order_price_ << "grn" << endl;

        }
    }


