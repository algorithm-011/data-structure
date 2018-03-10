#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    list<int> l;
    
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    for(auto it=l.begin(); it!=l.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
