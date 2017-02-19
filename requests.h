#ifndef _REQUESTS_H_
#define _REQUESTS_H_

#include <string>
#include <map>

using std::string;
using std::map;

//forward define
class respone;
class requests;


class requests 
{
public:
    respone get(string url) const;
    respone post(string url,map<string,string> data);
}

#endif
