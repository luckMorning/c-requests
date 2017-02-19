#include "tcpcli.h"

#include <iostream>
tcpcli::tcpcli(char *ip,int port)
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd<0) {
        throw std::runtime_error("创建socket失败");
    }

    struct sockaddr_in serverAddr;

    serverAddr.sin_family =AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ip);
    serverAddr.sin_port = htons(port);

    int err = connect(fd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
    if (err < 0) {
        throw std::runtime_error("不能连接");
    }
}
int tcpcli::sread(char *buff,int buffsize)
{
    char ch;
    char flag[5] = {0};//for \r\n\r\n
    int fi = 0, bi = 0; //flag index, buff index
    bool header_end = false;
    return recv(fd,buff, buffsize, 0);
    return bi;
}

int tcpcli::swrite(char *buff,int buffsize)
{
    return send(fd,buff,strlen(buff),0);
}



int main ()
{

    tcpcli cli("202.108.22.5",80);
    char buff[1024] = 
        "GET / HTTP/1.1\r\n"
        "Content-Type: */*\r\n"
        "Host: www.baidu.com\r\n"
        "\r\n";
    cli.swrite(buff,1024);
    memset(buff,0,1024);
    cli.sread(buff,1024);
    std::cout<<buff;
    std::cout<<strstr(buff,"Content-Encoding");
  //  std::cout<<buff;

}
