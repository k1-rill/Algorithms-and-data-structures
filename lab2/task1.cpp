#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
void merge(int *mas, int left, int mid, int right){
    int it1 = 0;
    int it2=0;
    int *SortedMas = new int [right - left];
    while (left + it1 < mid && mid + it2  < right){
        if (mas[left + it1] < mas[mid + it2]){
            SortedMas[it1+it2] = mas[left+it1];
            it1+=1;
        }
        else{
            SortedMas[it1+ it2] = mas[mid + it2];
            it2+=1;
        }
    }
    while (left + it1 < mid ){
        SortedMas[it1+it2] = mas[left + it1];
        it1+=1;
    }
 
    while( mid + it2 <right){
        SortedMas[it1+it2] = mas[mid + it2];
        it2+=1;
    }
    for (int i=0; i<it1+it2; i++){
        mas[left + i] = SortedMas[i];
    }
}
 
void sort(int *a, int left, int right){
    if (left + 1>=right )
        return;
    int mid = (right + left)/2;
    sort(a,left, mid);
    sort(a, mid, right);
    merge(a, left, mid, right);
}
 
int main(){
    ifstream sort_in;
    ofstream sort_out;
    sort_in.open("sort.in");
    sort_out.open("sort.out");
 
    int n; 
    sort_in >> n;
    int *MasInput = new int[n];
    for (int i=0 ; i<n; i++){
        sort_in >> MasInput[i];
    }
    sort(MasInput, 0, n);
    for (int i=0; i<n; i++){
        sort_out << MasInput[i] << ' ' ;
    }
    sort_in.close();
    sort_out.close();
    return 0;
}
