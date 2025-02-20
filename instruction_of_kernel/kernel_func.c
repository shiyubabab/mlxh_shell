/*************************************************************************
	> File Name: kernel_func.c
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 08:55:04 AM CST
 ************************************************************************/

#include"kernel_func.h"


static ins_t string2enum(const char *instruction){
	if(!strcmp(instruction,"ls")){
		return LS;
	}
	if(!strcmp(instruction,"wc")){
		return WC;
	}
	return DEFAULT;
}

int is_kernel_instruction(const char *instruction){
	int ret = 0;
	ins_t type_of_ins = string2enum(instruction);
	switch(type_of_ins){
		case 0:
			ret = 1;
			break;
		case 1:
			ret = 1;
			break;
		default:
			ret = 0;
			break;
	}
	return ret;
}

static void ls_function(char **args,char **envp){
	execve("/usr/bin/ls",args,envp);
}

static void wc_function(char **args,char **envp){
	if(!args[1]){
		perror("it is less paramters for wc instruction.");
		exit(0);
	}
	execve("/usr/bin/wc",args,envp);
}

void do_function(char **args,char **envp){
	ins_t type_of_ins = string2enum(args[0]);
	switch(type_of_ins){
		case 0:
			ls_function(args,envp);
			break;
		case 1:
			wc_function(args,envp);
			break;
		default:
			break;
	}
}

