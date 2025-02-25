/*************************************************************************
	> File Name: main.c
	> Author: mlxh
	> Mail: mlxh_gto@163.com 
	> Created Time: Thu 20 Feb 2025 08:55:04 AM CST
 ************************************************************************/

#include"all_of_include.h"

void signal_handler(int signum){
	printf("Received signal %d \n", signum);
	if(signum == SIGINT){
		//if((execlp("/usr/bin/clear","/usr/bin/clear",NULL))==-1){
			//perror("execlp process clear error.");
			//exit(1);
		//}
		printf("Please don't leave.\n");
		printf("Are you really going to leave?\n");
		printf("Alright then, come back next time.\n");
		printf("hahaha, Looks like you're stuck.\n");
		printf("You can open a new terminal. Use " GREEN BOLD "ps -ef " RESET "to find the process ID, then kill process using " GREEN BOLD "kill -9 [process ID].\n" RESET);
		//exit(0);
	}
}


int main(void){
	while(1){
		// signals setting
		struct sigaction sa;
		sigset_t mask;
		sa.sa_handler = signal_handler;
		sigemptyset(&mask);
		sigaddset(&mask, SIGQUIT);
		sa.sa_mask = mask;
		sa.sa_flags = 0;
		if(sigaction(SIGINT,&sa,NULL) == -1){
			perror("sigaction");
			return 1;
		}
		if(sigaction(SIGTERM,&sa,NULL) == -1){
			perror("sigaction");
			return 1;
		}

		//path setting
		char currentPath[MAXPATH];
		char str[MAXINPUT];
		char **args;
		int ifpipe=0;

		if(!getcwd(currentPath,sizeof(currentPath))){
			perror("getcwd error");
			exit(0);
		}
		printf(GREEN BOLD "mlxh_shell " RESET YELLOW "[%s]" RESET WHITE BOLD" > " RESET,currentPath);
		gets(str);
		args = remove_space(str,&ifpipe);

		if(ifpipe>0){
			do_finctions_for_pipe(ifpipe,args);
		}else{
			int status;
			pid_t pid;
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
	}
	return 0;
}

