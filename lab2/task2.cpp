#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
 
void sort(vector <pair<string, string>> &mas, int left, int mid, int right) {
    int it1 = mid - left + 1;
    int it2 = right - mid;
    vector <pair<string, string>> MasLeft(it1);
    vector <pair<string, string>> MasRight(it2);
    for (int i = 0; i < it1; i++) {
        MasLeft[i] = mas[left + i];
    }
    for (int j = 0; j < it2; j++) {
        MasRight[j] = mas[mid + 1 + j];
    }
    int index1, index2, k;
    index1 = 0;
    index2 = 0;
    k = left;
    while (index1 < it1 && index2 < it2) {
        if (MasLeft[index1].first <= MasRight[index2].first) {
            mas[k] = MasLeft[index1++];
        }
        else {
            mas[k] = MasRight[index2++];
        }
        k++;
    }
    while (index1 < it1) {
        mas[k++] = MasLeft[index1++];
    }
    while (index2 < it2) {
        mas[k++] = MasRight[index2++];
    }
}
void mergesort(vector <pair<string, string>>& mas, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        mergesort(mas, left, mid);
        mergesort(mas, mid + 1, right);
        sort(mas, left, mid, right);
    }
}
 
int main() {
    ifstream race_in;
    ofstream race_out;
    race_in.open("race.in");
    race_out.open("race.out");
     
    int n;
    race_in >> n;
    string* InputMas = new string[n];
    vector <pair<string, string>> MasCountry;
    string s, s1;
    for (int i = 0; i < n; i++) {
        race_in >> s >> s1;
        MasCountry.push_back(make_pair(s, s1));
    }
    int flag =0;
    string InputCountry;
    mergesort(MasCountry, 0, MasCountry.size()-1);
    InputCountry = MasCountry[0].first;
    race_out <<"=== "<< InputCountry << " ===" << endl;
    race_out << MasCountry[0].second<< endl;
    for (int i = 1; i < n; i++) {
        if (MasCountry[i].first!=InputCountry){
            InputCountry = MasCountry[i].first;
            race_out << "=== " << InputCountry << " ===" << endl;
        }
        race_out << MasCountry[i].second << endl;
 
    }
    race_in.close();
    race_out.close();
    return 0;
}
