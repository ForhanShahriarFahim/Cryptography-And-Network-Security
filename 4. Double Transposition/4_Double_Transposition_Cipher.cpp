#include <bits/stdc++.h>
using namespace std;

string encryptMsg(string msg, int width)
{
    int msgLen = msg.size();
    int col = msgLen / width, rem = msgLen % width, x = 0, y = 0;
    string ans = msg;

    for (int i = 0; i < msgLen; i++)
    {
        if (i % width == 0)
            x = y, y++;
        else if (i % width <= rem)
            x += 1;
        ans[x] = msg[i];
        x += col;
    }
    return ans;
}

string decryptMsg(string msg, int width)
{
    int msgLen = msg.size();
    int col = msgLen / width, rem = msgLen % width, x = 0, y = 0;
    string ans = msg;

    for (int i = 0; i < msgLen; i++)
    {
        if (i % width == 0)
            x = y, y++;
        else if (i % width <= rem)
            x += 1;
        ans[i] = msg[x];
        x += col;
    }
    return ans;
}

int main()
{
    string msg, encMsg, decMsg;

    // Opening file
    ifstream inFile("4_double_transposition.txt");
    

    // Reading input
    getline(inFile, msg);
    inFile.close(); // Closing the file after reading

    // Taking keys (widths)
    int width1, width2;
    cout << "Enter the first key (Width): ";
    cin >> width1;
    cout << "Enter the second key (Width): ";
    cin >> width2;

    // Display original text
    cout << "Input Text: " << msg << endl;

    // First encryption
    encMsg = encryptMsg(msg, width1);
    cout << "CipherText(1): " << encMsg << endl;

    // Second encryption
    encMsg = encryptMsg(encMsg, width2);
    cout << "CipherText(2): " << encMsg << endl;

    // First decryption (reverse second encryption)
    decMsg = decryptMsg(encMsg, width2);

    // Second decryption (reverse first encryption)
    decMsg = decryptMsg(decMsg, width1);

    // Display decrypted text
    cout << "PlainText: " << decMsg << endl;

    return 0;
}
