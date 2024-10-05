#include <bits/stdc++.h>
using namespace std;

string encryptCaesarCipher(string plaintext, int shift)
{
    string ciphertext = "";

    for (int i = 0; i < plaintext.size(); i++)
    {
        char ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        ciphertext += ch;
    }
    return ciphertext;
}

string decryptCaesarCipher(string ciphertext, int shift)
{
    string plaintext = "";

    for (int i = 0; i < ciphertext.size(); i++)
    {
        char ch = ciphertext[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        plaintext += ch;
    }
    return plaintext;
}

int main()
{
    freopen("1_caesar.txt", "r", stdin); // Open the file for input
    string plaintext, line, ciphertext;
    int shift = 3;

    // Read all lines from the file and concatenate them into a single string
    while (getline(cin, line))
    {
        plaintext += line + '\n'; // Concatenate each line with a newline character
    }

    // Encrypt the entire plaintext
    ciphertext = encryptCaesarCipher(plaintext, shift);
    cout << "Encrypted text (Caesar Cipher): " << endl
         << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = decryptCaesarCipher(ciphertext, shift);
    cout << "Decrypted text (Original Plaintext): " << endl
         << decryptedText << endl;

    return 0;
}
