#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("smallsort.in");
	ofstream fout("smallsort.out");
	int n;
	long long ni;
	long long mas_ni[10000];
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> mas_ni[i];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (mas_ni[j] > mas_ni[j+1])
				swap(mas_ni[j], mas_ni[j+1]);
		}
	}
	for (int i = 0; i < n; i++) {
		fout << mas_ni[i] <<' ';
	}
	fin.close();
	fout.close();
	return 0;
}
