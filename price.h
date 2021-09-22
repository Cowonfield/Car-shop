#include <Windows.h>
#include <iomanip>
#include<string>
#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};
void SetColor(int, int);


class price {
public:
    vector<string>m_;
    vector<string>a_;
    vector< int>car_price_;
    vector<int>acces_price_;
    price();
    price(vector<string>, vector<string>, vector<int>, vector<int>);
    price add_model(price&);
    price add_accessories(price&);
    price change_price(price&);
    price dell(price&);
};
