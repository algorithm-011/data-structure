#include <iostream>
#include <array>

using namespace std;

int main(void)
{
    array<int, 5> first = { {1, 2, 3, 4, 5} };
    array<string, 5> second = { {"github", "git", "linux", "ubuntu", "kernel"} };

    for(int i=0; i<5; i++)
        cout << second[i] << " ";
    cout << endl;

    return 0;
}
