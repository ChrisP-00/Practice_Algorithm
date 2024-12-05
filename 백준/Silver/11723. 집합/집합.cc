#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main()
{
    fast; 

    int commends;
    cin >> commends;

    int nums = 0;

    while(commends--)
    {
        string commend; 
        cin >> commend;
        

        if(commend == "all")
        {
            nums = (1 << 21) -1;
        }
        else if(commend == "empty")
        {
            nums = 0;
        }
        else
        {
            int value; 
            cin >> value;

            if(commend == "add")
            {
                nums |= (1 << value);
            }

            else if(commend == "remove")
            {
                nums &= ~(1 << value);
            }

            else if(commend == "check")
            {
                cout << ((nums & (1 << value)) ? 1 : 0) << '\n';
            }

            else if(commend == "toggle")
            {
                nums ^= (1 << value);
            }
        }
    }

    return 0;
}