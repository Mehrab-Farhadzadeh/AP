#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void get_request_info(string &mode, string &approach, string &key);
void get_files_paths(string &inFilePath, string &outFilePath);
char get_char_from_file(ifstream inFile);
char put_char_into_file(ofstream outFile, char ch);

void encryption(string approach, string key);
void simple_encryption(string key);
int encrypt_char_simple(char ch);
void complicated_encryption(string key);

void decryption(string approach, string key);
void simple_decryption(string key);
void complicated_decryption(string key);


int main()
{
  string mode, approach, key;
  get_request_info(mode, approach, key);

  if (mode == "encrypt")
    encryption(approach, key);
  else
    decryption(approach, key);

  return 0;
}

void get_request_info(string &mode, string &approach, string &key)
{
  cin >> mode >> approach >> key;
}

void get_files_paths(string &inFilePath, string &outFilePath)
{
  cin >> inFilePath >> outFilePath;
}

void encryption(string approach, string key)
{
  if (approach == "simple")
    simple_encryption(key);
  else
    complicated_encryption(key);
}

void decryption(string approach, string key)
{
  if (approach == "simple")
    simple_decryption(key);
  else
    complicated_decryption(key);
}

void simple_encryption(string key)
{
  string inFilePath, outFilePath;
  get_files_paths(inFilePath, outFilePath);

  ofstream outFile;
  ifstream inFile;
  inFile.open(inFilePath);
  outFile.open(outFilePath);

  char ch = get_char_from_file(inFile);
  int ecncrypted_ch = encrypt_char_simple(ch);
  put_char_into_file(outFile, (char)ecncrypted_ch);
}
void complicated_encryption(string key)
{

}

void simple_decryption(string key)
{
  
}
void complicated_decryption(string key)
{

}