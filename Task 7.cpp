#include <iostream>
using namespace std;

main()
{
    int n;
    cout << "Number of strings: ";
    cin >> n;
    string arr[n];
    for(int idx = 0; idx < n; idx++)
    {
        cin >> arr[idx];
    }

    for(int idx = n - 1; idx >= 0;idx--)
    {
        cout << arr[idx] << " ";
    }
}