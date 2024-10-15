#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include "./tool.h"



// 定义链表节点
typedef struct Article {
    char* num;                 // 文章标号
    char* title;               // 存储文章标题
    char* content;             // 存储文章内容
    struct Article *next;      // 指向下一个节点的指针
} Article;

/*
// 根据txt建立链表结构
输入值：
txt内容数组
返回值：
链表头指针
*/
struct Article * buil_article_list(char* txt_content )
{   
    // 链表头
    Article* head;
    head =( Article* )malloc( sizeof(Article) ); 
    // txt内容定位
    long tiltle_left = 0;
    long tiltle_right = 0;
    long content_left = 0;
    long content_right = 0;
    
    // 开始建立链表
    


}



/*
//将txt读入内存中，返回字符数组指针
*/
char* read_txt( char* txt_location )
{
    FILE *file;
    char *content = NULL;  // 指向字符数组的指针
    long file_size;
    // 打开文件
    file = fopen( txt_location , "r");
    if (file == NULL) {
        perror("无法打开文件");
        return NULL;
    }

    // 获取文件大小
    fseek(file, 0, SEEK_END);          // 移动到文件末尾
    file_size = ftell(file);           // 获取文件指针的位置，即文件大小
    fseek(file, 0, SEEK_SET);          // 移动回文件开头

    // 分配内存
    content = malloc(file_size + 1);  // +1 以便于存储字符串结束符
    if (content == NULL) {
        perror("内存分配失败");
        fclose(file);
        return NULL;
    }

    // 读取文件内容到内存
    fread(content, 1, file_size, file); // 读取文件内容
    content[file_size] = '\0';          // 添加字符串结束符    

    // 打印内容
    //printf("文件内容:\n%s\n", content);    

    // 关闭文件
    fclose(file);

    return content;
}
    
    












