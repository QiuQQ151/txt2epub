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
   // 打开日志文件
   FILE* log_fp = fopen("./log/log.txt","a+");
   if( log_fp == NULL ){
      printf("日志文件打开失败\n");
      return 1;
   }
   
   // 读取txt内容到内存
   char* content;
   content = read_txt(argv[1]);

   // 将内容转化为链表
   struct Article* head;
   head = buil_article_list(content);
   //printf("标题:%s\n",head->title);
   
   // 创建content.opf
   content_opf_create(head,log_fp);
   // 创建toc.ncx
   toc_ncx_create(head,log_fp);
   // 创建chapterx.html
   chapter_create(head,log_fp);
   // 创建index.html
   index_create(head,log_fp);

   // 释放资源
   free_article_list(head);
   free(content); 
   return 0;
}