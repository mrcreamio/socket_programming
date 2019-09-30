#include<iostream>
#include<sys/types.h> //contains number of datatypes used in system calls
#include<sys/socket.h> // includes a number of definations of structures 
#include<netinet/in.h>  // contains constants and structures needed for internet domain addresses
using namespace std;

void error(char *msg){
    cout<<msg;
}

int main(int argc, char const *argv[])
{
    struct info{
        string rollNo;
        string name;
    };
    struct info student[3];
    student[0].rollNo = "9433";
    student[0].name = "ahmed";
    student[1].rollNo = "9432";
    student[1].name = "abubakar";
    student[2].rollNo = "9434";
    student[2].name = "usama";
    int sockfd, newsockfd; // store the values returned by socket system calls and the accept system calls
    int portno = 7001, n;
    char buffer[256];
    struct sockaddr_in serv_addr; //contains the address of the the server
    struct sockaddr_in cli_addr; //contains the address of the the client
    
    //socket() system call creates a new socket

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET for internet domain::SOCK_STREAM for tcp connection
    if (sockfd == 0)
    {
        error("Error opening socket");
    }

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(portno); //converting port no to network byte order
    serv_addr.sin_addr.s_addr = INADDR_ANY;  //INADDR_ANY gives the IP address of the current machine/host

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Error on binding");
    }
    while (true)
    {
        
    
    
    listen(sockfd,5);
    socklen_t clilen = sizeof(cli_addr);
    
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd< 0)
    {
        error("Errror on accept");
    }
    recv(newsockfd,buffer,256,0);

    
    for (int i = 0; i < 3; i++)
    {
        if(student[i].rollNo == buffer){
            cout<<" student name is "<<student[i].name<<endl;
        }
        
    }
    
}

    return 0;
}
