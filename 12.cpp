#include <iostream> 
#include <string>
#include <cstring>
using namespace std;

class String
{
public:
    void operator = (String& obj2)
    {
        length = obj2.length;
        str = new char[length + 1];
        strcpy_s(this->str, length + 1, obj2.str);
    }

    String& operator += (string obj2)
    {
        size_t newLength = length + obj2.size();
        char* tempPtr = new char[length];
        strcat_s(str, newLength, obj2.c_str());
        length = newLength;
        return *this;
    }

    String(int length = 0, char* str = new char[1]) : length(length), str(str)
    {

    }

    String(const String& copy, int length = 0, char* str = new char[1]) : length(length), str(str)
    {
        str = new char[length + 1];
        strcpy_s(str, length + 1, copy.str);
    }

    ~String()
    {
        delete str;
    }


    friend ostream& operator << (ostream& stream, String& obj);
    friend istream& operator >> (istream& stream, String& obj);
private:
    char* str;
    int length;
};

ostream& operator << (ostream& stream, String& obj)
{
    stream << "Overloaded operation. String: " << obj.str;
    return stream;
}

istream& operator >> (istream& stream, String& obj)
{
    string temp;
    stream >> temp;
    obj.str = new char[temp.size() + 1];
    obj.length = temp.size() + 1;
    strcpy_s(obj.str, obj.length, temp.c_str());
    return stream;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    String obj1, obj2;
    int deistv;
    cout << "The first string: ";
    cin >> obj1;
    cout << "\nYour string - ";
    cout << obj1;
    cout << "\nThe second string: ";
    cin >> obj2;
    cout << "\nYour string - ";
    cout << obj2;

    while (1) {
        cout << "\n" << "Select the action (overload):\n";
        cout << "1. Demonstration assignment" << endl;
        cout << "2. Fold (+=)" << endl;
        cout << "3. The output from the program" << endl;
        cout << "->";
        cin >> deistv;
        if (deistv == 1) {
            obj2 = obj1;
            cout << obj2;
        }

        if (deistv == 2) {
            obj2 += "12345";
            cout << obj2;
        }

        if (deistv == 3) {
            return 0;
        }
    }
}