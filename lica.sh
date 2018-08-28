#!/bin/bash
echo 生成数$1
echo 保存到文件$2
i=0
echo>$2
while((i<$1))
do
  echo $RANDOM>>$2
  echo " ">>$2
  ((i++))
done
cat $2
