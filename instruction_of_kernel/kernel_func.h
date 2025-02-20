/*************************************************************************
	> File Name: kernel_func.h
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 02:44:56 PM CST
 ************************************************************************/
#ifndef __KERNEL_FUNC__
#define __KERNEL_FUNC__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

typedef enum instruction_of_kernel{
	LS=0,
	WC,
	GIT,
	DEFAULT
}ins_t;

int is_kernel_instruction(const char *instruction);
void do_function(char **args,char **envp);

#endif
