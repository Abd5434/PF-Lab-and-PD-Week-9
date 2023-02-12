#include <iostream>
using namespace std;

main()
{
    int directionsNum;
    cout << "No of directions: ";
    cin >> directionsNum;

    string directions[directionsNum];

    for(int idx = 0; idx < directionsNum; idx ++)
    {
        cout << "Direction " << idx + 1 << " : ";
        cin >> directions[idx];
    }

    int rightspuns = 0;;
    int leftspuns = 0;
    for (int idx = 0; idx < directionsNum; idx++)
    {
        if(directions[idx] == "right")
        {
            rightspuns = rightspuns + 1;
        }

        else if(directions[idx] != "right")
        {
            leftspuns = leftspuns + 1;
        }
       
    }
    int move = 0;
    if(rightspuns > leftspuns)
    {
        move = rightspuns - leftspuns;
    }

    else if(leftspuns > rightspuns)
    {
        move = leftspuns - rightspuns;
    }

    move = move / 4;

    cout << "360 Turns: " << move;
}
