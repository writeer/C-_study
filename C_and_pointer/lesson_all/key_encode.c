/**
 * @file key_encode.c
 * @author your name (you@domain.com)
 * @brief 简单的加密程序
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief 生成秘钥表
 * @param key 单词
 * @return 返回是否成功
 */
int prepare_key(char *key);

void encrypt(char *data,char const *key);//加密

void decrypt(char *data,char const *key);//解密

int main()
{
    char key[27] = "TRAILBLAZERS"; 
    char code[] = "ATTACK AT dawn";
    printf("加密单词:%s \n 密钥单词:%s \n",code,key);
    if(prepare_key(key))
        printf("密钥生成成功：%s\n",key);
    else
        printf("密钥生成失败，单词中含有非字母或为空");
    encrypt(code,key);
    printf("加密后：%s\n",code);
    decrypt(code,key);
    printf("解密后: %s\n",code);
    getchar();
    return 0;
}

int prepare_key(char *key)
{
    if (*key == 0)//判断参数是否为空，或者未初始化
        return 0;
    for (int i = 0; *(key + i) != '\0'; i++)//将秘钥全部转换为大写
    {
        key[i] = toupper(*(key + i));
    }
    char temp[27] = {0};
    int t,i;
    for (i = 0,t = 0; key[i] != '\0' ; i++,t++)//去掉秘钥中重复的单词
    {
        temp[t] = key[i];
        for (int j = i - 1; j != 0; j--)
        {
            if(t == 0)break;
            if(key[i] == key[j])
            {
                t--;
                break;
            }
        }
        
    }
    temp[t] = '\0';
    if(strcpy(key,temp) == NULL)
    {
        fprintf(stderr,"错误，秘钥生成失败");
    };
    int j,k;
    for (j = strlen(key),k = 'A'; k <= 'Z'; k++)//生成秘钥表
    {
        if(strchr(key,k) == NULL){
            key[j] = k;
            j++;
        }
    }
    key[j] = '\0';

    /*for(int i = 0;i < 26; i++)//测试字母表
        printf("%c ",key[i]);*/
    return 1;
}

void encrypt(char *data,char const *key)
{
    for (int i = 0; i < strlen(data); i++)
    {
        if(isalpha(data[i]))//查看是否是字母
        {
            if(isupper(data[i]))//是否大写
            {
                data[i] = key[data[i]-'A'];
            }
            else
            {
                data[i] = toupper(data[i]);//转化为大写加密后，转换为小写
                data[i] = key[data[i]-'A'];
                data[i] = tolower(data[i]);
            }
        }
        else
            continue;
    }
    
}

void decrypt(char *data,char const *key)
{
    for (int i = 0; i < strlen(data); i++)
    {
        if(isalpha(data[i]))//查看是否是字母
        {
            if(isupper(data[i]))//是否大写
            {
                int j;
                for(j = 0;j < strlen(key); j++){
                    if(data[i] == key[j])
                        break;
                }
                data[i] = j + 'A';
            }
            else
            {
                data[i] = toupper(data[i]);//转化为大写加密后，转换为小写
                int j;
                for(j = 0;j < strlen(key); j++){
                    if(data[i] == key[j])
                        break;
                }
                data[i] = j + 'A';
                data[i] = tolower(data[i]);
            }
        }
        else
            continue;
    }
}
