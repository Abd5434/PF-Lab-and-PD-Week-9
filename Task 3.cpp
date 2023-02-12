#include <iostream>
using namespace std;


main()
{
    int n;
    cout << "Number of values: ";
    cin >> n;
    int input[n];
    int finalarr[n];

    for(int idx = 0; idx < n; idx++)
    {
        cout << "Input for value " << idx + 1 << ": ";
        cin >> input[idx];
    }
    cout << "[ ";
    int counter = 0;
    for(int x = 1; x < n-1; x++)
    {
        if((input[x] > input[x-1]) && (input[x] > input[x+1]))
        {
            finalarr[counter] = input[x];
            cout << input[x] << " ";
            counter++;
        }
        else
        {
            cout << "No peak found.";
        }
    }
    cout << "]";
}

