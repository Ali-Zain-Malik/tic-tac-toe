#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
class RLEEncoder
{
public:
    string encode(const T arr[], int size)
    {
        ostringstream result;
        T prev = arr[0];
        int count = 1;

        for (int i = 1; i < size; ++i)
        {
            if (arr[i] == prev)
            {
                count++;
            }
            else
            {
                result << prev << count;
                prev = arr[i];
                count = 1;
            }
        }

        result << prev << count;
        return result.str();
    }
};

int main()
{
    cout<<"Student ID: BC230200024\n\n";
    int intArr[] = {2, 2, 2, 3, 3, 3, 3};
    char charArr[] = {'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b'};
    float floatArr[] = {2.2, 2.2, 3.3, 3.3, 3.3};
    char symbolArr[] = {'@', '@', '#', '#', '$', '$', '$'};

    RLEEncoder<int> intEncoder;
    RLEEncoder<char> charEncoder;
    RLEEncoder<float> floatEncoder;
    RLEEncoder<char> symbolEncoder;

    cout << "Actual Integer Array: ";
    for (int i : intArr)
    {
        cout << i << " ";
    }
    cout << "\nEncoded Integer Array: " << intEncoder.encode(intArr, sizeof(intArr) / sizeof(int)) << "\n\n";

    cout << "Actual Character Array: ";
    for (char c : charArr)
    {
        cout << c << " ";
    }
    cout << "\nEncoded Character Array: " << charEncoder.encode(charArr, sizeof(charArr) / sizeof(char)) << "\n\n";

    cout << "Actual Float Array: ";
    for (float f : floatArr)
    {
        cout << f << " ";
    }
    cout << "\nEncoded Float Array: " << floatEncoder.encode(floatArr, sizeof(floatArr) / sizeof(float)) << "\n\n";

    cout << "Actual Symbol Array: ";
    for (char s : symbolArr)
    {
        cout << s << " ";
    }
    cout << "\nEncoded Symbol Array: " << symbolEncoder.encode(symbolArr, sizeof(symbolArr) / sizeof(char)) << "\n";

    system("pause");
    return 0;
}
