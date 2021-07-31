#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main (){


 int sockServer, status, port = 8080, captured, c, sockClient, count;
 struct sockaddr_in server, client;
 char kataKata[2000], *balasan, temp;


 int optval;
 socklen_t optlen = sizeof(optval);


 //socket creation
 sockServer = socket(AF_INET, SOCK_STREAM, 0);


  if (sockServer < 0)
  {
   printf("Error la! \n");
  }
  else {
   printf("NICE!, setel \n");
  }




   if(getsockopt(sockServer, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen) < 0) {
   perror("getsockopt()");
   close(sockServer);
   exit(EXIT_FAILURE);
   }


   printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));


        /* Set the option active */
   optval = 1;
   optlen = sizeof(optval);


   if(setsockopt(sockServer, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen) < 0) {
   perror("setsockopt()");
   close(sockServer);
   exit(EXIT_FAILURE);
   }
   printf("SO_KEEPALIVE set on socket\n");




        /* Check the status again */
   if(getsockopt(sockServer, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen) < 0) {
   perror("getsockopt()");
   close(sockServer);
   exit(EXIT_FAILURE);
   }
   printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));






 //BIND creation inet_addr("169.254.98.74")
 server.sin_family = AF_INET;
 server.sin_addr.s_addr = inet_addr("169.254.98.73");
 server.sin_port = htons(port);


 status = bind(sockServer,(struct sockaddr *)&server, sizeof(server));


  if(status < 0){
   printf("OH MAN, CAN’T BIND \n");
  }
  else{
   printf("Alrigthtt gooddd bind done in port %d.. \n", port);
  }


 //listen creation
 captured =  listen (sockServer, 3);


  if (captured < 0){
   printf("nothing... \n");
  }
  else{
   printf("okayyy, Im waitinggg...\n");
  }


 c = sizeof(struct sockaddr_in);
 sockClient = accept(sockServer, (struct sockaddr *)&client, (socklen_t *)&c );


 while(strncmp(kataKata , "berhenti", 8) != 0){


  count = 0;
  printf("From client: ");


  recv(sockClient, kataKata, 2000, 0);
  puts(kataKata);


  memset(kataKata,0,sizeof(kataKata));
  printf("From server: ");
  scanf("%c", &temp);
  scanf("%[^\n]", balasan);
  count = send(sockClient, balasan, strlen(balasan), 0);



 }


 close(sockServer);


}


