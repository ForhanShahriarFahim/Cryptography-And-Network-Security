#include<bits/stdc++.h>

using namespace std;

int main()
{
    ofstream file("OTP_key.txt");
    string dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string key = "";
    for (int i = 0; i < 100; i++)
    {
        int idx = rand() % 52;
        key += dictionary[idx];
    }
    file << key;
    file.close();
    return 0;
}