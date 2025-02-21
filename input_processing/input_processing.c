/*************************************************************************
	> File Name: input_processing.c
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 09:45:57 AM CST
 ************************************************************************/

#include"input_processing.h"

char **remove_space(const char *str){
	int length = strlen(str);
	int str_num = 0, i=0;
	int flag = 0;
	char **args = (char **)malloc(sizeof(char *)*MAXSTRNUM);
	while(i<length){
		if(str[i] == '"') flag = (flag+1)%2;
		if(str[i] == ' ' && !flag){
			i++;
			continue;
		}
		args[str_num] = (char *)malloc(sizeof(char)*MAXSTR);
		int x=0;
		while((i<length) && (flag || str[i]!=' ')){
			args[str_num][x++] = str[i++];
			if(str[i] == '"')
				flag = (flag+1)%2;
			if(x>MAXSTR){
				perror("it is out of size for input word char.");
				break;
			}
		}
		str_num++;
		if(str_num>MAXSTRNUM){
			perror("it is out of size for input word.");
			break;
		}
	}
	args[str_num] = (char *)malloc(sizeof(char)*MAXSTR);
	args[str_num] = NULL;
	return args;
}

