#include <iostream>
using namespace std;    
static int index = 0;
bool step(int num, char str[101])
{
    index++;
    switch (str[index])
    {
    case 'p':
        return num & 1;
    case 'q':
        return (num >> 1) & 1;
    case 'r':
        return (num >> 2) & 1;
    case 's':
        return (num >> 3) & 1;
    case 't':
        return (num >> 4) & 1;
    case 'K':
        return step(num, str) & step(num, str);
    case 'A':
        return step(num, str) | step(num, str);
    case 'N':
        return !step(num, str);
    case 'C':
        return (!step(num, str)) | step(num, str);
    case 'E':
        return step(num, str) == step(num, str);
    default:
        return 1;
    }
}
bool enumerate(char str[101])
{

    for (int i = 0; i < 32; i++)
    {
        index = -1;
        if (!step(i, str))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char str[101];
    while (cin>>str)
    {
        if (str[0] == '0')
            break;
        if (enumerate(str))
        {
            cout << "tautology" << endl;
        }
        else
        {
            cout << "not" << endl;
        }
    }
    return 0;
}