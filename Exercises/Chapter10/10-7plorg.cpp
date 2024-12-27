#include <iostream>
#include <cstring>
using namespace std;

class Plorg {
private:
    static const int NAME_LEN = 19;
    char name[NAME_LEN];
    int CI;

public:
    Plorg(const char *n = "Plorga", int ci = 50) {
        strncpy(name, n, NAME_LEN - 1);
        name[NAME_LEN - 1] = '\0';
        CI = ci;
    }

    void setCI(int ci) {
        CI = ci;
    }

    void show() const {
        cout << "Name: " << name << ", CI: " << CI << endl;
    }
};

int main() {
    Plorg p1;
    p1.show();

    Plorg p2("Betelgeusean", 100);
    p2.show();

    p2.setCI(75);
    p2.show();

    return 0;
}
