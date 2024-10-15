#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "./lib/tool.h"


/*
主函数
参数传递：
<被转换的txt文件地址>

*/
int main(int argc,char *argv[] )
{  
   // 读取txt内容到内存
   char* content;
   content = read_txt(argv[1]);

   // 将内容转化为链表
   struct Article* head;
   head = buil_article_list(content);
   printf("标题:%s\n",head->title);

   free_article_list(head);
   free(content); // 释放资源
   return 0;
}