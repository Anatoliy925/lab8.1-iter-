#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* str)
{
    if (strlen(str) < 3)
        return 0;
    int k = 0, i;
    for (i = 0; str[i] != 0 && k != 3; i++)
        if (str[i] == ',')
            k++;
    return i - 1;
}
char* Change(char* str)
{
    size_t len = strlen(str);
  
    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;
    
    while (i < len && str[i] != 0)
    {
        if (str[i] == ',')
        {
            strcat(t, "**");
            t += 2;
            i += 1;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}
int main() {
    
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "Третя за порядком кома на позиції " << "S(" << Count(str) << ")"<< endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
    
}
