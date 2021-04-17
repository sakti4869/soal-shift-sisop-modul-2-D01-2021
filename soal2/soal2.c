#include<sys/types.h>
#include<sys/stat.h>
#include<syslog.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<time.h>
#include<wait.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>
#include<fcntl.h>

int main() {
    int stat, stat2, stat3;
    pid_t nid;
    nid = fork();
    if(nid < 0) exit(0);
    if(nid == 0) {
        char *argu[] = {"unzip", "-o", "-q", "/home/sakti4869/modul2/pets.zip", "-d", "/home/sakti4869/modul2/petshop", NULL};
        execv("/usr/bin/unzip", argu);
    }
    
    while(wait(&stat) > 0);
    DIR *direc;
    struct dirent *access;
    direc = opendir("/home/sakti4869/modul2/petshop");
    while((access = readdir(direc)) != NULL) {
        if((access->d_type == DT_DIR) && strcmp(access->d_name, ".") != 0 && strcmp(access->d_name, "..") != 0) {
            pid_t nid;
            nid = fork();
            if(nid < 0) exit(0);
            if(nid == 0) {
                char fldrnme[300];
                sprintf(fldrnme, "/home/sakti4869/modul2/petshop/%s", access->d_name);
                char *argu[] = {"rm", "-r", fldrnme, NULL};
                execv("/bin/rm", argu);
            }
        }
    }
    while(wait(&stat2) > 0);
    DIR *direc2;
    struct dirent *access2;
    direc2 = opendir("/home/sakti4869/modul2/petshop");
    char fldrnme[100][300];
    int zid = 0;
    while((access2 = readdir(direc2)) != NULL) {
        if(access2->d_type == DT_REG) {
            char temp[300], temp2[300];
            memset(fldrnme[zid], 0, sizeof(fldrnme[zid]));
            memset(temp2, 0, sizeof(temp2));
            strcpy(temp, access2->d_name);
            
            int a, fnd = 0;
            for(a = 0; a < strlen(temp); a++) {
                if(temp[a] == ';') break;
                temp2[a] = temp[a];
            }
            
            for(a = 0; a < zid && fnd == 0; a++)
                if(strcmp(fldrnme[a], temp2) == 0)
                    fnd = 1;
            
            if(fnd == 0) {
                strcpy(fldrnme[zid], temp2);
                zid++;
            }
        }
    }
    
    int a;
    for(a = 0; a < zid; a++) {
        pid_t nid;
        nid = fork();
        if(nid < 0) exit(0);
        if(nid == 0) {
            char temp[300];
            sprintf(temp, "/home/sakti4869/modul2/petshop/%s", fldrnme[a]);
            char *argu[] = {"mkdir", temp, NULL};
            execv("/bin/mkdir", argu);
        }
    }
    while(wait(&stat3) > 0);
    DIR *direc3;
    struct dirent *access3;
    direc3 = opendir("/home/sakti4869/modul2/petshop");
    while((access3 = readdir(direc3)) != NULL) {
        if(access3->d_type == DT_REG) {
            char temp[300];
            char temp2_jenis[300], temp2_nama[300], temp2_umur[300];
            char temp3_jenis[300], temp3_nama[300], temp3_umur[300];
            memset(temp2_jenis, 0, sizeof(temp2_jenis));
            memset(temp2_nama , 0, sizeof(temp2_nama));
            memset(temp2_umur , 0, sizeof(temp2_umur));
            memset(temp3_jenis, 0, sizeof(temp3_jenis));
            memset(temp3_nama , 0, sizeof(temp3_nama));
            memset(temp3_umur , 0, sizeof(temp3_umur));
            strcpy(temp, access3->d_name);
            
            int a, b, fnd = 0, two = 0;
            for(a = 0; a < strlen(temp); a++) {
                if(temp[a] == ';') break;
                temp2_jenis[a] = temp[a];
            }
            
            a++; b = a;
            for(; a < strlen(temp); a++) {
                if(temp[a] == ';') break;
                temp2_nama[a-b] = temp[a];
            }
            
            a++; b = a;
            for(; a < strlen(temp); a++) {
                if(temp[a] == '_' || (temp[a] == '.' && temp[a+1] == 'j')) break;
                temp2_umur[a-b] = temp[a];
            }
            
            if(temp[a] == '_') {
                a++; b = a;
                for(; a < strlen(temp); a++) {
                    if(temp[a] == ';') break;
                    temp3_jenis[a-b] = temp[a];
                }
                
                a++; b = a;
                for(; a < strlen(temp); a++) {
                    if(temp[a] == ';') break;
                    temp3_nama[a-b] = temp[a];
                }
                
                a++; b = a;
                for(; a < strlen(temp); a++) {
                    if(temp[a] == '.' && temp[a+1] == 'j') break;
                    temp3_umur[a-b] = temp[a];
                }
                
                two = 1;
            }
   
            
            int stat, stat2;
            pid_t nid;
            nid = fork();
            if(nid < 0) exit(0);
            if(nid == 0) {
                char from[300], to[300];
                sprintf(from, "/home/sakti4869/modul2/petshop/%s", access3->d_name);
                sprintf(to, "/home/sakti4869/modul2/petshop/%s/%s", temp2_jenis, temp2_nama);
                char *argu[] = {"cp", "-r", from, to, NULL};
                execv("/bin/cp", argu);
            }
          
            while(wait(&stat) > 0);
            char keter[300];
            sprintf(keter, "/home/sakti4869/modul2/petshop/%s/keterangan.txt", temp2_jenis);
            FILE *filez;
            filez = fopen(keter, "a+");
            fprintf(filez, "nama : %s\n", temp2_nama);
            fprintf(filez, "umur : %s tahun\n\n", temp2_umur);
            fclose(filez);
            
            if(two == 1) {
                pid_t nid;
                nid = fork();
                if(nid < 0) exit(0);
                if(nid == 0) {
                    char from[300], to[300];
                    sprintf(from, "/home/sakti4869/modul2/petshop/%s", access3->d_name);
                    sprintf(to, "/home/sakti4869/modul2/petshop/%s/%s", temp3_jenis, temp3_nama);
                    char *argu[] = {"cp", "-r", from, to, NULL};
                    execv("/bin/cp", argu);
                }
              
                while(wait(&stat2) > 0);
                char keter[300];
                sprintf(keter, "/home/sakti4869/modul2/petshop/%s/keterangan.txt", temp3_jenis);
                FILE *filez;
                filez = fopen(keter, "a+");
                fprintf(filez, "nama : %s\n", temp3_nama);
                fprintf(filez, "umur : %s tahun\n\n", temp3_umur);
                fclose(filez);
                
            }
         
        }
    }
}
