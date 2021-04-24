#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/stat.h>

char *fAddress;
int folderId;
int dfolderId;
char *tDate;

void makedir () {

	time_t current;
	current = time(NULL);
   	struct tm * tLocal = localtime(&current);

	char buffer[20];
    	strftime(buffer, sizeof(buffer), "%Y-%m-%d_%T", tLocal);
	
	if ((tDate = (char *) shmat(dfolderId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
	strcpy(tDate, buffer);

	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}	
	
	char *rDir = "/home/fortunela/seslab_sisop/asistensi2/";
	strcpy(fAddress, rDir);
    	strcat(fAddress, tDate);
	
	char *argv[] = {"mkdir", "-p", fAddress, NULL};
	execv("/bin/mkdir", argv);
}

int oldId;
int newId;
char *oldName;
char *newName;
    	
void download () {
	time_t current;
	current = time(NULL);
	char buffer2[30];
    	snprintf(buffer2, 30, "https://picsum.photos/%ld", (current % 1000) + 50);
	if ((oldName = (char *) shmat(oldId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}

	if ((newName = (char *) shmat(newId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}

	char buffer3[10];
	snprintf(buffer3, 10, "/%ld", (current % 1000) + 50);
	strcpy(oldName, buffer3);

	struct tm * tLocal = localtime(&current);
	char buffer4[30];
	strftime(buffer4, sizeof(buffer4), "/%Y-%m-%d_%H:%M:%S", tLocal);
	strcpy(newName, buffer4);

	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}

	char *argv[] = {"/usr/bin/wget", "-q", buffer2, "-P", fAddress, NULL};
	execvp("/usr/bin/wget", argv);	
}

void renameFile () {
	
	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}

	if ((oldName = (char *) shmat(oldId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
    	
	if ((newName = (char *) shmat(newId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}

	char *initName = (char*) malloc(100);	
	strcpy(initName, fAddress);
    	strcat(initName, oldName);

	char *finalName = (char*) malloc(100);
	strcpy(finalName, fAddress);
    	strcat(finalName, newName);

	char *argv[] = {"mv", initName, finalName, NULL};
	execvp("/bin/mv", argv);

}

void appendStat(){
	char text[] = "Download Success";
	int shift = 5;
	for(int i=0; i<strlen(text); i++){

		if(text[i] >= 'a' && text[i] <= 'z'){
			text[i] += shift;
			if(text[i] > 'z') text[i] = text[i] - 'z' + 'a' - 1;
		}
		else if(text[i] >= 'A' && text[i] <= 'Z'){
			text[i] += shift;
			if(text[i] > 'Z') text[i] = text[i] - 'Z' + 'A' - 1;
		}
	}
	FILE *fStatus = fopen("status.txt", "a");
	fprintf(fStatus, "%s\n", text);
	fclose(fStatus);

	if ((tDate = (char *) shmat(dfolderId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
	
	char zipName[30];
	sprintf(zipName, "%s.zip", tDate);
	char *argv[] = {"zip", "-rm", zipName, tDate, NULL};
	execvp("/usr/bin/zip", argv);
}

void bashKiller(char option[]) {
	
	FILE *fKiller = fopen("killer.sh", "w");

	if(!(strcmp(option, "-x"))) {
		fprintf(fKiller, "#!/bin/bash \n\nkill %d \necho \'Program is successfully terminated.\' \nrm \"$0\" \n", getpid());
	}
	if(!(strcmp(option, "-z"))) {
		fprintf(fKiller, "#!/bin/bash \n\nkillall -9 3a.o \necho \'Program is forcefully killed.\' \nrm \"$0\" \n");
	}
	fclose(fKiller);

	pid_t pid = fork();
    	if(pid == 0){
        	char *argv[] = {"chmod", "+x", "killer.sh", NULL};
        	execv("/bin/chmod", argv);
    	}

}

int main(int argc, char* argv[]) {

	if(argc < 2) {
        	printf("Default option is -z.\n");
		argv[1] = "-z";
    	}
	else if(argv[1][1] != 'z' && argv[1][1] != 'x'){
		printf("Only option -z or -x is permitted.\n");
        	exit(0);
	}

	pid_t sid, pid0 = fork();
	if(pid0 < 0) exit(EXIT_FAILURE);
	else if(pid0 > 0) exit(EXIT_SUCCESS);

	umask(0);
	if((sid = setsid()) < 0) exit(EXIT_FAILURE);
	
	if((chdir("/home/fortunela/seslab_sisop/asistensi2")) < 0) 		 	exit(EXIT_FAILURE);
	close(STDIN_FILENO);	
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	
	bashKiller(argv[1]);
	
	int status, status2;
	
	while(1) {
	if ((folderId = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0666)) < 0)
        	printf("smget returned -1\n");

	if ((oldId = shmget(IPC_PRIVATE, 10, IPC_CREAT | 0666)) < 0)
        	printf("smget returned -1\n");
  
	if ((newId = shmget(IPC_PRIVATE, 20, IPC_CREAT | 0666)) < 0)
        	printf("smget returned -1\n");
   	
	if ((dfolderId = shmget(IPC_PRIVATE, 20, IPC_CREAT | 0666)) < 0)
        	printf("smget returned -1\n");
	
	pid_t pidn, pid1, pid2, pid3;
	pidn = fork();
	
	if(pidn == 0) {	
		pid1 = fork();
		if(pid1 == 0) makedir();
		else if(pidn == -1) exit(0);

		while ((wait(&status)) >0);
		for(int i=10; i>0; --i){
			pid2 = fork();
			if(pid2 == 0) {
				sleep(5);
				download();
			}
			else if(pidn == -1) exit(0);
			while ((wait(&status)) > 0);
			
			pid3 = fork();
			if(pid3 == 0) {
				renameFile();
			}
			else if(pidn == -1) exit(0);

		}
		while ((wait(&status2)) >0);
		appendStat();
		
	}
	else if(pidn == -1) exit(0);

	sleep(40);

	}
}
