#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
#include<string> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
using namespace std;
#define PORT     7004
#define MAXLINE 1024 
struct info
{
    string name;
    string rollNo;
};

int main() { 
    struct info student[3];
    student[0].rollNo = "9433";
    student[0].name = "ahmed";
    student[1].rollNo = "9432";
    student[1].name = "abubakar";
    student[2].rollNo = "9434";
    student[2].name = "usama";
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from server"; 
    struct sockaddr_in servaddr, cliaddr; 
      
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
socklen_t len;
    int n; 
for(int i=0;i<10;i++){
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,MSG_WAITALL, ( struct sockaddr *) &cliaddr,   &len); 
    buffer[n] = '\0'; 
    printf("Client : %s\n", buffer); 
    for (int i = 0; i < 3; i++)
    {
        if (buffer == student[i].name)
        {
            sendto(sockfd, student[i].rollNo.c_str(), strlen(student[i].rollNo.c_str()),  MSG_CONFIRM, (const struct sockaddr *) &cliaddr,  len);
            
        }
        
    }
    
    
    i = 0; 
} 
      
    return 0; 
} 
