#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void get_request_info(string &mode, string &approach, string &key);
void get_files_paths(string &inFilePath, string &outFilePath);
char get_char_from_file(ifstream &inFile);
void put_char_into_file(ofstream &outFile, char decrypted_code);
int get_code_from_file(ifstream &inFile);
void put_code_into_file(ofstream &outFile, char ch);

void encryption(string approach, string key);
void simple_encryption(string key);
int encrypt_char_simple(string key, char ch_to_encrypt);
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
char get_char_from_file(ifstream &inFile)
{
  char ch_to_encrypt;
  inFile >> ch_to_encrypt;
  return ch_to_encrypt;
}
void put_char_into_file(ofstream &outFile, char decrypted_code)
{
  outFile << decrypted_code;
}
int get_code_from_file(ifstream &inFile)
{
  int code;
  inFile >> code;
  return code;
}
void put_code_into_file(ofstream &outFile, int code)
{
  outFile << code << endl;
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

  ifstream inFile(inFilePath);
  ofstream outFile(outFilePath);

  if (!inFile.is_open() || !outFile.is_open())
    cout << "Unable to open file(s)" << endl;

  while (!inFile.eof())
  {
    char ch_to_encrypt = get_char_from_file(inFile);
    // if (inFile.eof())
    //   break;
    int ecncrypted_ch = encrypt_char_simple(key, ch_to_encrypt);
    put_code_into_file(outFile, ecncrypted_ch);
  }

  inFile.close();
  outFile.close();
}

int encrypt_char_simple(string key, char ch_to_encrypt)
{
  return (time(NULL) % 100) + 50;
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