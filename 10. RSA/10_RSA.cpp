#include <bits/stdc++.h>
using namespace std;

// Function to calculate (base^exp) % mod using modular exponentiation
long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to split a large number (message) into blocks of size k
vector<long long> splitMessageIntoBlocks(string message, int blockSize)
{
    vector<long long> blocks;
    for (int i = 0; i < message.length(); i += blockSize)
    {
        // Extract a block of blockSize characters from the message string
        string block = message.substr(i, blockSize);
        blocks.push_back(stoll(block)); // Convert to long long and add to blocks
    }
    return blocks;
}

int main()
{
    // Given RSA parameters
    long long p = 47;
    long long q = 71;
    long long n = p * q;               // n = p * q
    long long phi = (p - 1) * (q - 1); // phi(n) = (p-1)*(q-1)
    long long e = 79;                  // Public key exponent
    long long d = 1019;                // Private key exponent

    // Define the original message as a large number string
    string message = "6882326879666683";

    // Determine the block size based on the number of digits in n
    int blockSize = to_string(n).length() - 1; // Block size = (digits in n) - 1
    cout << "Block size: " << blockSize << " digits" << endl;

    vector<long long> chunksMessage, chunksCipher;
    vector<int> chunksLength;

    // Divide the plaintext into chunks and convert each to an integer
    for (int i = 0; i < message.size(); i += blockSize)
    {
        string chunk = message.substr(i, blockSize);
        chunksMessage.push_back(stoll(chunk)); // Convert chunk to long long
        chunksLength.push_back(chunk.size());  // Track length for proper decryption
    }

    // Encryption: ci = mi^e % n
    cout << "Ciphertext: ";
    for (long long chunk : chunksMessage)
    {
        long long ciphertext = modExp(chunk, e, n);
        chunksCipher.push_back(ciphertext);
        cout << ciphertext << " ";
    }
    cout << endl;

    // Decryption: mi = ci^d % n
    cout << "Decrypted text: ";
    for (int i = 0; i < chunksCipher.size(); i++)
    {
        long long decrypted_long = modExp(chunksCipher[i], d, n);
        string decrypted = to_string(decrypted_long);
        decrypted = string(chunksLength[i] - decrypted.size(), '0') + decrypted;
        cout << decrypted << ' ';        
    }
    cout << endl;

    return 0;
}
