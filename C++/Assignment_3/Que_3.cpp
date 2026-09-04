#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class LogBuffer {

    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

public:

    LogBuffer(int capacity);

    LogBuffer(const LogBuffer& other);

    LogBuffer& operator=(const LogBuffer& other);

    ~LogBuffer();

    void append(const char* msg);
    void print() const;
    void clear();

    static int getInstanceCount();
};

int LogBuffer::instanceCount = 0;

LogBuffer::LogBuffer(int capacity) {

    this->capacity = capacity;
    size = 0;

    buffer = new char[capacity + 1];

    buffer[0] = '\0';

    instanceCount++;

    cout << "[LogBuffer Created] capacity = " << capacity << endl;
}


LogBuffer::LogBuffer(const LogBuffer& other) {

    capacity = other.capacity;
    size = other.size;

    buffer = new char[capacity + 1];

    instanceCount++;

    cout << "[LogBuffer Deep Copied] capacity = " << capacity << endl;
}


LogBuffer& LogBuffer::operator=(const LogBuffer& other) {

    if(this == &other) {
        cout << "[Self-assignment detected - no operation]" << endl;
        return *this;
    }

    delete[] buffer;

    capacity = other.capacity;
    size = other.size;

    buffer = new char[capacity + 1];

    memcpy(buffer, other.buffer, size + 1);

    cout << "[LogBuffer Assigned]" << endl;

    return *this;
}


LogBuffer::~LogBuffer() {

    delete[] buffer;

    instanceCount--;

    cout << "[Logbuffer Destroyed]" << endl;
}


void LogBuffer::append(const char* msg) {

    int msgLength = strlen(msg);

    int available = capacity - size;

    int copyLength = min(msgLength, available);

    memcpy(buffer + size, msg, copyLength);

    size+=copyLength;

    buffer[size] = '\0';
}


void LogBuffer::print() const {
    cout << buffer << endl;
}

void LogBuffer::clear() {
    size = 0;
    buffer[0] = '\0';
}


int LogBuffer::getInstanceCount() {
    return instanceCount;
}


int main() {

    LogBuffer log1(256);

    log1.append("Server started on port 8080");

    log1.append(" | Request received from 192.168.1.10");

    log1.print();


    LogBuffer log2 = log1;

    log2.append(" | Cached response sent");

    cout << "log1 : ";
    log1.print();

    cout << "log2 : ";
    log2.print();


    LogBuffer log3(128);

    log3 = log1;

    cout << "log3 : ";
    log3.print();

    cout << "log1 : ";
    log1.print();


    log1 = log1;

    log1.print();


    cout << "Live Logbuffer objects : " << LogBuffer::getInstanceCount() << endl;


    return 0;
}