//25125080
//PHAM QUOC BAO
//25A02
#include <iostream>
using namespace std;
int* returnPointer(int* a, int n){
    if(n <= 0) return nullptr;
    int m = n*2;
    int* b = new int[m];
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
    for(int i = n; i < m; i++){
        b[i] = 0;
    }
    return b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int* b = returnPointer(a,n);
    for(int i = 0; i < 2*n;i++){
        cout << b[i] << " ";
    }
    delete[] a;
    a = nullptr;
    delete[] b;
    b = nullptr;
    return 0;
}