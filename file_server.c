#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define BSIZE 1024

void error_handling(char *message);

int main(int argc,char **argv)
{
    int Csocket, Lsocket;//一个用listen一个accept
    struct sockaddr_in C_socket;
    struct sockaddr_in L_socket;
    socklen_t clnt_addr_size;
    char buf[BSIZE];//文件缓冲区
    char file_name[50];//文件名

    if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

    Lsocket = socket(PF_INET, SOCK_STREAM, 0); // 创建套接字
    if(Lsocket == -1)
		error_handling("socket() error");
	
	memset(&L_socket, 0, sizeof(L_socket));
	L_socket.sin_family=AF_INET;
	L_socket.sin_addr.s_addr=htonl(INADDR_ANY);
	L_socket.sin_port=htons(atoi(argv[1]));

    int i;
    
    if(bind(Lsocket, (struct sockaddr*) &L_socket, sizeof(L_socket))==-1 )
		error_handling("bind() error"); 
	
	if(listen(Lsocket, 5)==-1)
		error_handling("listen() error");
	for(i = 0;i < 5;i++)
    {
	    clnt_addr_size=sizeof(C_socket);  
	    Csocket=accept(Lsocket, (struct sockaddr*)&C_socket,&clnt_addr_size);
        if(Csocket==-1)
		    error_handling("accept() error");  
        read(Csocket,file_name,sizeof(file_name));
        int return_flag = 1;
        ssize_t bytesRead;
            
            // 打开文件
        int file = open(file_name, "r");
            if (file == -1) {
                return_flag = -2;//表示未找到文件
                write(Csocket,(char *)&return_flag,sizeof(int));
                exit(EXIT_FAILURE);
            }
            write(Csocket,(char *)&return_flag,sizeof(int));
            while ((bytesRead = read(file, buf, sizeof(buf))) > 0) {    
            // 将读取的内容写入套接字
                if (write(Csocket, buf, sizeof(buf)) != bytesRead) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            }
    }
	
    close(Csocket);
    close(Lsocket);
    return 0;
    }

    


void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
