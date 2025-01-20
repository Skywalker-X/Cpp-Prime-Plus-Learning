#include<iostream> 
#include<cmath>
#include<stdexcept>
#include<string>

using namespace std;

class bad_hmean : public logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a=0, double b=0, string s="invalid arguments: a = -b not allowed\n") : logic_error(s), v1(a), v2(b) {}
};

class bad_gmean : public logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a=0, double b=0, string s="gmean() arguments should be >= 0\n") : logic_error(s), v1(a), v2(b) {}
};

double hmean(double a, double b)
{
    if(a==-b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if(a<0 || b<0)
        throw bad_gmean(a, b);
    return sqrt(a * b);
}

int main()
{
    double x, y, z;

    cout<<"Enter two numbers: ";
    while(cin>>x>>y)
    {
        try{
            z = hmean(x, y);
            cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "<<z<<endl;
            cout<<"Geometric mean of "<<x<<" and "<<y<<" is "<<gmean(x, y)<<endl;
            cout<<"Enter next set of numbers <q to quit>: ";
        }
        catch(bad_hmean & bg)
        {
            cout<<bg.what();
            cout<<"Try again.\n";
            continue;
        }
        catch(bad_gmean & hg)
        {
            cout<<hg.what();
            cout<<"Values used: "<<hg.v1<<", "<<hg.v2<<endl;
            cout<<"Sorry, you don't get to play any more.\n";
            break;  
        }
    }

    cout<<"Bye!\n";
    return 0;
}