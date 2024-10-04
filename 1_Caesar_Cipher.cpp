#include<bits/stdc++.h>
using namespace std;

string encryptCaesarCipher(string plaintext, int shift){
    string ciphertext = "";

    for(int i = 0;i<plaintext.size();i++){
        char ch = plaintext[i];
        if(ch >= 'A' && ch <= 'Z'){
            ch = (ch - 'A' + shift) % 26 + 'A'; 
        }
        else if(ch>= 'a' && ch<= 'z'){
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        ciphertext +=ch;
    }
    return ciphertext;
}

string decryptCaesarCipher(string ciphertext, int shift)
{
    string plaintext = "";
    
    for(int i = 0;i<ciphertext.size();i++){
        char ch = ciphertext[i];
        if(ch >= 'A' && ch <= 'Z'){
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        else if(ch>='a' && ch<='z'){
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        plaintext += ch;
    }
    return plaintext;
}

int main(){
    freopen("caesar.txt", "r", stdin);
    string plaintext, ciphertext;
    int shift = 3;  
    cout<<"Enter the plaintext";    
    getline(cin, plaintext); //One line input
    //if multiple line
    // string str;
    // while (getline(cin, plaintext))
    // {
    //     str += plaintext;
    // }

    ciphertext = encryptCaesarCipher(plaintext, shift);
    cout<<"Encrypted text (Caesar Cipher): "<<ciphertext<<endl;
    
    string decryptedText = decryptCaesarCipher(ciphertext, shift);
    cout<<"Decrypted text (Original Plaintext): "<<decryptedText<<endl;
    return 0;


}