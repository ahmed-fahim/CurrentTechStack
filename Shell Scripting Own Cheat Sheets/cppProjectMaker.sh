printf "New Project Name? : ";
read proj_name;
mkdir -p -m a=rwx "$proj_name";
PREV_CMD_RES=$?;
if(($PREV_CMD_RES == 0));
then
	cd "$proj_name";
	PREV_CMD_RES=$?;
	if(($PREV_CMD_RES == 0));
	then
		touch $proj_name".cpp";
		touch $proj_name".sh";
		chmod 777 $proj_name".sh";
		chmod 777 $proj_name".cpp";
		printf "cd \"$(pwd)\\\";\n" > $proj_name".sh";
		printf "Decision=0;\n" >> $proj_name".sh";
		printf "while((\$Decision != 3));do\n" >> $proj_name".sh";
		printf "\tprintf \"Press 1 to Compile\\\n\";\n" >> $proj_name".sh";
		printf "\tprintf \"Press 2 to Compile & Run\\\n\";\n" >> $proj_name".sh";
		printf "\tprintf \"Press 3 to Exit\\\n\";\n" >> $proj_name".sh";
		printf "\tread Decision;\n" >> $proj_name".sh";
		printf "\tif((\$\? == 0));then\n" >> $proj_name".sh";
		printf "\t\tif((\$Decision == '1')); then\n" >> $proj_name".sh";
		printf "\t\t\tg++ -std=c++11 "$proj_name".cpp -o "$proj_name".o\n" >> $proj_name".sh";
		printf "\t\t\tif((\$\? != 0)); then\n" >> $proj_name".sh";
		printf "\t\t\t\tprintf \"There were errors while compiling\\\n\";\n" >> $proj_name".sh";
		printf "\t\t\t\tcontinue;\n" >> $proj_name".sh";
		printf "\t\t\telse\n" >> $proj_name".sh";
		printf "\t\t\t\tprintf \"Successfully compiled\\\n\";\n" >> $proj_name".sh";
		printf "\t\t\t\tcontinue;\n" >> $proj_name".sh";
		printf "\t\t\tfi;\n" >> $proj_name".sh";
		printf "\t\telif((\$Decision == '2')); then\n" >> $proj_name".sh";
		printf "\t\t\tg++ -std=c++11 "$proj_name".cpp -o "$proj_name".o\n" >> $proj_name".sh";
		printf "\t\t\tif((\$\? != 0)); then\n" >> $proj_name".sh";
		printf "\t\t\t\tprintf \"There were errors while compiling\\\n\";\n" >> $proj_name".sh";
		printf "\t\t\t\tcontinue;\n" >> $proj_name".sh";
		printf "\t\t\telse\n" >> $proj_name".sh";
		printf "\t\t\t\tprintf \"Successfully compiled\\\n\";\n" >> $proj_name".sh";
		printf "\t\t\t\tprintf \"\\\n\\\n*****************Console Begin**************\\\n\";\n" >> $proj_name".sh";
		printf "\t\t\t\t./"$proj_name".o\n" >> $proj_name".sh";
		printf "\t\t\t\tprintf \"******************Console End***************\\\n\\\n\\\n\";\n" >> $proj_name".sh";
		printf "\t\t\t\tcontinue;\n" >> $proj_name".sh";
		printf "\t\t\tfi;\n" >> $proj_name".sh";
		printf "\t\telse\n" >> $proj_name".sh";
		printf "\t\t\tbreak;\n" >> $proj_name".sh";
		printf "\t\tfi\n" >> $proj_name".sh";
		printf "\tfi\n" >>  $proj_name".sh";
		printf "done\n" >> $proj_name".sh";
		printf "exit;\n" >> $proj_name".sh";
		open -a Terminal.app $proj_name".sh";
		if(($? == 0));
		then
			printf "Successfully completed execution\n";
		else
			printf "There were genjam\n";
		fi
	fi
fi
