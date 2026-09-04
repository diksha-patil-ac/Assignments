#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

enum class HttpStatus {

    Ok             = 200,
    Created        = 201,
    BadRequest     = 400,
    Unauthorized   = 401,
    NotFound       = 404,
    ServerError    = 500,
};

void handleResponse(HttpStatus status, const string& endpoint) {

    switch(static_cast<int>(status)) {

        case 200 :
            cout << endpoint << "        -> 200 Ok            : Request successful" << endl;
            break;

        case 201 :
            cout << endpoint << "-> 201 Created : Resource created successfully" << endl;
            break;

        case 400 :
            cout << endpoint << "-> 400 BadRequest : Invalid request" << endl;
            break;

        case 401 :
            cout << endpoint << "        -> 401 Unauthorized  : Authentication required " << endl;
            break;

        case 404 :
            cout << endpoint << "  -> 404 NotFound      : Endpoint does not exist" << endl;
            break;

        case 500 :
            cout << endpoint << "        -> 500 ServerError   : Internal server error : retry later" << endl;
            break;

        default :
            cout << "Unknown Http status code" << endl;
            break;
    }
}

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers) {
        
    for(const Header& h:headers) {
        cout << h.first << " : " << h.second << endl; 
    }
}


int main() {

    // Part A :
    handleResponse(HttpStatus::Ok, "api/users");
    handleResponse(HttpStatus::Unauthorized, "api/login");
    handleResponse(HttpStatus::NotFound, "api/products/99");
    handleResponse(HttpStatus::ServerError, "api/order");
    
    // Part B :
    RequestId requestId = 1748293847;

    Port serverPort = 8080;

    HeaderList Headers = {
        {"Content-Type    ", "application/jason"}, 
        {"Authorization   ", "Bearer eyJhbGci..."}, 
        {"Accept-Language ", "en-US"}
    };

    cout << "  " << endl;

    cout << "Request ID  : " << requestId << endl;

    cout << "Server Port : " << serverPort << endl;

    cout << "  " << endl;

    cout << "Headers: " << endl;

    printHeaders(Headers);

    return 0;
}