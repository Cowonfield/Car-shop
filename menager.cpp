#include"menager.h"


       menager:: menager() :Order(), z_m() {}
       menager:: menager(vector<Order> z, string model, string color, string accessories, double order_price, vector<string>mod, vector<string>acces, vector< int> car_price, vector<int> acces_price) :
            Order(model, color, accessories, order_price, mod, acces, car_price, acces_price), z_m(z) {}
       void menager:: save(Order& ord)
        {
            z_m.push_back(ord);
            for (int j = 0; j < z_m.size(); j++)

                cout << z_m[j].model_ << "\t" << z_m[j].color_ << "\t" << z_m[j].accessories_<<"\t"<<z_m[j].order_price_ << endl;

        }
        void menager::find_ord(menager& m, price& p) {
            int choice;
            cout << "Enter car model choose from list\n";
            for (int i = 0; i < p.m_.size(); i++)
                cout << i + 1 << "\t" << p.m_[i] << "\n";
            cin >> choice;
            if (choice > p.m_.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice try agan!\n");
            }
            choice--;
            for (int i = 0; i < p.m_.size(); i++)
                for (int j = 0; j < m.z_m.size(); j++)
                    if (m.z_m[j].model_ == p.m_[choice])
                        cout << m.z_m[j].model_ << "\t" << m.z_m[j].color_ << "\t" << m.z_m[j].accessories_ << "\t" << m.z_m[j].order_price_ << endl;

        }
        vector<Order> menager::dell_ord(menager& m)
        {
            int choice;
            cout << "Enter car model choose from list\n";
            for (int i = 0; i < m.z_m.size(); i++)
                cout << i + 1 << "\t" << m.z_m[i].model_ << "\t" << m.z_m[i].color_ << "\t" << m.z_m[i].accessories_ << "\t" << m.z_m[i].order_price_ << "\n";
            cin >> choice;
            if (choice > m.z_m.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice try agan!\n");
            }
            choice--;
            for (int i = 0; i < m.z_m.size(); i++)
                m.z_m.erase(m.z_m.begin() + choice);
            return m.z_m;
        }
        void menager::save_f(menager& m, price& p, string path) {
            ofstream fout;
            fout.open(path);
            if (fout.is_open())
            {
                for (int i = 0; i < z_m.size(); i++)
                    fout << "Car model\t" << "Color\t" << "Accessories\t" << "Order price" << endl;
                for (int i = 0; i < z_m.size(); i++)
                {
                    fout << z_m[i].model_ << "\t" << z_m[i].color_ << "\t\t" << z_m[i].accessories_ << "\t" << z_m[i].order_price_ << endl;
                }
                fout.close();
            }
            else
            {
                SetColor(4, 15);
                cout << "can't open file" << path << endl;
                SetColor(0, 15);

            }

        }
        void menager::load(string path) {
            ifstream fin;
            fin.open(path);
            if (fin.is_open())
            {
                string tmp;
                while (!fin.eof()) {
                    getline(fin, tmp);
                    cout << tmp << endl;
                }
                fin.close();
            }
            else
            {
                SetColor(4, 15);
                fin.exceptions(ifstream::badbit | ifstream::failbit);
            }
        }

    

