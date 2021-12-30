#include <iostream>
#include <fstream>

using namespace std;
int main() {
	ifstream fin("sortland.in");
	ofstream fout("sortland.out");
	long long n;
	double poor, middle, rich;
	double money[9999];
	double mas_index[9999];
	fin >> n;
	for (int i = 1; i <= n; i++) {
		fin >> money[i];
		mas_index[i] = i;
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = 1; j <= n-1; j++) {
			if (money[j] > money[j + 1]) {
				swap(money[j], money[j + 1]);
				swap(mas_index[j], mas_index[j + 1]);
			}
		}
	}
	poor = mas_index[1];
	rich = mas_index[n];
	middle = mas_index[(n+1) / 2];
	fout << poor << ' ' << middle << ' ' << rich;
	fin.close();
	fout.close();
	return 0;
}
