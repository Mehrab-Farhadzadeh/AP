#include <iostream>
#include <string>

using namespace std;

#define MAX_ATTEMPTS 3
#define TIMEOUT (rand() % 10 != 0)

void open_connection(){};
void close_connection(){};
class NetworkError
{
public:
    NetworkError(string err) : error(err) {}
    string get_error() { return error; }

private:
    string error;
    // other fields describing the error
};
void send_bytes(const char *bytes, int len)
{
    // try to send s over the network …
    if (TIMEOUT)
        throw NetworkError("Connection time-out");
    // …
}
void send_bytes_alt(string msg, int length)
{
    // try to send s over the network …
    if (TIMEOUT)
        throw NetworkError("Connection time-out");
    // …
}

void send_message_alt(string msg)
{
    open_connection();
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS)
        try
        {
            send_bytes(msg.c_str(), msg.length());
            cout << "Message sent successfully\n";
            break;
        }
        catch (NetworkError &ex)
        {
            send_bytes_alt(msg.c_str(), msg.length());
            cerr << "Could not send the message ";
            attempts++;
            if (attempts < MAX_ATTEMPTS)
                cerr << ", retrying...";
            else
            {
                close_connection();
                throw;
            }
            cerr << endl;
        }
    close_connection();
}

void send_message(string msg)
{
    open_connection();
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS)
        try
        {
            send_bytes(msg.c_str(), msg.length());
            cout << "Message sent successfully\n";
            break;
        }
        catch (NetworkError &ex)
        {
            cerr << "Could not send the message ";
            attempts++;
            if (attempts < MAX_ATTEMPTS)
                cerr << ", retrying...";
            else
            {
                close_connection();
                throw;
            }
            cerr << endl;
        }
    close_connection();
}

int main()
{
    long seed = time(0);
    cout << "random seed = " << seed << endl;
    srand(seed);
    send_message("Hello");
}