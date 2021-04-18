#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/mman.h>

char *fAddress;
int folderId;
char *rDir = "/home/fortunela/seslab_sisop/asistensi2/";

void makedir () {

	time_t current;
	current = time(NULL);
   	struct tm * tLocal = localtime(&current);

	char buffer[20];
    	strftime(buffer, sizeof(buffer), "%Y-%m-%d_%T", tLocal);

	char *tDate = (char *) malloc(strlen(buffer)+1);
	strcpy(tDate, buffer);

	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
    	//else printf("Process %d attached the segment %d\n", getpid(), folderId);	
	
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
    	//else printf("Process %d attached the segment %d\n", getpid(), oldId);

	if ((newName = (char *) shmat(newId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
    	//else printf("Process %d attached the segment %d\n", getpid(), newId);

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
    	//else printf("Process %d attached the segment %d\n", getpid(), folderId);

	char *argv[] = {"/usr/bin/wget", "-q", buffer2, "-P", fAddress, NULL};
	execvp("/usr/bin/wget", argv);	
}

void renameFile () {
	
	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
    	//else printf("Process %d attached the segment %d\n", getpid(), folderId);

	if ((oldName = (char *) shmat(oldId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
    	//else printf("Process %d attached the segment %d\n", getpid(), oldId);

	if ((newName = (char *) shmat(newId, NULL, 0)) == (char *) -1){
        	printf("Process shmat returned NULL\n");
    	}
    	//else printf("Process %d attached the segment %d\n", getpid(), newId);

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
	char text[] = "'Download Success'";
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
	char *statAddr = (char*) malloc(100);	
	strcpy(statAddr, rDir);
	strcat(statAddr, "status.txt");
	char *argv[] = {"echo", text, ">>", "status.txt", NULL};
	execvp("/bin/echo", argv);
}

void zipFolder() {
	

}

void delFolder() {


}

int main(void) {
	while(1) {
	if ((folderId = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0666)) < 0) {
        	printf("smget returned -1\n");
   	 }
    	//else printf("Allocated %d, at id %d\n", (int) sizeof(fAddress), folderId);

	if ((oldId = shmget(IPC_PRIVATE, 10, IPC_CREAT | 0666)) < 0) {
        	printf("smget returned -1\n");
   	 }
    	//else printf("Allocated %d, at id %d\n", (int) sizeof(fAddress), oldId);

	if ((newId = shmget(IPC_PRIVATE, 20, IPC_CREAT | 0666)) < 0) {
        	printf("smget returned -1\n");
   	 }
    	//else printf("Allocated %d, at id %d\n", (int) sizeof(fAddress), newId);

	int status=0;
 	pid_t wpid;
	
	for(int i=0; i<=23; i++) {
		int pid = fork();
		while ((wpid=wait(&status)) >0);
		if(pid == 0) {
			if(i==0) makedir();
			else if(i != 0 && i%2 == 1 && i < 20) {
				sleep(5);
				download();
				puts("here");
			}
			else if(i != 0 && i%2 == 0 && i <= 20) renameFile();
			else if(i == 21) appendStat();
			else if(i == 22) zipFolder();
			else if(i == 23) delFolder();
		}else if (pid == -1){
                    printf("%d\n", getpid());
                    exit(0);
		}
         }
	while ((wpid=wait(&status)) >0);
	sleep(40);
        //exit(0);
	}
}
