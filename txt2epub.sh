#!/bin/bash
# txt转换为epub执行脚本

# 1 删除旧的内容目录，重建目录
cd "/root/project/txt2epub" # 进入操作目录
rm -r "epub"  # 删除目录
mkdir "epub"  # 重建目录
mkdir "epub/META-INF"
mkdir "epub/OEBPS"

# 2 准备通用文件
cp "lib/mimetype" "epub"
cp "lib/container.xml" "epub/META-INF/"

# 3 启动转换程序
./txt2epub.exe ./新华日报20241015.txt

# 4 文件打包
cd "epub"
zip -X0 ../新华日报.epub mimetype
zip -rX9 ../新华日报.epub META-INF/ OEBPS/