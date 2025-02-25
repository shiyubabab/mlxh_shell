/*************************************************************************
	> File Name: pipe_instruction.c
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Tue 25 Feb 2025 02:15:09 PM CST
 ************************************************************************/

#include "pipe_instruction.h"

void do_finctions_for_pipe(const int ifpipe,char **args){
	pid_t pid1,pid2;
	int pipefd[2];
	int status1,status2;
	int pi=0,pj=0;
	char **args1 = (char **)malloc(sizeof(char *)*MAXWORD);
	char **args2 = (char **)malloc(sizeof(char *)*MAXWORD);

	for(pi;pi<ifpipe;pi++){
		args1[pi] = args[pi];
	}
	args1[pi] = NULL;
	for(pj;args[ifpipe+pj];pj++){
		args2[pj] = args[ifpipe+pj];
	}
	args2[pj] = NULL;

	if(pipe(pipefd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	//create first process
	pid1 = fork();
	if(pid1 == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid1 == 0){
		dup2(pipefd[1],STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		if(is_kernel_instruction(args1[0])){
			do_function(args1,environ);
			exit(0);
		}
		execve(args1[0],args1,environ);
		exit(0);
	}

	waitpid(pid1,&status1,0);
	if(WIFEXITED(status1)){
		int exit_code = WEXITSTATUS(status1);
		printf("Child process exited with code %d\n",exit_code);
	}

	//create another process
	pid2 = fork();
	if(pid2 == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid2 == 0){
		dup2(pipefd[0],STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		if(is_kernel_instruction(args2[0])){
			do_function(args2,environ);
			exit(0);
		}
		execve(args2[0],args2,environ);
		exit(0);
	}

	close(pipefd[0]);
	close(pipefd[1]);

	waitpid(pid2,&status2,0);
	if(WIFEXITED(status2)){
		int exit_code = WEXITSTATUS(status1);
		printf("Child process exited with code %d\n",exit_code);
	}
}

