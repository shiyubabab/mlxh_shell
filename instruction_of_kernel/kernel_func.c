/*************************************************************************
	> File Name: kernel_func.c
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 08:55:04 AM CST
 ************************************************************************/

#include"kernel_func.h"

static char dirname[] = "/usr/bin";

static int is_executable(const char *filepath){
	struct stat st;
	if(stat(filepath,&st)==0){
		if(st.st_mode & S_IXUSR || st.st_mode & S_IXGRP || st.st_mode & S_IXOTH){
			return 1;
		}
	}
	return 0;
}

int is_kernel_instruction(const char *instruction){
	char filepath[1024];
	snprintf(filepath,sizeof(filepath),"%s/%s",dirname,instruction);
	return is_executable(filepath);
}


void do_function(char **args,char **envp){
	char filepath[1024];
	snprintf(filepath,sizeof(filepath),"%s/%s",dirname,args[0]);
	execve(filepath,args,envp);
}

