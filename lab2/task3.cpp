#include <iostream>
#include <vector>
#include <string>
#include <fstream>
typedef long long ll;
using namespace std;
ll CountInv = 0;
void merge(ll *mas, ll left, ll mid, ll right){
    ll it1 = 0;
    ll it2=0;
    ll *SortedMas = new ll[right - left];
    while (left + it1 < mid && mid + it2  < right){
        if (mas[left + it1] <= mas[mid + it2]){
            SortedMas[it1+it2] = mas[left+it1];
            it1+=1;
        }
        else{
            SortedMas[it1+ it2] = mas[mid + it2];
            it2+=1;
            CountInv += (mid - it1 - left);
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
 
void sort(ll *a, ll left, ll right){
    if (left + 1>=right )
        return;
    ll mid = (right + left)/2;
    sort(a,left, mid);
    sort(a, mid, right);
    merge(a, left, mid, right);
}
 
 int main(){
     
     ifstream inversions_in;
     ofstream inversions_out;
     inversions_in.open("inversions.in");
     inversions_out.open("inversions.out");
     ll n;
     inversions_in >> n;
     ll *InputMas = new ll[n];
     for (int i=0; i<n; i++){
         inversions_in >> InputMas[i];
     }
     sort(InputMas, 0, n);
     inversions_out << CountInv;
     inversions_out.close();
     inversions_in.close();
     return 0;
 }
