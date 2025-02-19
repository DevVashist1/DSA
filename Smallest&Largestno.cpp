#include <iostream>
using namespace std;

int main() {
    int arr[] = { 2, 14, 9, 23, 31};
    int first = INT_MIN;
    int second = INT_MAX; 
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        if ( arr[i] > first ) {
            first = arr[i];
        }
        if (arr[i] < second)
        {
            second = arr[i];
        }
        
    }
    cout << "Largest no. is : " << first <<"\n";
    cout << "Smallest no. is : " << second <<"\n";
    
}