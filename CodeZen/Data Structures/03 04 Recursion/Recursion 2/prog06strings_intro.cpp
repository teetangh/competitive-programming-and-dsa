#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    // Statically allocated
    string s = "abc";
    cout << s << endl;

    string s1 = "def";
    cout << s1 << endl;

    // Dynamically allocated
    string *sp = new string;
    *sp = "ghi";
    cout << sp << endl;
    cout << *sp << endl;

    // Scannig Strings from  the input stream
    string s2 = "abc";
    // cin >> s2;
    getline(cin, s2);
    cout << s2 << endl;

    // Treating strings like arrays
    s2 = "defdef";
    cout << s2 << endl;
    s2[0] = 'g';
    cout << s2 << endl;

    // String Concatenation
    string s3 = s + s1;
    cout << s3 << endl;

    // Calculating the string size
    // Can also use length function
    cout << s.size() << endl;
    cout << s1.size() << endl;
    cout << s2.size() << endl;
    cout << s3.size() << endl;

    // Substring Function
    cout << s3.substr(3) << endl;
    cout << s3.substr(2, 5) << endl;

    // Find the first index
    cout << s3.find("def") << endl;
    return 0;
}
