#include"price.h"
void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
   price:: price() :m_{}, a_{}, car_price_{}, acces_price_{}{}
   price:: price(vector<string>mod, vector<string>acces, vector<int> car_price, vector<int> acces_price) :
        m_(mod), a_(acces), car_price_(car_price), acces_price_(acces_price) {}
   price price::add_model(price& p) {
        string tmp;
        int pr;
        cout << "Enter new model- ";
        getline(cin, tmp);
        p.m_.push_back(tmp);
        cout << "Enter price of new model- ";
        cin >> pr;
        p.car_price_.push_back(pr);
        return p;
    }
    price price:: add_accessories(price& p) {
        string tmp;
        int pr;
        cout << "Enter new accessories- ";
        getline(cin, tmp);
        p.a_.push_back(tmp);
        cout << "Enter price of new accessories- ";
        cin >> pr;
        p.acces_price_.push_back(pr);
        return p;
    }
    price price:: change_price(price& p) {
        int tmp, n;

        cout << "If you want change car price enter 1, accessories-2\n"; cin >> n;
        cin.ignore();
        if (n == 1) {
            cout << "Enter car model choose from list\n";
            for (int i = 0; i < p.m_.size(); i++)
                cout << i + 1 << "\t" << p.m_[i] << "\n";
            int choice;
            cin >> choice;
            if (choice > p.m_.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice!");
            }
            choice--;
            cout << "Enter new price: "; cin >> tmp;

            for (int j = 0; j < p.car_price_.size(); j++)
            {
                p.car_price_[choice] = tmp;
                return p;
            }

        }

        else if (n == 2) {
            cout << "Enter car model choose from list\n";
            for (int i = 0; i < p.a_.size(); i++)
                cout << i + 1 << "\t" << p.a_[i] << "\n";
            int choice;
            cin >> choice;
            if (choice > p.a_.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice!");
            }
            choice--;
            cout << "Enter new price: "; cin >> tmp;
            for (int j = 0; j < p.acces_price_.size(); j++)
            {
                p.acces_price_[choice] = tmp;
                return  p;
            }

        }

    }
    price price::dell(price& p) {
        int n;
        cout << "If you want dell car enter 1, accessories-2\n"; cin >> n;
        cin.ignore();
        if (n == 1) {
            cout << "Enter car model choose from list\n";
            for (int i = 0; i < p.m_.size(); i++)
                cout << i + 1 << "\t" << p.m_[i] << "\n";
            int choice;
            cin >> choice;
            if (choice > p.m_.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice!");
            }
            choice--;
            p.m_.erase(p.m_.begin() + choice);
            p.car_price_.erase(p.car_price_.begin() + choice);
        }
        else if (n == 2)
        {
            cout << "Enter accessore choose from list\n";
            for (int i = 0; i < p.a_.size(); i++)
                cout << i + 1 << "\t" << p.a_[i] << "\n";
            int choice;
            cin >> choice;
            if (choice > p.a_.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice!");
            }
            choice--;
            p.a_.erase(p.a_.begin() + choice);
            p.acces_price_.erase(p.acces_price_.begin() + choice);

        }
        return p;
    }


