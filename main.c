/*************************************************************************
	> File Name: main.c
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 08:55:04 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main(void){
	pid_t pid = fork();
	if(pid == 0){
		printf("I am sun of process.\n");
	}
	if(pid != 0){
		printf("I am father of process.\n");
	}
	return 0;
}

