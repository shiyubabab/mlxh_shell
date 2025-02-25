/*************************************************************************
	> File Name: all_of_include.h
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 09:33:26 AM CST
 ************************************************************************/

#ifndef __INCLUD_H__
#define __INCLUD_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "./input_processing/input_processing.h"
#include "./instruction_of_kernel/kernel_func.h"
#include "./shell_IO/pipe_instruction.h"

#define MAXINPUT 100
#define MAXPATH 256

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BOLD "\033[1m"
#define RESET "\033[0m" 

extern char **environ;

#endif



