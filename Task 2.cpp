#include <iostream>
using namespace std;

main()
{
    char checkLetter;
    int x = 0, n, counter = 0;
    cout << "Number of strings: ";
    cin >> n;
    cout << "Character: ";
    cin >> checkLetter;
    string word;

    for(int idx = 0; idx < n ; idx++)
    {
        cout << "Enter string for index " << idx + 1 << ": ";
        cin >> word;
        while(word[x] != '\0')
        {
            if(word[x] == checkLetter)
            {
                counter = counter + 1;
            }
            x++;
        }
        x = 0;
    }
    cout << "Counter: " << counter;
}