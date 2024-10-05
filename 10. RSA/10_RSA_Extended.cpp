#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Function to compute GCD using Euclid's algorithm
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse of 'a' under modulo 'm' using brute-force method
long long modInverse(long long a, long long m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // Return -1 if no modular inverse exists
}

// Function to find a suitable encryption key 'e'
int findEncryptionKey(int phi)
{
    int e = 2; // Start with the smallest prime candidate for 'e'
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
        {
            return e; // Return if 'e' is coprime with φ(n)
        }
        e++;
    }
    return -1; // Return -1 if no suitable 'e' is found (this should not happen in practice)
}

// Function to generate RSA keys
void generateKeys(int &n, int &e, int &d, int p, int q)
{
    n = p * q;                   // Compute n = p * q
    int phi = (p - 1) * (q - 1); // Compute φ(n) = (p - 1) * (q - 1)

    // Find a suitable 'e'
    e = findEncryptionKey(phi);
    if (e == -1)
    {
        cout << "Error: Could not find a suitable encryption key 'e'." << endl;
        return;
    }

    // Compute the private key 'd' as the modular inverse of 'e'
    d = modInverse(e, phi);
    if (d == -1)
    {
        cout << "Error: Could not find the modular inverse of 'e'." << endl;
    }
}

// Fast modular exponentiation function
long long bigMod(long long b, long long p, long long m)
{
    if (p == 0)
        return 1;

    long long res = 1;
    while (p > 0)
    {
        if ((p & 1) == 1)
            res = (res * b) % m;
        p /= 2;
        b = (b * b) % m;
    }
    return res % m;
}

// Function to encrypt a plaintext chunk
long long encrypt(long long plaintext, long long e, long long n)
{
    return bigMod(plaintext, e, n);
}

// Function to decrypt a ciphertext chunk
long long decrypt(long long ciphertext, long long d, long long n)
{
    return bigMod(ciphertext, d, n);
}

int main()
{
    int n, e, d;
    int p = 47, q = 71; // Example prime numbers

    // Generate RSA keys
    generateKeys(n, e, d, p, q);
    if (d == -1)
    {
        cout << "Error in key generation." << endl;
        return -1;
    }

    // Output the public and private keys
    cout << "Public key: (" << e << ", " << n << ")" << endl;
    cout << "Private key: (" << d << ", " << n << ")" << endl
         << endl;

    // Read the plaintext from file
    ifstream fin("message.txt");
    ofstream fout("cipher.txt");
    ofstream fout2("output.txt");

    string plaintext;
    char c;
    while (fin.get(c))
    {
        plaintext += c;
    }
    cout << "Plaintext: " << plaintext << endl;

    // Calculate the chunk size for encryption based on the size of 'n'
    int chunkSize = to_string(n).size() - 1;

    vector<long long> chunksMessage, chunksCipher;
    vector<int> chunksLength;

    // Divide the plaintext into chunks and convert each to an integer
    for (int i = 0; i < plaintext.size(); i += chunkSize)
    {
        string chunk = plaintext.substr(i, chunkSize);
        chunksMessage.push_back(stoll(chunk)); // Convert chunk to long long
        chunksLength.push_back(chunk.size());  // Track length for proper decryption
    }

    // Encrypt each chunk and store the cipher text
    cout << "Ciphertext: ";
    for (long long chunk : chunksMessage)
    {
        long long ciphertext = encrypt(chunk, e, n);
        chunksCipher.push_back(ciphertext);
        cout << ciphertext << " ";
        fout << ciphertext << " "; // Write ciphertext to file
    }
    cout << endl;

    // Decrypt the ciphertext and print the decrypted text
    cout << "Decrypted text: ";
    for (int i = 0; i < chunksCipher.size(); i++)
    {
        long long decrypted_long = decrypt(chunksCipher[i], d, n);
        string decrypted = to_string(decrypted_long);
        decrypted = string(chunksLength[i] - decrypted.size(), '0') + decrypted;
        cout << decrypted << ' ';
        fout2 << decrypted; // Write decrypted text to file
    }
    cout << endl;

    return 0;
}
