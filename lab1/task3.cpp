#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int h, w, i;
	long long field[1000][1000];
	ifstream fin("turtle.in");
	ofstream fout("turtle.out");
	fin >> h >> w;
	for (i = 1; i <= h+1; i++) {
		for (int j = 0; j <= w; j++) {
			if (i == h + 1 || j == 0)
				field[i][j] = 0;
			else
			  fin >> field[i][j];
		}
	}
	
	for (int i = h ; i >= 0; i--) {
		for (int j = 1; j <= w; j++) {
			if (field[i][j - 1] > field[i + 1][j]) {
				field[i][j] += field[i][j - 1];
			}
			else
				field[i][j] += field[i + 1][j];
		}
	}
	fout << field[1][w];
	fin.close();
	fout.close();
	return 0;
}
