#include<bits/stdc++.h>
using namespace std;

map<string, string> encoder;
map<string, string> decoder;


string cipherText(string &text, int block_size){
    string cipher = "";

    for(int i = 0;i<text.size();i+=block_size){
        string block = text.substr(i, block_size);        
        if(encoder.find(block)!=encoder.end()){
            cipher +=encoder[block]; // Substitute if block is found            
        } else{
            cipher += block; // Leave unchanged if block not found
        }
    }
    return cipher;
}

string decipherText(string &text, int block_size){
    string decipher;
    for(int i = 0;i<text.size();i+=block_size){
        string block = text.substr(i, block_size);
        if(decoder.find(block)!=decoder.end()){
            decipher+=decoder[block];
        } else{
            decipher+=block;
        }
    }
    return decipher;
}

int main(){
    freopen("2_polygram.txt", "r", stdin);
    string text;
    getline(cin, text);
    cin.clear();

    freopen("2_dictionary.txt", "r", stdin);
    string s1, s2;
    while(cin>>s1>>s2){
        encoder[s1] = s2;
        decoder[s2] = s1;
    }
    int block_size = 3;

    // Encryption
    string cipher  = cipherText(text, block_size);
    // Decryption
    string decipher = decipherText(cipher, block_size);

    //output
    cout<<"Plain-Text: "<<text<<endl;
    cout<<"Cipher-Text: "<<cipher<<endl;
    cout<<"Decipher-Text: "<<decipher<<endl;
    return 0;
}