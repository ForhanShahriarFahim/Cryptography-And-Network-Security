#include <bits/stdc++.h>
using namespace std;

string encryptCaesarCipher(string plaintext, int shift)
{
    string cipherText = "";

    for (char ch : plaintext)
    {
        if(isalpha(ch)){
            char start = isupper(ch) ? 'A' : 'a';
            char cipherChar = ((ch - start + shift) % 26) + start;
            cipherText += cipherChar;
        }else{
            cipherText +=ch;
        }
    }
    return cipherText;
}

string decryptCaesarCipher(string cipherText, int shift)
{
    return encryptCaesarCipher(cipherText, 26 - shift);
}

int main()
{
    ifstream inFile("message.txt");
    ofstream oFile("encrypted.txt");
    
    string plaintext, line, ciphertext;
    int shift = 3;

    // // Read all lines from the file and concatenate them into a single string
    // while (getline(cin, line))
    // {
    //     plaintext += line + '\n'; // Concatenate each line with a newline character
    // }
    char c;
    while(inFile.get(c)){
        plaintext +=c;
    }

    cout<<plaintext<<endl;

    // Encrypt the entire plaintext
    ciphertext = encryptCaesarCipher(plaintext, shift);
    cout << "Encrypted text (Caesar Cipher): " << endl << ciphertext << endl;
    
    // oFile<<ciphertext;
    // // Write the encrypted text to a file using freopen
    // freopen("encrypted_caesar.txt", "w", stdout); // Open the output file for writing encrypted text
    // cout << ciphertext;                           // Write the encrypted text

    // Decrypt the ciphertext
    string decryptedText = decryptCaesarCipher(ciphertext, shift);
    cout << "Decrypted text (Original Plaintext): " << endl<< decryptedText << endl;    
    return 0;
}
