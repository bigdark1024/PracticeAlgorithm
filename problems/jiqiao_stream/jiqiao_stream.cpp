#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    string ip_string = "3.15.88.5";
    stringstream ss(ip_string);
    string p;
    const char cc = ',';
    while (std::getline(ss, p, cc)) {
        cout << p << " " << endl;
    }
    return 0;
}
