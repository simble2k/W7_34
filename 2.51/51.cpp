#include <iostream>
using namespace std;

int main(){
    cout << "Enter number of element: ";
    int n; cin >> n;
    int* arr = new int[n];
    cout << "Enter all elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Elements: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    cout << "Sum of all elements: ";
    cout << sum << '\n';
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    cout << "Largest value: ";
    cout << max << '\n';
    cout << "Enter index to delete: ";
    int pos; cin >> pos;
    for(int i = pos; i < n - 1;i++){
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Elements: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
    cout << "Enter index to insert: ";
    int idx; cin >> idx;
    cout << "Enter element to add: ";
    int num; cin >> num;
    int* newArr = new int[n+1];
    for(int i = 0; i < idx; i++) newArr[i] = arr[i];
    newArr[idx] = num;
    for(int i = idx; i < n; i++) newArr[i+1] = arr[i];
    delete[] arr;
    arr = newArr;
    n++;
    cout << "Elements: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n/2; i++){
        swap(arr[i],arr[n-i-1]);
    }
    cout << "Reserved elements: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
    delete[] arr;
    arr = nullptr;
    return 0;
}