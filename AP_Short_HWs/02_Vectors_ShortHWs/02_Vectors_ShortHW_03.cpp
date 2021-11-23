#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int most_frequent(vector<int> integers);

int main()
{
    vector<int> integers(10);
    
    integers[0] = 11; integers[1] = 11;
    integers[2] = 12; integers[3] = 11;
    integers[4] = 12; integers[5] = 11;

    cout << "Most frequent number is : " << most_frequent(integers) << endl;

    return 0;
}

int most_frequent(vector<int> integers)
{
    int most_frequent_number, most_frequency = 0, frequency = 0;

    sort(integers.begin(), integers.end());
    for (int i = 0, index_of_the_inCunting_number = 0; i < integers.size(); i++)
    {
        if (integers[index_of_the_inCunting_number] == integers[i])
        {
            frequency++;
        }
        else 
        {
            if (frequency >= most_frequency)
            {
                most_frequency = frequency;
                most_frequent_number = integers[index_of_the_inCunting_number];
            }
            frequency = 0;
            index_of_the_inCunting_number = i--;
        }
    }

    return most_frequent_number;
}