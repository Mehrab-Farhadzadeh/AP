#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> asymmetricTwoD(3);
    
    asymmetricTwoD[0].push_back(2);
    asymmetricTwoD[0].push_back(4);
    asymmetricTwoD[0].push_back(3);

    asymmetricTwoD[1].push_back(4);

    asymmetricTwoD[2].push_back(6);
    asymmetricTwoD[2].push_back(9);

    for (int i = 0; i < asymmetricTwoD.size(); i++)
    {
        for (int j = 0; j < asymmetricTwoD[i].size(); j++)
        {
            cout << asymmetricTwoD[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}