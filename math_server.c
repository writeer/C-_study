#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char* message);
/**
 * @brief 计算结果返回
 * 
 * @param num 指针
 * @param oper 运算符
 * @param count 数字总数
 * @return double 
 */
double operation(double *num,char oper,int count);


int main(int argc,char **argv)
{
        int serv_sock;
	int clnt_sock;
        char buf[30];

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;
    if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

    serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");

    serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1 )
		error_handling("bind() error"); 
	
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	
	clnt_addr_size=sizeof(clnt_addr);  
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);
	if(clnt_sock==-1)
		error_handling("accept() error");  

    double num[30];//最多接受三十个数字
    if(read(clnt_sock,buf,sizeof(buf)))
    {
            int j,i,m;
            for(j = 0,i = 0,m = 0;i < 50;i++)//i遍历，j记录数字个数，m用作缓冲
            {
                if(buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/')
                {
                    double oper_count = operation(num,buf[i],j);
                    write(clnt_sock,(char *)&oper_count,sizeof(double));
			sleep(1);
                    break;
                }
                else if(buf[i] == ' ')
                {
                    if(j == 0)
                        {
                            sscanf(&buf[0],"%lf",&num[j]);
                            j++;
                            m = i;
                        }
                    else{
                        sscanf(&buf[m],"%lf",&num[j]);
                        m = i;
                        j++;
                    }
                }
            }
        
    }

	close(clnt_sock);	
	close(serv_sock);
    return 0;
}


void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

double operation(double *num,char oper,int count)
{
    double sum = num[0];
    int i;
    switch (oper)
    {
    case '+':
        for (i = 1; i < count; i++)
        {
            sum += num[i];
        }
        
        break;
    case '-':
        for (i = 1; i < count; i++)
        {
            sum -= num[i];
        }
        
        break;
    case '*':
        for (i = 1; i < count; i++)
        {
            sum *= num[i];
        }
        
        break;
    case '/':
        for (i = 1; i < count; i++)
        {
            sum /= num[i];
        }
        
        break;
    default:
        break;
    }
    return sum;
}
