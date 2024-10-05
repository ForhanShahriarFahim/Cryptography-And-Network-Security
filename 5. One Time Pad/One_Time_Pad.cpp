#include <bits/stdc++.h>
using namespace std;

string encryption(string &plaintext, string &key)
{
    string cipherText = "";
    for (size_t i = 0; i < plaintext.length(); i++)
    {
        char ch = plaintext[i];
        if (isalpha(ch))
        {
            char start = isupper(ch) ? 'A' : 'a';
            char keyStart = isupper(key[i]) ? 'A' : 'a';
            char cipherChar = ((ch - start + key[i] - keyStart) % 26) + start;
            cipherText +=cipherChar;
        }
        else{
            cipherText += ch;
        }
    }
    return cipherText;
}

string decryption(string &cipherText, string &key)
{
    string plainText = "";
    for (size_t i = 0; i < cipherText.length(); i++)
    {
        char ch = cipherText[i];
        if (isalpha(ch))
        {
            char start = isupper(ch) ? 'A' : 'a';
            char keyStart = isupper(key[i]) ? 'A' : 'a';
            char plainChar = ((ch - start - (key[i] - keyStart) + 26) % 26) + start;
            plainText += plainChar;
        }
        else {
            plainText += ch;
        }       
    }
    return plainText;
}


int main()
{
    string plaintext, key, cipherText, decipherText;    
    ifstream inFile("message.txt");    
    getline(inFile, plaintext);   
    ifstream keyFile("otp_key.txt");
    getline(keyFile, key);    

    // Encryption and decryption process
    cipherText = encryption(plaintext, key);
    decipherText = decryption(cipherText, key);

    // Output to console
    cout << "Plain-Text: " << plaintext << endl;
    cout << "Cipher-Text: " << cipherText << endl;
    cout << "Decipher-Text: " << decipherText << endl;

    
    ofstream outFile("encryption_results.txt");
    

    outFile << "Plain-Text: " << plaintext << endl;
    outFile << "Cipher-Text: " << cipherText << endl;
    outFile << "Decipher-Text: " << decipherText << endl;

    

    return 0;
}