#include <iostream>
using namespace std;

int arr[100];

main()
{
    int n;
    cout << "Number of Boxes: ";
    cin >> n;
    arr[n*3];

    for(int x = 0; x < n*3; x++)
    {
        cout << "Enter value for array: ";
        cin >> arr[x];
    }
    int product = 0;
    int dimension = 0;
    for(int x = 0; x < n; x++)
    {
        product = product + (arr[dimension] * arr[dimension + 1] * arr[dimension + 2]);
        dimension = dimension + 3;
    }

    cout << "Volume: " << product;
}
