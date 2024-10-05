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

    // Split the original message into blocks dynamically
    vector<long long> messageBlocks = splitMessageIntoBlocks(message, blockSize);

    cout << "Original Message Blocks: ";
    for (auto m : messageBlocks)
        cout << m << " ";
    cout << endl;

    // Encryption: ci = mi^e % n
    vector<long long> encryptedBlocks;
    for (auto m : messageBlocks)
    {
        long long encrypted = modExp(m, e, n);
        encryptedBlocks.push_back(encrypted);
    }

    cout << "Encrypted Message Blocks: ";
    for (auto c : encryptedBlocks)
        cout << c << " ";
    cout << endl;

    // Decryption: mi = ci^d % n
    vector<long long> decryptedBlocks;
    for (auto c : encryptedBlocks)
    {
        long long decrypted = modExp(c, d, n);
        decryptedBlocks.push_back(decrypted);
    }

    cout << "Decrypted Message Blocks: ";
    for (auto m : decryptedBlocks)
        cout << m << " ";
    cout << endl;

    return 0;
}
