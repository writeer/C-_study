#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>

void ErrorHandling(char* message);

int main(int argc,char **argv){
    WSADATA wsadata;
    SOCKET  hClntSock;		
	SOCKADDR_IN clntAddr;
    char math[50] ={ '\0'};//储存要运算的数字
    char buf[10];//缓冲区
    char oper[2];//储存运算符号
    int count;
    printf("Connected...............");
    printf("\nOperand counnt:");
    scanf("%d",&count); //有几个数需要进行计算
    for (int i = 1; i <= count; i++)
    {
        printf("\nOperand %d :",i);
        scanf("%s",buf);
        strcat(math,buf);
        int c = strlen(math);
        math[c] = ' ';
        math[c+1] = '\0';
    }
    printf("Operator:");
    scanf("%s",&oper);
    if(oper[0] != '+' && oper[0] != '-' && oper[0] != '*' && oper[0] != '/')
    {
        fprintf(stderr,"oper error!\n");
        return 1;
    }
    strcat(math,oper);
    if(WSAStartup(MAKEWORD(2, 2), &wsadata)!=0)
		ErrorHandling("WSAStartup() error!"); 
    
    hClntSock = socket(PF_INET,SOCK_STREAM,0);

    if(hClntSock == INVALID_SOCKET)
        ErrorHandling("socket() error");
    
    memset(&clntAddr,0,sizeof(clntAddr));
    clntAddr.sin_family = AF_INET;
    clntAddr.sin_addr.s_addr = inet_addr(argv[1]);
    clntAddr.sin_port = htons(atoi(argv[2]));
    if(connect(hClntSock,(SOCKADDR*)&clntAddr,sizeof(clntAddr)) == SOCKET_ERROR) {
        fprintf(stderr, "Connection failed\n");
        closesocket(hClntSock);
        WSACleanup();
        return 1;
    }
    int str_len = sizeof(math);
    if(send(hClntSock,math,str_len,0) == SOCKET_ERROR)//发送数字串
    {
        fprintf(stderr, "secd failed\n");
        closesocket(hClntSock);
        WSACleanup();
        return 1;
    }
    double oper_sum = 0;
    // 接收数据
    int bytesReceived = recv(hClntSock, (char *)&oper_sum, sizeof(double), 0);

    if (bytesReceived == SOCKET_ERROR) {
        int errorCode = WSAGetLastError();
        perror("recv");
        fprintf(stderr, "recv failed with error code %d\n", errorCode);
    // 处理错误或关闭连接等操作

        closesocket(hClntSock);
        WSACleanup();
        return 1;
    } else if (bytesReceived == 0) {
        // 连接关闭
        printf("Connection closed by peer.\n");
        closesocket(hClntSock);
        WSACleanup();
        return 1;
    }
    printf("Opertion: result: %.2lf \n",oper_sum);
    closesocket(hClntSock);
    WSACleanup();
    return 0;
}


void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}