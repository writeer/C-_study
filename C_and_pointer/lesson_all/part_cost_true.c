#include "part_cost.h"
#include <ctype.h>

static short totals = 0;//所有零件总数量

bool news(cost * costs)
{
    char * par;//用来记录参数
    cost part;
    int num;
    double value;//零件单价
    //检查参数
    par = strtok(NULL,",");
    if (strlen(par) < 20)
    {
        strcpy(part.description,par);
    }
    else{
        fprintf(stderr,"参数错误!!");
        return 0;
    }
    par = strtok(NULL,",");//这个参数和下面那个参数，还可以加上判断每个参数输入是否是数字，也就是检测输入是否正确然后在转换，我也懒得写了
    sscanf(par,"%d",&num);
     if (num > 0)//零件数量非负数，且不等于0
    {
        part.quantity = num;
    }
    else{
        fprintf(stderr,"参数错误!!!");
        return 0;
    }
    par = strtok(NULL,"\n");
    sscanf(par,"%lf",&value);
     if (value > 0)//假设单价大于零
    {
        part.Total_price = part.quantity * value;
    }
    else{
        fprintf(stderr,"参数错误!!!!");
        return 0;
    }
    for (int i = 1; i <= totals; i++)//如果存在被删除的零件，则把这个零件的零件号分配给新零件使用
    {
        if(costs[i].description[0] == ' ')
        {
            part.id = i;
            memcpy(&costs[i],&part,sizeof(cost));
            return 1;
        }
    }
    
    part.id = ++totals;//储存id大小

    costs = (cost *)(realloc(costs,(totals + 1) * sizeof(cost)));
    if(costs == NULL)
    {
        fprintf(stderr,"内存不足!");
        free(costs);
        exit(EXIT_FAILURE);
    }
    memcpy(&costs[totals],&part,sizeof(cost));
    return 1;
    
    
}

bool buy(cost * costs)
{
    if(costs == NULL)
    {
        fprintf(stderr,"库存中没有零件");
        return 0;
    }
     char * par;//用来记录参数
    int id,num;//零件号，数量，
    double cost_each;//单价
    //检查参数
    par = strtok(NULL,",");
    sscanf(par,"%d",&id);//零件号
    if (id > totals || id < 0)
    {
        fprintf(stderr,"零件不存在");
        return 0;
    }
    //如同我在上个函数里说的，我不会写检测输入是否合格，只做简单的测试，如果要测试是否是数字或者含有字符而错误，需要再写一个函数
    //并且因为每个函数的参数不同，所以每个函数要有独特的参数检测，但基本都是字符数字区别测试的复制,并且还有换行符等。
    //这样我用strtok实现不方便
    par = strtok(NULL,","); 
    sscanf(par,"%d",&num);
    if(num < 0)
    {
        fprintf(stderr,"参数错误！数量不能小于0");
        return 0;
    }
    costs[id].quantity += num;//增加数量
    par = strtok(NULL,"\n");
    sscanf(par,"%lf",&cost_each);
    if(cost_each < 0)//如果单价是负数，岂不是没有成本，虽然题目没有要求我还是加上了
    {
        fprintf(stderr,"参数错误！单价不能小于0");
        return 0;
    }
    costs[id].Total_price += cost_each * num;

    return 1;
}

bool shell(cost * costs)
{
    if(costs == NULL)
    {
        fprintf(stderr,"库存中没有零件");
        return 0;
    }
     char * par;//用来记录参数
    int id,num;
    double cost_each;//零件号，数量，单价
    //检查参数
    par = strtok(NULL,",");
    sscanf(par,"%d",&id);//零件号
    if (id > totals || id < 0)
    {
        fprintf(stderr,"零件不存在");
        return 0;
    }
    par = strtok(NULL,","); 
    sscanf(par,"%d",&num);
    if(num < 0)
    {
        fprintf(stderr,"参数错误！数量不能小于0\n");
        return 0;
    }
    int diff = costs[id].quantity - num;
    double price;//单价
    if(diff > 0){//零件数量不能减少到负数
        price = costs[id].Total_price / costs[id].quantity;//计算原来的单价
        costs[id].quantity = diff;//减少数量
    }
    else
    {
        fprintf(stderr,"零件数量不足，请先补货\n");
        return 0;
    }
    par = strtok(NULL,","); 
    sscanf(par,"%lf",&cost_each);
    if(cost_each < 0)//如果单价是负数，岂不是没有成本，虽然题目没有要求我还是加上了
    {
        fprintf(stderr,"参数错误！单价不能小于0\n");
        return 0;
    }
    
    double profit = cost_each - (price);//每单利润
    costs[id].Total_price -= price * num;//总价值减去出售的价值
    fprintf(stdout,"每单利润: %0.2lf 总利润 : %.2lf",profit, profit * num);//计算利润并打印
    return 1;
}

bool deletes(cost * costs)
{
    if(costs == NULL)
    {
        fprintf(stdin,"库存中没有零件");
        return 0;
    }
    int id;
    char * par = strtok(NULL,"\n");
    sscanf(par,"%d",&id);
    if (id >= totals || id < 0)
    {
        fprintf(stderr,"零件不存在");
        return 0;
    }
    memset(costs[id].description,0,sizeof(costs[id].description));
    //因为我的新零件的测试，是使用的空格，所以要设一个空格，这样读取文件和在数据流中都能进行删除
    memset(costs[id].description,' ',sizeof(int));
    return 1;
}

void print_num(cost * costs)
{
    char *par = strtok(NULL,"\n");
    bool flag = 0;//效验位
    for (size_t i = 0; i < strlen(par); i++)//这个代码用于判断字符是否是数字，也可以用在上面的函数中
    {
        if(!isdigit(par[i]))
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        if(strcmp(par,"all") == 0)
        {
            fprintf(stdout,"|id   ");
            fprintf(stdout,"|零件描述信息(description)");
            fprintf(stdout,"|零件数量(quantity)");
            fprintf(stdout,"|总价值(Total_price)\n");
            for (size_t i = 1; i <= totals; i++)
            {
                fprintf(stdout,"|%-5d",costs[i].id);
                fprintf(stdout,"|%-25s",costs[i].description);
                fprintf(stdout,"|%-18d",costs[i].quantity);
                fprintf(stdout,"|%-5.2lf\n",costs[i].Total_price);
            }
        }else{
            fprintf(stderr,"参数错误!   可以尝试print all or print id");
        }
    }
    else
    {
        int id;//记录id
        sscanf(par,"%d",&id);
        if (id > totals || id < 0)
    {
        fprintf(stderr,"零件不存在");
        return ;
    }
        fprintf(stdout,"零件号(id): %-5d\n",costs[id].id);
        fprintf(stdout,"零件描述信息(description): %-20s\n",costs[id].description);
        fprintf(stdout,"零件数量(quantity): %-8d\n",costs[id].quantity);
        fprintf(stdout,"总价值(Total_price): %-23.2f\n",costs[id].Total_price);
    }
}

void total(cost * costs)
{
    double sum = 0; //计算储存所有零件的总价值
    for (size_t i = 1; i <= totals; i++)
    {
        sum += costs[i].Total_price;
    }
    fprintf(stdout,"所有零件总价值为: %.2lf",sum);
}

cost * file_read(FILE *fp)
{
    char buffer[251]; //缓冲区
    if (fgets(buffer, 251, fp) == NULL) // 文件为空
    {
        cost *costs = (cost *)malloc(sizeof(cost)); // 分配一些内存来存储一条记录
        if (costs == NULL)
        {
            fprintf(stderr, "无法分配内存");
            exit(EXIT_FAILURE);
        }
        costs[0].id = 0;
        memset(costs[0].description, 0, sizeof(costs[0].description)); // 初始化字符串为零
        costs[0].quantity = 0;
        costs[0].Total_price = 0;
        return costs;
        }
    //用读模式打开时，不知道为什么文件会偏移，于是读不到第一个id，所以重绕指针
    rewind(fp);
    char *par;
    cost * costs = (cost *)malloc(sizeof(cost));
    if(costs == NULL)
    {
        fprintf(stderr,"内存不足!");
        exit(EXIT_FAILURE);
    }
    size_t j = 0;
    while (fgets(buffer,251,fp) != NULL)
    {
        //我在写代码时发现如果中间的间隔符使用宽字符，会导致读取后更改文件格式，然后数据出现错误
        //所以在面对符号间隔等内容，最好不好中英文混用，全半角符号混用
        par = strtok(buffer,":");
        if(strcmp(par,"id") == 0)
        {
            par = strtok(NULL,"\n");
            int id;
            sscanf(par,"%d",&id);
            costs[j].id = id;
        }
        else if (strcmp(par,"description") == 0)
        {
            par = strtok(NULL,"\n");
            strcpy(costs[j].description,par);
        }
        else if (strcmp(par,"quantity") == 0)
        {
            par = strtok(NULL,"\n");
            int quantity;
            sscanf(par,"%d",&quantity);
            costs[j].quantity = quantity;
        }
        else if (strcmp(par,"Total_price") == 0)
        {
            par = strtok(NULL,"\n");
            double Total;//总价值
            sscanf(par,"%lf",&Total);
            costs[j].Total_price = Total;
            j++;

            costs = (cost *)realloc(costs,(j + 1) * sizeof(cost));
            if(costs == NULL)
            {
                fprintf(stderr,"内存不足!");
                free(costs);
                exit(EXIT_FAILURE);
            }
           
        }
    }
    totals = j - 1;
    //因为上面的逻辑是提前申请内存，然后变量j位移指向下一个，最后一次执行就会剩下一个多余的，所以下面去掉多余的。
    costs = (cost *)realloc(costs,(totals + 1) * sizeof(cost));
    
    return costs;
}

void file_write(FILE *fp,cost * costs)
{
    fseek(fp,0,SEEK_SET);
    fprintf(fp,"id:%d\n",costs[0].id);
    fprintf(fp,"description: \n");
    fprintf(fp,"quantity:0\n");
    fprintf(fp,"Total_price:0\n\n");
    for (int i = 1; i <= totals; i++)
    {
        fprintf(fp,"id:%d\n",costs[i].id);
        if(costs[i].description[0] == 0)
        {
            fprintf(fp,"description: \n");
        }
        else{
            fprintf(fp,"description:%s\n",costs[i].description);
        }
        fprintf(fp,"quantity:%d\n",costs[i].quantity);
        fprintf(fp,"Total_price:%.2lf\n\n",costs[i].Total_price);
    }
    free(costs);
    fclose(fp);
    exit(EXIT_SUCCESS);
}