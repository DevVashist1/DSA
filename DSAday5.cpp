// Code to write the smallest and largest number out of an array 
#include <iostream>
using namespace std;

int main () {
    double marks[5] = {78, 56, 89, 64, 38};
    int size = 5;
    int idsno ;
    int idlno ;
    int sno = INT_MAX;
    int lno = INT_MIN;

    for ( int i = 0; i < size; i++) {
        if ( marks[i]<sno) {
            sno = marks[i];
            idsno = i;
        }
        if (lno < marks[i])
        {
            lno = marks[i];
            idlno = i;
        }
    }
    cout << "Smallest no. = " << sno << endl;
    cout << "Index of smallest no. = " <<idsno << endl;
    cout << "Largest no. = " << lno <<endl;
    cout << "Index of Largest no. = " << idlno <<endl;


}