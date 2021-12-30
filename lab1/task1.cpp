#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    long long a, b;
    ifstream aplusb_in;
    ofstream aplusb_out;
    aplusb_in.open("aplusb.in");
    aplusb_out.open("aplusb.out");
    aplusb_in >> a >> b;
    aplusb_out << a + b;
    aplusb_in.close();
    aplusb_out.close();
    return 0;
}
