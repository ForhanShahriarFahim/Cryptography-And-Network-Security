#include <bits/stdc++.h>
using namespace std;

map<string, string> encoder; // Map for encoding (plain -> cipher)
map<string, string> decoder; // Map for decoding (cipher -> plain)

// Function to encrypt the text using polygram substitution
string cipherText(const string &text, int block_size)
{
    string cipher = "";

    // Process the text in blocks of the given size
    for (int i = 0; i < text.size(); i += block_size)
    {
        string block = text.substr(i, block_size); // Extract block

        // If the block is found in the encoder map, substitute it
        if (encoder.find(block) != encoder.end())
        {
            cipher += encoder[block]; // Substitute block
        }
        else
        {
            cipher += block; // Leave block unchanged if not found
        }
    }
    return cipher;
}

// Function to decrypt the text using polygram substitution
string decipherText(const string &text, int block_size)
{
    string decipher = "";

    // Process the ciphered text in blocks of the given size
    for (int i = 0; i < text.size(); i += block_size)
    {
        string block = text.substr(i, block_size); // Extract block

        // If the block is found in the decoder map, substitute it back
        if (decoder.find(block) != decoder.end())
        {
            decipher += decoder[block]; // Substitute block
        }
        else
        {
            decipher += block; // Leave block unchanged if not found
        }
    }
    return decipher;
}

int main()
{
    // Open and read the input text file
    freopen("2_polygram.txt", "r", stdin);
    string text;
    getline(cin, text); // Read the entire text (assuming single-line input)
    cin.clear();

    // Open and read the dictionary (substitution rules) file
    freopen("2_dictionary.txt", "r", stdin);
    string s1, s2;

    // Load the encoder and decoder maps
    while (cin >> s1 >> s2)
    {
        encoder[s1] = s2;
        decoder[s2] = s1;
    }

    int block_size = 3; // Define the block size for polygram substitution

    // Perform encryption
    string cipher = cipherText(text, block_size);

    // Perform decryption
    string decipher = decipherText(cipher, block_size);

    // Output results
    cout << "Plain-Text: " << text << endl;
    cout << "Cipher-Text: " << cipher << endl;
    cout << "Deciphered-Text: " << decipher << endl;

    return 0;
}
