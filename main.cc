#include <iostream>
#include <vector>
using namespace std;




int main()
{
    vector<int> myVector(20);
    myVector.push_back(2);
    myVector.push_back(44);
    myVector.push_back(77);
    myVector.push_back(77);
    myVector.push_back(77);
    myVector.push_back(77);

    cout << myVector.size() << endl;
    myVector.shrink_to_fit();

    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << " ";
    }


    cout << myVector.capacity() << endl;
    // myVector.pop_back();
    // cout << endl;
    // cout << myVector.size() << endl;

    // for (int i = 0; i < myVector.size(); i++)
    // {
    //     cout << myVector[i] << " ";
    // }


    return (0);
}
