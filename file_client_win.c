/**
 * @file file_client_win.c
 * @author your name (you@domain.com)
 * @brief 这个程序我基本上写完了，包括服务端，但是因为我是跨平台写的文件传输，所以在传输文本文件时，会出现编码转换问题，如果有兴趣可以自行解决
 * @version 0.1
 * @date 2024-02-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>

#define BSIZE 1024

void ErrorHandling(char* message);


int main(int argc,char **argv)
{
    WSADATA wsadata;
    SOCKET client_soket;
    SOCKADDR_IN clientA;
    char buf[BSIZE];//缓冲区
    FILE *fp; // 用来保存文件

    if(argc != 4)//刚好ip,port,filename
    {
        printf("parameter error");
        exit(1);
    }

    if(WSAStartup(MAKEWORD(2, 2), &wsadata)!=0)
		ErrorHandling("WSAStartup() error!"); 
    printf("%s\n",argv[3]);
    client_soket = socket(PF_INET,SOCK_STREAM,0);

    memset(&clientA,0,sizeof(clientA));
    clientA.sin_family = AF_INET;
    clientA.sin_addr.s_addr = inet_addr(argv[1]);
    clientA.sin_port = htons(atoi(argv[2]));

    if(connect(client_soket,(SOCKADDR *)&clientA,sizeof(clientA)) == SOCKET_ERROR)
    {
        ErrorHandling("Connection failed\n");
    }
    int str_file = strlen(argv[3]) + 1;//我的服务端写的基本没问题，但是发送端我没有很好的理解send函数，所以导致我一直没有发送正确的字符串，而是运用sizeof(argv[3])计算了指针。
    if(send(client_soket,argv[3],str_file,0) == SOCKET_ERROR)
    {
        ErrorHandling("Send failed");
    }
    int file_size = 0;
    int bytesReceived = recv(client_soket,(char *)&file_size,sizeof(int),0);
    if (bytesReceived == SOCKET_ERROR) {
        int errorCode = WSAGetLastError();
        perror("recv");
        fprintf(stderr, "recv failed with error code %d\n", errorCode);
        ErrorHandling("recv failed");
    } else if (bytesReceived == 0) {
        // 连接关闭
       ErrorHandling("Connection closed by peer");
    }

    if(file_size == -2)//如果传输-2说明没找到文件
    {
        fprintf(stdout,"file does not exist!\n");
    }
    else{
        fp = fopen(argv[3],"wb");
        while (recv(client_soket,buf,sizeof(buf),0))
        {
            fwrite(buf,sizeof(char),sizeof(buf),fp);
        }
        printf("File transfer successful!\n");
    }

    fclose(fp);
    closesocket(client_soket);
    WSACleanup();
    return 0;
}

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}