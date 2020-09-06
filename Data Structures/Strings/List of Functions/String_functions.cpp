#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    string s = "bitch";
    string s2 = "lingual";
    s.replace(2, s2.size(), s2);
    s.resize(7);
    s.append("ist");
    cout << s << endl;
    cout << s.find_last_of("i") << endl;
    cout << s[s.find_last_not_of("cbh")];
    for (int i = 0; i < s.size(); i++) {
        printf("s[%d] = ", i);
        cout << s[i] << endl;
    }
    cout << s[9] << '\t' << s.find_last_not_of("cbh");
    cout << s.find("k");

    // a = 97, A = 65 in ASCII, so to make a string uppercase, subtract 32 from it's value
    string l = "heyy";
    for (int i = 0; i < l.size(); i++) l[i] -= 32;
    cout << endl
         << l;
}