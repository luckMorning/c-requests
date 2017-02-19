#ifndef _REQUESTS_H_
#define _REQUESTS_H_

#include <string>
#include <map>

using std::string;
using std::map;

//forward define
class respone;
class Requests;

class respone 
{

public:
    string status_code;
    string text;
    map <string,string> headers;
};

class Requests 
{
public:
    map <string,string> headers;
    respone get(string url) ;
    respone post(string url,map<string,string> data);
};

Requests requests;

#endif
