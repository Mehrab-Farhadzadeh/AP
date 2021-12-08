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
int encrypt_char_simple(string key, char ch_to_encrypt, int ch_pos);
void complicated_encryption(string key);
int sum_of_strings_chars(string str);
int encrypt_char_complicated(char ch_to_encrypt);

void decryption(string approach, string key);
void simple_decryption(string key);
char decrypt_code_simple(string key, int code_to_decrypt, int code_pos);
void complicated_decryption(string key);
char decrypt_code_complicated(int code_to_decrypt);

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

void simple_encryption(string key)
{
  string inFilePath, outFilePath;
  get_files_paths(inFilePath, outFilePath);

  ifstream inFile(inFilePath);
  ofstream outFile(outFilePath);

  if (!inFile.is_open() || !outFile.is_open())
    cout << "Unable to open file(s)" << endl;

  int ch_pos = 0;
  while (true)
  {
    char ch_to_encrypt = get_char_from_file(inFile);
    if (inFile.eof())
      break;
    int ecncrypted_ch = encrypt_char_simple(key, ch_to_encrypt, ch_pos);
    put_code_into_file(outFile, ecncrypted_ch);
    ch_pos++;
  }

  inFile.close();
  outFile.close();
}

int encrypt_char_simple(string key, char ch_to_encrypt, int ch_pos)
{
  int encrypted_ch = (int)key[ch_pos % key.size()] + (int)ch_to_encrypt;
  return encrypted_ch;
}

void complicated_encryption(string key)
{
  string inFilePath, outFilePath;
  get_files_paths(inFilePath, outFilePath);

  ifstream inFile(inFilePath);
  ofstream outFile(outFilePath);

  if (!inFile.is_open() || !outFile.is_open())
    cout << "Unable to open file(s)" << endl;

  int ch_pos = 0;
  int sum_of_keys_chars = sum_of_strings_chars(key);
  srand(sum_of_keys_chars);
  while (true)
  {
    char ch_to_encrypt = get_char_from_file(inFile);
    if (inFile.eof())
      break;
    int ecncrypted_ch = encrypt_char_complicated(ch_to_encrypt);
    put_code_into_file(outFile, ecncrypted_ch);
    ch_pos++;
  }

  inFile.close();
  outFile.close();
}

int sum_of_strings_chars(string str)
{
  int sum = 0;
  for (int i = 0; str[i]; i++)
    sum += (int)str[i];
  return sum;
}

int encrypt_char_complicated(char ch_to_encrypt)
{
  int encrypted_ch = (rand() % 11) + (int)ch_to_encrypt;
  return encrypted_ch;
}

void decryption(string approach, string key)
{
  if (approach == "simple")
    simple_decryption(key);
  else
    complicated_decryption(key);
}

void simple_decryption(string key)
{
  string inFilePath, outFilePath;
  get_files_paths(inFilePath, outFilePath);

  ifstream inFile(inFilePath);
  ofstream outFile(outFilePath);

  if (!inFile.is_open() || !outFile.is_open())
    cout << "Unable to open file(s)" << endl;

  int code_pos = 0;
  while (true)
  {
    int code_to_decrypt = get_code_from_file(inFile);
    if (inFile.eof())
      break;
    char decrypted_code = decrypt_code_simple(key, code_to_decrypt, code_pos);
    put_char_into_file(outFile, decrypted_code);
    code_pos++;
  }

  inFile.close();
  outFile.close();
}

char decrypt_code_simple(string key, int code_to_decrypt, int code_pos)
{
  char decrypted_code = (char)(code_to_decrypt - (int)key[code_pos % key.size()]);
  return decrypted_code;
}

void complicated_decryption(string key)
{
  string inFilePath, outFilePath;
  get_files_paths(inFilePath, outFilePath);

  ifstream inFile(inFilePath);
  ofstream outFile(outFilePath);

  if (!inFile.is_open() || !outFile.is_open())
    cout << "Unable to open file(s)" << endl;

  int code_pos = 0;
  int sum_of_keys_chars = sum_of_strings_chars(key);
  srand(sum_of_keys_chars);
  while (true)
  {
    int code_to_decrypt = get_code_from_file(inFile);
    if (inFile.eof())
      break;
    char decrypted_code = decrypt_code_complicated(code_to_decrypt);
    put_char_into_file(outFile, decrypted_code);
    code_pos++;
  }

  inFile.close();
  outFile.close();
}

char decrypt_code_complicated(int code_to_decrypt)
{
  char decrypted_code = (char)(code_to_decrypt - (rand() % 11));
  return decrypted_code;
}