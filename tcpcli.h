#ifndef _TCPCLI_H_
#define _TCPCLI_H_


#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <string.h>
#include <stdexcept>

class tcpcli 
{
  int fd;
public:
  tcpcli(char *ip,int port);
  int sread(char *buff,int buffsize);
  int swrite(char *buff, int buffsize);
};

#endif
