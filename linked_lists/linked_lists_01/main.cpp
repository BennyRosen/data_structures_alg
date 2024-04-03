#include <iostream>
using namespace std;

class Cookie {
    private:
        string color;
        int hand;

    public:
        Cookie(string color) {
            this->color = color;
        }

        int getHand() {
            return this->hand;
        }

        string getColor() {
            return this->color;
        }

        void setColor(string color) {
            this->color = color;
        }
};

int main() {
    
    Cookie* cookie = new Cookie("hi");
    cout << cookie->getColor() << endl;

    int* num1 = new int(10);
    int* num2 = num1;

    *num1 = 22;

    cout << "num1: " << *num1 << endl;
    cout << "num2: " << *num2 << endl;

    return 0;
}