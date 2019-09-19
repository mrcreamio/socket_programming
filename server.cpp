#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
# define port 7007
using namespace std;
int main(int argc, char const *argv[])
{    cout<<"hi"<<endl;
    int bufsize=1024;
    char * buffer= new char[bufsize];
    int socket_df = socket(AF_INET,SOCK_STREAM,0);
    if (socket_df == -1)
    {
        std::cout<<"error"<<std::endl;
        return 0;
    }
    cout<<"socket created"<<endl;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(socket_df,(struct sockaddr *)&address, sizeof(address));

    if (listen(socket_df,30)<0)
  {
    
    cout<<"listen"<<endl;
    return 0;
  }
  cout<<"listen succesfull"<<endl;

    socklen_t addrlen = sizeof(address);
    int new_socket = accept(socket_df,(struct sockaddr *)& address,&addrlen);
    if (new_socket < 0)
    {
        cout<<"error while accept"<<endl;
    }
    else{   
        cout<<"new socket is "<< new_socket <<endl;
    }
    char *message= "This is a message to send\n\r I am server";
    send(new_socket,message,strlen(message),0);
    recv(new_socket,buffer,bufsize,0);

    cout<<buffer<<endl;
    close(socket_df);
    cout<<"terminated the client"<<endl;
    return 0;
    
}
