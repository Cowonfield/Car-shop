#include"Printer.h"
int main()
{
    Order ord;
    Print s;
    menager m;
    vector<string>model{ "Opel 1,9", "Opel 2,5","Ford 1,3","Ford 3,0","Honda 3 ","Honda 5 ", };
    vector<string>accessories{ "covers","rugs","fire_extinguisher","first_aid_kit","disks","wheel_caps","winter_wheels" };
    vector<int> car_price{ 200000,250000,150000,300000,400000,430000 };
    vector<int>acces_price{ 200,500,150,70,2000,540,2500 };
    price p(model, accessories, car_price, acces_price);
    int ch, ch_m;
    bool job = 1;
    string path;
    while (job) {

        cout << "Enter your choice:\n1-look price,\n2-make order,\n3-edit your order,\n4-show order,\n";
        cout << "5-look order list,\n6-find order in list,\n7-save list,\n8-read from file,\n";
        cout << "9-add model to pricelist,\n10-add new accessorie,\n11-change price,\n12-Dell element from pricelist,\n13-delete order,\n0-exit\n ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            s.show_price(p);
            break;
        case 2:
            try {
                ord = ord.add(ord, p);
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }
            SetColor(0, 15);

            cout << "If you want save this order press 1:\n"; cin >> ch;
            if (ch == 1)
                m.save(ord);
            SetColor(4, 15);
            cout << "Your order was saved successfully!\n";
            SetColor(0, 15);
            break;
        case 3:
            try {
                ord.edit(ord, p);
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }
            SetColor(0, 15);
            cout << "If you want save this order press 1:\n"; cin >> ch;
            if (ch == 1)
                m.save(ord);
            break;
        case 4:
            s.show_ord(ord);
            break;

        case 5:
            s.show_list(m, p);
            break;
        case 6:
            try {
                m.find_ord(m, p);
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }
            SetColor(0, 15);
            break;

        case 7:
            cout << "Enter filename- ";
            cin.ignore();
            getline(cin, path);
            m.save_f(m, p, path);
            break;
        case 8:
            cout << "Enter filename- ";
            cin.ignore();
            getline(cin, path);
            try {
                m.load(path);
            }
            catch (const ifstream::failure& ex) {
                cout << ex.what() << endl;
                cout << ex.code() << endl;
            }
            SetColor(0, 15);
            break;
        case 9:
            cin.ignore();
            p.add_model(p);
            break;
        case 10:
            cin.ignore();
            p.add_accessories(p);
            break;
        case 11:
            try {
                p.change_price(p);
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }
            SetColor(0, 15);
            break;
        case 12:
            try {
                p.dell(p);
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }
            SetColor(0, 15);
            break;
        case 13:
            try {
                m.dell_ord(m);
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }
            SetColor(0, 15);
            break;
        case 0:
            job = 0;
            break;
        default:
            cout << "Wrong choice\n";
        }
    }
}
        

