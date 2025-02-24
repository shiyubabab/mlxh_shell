/*************************************************************************
	> File Name: main.c
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 08:55:04 AM CST
 ************************************************************************/

#include"all_of_include.h"

int main(void){
	while(1){
		char currentPath[MAXPATH];
		char str[MAXINPUT];
		char **args;
		int status;
		pid_t pid;

		if(!getcwd(currentPath,sizeof(currentPath))){
			perror("getcwd error");
			exit(0);
		}
		printf(GREEN BOLD "mlxh_shell " RESET YELLOW "[%s]" RESET WHITE BOLD" > " RESET,currentPath);
		gets(str);
		args = remove_space(str);
		pid = fork();
		if(pid == 0){
			if(is_kernel_instruction(args[0])){
				do_function(args,environ);
				exit(1);
			}
			execve(args[0],args,environ);
			exit(1);
		}else if(pid < 0){
			perror("it is error in fork");
			exit(1);
		}else{
			waitpid(pid,&status,0);
			if(WIFEXITED(status)){
				int exit_code = WEXITSTATUS(status);
				printf("Child process exited with code %d\n",exit_code);
			}
		}
	}
	return 0;
}

