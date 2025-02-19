#include <iostream>
using namespace std;

int main() {
    int arr[] = { 4, 16, 14, 9, 10};
    int first =  arr[0] ; 
    int second = -1;
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        if (arr[i]  > first)
        {
            first = arr[i];
        }
        
    }
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > second && arr[i] < first)
        {
            second =arr[i];
        }
        
    }

    cout << "Second Largest number is : " << second << "\n";
    

}