#include <iostream>
using namespace std;

main()
{
    int num;
    int count = 0;
    cout << "Number of values: ";
    cin >> num;
    int arr[num];
    for(int idx = 0; idx < num; idx++)
    {
        cout << "Enter the value for index " << idx + 1 << ": ";
        cin >> arr[idx];
    }

    for(int idx = 0; idx < num; idx++)
    {
        if(arr[idx] > arr[idx - 1])
        {
            count = count + 1;
        }
    }
    cout << "Progress Days: " << count; 
}