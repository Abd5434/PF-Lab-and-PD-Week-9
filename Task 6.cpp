#include <iostream>
using namespace std;

main()
{
    int arr[10];
    for(int idx = 0; idx < 10; idx++)
    {
        cout << "Enter value for index " << idx + 1 << ": ";
        cin >> arr[idx];
    }
    int temporary;
    for(int idx = 0; idx < 10; idx++)
    {
        for(int x = 0; x < 10; x++)
        {
            if (arr[idx] < arr[x])
            {
                temporary = arr[idx];
                arr[idx] = arr[x];
                arr[x] = temporary;

            }
        }
    }
    for(int x = 0; x <10; x++)
    {
        cout << arr[x] << " ";
    }
}