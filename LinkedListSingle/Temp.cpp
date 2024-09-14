#include <iostream>

using namespace std;

namespace HelloWorld {
    void printHello () {
        cout << " Hello \n";
    }
};
int main(void) {
    HelloWorld::printHello();
    return 0;
}


// namespace First {
//     class Person {
//         public:
//         string name;
//         int age;
//     };
// };

// namespace Second {
//     class Person {
//         public:
//         char name;
//         int age;
//     };
// };

// int main(void) {
//     First::Person per1;
//     per1.name = "string";
//     Second::Person per2;
//     per2.name = 's';

//     cout << &per1 << " " << &per2 << "\n";
//     return 0;
// }