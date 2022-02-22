#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct RequestInfos
{
  string mode;
  string approach;
  string key;
};

struct FilesPath
{
  string in_f;
  string out_f;
};

struct FilesStream
{
  ifstream in_f;
  ofstream out_f;
};

RequestInfos get_request_info();
FilesPath get_files_paths();
char get_char_from_file(ifstream &in_file);
void put_char_into_file(ofstream &out_file, char decrypted_code);
int get_code_from_file(ifstream &in_file);
void put_code_into_file(ofstream &out_file, char ch);
FilesStream open_files();

void encrypt(string approach, string key);
void simple_encrypt(string key);
int encrypt_char_simple(string key, char ch_to_encrypt, int ch_pos);
void complicated_encrypt(string key);
int sum_chars_ascii_code_of_string(string str);
int encrypt_char_complicated(char ch_to_encrypt);

void decrypt(string approach, string key);
void simple_decrypt(string key);
char decrypt_code_simple(string key, int code_to_decrypt, int code_pos);
void complicated_decrypt(string key);
char decrypt_code_complicated(int code_to_decrypt);

int main()
{
  RequestInfos request_info;
  request_info = get_request_info();

  if (request_info.mode == "encrypt")
    encrypt(request_info.approach, request_info.key);
  else
    decrypt(request_info.approach, request_info.key);

  return 0;
}

RequestInfos get_request_info()
{
  RequestInfos request_info;
  cin >> request_info.mode >> request_info.approach >> request_info.key;
  return request_info;
}

FilesPath get_files_paths()
{
  FilesPath files_path;
  cin >> files_path.in_f >> files_path.out_f;
  return files_path;
}
char get_char_from_file(ifstream &in_file)
{
  char ch_to_encrypt;
  in_file.get(ch_to_encrypt);
  return ch_to_encrypt;
}
void put_char_into_file(ofstream &out_file, char decrypted_code)
{
  out_file << decrypted_code;
}
int get_code_from_file(ifstream &in_file)
{
  int code;
  in_file >> code;
  return code;
}
void put_code_into_file(ofstream &out_file, int code)
{
  out_file << code << endl;
}

FilesStream open_files()
{
  FilesPath files_path;
  FilesStream files_stream;
  files_path = get_files_paths();
  files_stream.in_f.open(files_path.in_f);
  files_stream.out_f.open(files_path.out_f);

  if (!files_stream.in_f.is_open() || !files_stream.out_f.is_open())
  {
    cout << "Unable to open file(s)" << endl;
    abort();
  }

  return files_stream;
}

void encrypt(string approach, string key)
{
  if (approach == "simple")
    simple_encrypt(key);
  else
    complicated_encrypt(key);
}

void simple_encrypt(string key)
{
  FilesStream files_stream;
  files_stream = open_files();

  int ch_pos = 0;
  while (true)
  {
    char ch_to_encrypt = get_char_from_file(files_stream.in_f);
    if (files_stream.in_f.eof())
      break;
    int ecncrypted_ch = encrypt_char_simple(key, ch_to_encrypt, ch_pos);
    put_code_into_file(files_stream.out_f, ecncrypted_ch);
    ch_pos++;
  }

  files_stream.in_f.close();
  files_stream.out_f.close();
}

int encrypt_char_simple(string key, char ch_to_encrypt, int ch_pos)
{
  int encrypted_ch = (int)key[ch_pos % key.size()] + (int)ch_to_encrypt;
  return encrypted_ch;
}

void complicated_encrypt(string key)
{
  FilesStream files_stream;
  files_stream = open_files();

  int ch_pos = 0;
  int sum_of_chars_ascii_code_of_key = sum_chars_ascii_code_of_string(key);
  srand(sum_of_chars_ascii_code_of_key);
  while (true)
  {
    char ch_to_encrypt = get_char_from_file(files_stream.in_f);
    if (files_stream.in_f.eof())
      break;
    int ecncrypted_ch = encrypt_char_complicated(ch_to_encrypt);
    put_code_into_file(files_stream.out_f, ecncrypted_ch);
    ch_pos++;
  }

  files_stream.in_f.close();
  files_stream.out_f.close();
}

int sum_chars_ascii_code_of_string(string str)
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

void decrypt(string approach, string key)
{
  if (approach == "simple")
    simple_decrypt(key);
  else
    complicated_decrypt(key);
}

void simple_decrypt(string key)
{
  FilesStream files_stream;
  files_stream = open_files();

  int code_pos = 0;
  while (true)
  {
    int code_to_decrypt = get_code_from_file(files_stream.in_f);
    if (files_stream.in_f.eof())
      break;
    char decrypted_code = decrypt_code_simple(key, code_to_decrypt, code_pos);
    put_char_into_file(files_stream.out_f, decrypted_code);
    code_pos++;
  }

  files_stream.in_f.close();
  files_stream.out_f.close();
}

char decrypt_code_simple(string key, int code_to_decrypt, int code_pos)
{
  char decrypted_code = (char)(code_to_decrypt - (int)key[code_pos % key.size()]);
  return decrypted_code;
}

void complicated_decrypt(string key)
{
  FilesStream files_stream;
  files_stream = open_files();

  int code_pos = 0;
  int sum_of_chars_ascii_code_of_key = sum_chars_ascii_code_of_string(key);
  srand(sum_of_chars_ascii_code_of_key);
  while (true)
  {
    int code_to_decrypt = get_code_from_file(files_stream.in_f);
    if (files_stream.in_f.eof())
      break;
    char decrypted_code = decrypt_code_complicated(code_to_decrypt);
    put_char_into_file(files_stream.out_f, decrypted_code);
    code_pos++;
  }

  files_stream.in_f.close();
  files_stream.out_f.close();
}

char decrypt_code_complicated(int code_to_decrypt)
{
  char decrypted_code = (char)(code_to_decrypt - (rand() % 11));
  return decrypted_code;
}
