#include <bits/stdc++.h>
using namespace std;

string encryption(string &str, string &key)
{
    string result = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (isupper(ch))
        {
            ch = (ch - 'A' + key[i] - 'A') % 26 + 'A';
        }
        else if (islower(ch))
        {
            ch = (ch - 'a' + key[i] - 'a') % 26 + 'a';
        }
        result += ch;
    }
    return result;
}

string decryption(string &str, string key)
{
    string result = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (isupper(ch))
        {
            ch = (ch - 'A' - key[i] + 'A' + 26) % 26 + 'A';
        }
        else if (islower(ch))
        {
            ch = (ch - 'a' - key[i] + 'A' + 26) % 26 + 'a';
        }
        result += ch;
    }
    return result;
}

string generateRandomKey(int length)
{
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = "";

    // Seed for random number generation
    srand(time(0));

    for (int i = 0; i < length; i++)
    {
        key += chars[rand() % chars.size()];
    }
    return key;
}

int main()
{
    string plaintext, key, cipherText, decipherText;

    // Input from file
    ifstream inFile("5_one_time.txt");
    if (!inFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    getline(inFile, plaintext);
    inFile.close();

    ifstream inFile2("5_one_time_key.txt");
    if (!inFile2)
    {
        cerr << "Error opening key file!" << endl;
        return 1;
    }
    getline(inFile2, key);
    inFile2.close();

    // Generate a random key of the same length as the plaintext
    // key = generateRandomKey(plaintext.size());
    // cout<<key<<endl;

    // Encryption and decryption process
    cipherText = encryption(plaintext, key);
    decipherText = decryption(cipherText, key);

    // Output to console
    cout << "Plain-Text: " << plaintext << endl;
    cout << "Cipher-Text: " << cipherText << endl;
    cout << "Decipher-Text: " << decipherText << endl;

    // Write result to a file
    // ofstream outFile("encryption_results.txt");
    // if (!outFile)
    // {
    //     cerr << "Error opening output file!" << endl;
    //     return 1;
    // }

    // outFile << "Plain-Text: " << plaintext << endl;
    // outFile << "Cipher-Text: " << cipherText << endl;
    // outFile << "Decipher-Text: " << decipherText << endl;

    // outFile.close();

    return 0;
}
