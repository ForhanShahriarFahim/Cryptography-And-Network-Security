#include <bits/stdc++.h>
using namespace std;

// OTP encryption function
string encryptOneTimePad(string plaintext, string &key, int &keyIndex)
{
    string cipherText = "";

    for (char ch : plaintext)
    {
        if (isalpha(ch))
        {
            // Determine the start point (upper or lower case)
            char start = isupper(ch) ? 'A' : 'a';
            char keyStart = isupper(key[keyIndex]) ? 'A' : 'a';

            // Encrypt character using OTP
            char cipherChar = ((ch - start + key[keyIndex] - keyStart) % 26) + start;
            cipherText += cipherChar;

            keyIndex++; // Move to the next key character            
        }
        else
        {
            cipherText += ch; // Leave non-alphabetic characters unchanged
        }
    }

    return cipherText;
}

// OTP decryption function
string decryptOneTimePad(string cipherText, string &key, int &keyIndex)
{
    string plainText = "";

    for (char ch : cipherText)
    {
        if (isalpha(ch))
        {
            // Determine the start point (upper or lower case)
            char start = isupper(ch) ? 'A' : 'a';
            char keyStart = isupper(key[keyIndex]) ? 'A' : 'a';

            // Decrypt character using OTP
            char plainChar = ((ch - start - (key[keyIndex] - keyStart) + 26) % 26) + start;
            plainText += plainChar;

            keyIndex++; // Move to the next key character            
        }
        else
        {
            plainText += ch; // Leave non-alphabetic characters unchanged
        }
    }

    return plainText;
}

// Caesar Cipher encryption
string encryptCaesarCipher(string text, int shift)
{
    string cipherText = "";

    for (char ch : text)
    {
        if (isalpha(ch))
        {
            // Determine the start point (upper or lower case)
            char start = isupper(ch) ? 'A' : 'a';

            // Encrypt character using Caesar Cipher
            char cipherChar = ((ch - start + shift) % 26) + start;
            cipherText += cipherChar;
        }
        else
        {
            cipherText += ch; // Leave non-alphabetic characters unchanged
        }
    }

    return cipherText;
}

// Caesar Cipher decryption
string decryptCaesarCipher(string cipherText, int shift)
{
    return encryptCaesarCipher(cipherText, 26 - shift); // Reverse shift for decryption
}

int main()
{
    string plaintext, key, otpEncryptedText, finalCipherText, decryptedText;
    int shift = 3;    
    int keyIndex = 0; 

    // Read the plaintext from a file
    ifstream inFile("message.txt");
    getline(inFile, plaintext);
    inFile.close();

    // Read the key from a file
    ifstream keyFile("otp_key.txt");
    getline(keyFile, key);
    keyFile.close();

    // Step 1: Encrypt using One-Time Pad
    otpEncryptedText = encryptOneTimePad(plaintext, key, keyIndex);
    cout << "After OTP Encryption: " << otpEncryptedText << endl;

    // Step 2: Encrypt using Caesar Cipher
    finalCipherText = encryptCaesarCipher(otpEncryptedText, shift);
    cout << "After Caesar Cipher Encryption: " << finalCipherText << endl;

    // Write the final cipher text to a file
    ofstream outFile("final_ciphertext.txt");
    outFile << finalCipherText;
    outFile.close();

    // Reset the key index for decryption
    keyIndex = 0;

    // Now, decrypt the message

    // Step 1: Reverse Caesar Cipher
    string caesarDecryptedText = decryptCaesarCipher(finalCipherText, shift);
    cout << "After Caesar Cipher Decryption: " << caesarDecryptedText << endl;

    // Step 2: Reverse OTP Encryption
    decryptedText = decryptOneTimePad(caesarDecryptedText, key, keyIndex);
    cout << "Decrypted Text (Original Plaintext): " << decryptedText << endl;

    cout<<"Remaining key: "<<key.substr(keyIndex);

    return 0;
}
