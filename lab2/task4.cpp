                #include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
/*void qsort(int left, int right){
    int i, j, key;
    key = mas[(left + right ) /2];
    i = left;
    j = right;
    while (i<j){
        while (mas[i] < key){
            i++;
        }
        while (mas[j]>key){
            j--;
        }
        if (i<=j)
            swap(mas[i++], mas[j--]);
    }
    if (left<j) qsort(left, j);
    if (right>i) qsort(i, right);
}
*/

int main(){
    ifstream antiqs_in;
    ofstream antiqs_out;
    antiqs_in.open("antiqs.in");
    antiqs_out.open("antiqs.out");
    int n;
    
    antiqs_in >> n;
    int *mas = new int[n];
    for (int i=0; i<n; i++){
        mas[i] = i+1;
    }
    
    for (int i=0; i<=n-1; i++){
        swap(mas[i], mas[i/2]);
    }
    //qsort(0, n-1);
    for (int i=0; i<n; i++){
        antiqs_out << mas[i] << ' ';
    }

    antiqs_in.close();
    antiqs_out.close();
    return 0;
}
