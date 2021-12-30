#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    long long a, b, c;
    ifstream aplusb_in;
    ofstream aplusb_out;
    aplusb_in.open("aplusbb.in");
    aplusb_out.open("aplusbb.out");
    aplusb_in >> a >> b;
    aplusb_out << a+b*b;
    aplusb_in.close();
    aplusb_out.close();
    return 0;
}
