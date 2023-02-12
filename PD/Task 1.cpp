#include <iostream>
using namespace std;

main()
{
    int num;
    cout << "Array Length: ";
    cin >> num;
    int arr[num];
    bool flag;

    for(int idx = 0; idx < num; idx++)
    {
        cout << "Value at index " << idx + 1 << " : ";
        cin >> arr[idx];
    }
    int temp;
    for(int idx = 0; idx < num;idx++)
    {
        for (int i = 0; i < num; i++)
        {
            if (arr[idx] < arr[i])
            {
                temp = arr[idx];
                arr[idx] = arr[i];
                arr[i] = temp;     
            }
        }
        
    }

    for(int idx = 0; idx < num - 1; idx++)
    {
        if(arr[idx] + 1 == arr[idx + 1])
        {
            flag = true;
        }
        else if(arr[idx] + 1 != arr[idx + 1])
        {
            flag = false;
        }
    }

    if(flag == true)
    {
        cout << "True!!!";
    }
    else
    {
        cout << "False!!!";
    }
}