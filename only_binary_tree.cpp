#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;

int main()
{
    char arr[6] = {'A',
                   'B',
                   'C',
                   'D',
                   'E',
                   'F'};
    for (int i = 0; i < 6; i++)
    {
        char current = arr[i];
        if ((2 * i) + 1 <= 6)
        {
            cout << current << "->left->" << arr[(2 * i) + 1] << endl;
        }
        if ((2 * i) + 2 <= 6)
        {
            cout << current << "->right->" << arr[(2 * i) + 2] << endl;
        }
    }
    return 0;
}
