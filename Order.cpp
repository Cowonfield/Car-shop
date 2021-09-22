#include"Order.h"

   Order:: Order() : price(), model_(""), color_(""), accessories_(""), order_price_(0) {}
   Order:: Order(string model, string color, string accessories, double ord_price, vector<string>mod, vector<string>acces, vector<int> car_price, vector<int> acces_price) :
        price(mod, acces, car_price, acces_price), model_(model), color_(color), accessories_(accessories), order_price_(ord_price) {}


  Order Order::add(Order& ord, price& p)
    {
      float NDS = 0;
      cout << "Enter number car model in list\n";
      for (int i = 0; i < p.m_.size(); i++)
          cout << i + 1 << "\t" << p.m_[i] << "\n";
      int choice;
      cin >> choice;
      if (choice > p.m_.size())
      {
          SetColor(4, 15);
          throw exception("Wrong choice try agan!\n");
      }
      choice--;
      for (auto i = p.m_.begin(); i < p.m_.end(); i++)
          ord.model_ = p.m_[choice];
      cin.ignore();
      cout << "Choose color: "; getline(cin, ord.color_);
      cout << "Enter number of accessore in list \n";
          for (int i = 0; i < p.a_.size(); i++)
              cout << i + 1 << "\t" << p.a_[i] << "\n";
          cin >> choice;
          if (choice > p.a_.size())
          {
              SetColor(4, 15);
              throw exception("Wrong choice try agan!\n");
          }
          choice--;
          for (auto i = p.a_.begin(); i < p.a_.end(); i++)
               ord.accessories_ = p.a_[choice];
       int k = 0;
      int c=0;
      for (int j = 0; j < p.m_.size(); j++)
      {
          if (ord.model_ == p.m_[j])
               c = j;
      }
      for (int j = 0; j < p.a_.size(); j++)
      {
          if (ord.accessories_ == p.a_[j])
               k = j;
      }
      for (int j = 0; j < p.acces_price_.size(); j++)
      {
         if (j == k)
              for (int i = 0; i < p.car_price_.size(); i++)
              {
                  if (i == c)
                  {
                      NDS = static_cast<float>(((p.car_price_[i] + p.acces_price_[j]) / 100) * 20);
                      order_price_ = static_cast<double>((p.car_price_[i] + p.acces_price_[j]) + NDS);
                  }
              }
      }
       SetColor(1, 15);
     cout << "NDS- " << NDS << endl;
     cout << "Total price- " << order_price_ << endl;
      SetColor(0, 15);
 
      return ord;

    }
 void Order::edit(Order& ord, price& p) {
        float NDS = 0;
        int n;
        cout << "Enter choice:\n1-for edit model,2-for edit color,3-for add  accessories\n";
        cin >> n;
        cin.ignore(32767, '\n');
        switch (n)
        {
        case 1:
            cout << "Enter car model choose from list\n";
            for (int i = 0; i < p.m_.size(); i++)
                cout << i + 1 <<"\t"<< p.m_[i] << "\n";
            int choice;
            cin >> choice;
            if (choice > p.m_.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice try agan!\n");
            }
            choice--;
            for (int i = 0; i < p.m_.size(); i++)
                ord.model_ = p.m_[choice];
            break;
        case 2:
            cout << "Enter new color\n"; getline(cin, ord.color_);
            break;
        case 3:
            cout << "Enter your choice:choose from list\n";
            for (int i = 0; i < p.a_.size(); i++)
                cout << i + 1 << "\t" << p.a_[i] << "\n";
            cin >> choice;
            if (choice > p.a_.size())
            {
                SetColor(4, 15);
                throw exception("Wrong choice try agan!\n");
            }
            choice--;
            for (int i = 0; i < p.a_.size(); i++)
            {
                ord.accessories_ = p.a_[choice];
            }
        default:
            cout << "Wrong choice\n";
            break;
        }
        int k = 0;
        int c = 0;
        for (int j = 0; j < p.m_.size(); j++)
        {
            if (ord.model_ == p.m_[j])
                c = j;
        }
        for (int j = 0; j < p.a_.size(); j++)
        {
            if (ord.accessories_ == p.a_[j])
                k = j;
        }
        for (int j = 0; j < p.acces_price_.size(); j++)
        {
            if (j == k)
                for (int i = 0; i < p.car_price_.size(); i++)
                {
                    if (i == c)
                    {
                        NDS = static_cast<float>(((p.car_price_[i] + p.acces_price_[j]) / 100) * 20);
                        order_price_ = static_cast<double>(p.car_price_[i] + p.acces_price_[j]) + NDS;
                    }
                }
        }
        SetColor(1, 15);
        cout << "NDS- " << NDS << endl;
        cout << "Total price- " << order_price_ << endl;
        SetColor(0, 15);
 }
 


