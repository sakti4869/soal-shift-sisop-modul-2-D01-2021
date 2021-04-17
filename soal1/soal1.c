#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>
#include <dirent.h>

int main() {
	//  - Foto
	//  - Musik
	//  - Film
	
	pid_t pid, sid;        // Variabel untuk menyimpan PID

	pid = fork();     // Menyimpan PID dari Child Process

	/* Keluar saat fork gagal
	* (nilai variabel pid < 0) */
	if (pid < 0) {
		exit(EXIT_FAILURE);
	}

	/* Keluar saat fork berhasil
	* (nilai variabel pid adalah PID dari child process) */
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	umask(0);

	sid = setsid();
	if (sid < 0) {
		exit(EXIT_FAILURE);
	}

	if ((chdir("/home/david/Desktop/praktikumSisop/modul2/soalShift/soal1/final/")) < 0) {
	exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	time_t t = time(NULL);
	struct tm tm;

	while (1) {
		t = time(NULL);
		tm = *localtime(&t);

		if (tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 16 && tm.tm_min == 22 && tm.tm_sec == 0) { // (No. E)
			pid_t childId;
			int status;
			
			// Buat folder Fylm, Musyik, Pyoto (No. A)
			
			childId = fork();
			
			if (childId == 0) {
				char * argv[] = {
					"mkdir", "Fylm", "Musyik", "Pyoto", NULL
				};
				
				execv("/bin/mkdir", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// (No. B)
			
			// Download fotoForStevany.zip
			
			childId = fork();
			
			if (childId == 0) {
				char * link = "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download";
				char * argv[] = {
					"wget",
					"--no-check-certificate",
					link,
					"-O",
					"fotoForStevany.zip",
					"-q",
					NULL
				};
				
				execv("/bin/wget", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// Extract zip fotoForStevany.zip (No. C)
			
			childId = fork();
			
			if (childId == 0) {
				char * argv[] = {
					"unzip",
					"fotoForStevany.zip",
					NULL
				};
				
				execv("/bin/unzip", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// Download filmForStevany.zip
			
			childId = fork();
			
			if (childId == 0) {
				char * link = "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download";
				char * argv[] = {
					"wget",
					"--no-check-certificate",
					link,
					"-O",
					"filmForStevany.zip",
					"-q",
					NULL
				};
				
				execv("/bin/wget", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// Extract zip filmForStevany.zip (No. C)
			
			childId = fork();
			
			if (childId == 0) {
				char * argv[] = {
					"unzip",
					"filmForStevany.zip",
					NULL
				};
				
				execv("/bin/unzip", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// Download musikForStevany.zip
			
			childId = fork();
			
			if (childId == 0) {
				char * link = "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download";
				char * argv[] = {
					"wget",
					"--no-check-certificate",
					link,
					"-O",
					"musikForStevany.zip",
					"-q",
					NULL
				};
				
				execv("/bin/wget", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// Extract zip musikForStevany.zip (No. C)
			
			childId = fork();
			
			if (childId == 0) {
				char * argv[] = {
					"unzip",
					"musikForStevany.zip",
					NULL
				};
				
				execv("/bin/unzip", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// (No. D)
			
			// Buat baca folder sama file
			
			DIR *dir;
			struct dirent *dirFile;
			
			// Pindahin semua file dari FOTO ke Pyoto
			
			chdir("./FOTO/"); // Pindah ke folder FOTO
			dir = opendir("."); // Baca isi folder FOTO
			
			if (dir) {
				while ((dirFile = readdir(dir)) != NULL) {
					childId = fork();
					
					if (childId == 0) {
						char * argv[] = {
							"mv",
							dirFile->d_name,
							"../Pyoto/",
							NULL
						};
						
						execv("/bin/mv", argv);
					} else {
						while ((wait(&status)) > 0);
					}
				}
				
				closedir(dir); // Tutup folder FOTO
				chdir("../"); // Pindah ke folder final
			}
			
			// Pindahin semua file dari FILM ke Fylm
			
			chdir("./FILM/"); // Pindah ke folder FILM
			dir = opendir("."); // Baca isi folder FILM
			
			if (dir) {
				while ((dirFile = readdir(dir)) != NULL) {
					childId = fork();
					
					if (childId == 0) {
						char * argv[] = {
							"mv",
							dirFile->d_name,
							"../Fylm/",
							NULL
						};
						
						execv("/bin/mv", argv);
					} else {
						while ((wait(&status)) > 0);
					}
				}
				
				closedir(dir); // Tutup folder FILM
				chdir("../"); // Pindah ke folder final
			}
			
			// Pindahin semua file dari MUSIK ke Musyik
			
			chdir("./MUSIK/"); // Pindah ke folder MUSIK
			dir = opendir("."); // Baca isi folder MUSIK
			
			if (dir) {
				while ((dirFile = readdir(dir)) != NULL) {
					childId = fork();
					
					if (childId == 0) {
						char * argv[] = {
							"mv",
							dirFile->d_name,
							"../Musyik/",
							NULL
						};
						
						execv("/bin/mv", argv);
					} else {
						while ((wait(&status)) > 0);
					}
				}
				
				closedir(dir); // Tutup folder MUSIK
				chdir("../"); // Pindah ke folder final
			}
		}
		
		if (tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 22 && tm.tm_min == 22 && tm.tm_sec == 0) { // (No. E)
			pid_t childId;
			int status;
			
			// Pindahin folder Fylm, Musyik, Pyoto ke zip Lopyu_Stevany.zip
			
			childId = fork();
			
			if (childId == 0) {
				char * argv[] = {
					"zip",
					"-m",
					"Lopyu_Stevany.zip",
					"-r",
					"Fylm",
					"Musyik",
					"Pyoto",
					NULL
				};
				
				execv("/bin/zip", argv);
			} else {
				while ((wait(&status)) > 0);
			}
			
			// Hapus folder FILM, FOTO, dan MUSIK
			
			childId = fork();
			
			if (childId == 0) {
				char * argv[] = {
					"rmdir",
					"FILM",
					"FOTO",
					"MUSIK",
					NULL
				};
				
				execv("/bin/rmdir", argv);
			} else {
				while ((wait(&status)) > 0);
			}
		}

		sleep(1);
	}
}
