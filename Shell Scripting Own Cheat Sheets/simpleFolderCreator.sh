#!/bin/bash
#Sample Folder Creator Script

printf "How Many Folders You Require?\n";
read folder_number;
printf "General Folder Name Suffix?\n";
read suffix;

for((i = 1; i <= folder_number; i++)); do
	mkdir $suffix" "$i;
done


