#include <iostream>
using namespace std;

int arr[100];

main()
{
    int n;
    cout << "Number of array elements: ";
    cin >> n;

    for(int idx = 0; idx < n; idx++)
    {
        cout << "Array Element " << idx + 1 << ": ";
        cin >> arr[idx];
    }    
    

    int num;
    cout << "Enter cycle number: ";
    cin >> num;
    
    bool flag;
    for(int idx = 0; idx < num; idx++)
   {
    if(arr[idx] != arr[idx + num])
    {
        flag = false;
        
    }
    else if (arr[idx] == arr[idx + num])
    {
        flag = true;
    }
    
}
    if(num > n)
    {
        flag = true;
    }
    if (flag == true)
    {
        cout << "True";
    }

    else
    {
        cout << "False";
    }
}


