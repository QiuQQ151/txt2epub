#!/bin/bash
# txt转换为epub执行脚本
file_pattern="/root/project/txt2epub"

# 0 保存旧文件
for file in /root/project/txt2epub/temp/*; do  # 遍历目标目录
    if [ -f "$file" ]; then
        mv $file /root/project/txt2epub/history/
    fi
done


# 1 删除旧的内容目录，重建目录
cd "/root/project/txt2epub" # 进入操作目录
rm -r "epub"  # 删除目录
mkdir "epub"  # 重建目录
mkdir "epub/META-INF"
mkdir "epub/OEBPS"

# 2 准备通用文件
cp "lib/mimetype" "epub"
cp "lib/container.xml" "epub/META-INF/"

#  考虑多文件问题，依次转换打包
for txt_file in ../html2txt/temp/*.txt; do

filename=$(basename "$txt_file" .txt)  # 如 新华日报20241016
epub_file="../temp/${filename}.epub"

# 3 启动转换程序
./txt2epub.exe "$txt_file"
# 4 epub文件打包
cd "epub"
zip -X0 "$epub_file" mimetype
zip -rX9 "$epub_file" META-INF/ OEBPS/
cd ".."

done