#include <stdio.h>
#include <unistd.h>
#include <cstring>
/* for EXIT_FAILURE and EXIT_SUCCESS */
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
# define port 7001
using namespace std;
int main(int argc, char const *argv[])
{   cout<<"I am client"<<endl;
    
    char buffer[1024];
    int client_df = socket(AF_INET,SOCK_STREAM,0);
    if (client_df == -1)
    {
        cout<<"error"<<endl;
        return 0;
    }
    else{
      cout<<"socket discripter succesfully made"<<endl;
    }
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(client_df,(struct sockaddr *)&address, sizeof(address));

  if(connect(client_df,(struct sockaddr*)&address,sizeof(address))< 0){
    cout<<" connect client"<<endl;
  }
  else{
    cout<<"connect is suucessful"<<endl;
  }
    char *message= "9432";
    
    send(client_df,message,strlen(message),0);
    
    
    int valread;
    valread = recv(client_df,&buffer,1024,0);
    if (valread > 0){
        cout<<buffer<<endl;
    }
    else{
        cout<<"not read"<<endl;
    }
    


    close(client_df);
    cout<<"at the end"<<endl;
    return 0;
    
}
