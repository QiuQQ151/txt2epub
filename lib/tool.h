
// void content_opf_create( File* txt, File* log );
// void toc_ncx_create( File* txt, File* log );
// void chapter_create( File* txt, File* log );
char* read_txt(char* txt_location);  //将txt读入内存中，返回字符数组指针
struct Article * buil_article_list(char* txt_content );  // 根据txt建立链表结构