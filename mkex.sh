#!/bin/bash

# 進行状況を示すメッセージの色を変更
yellow='\033[1;33m'
green='\033[0;32m'
no_color='\033[0m'

# 引数の数とオプションを確認
if [ $# -lt 1 ] || [ $# -gt 2 ]; then
	echo -e "${yellow}Usage: mkex [number(ex0n)] [-f(optional to make file in src or inc)]${no_color}"
  exit 1
fi

# ex00〜ex0$1 のディレクトリを作成
for i in $(seq -w 0 $1); do
  dir_name="ex0$i"
  echo -e "${yellow}Creating directory $dir_name ...${no_color}"
  mkdir $dir_name
  cd $dir_name
  mkdir src inc
  
  # -f オプションが指定されていた場合は、incとsrc内にファイルを作成
  if [ $# -eq 2 ] && [ $2 == "-f" ]; then
    while true; do
      echo -e "${yellow}Creating file in $dir_name/inc ...${no_color}"
      read -p "Enter a file name for inc: " inc_file
      touch inc/$inc_file
      echo -e "${green}File inc/$inc_file created.${no_color}"
      read -p "Do you want to create another inc file? (y/n) " answer
      if [ $answer == "n" ]; then
        break
      fi
    done
    while true; do
      echo -e "${yellow}Creating file in $dir_name/src ...${no_color}"
      read -p "Enter a file name for src: " src_file
      touch src/$src_file
      echo -e "${green}File src/$src_file created.${no_color}"
      read -p "Do you want to create another src file? (y/n) " answer
      if [ $answer == "n" ]; then
        break
      fi
    done
  fi
  
  cd ..
done

