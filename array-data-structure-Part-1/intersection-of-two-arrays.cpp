// To find the intersection(same elements) in Two arrays

#include <iostream>
using namespace std;

int main(){

    int size1,size2;
    cout << "Enter the size of array 1 : ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter the elements of the array 1 : ";
    for (int i = 0; i < size1; i++){
        cin >> arr1[i];
    }

    cout << "Enter the size of array 2 : ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter the elements of the array 1 : ";
    for (int i = 0; i < size2; i++){
        cin >> arr2[i];
    }

    cout << "Intersection of Two arrays (is/are) : ";

    for (int i = 0; i < size1; i++){

        for (int j = 0; j < size2; j++){ 

            if (arr1[i] == arr2[j]){

                // Check if this element has already been printed
                // Check for any duplicates 

                int k;
                for (k = 0; k < i; k++) {
                    if (arr1[k] == arr1[i]) {
                        break;  // already printed
                    }
                }
                if (k == i) {
                    cout << arr1[i] << " ";
                }
                break;
            }
        }
    }

    cout << endl;

    return 0;
}

// Output :

// Enter the size of array 1 : 5
// Enter the elements of the array 1 : 1 2 3 2 4
// Enter the size of array 2 : 8
// Enter the elements of the array 1 : 1 9 10 24 3 2 3 1
// Intersection of Two arrays (is/are) : 1 2 3 