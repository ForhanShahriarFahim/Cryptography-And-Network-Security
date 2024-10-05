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
    ifstream inFile("3_transpose.txt"); // Open the file

    if (!inFile)
    { // Check if the file opened successfully
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int width;

    getline(inFile, msg);
    cout << "Enter the Width: ";
    cin >> width;

    encMsg = encryptMsg(msg, width);
    decMsg = decryptMsg(encMsg, width);

    cout << "Input Text: " << msg << endl;
    cout << "Encrypted Message: " << encMsg << endl;
    cout << "Decrypted Message: " << decMsg << endl;

    return 0;
}