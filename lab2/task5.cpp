#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
void qsort(vector < int> &mas, int left, int right,int k){
    if (left >= right) return;
    int i, j;
    int key = mas[(left + right) / 2];
    i = left; 
    j = right;
    while (i<=j){
        while (mas[i] < key){
            i++;
        }
        while (mas[j] > key ){
            j--;
        }
        if (i<=j){
            swap(mas[i++], mas[j--]);
        }
    }
    if (k <= j){
        return qsort(mas, left, j, k);
    }
    else{
        return qsort(mas, i, right, k);
    }
}
 
int main(){
    ifstream k_in;
    ofstream k_out;
    k_in.open("kth.in");
    k_out.open("kth.out");
    int n, k, a, b, c, a1, a2;
    k_in >> n >> k;
    k_in >> a >> b >> c >> a1 >> a2;
    vector <int> mas(30000000);
    mas[0] = a1;
    mas[1] = a2;
    for (int i=2; i<n ; i++){
        mas[i] = a*mas[i-2] + b*mas[i-1] + c;
    }
    qsort(mas, 0, n-1, k-1);
     
    /*for (int i=0; i<n ; i++){
        k_out << mas[i] << ' ';
    }*/
    k_out << mas[k-1];
    k_in.close();
    k_out.close();
}
