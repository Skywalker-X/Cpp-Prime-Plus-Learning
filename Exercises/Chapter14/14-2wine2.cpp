#include<iostream>
#include<valarray>

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
};

template <class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}


typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private PairArray
{
private:
    std::string label;
    int years;
public:
    Wine(const char * l, int y, const int yr[], const int bot[])
        : label(l), years(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}
    Wine(const char * l, int y)
        : label(l), years(y), PairArray(ArrayInt(y), ArrayInt(y)) {}
    void GetBottles();
    const std::string & Label() const { return label; }
    int sum() const { return second().sum(); }
    void Show() const;
};

void Wine::GetBottles()
{
    using std::cout;
    using std::cin;
    cout << "Enter " << label << " data for " << years << " year(s):\n";
    for (int i = 0; i < years; i++)
    {
        cout << "Enter year: ";
        cin >> first()[i];
        cout << "Enter bottles for that year: ";
        cin >> second()[i];
    }
}

void Wine::Show() const
{
    using std::cout;
    using std::endl;
    cout << "Wine: " << label << endl;
    cout << "\tYear\tBottles\n";
    for (int i = 0; i < years; i++)
        cout << "\t" << first()[i] << "\t" << second()[i] << endl;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS = 3;

    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48, 60, 72 };

    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
    cout << "Bye\n";

    return 0;
}