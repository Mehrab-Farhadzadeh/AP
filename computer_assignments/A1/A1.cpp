#include <iostream>
#include <vector>
#include <string>
using namespace std;

void get_request_info(string &mode, string &approach, string &key);
void get_files_paths(string &inFilePath, string &outFilePath);

void encryption(string approach, string key);
void simple_encryption(string key);
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