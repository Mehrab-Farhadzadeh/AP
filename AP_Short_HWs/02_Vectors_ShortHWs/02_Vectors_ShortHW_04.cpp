#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> most_frequents(vector<int> integers);
int most_frequency(vector<int> integers);

int main()
{
    vector<int> integers(10);
    
    integers[0] = 11; integers[1] = 11;
    integers[2] = 12; integers[3] = 11;
    integers[4] = 12; integers[5] = 11;

    cout << "Most frequent numbers are : ";
    vector<int> most_frequent_numbers = most_frequents(integers);

    for(int i = 0; i < most_frequent_numbers.size(); i++)
    {
        cout << most_frequent_numbers[i] << " ";
    }

    return 0;
}

vector<int> most_frequents(vector<int> integers)
{
    vector<int> most_frequent_numbers;
    int most_frequency_value = most_frequency(integers), frequency = 0;

    sort(integers.begin(), integers.end());

    for (int i = 0, index_of_the_inCunting_number = 0; i < integers.size(); i++)
    {
       if (integers[index_of_the_inCunting_number] == integers[i])
        {
            frequency++;
        }
        else 
        {
            if (frequency == most_frequency_value)
            {
                most_frequent_numbers.push_back(integers[index_of_the_inCunting_number]);
            }
            frequency = 0;
            index_of_the_inCunting_number = i--;
        }
    }

    return most_frequent_numbers;
}

int most_frequency(vector<int> integers)
{
    int most_frequency_value = 0;

     for (int i = 0; i < integers.size(); i++)
    {
        int frequency = 0;
        for (int j = 0; j < integers.size(); j++)
        {
            if (integers[i] == integers[j])
            {
                frequency++;
            }
        }
        if (frequency >= most_frequency_value){
            most_frequency_value = frequency;
        }
    }

    return most_frequency_value;
}