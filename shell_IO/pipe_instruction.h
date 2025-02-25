/*************************************************************************
	> File Name: pipe_instruction.h
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Tue 25 Feb 2025 02:15:24 PM CST
 ************************************************************************/

#ifndef __IOINS_H
#define __IOINS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../input_processing/input_processing.h"
#include "../instruction_of_kernel/kernel_func.h"

#define MAXWORD 256
extern char **environ;
void do_finctions_for_pipe(const int ifpipe,char **args);

#endif
