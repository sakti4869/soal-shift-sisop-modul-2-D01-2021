# soal-shift-sisop-modul-2-D01-2021

##  Daftar Isi ##
   - [Anggota Kelompok](https://github.com/sakti4869/soal-shift-sisop-modul-2-D01-2021/blob/main/README.md#anggota-kelompok)
   - [Soal 1](https://github.com/sakti4869/soal-shift-sisop-modul-2-D01-2021/blob/main/README.md#soal-1)
      - [1a]
      - [1b]
      - [1c]
      - [1d]
      - [1e]
      - [1f]
   - [Soal 2](https://github.com/sakti4869/soal-shift-sisop-modul-2-D01-2021/blob/main/README.md#soal-2)
      - [2a]
      - [2b]
      - [2c]
      - [2d]
      - [2e]
   - [Soal 3](https://github.com/sakti4869/soal-shift-sisop-modul-2-D01-2021/blob/main/README.md#soal-3)
      - [3a]
      - [3b]
      - [3c]
      - [3d]
      - [3e]

## Anggota Kelompok ##

Khaela Fortunela 05111940000057

M Haikal Aria Sakti 05111940000088

David Ralphwaldo M 05111940000190

## Soal 1 ##

Pada suatu masa, hiduplah seorang Steven yang hidupnya pas - pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya.

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal - hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing - masing sesuai extensi.

**(a)** Dikarenakan Stevany sangat menyukai huruf **Y**, Steven ingin nama folder-foldernya adalah **Musyik** untuk mp3, **Fylm** untuk mp4, dan **Pyoto** untuk jpg.

![Soal1A](https://i.postimg.cc/mgtcDrhN/a.png)

### Cara Pengerjaan ###

1. Melakukan fork pada parent process.
2. Dalam child process, membuat array argumen - argumen yang digunakan untuk membuat folder yaitu mkdir untuk membuat folder, dan nama - nama foldernya yaitu Fylm, Musyik, Pyoto.
3. Memanggil fungsi execv dengan argumen pertama `"/bin/mkdir"` dan argumen kedua array argumen `argv`.
4. Melakukan wait pada parent process.

### Kendala ###

Tidak ada kendala.

**(b)** Untuk musik Steven **mendownloadnya** dari link di bawah, film dari link di bawah lagi, dan foto dari link di bawah juga :).

![Soal1Ba](https://i.postimg.cc/kgz2tdbr/b-1.png)
![Soal1Bb](https://i.postimg.cc/7Lzf3Q35/b-2.png)
![Soal1Bc](https://i.postimg.cc/gJPrNqsN/b-3.png)

### Cara Pengerjaan ###

1. Untuk setiap file yang ingin didownload, pertama kami melakukan forking pada parent process.
2. Pada process child, membuat variabel `char * link` yang berisikan link dari masing - masing file yang ingin didownload.
3. Membuat array argumen `char * argv[]` yang berisikan argumen - argumen yang berisikan argumen - argumen untuk mendownload file.
4. Memanggil fungsi execv dengan argumen pertama `"/bin/wget"` dan argumen kedua array `argv`.
5. Melakukan wait pada parent process.

### Kendala ###

Awalnya kami menggunakan `wget --no-check-certificate *linkDownload* -O *namaFile.extensi*` tetapi tidak bekerja dan file tidak dapat didownload. Tetapi ditambahkan opsi `-q` dan diubah menjadi `wget --no-check-certificate *linkDownload* -O *namaFile.extensi* -q` dan file - filenya pun dapat didownload.

**(c)** Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu **meng-extract-nya** setelah didownload serta

![Soal1Ca](https://i.postimg.cc/vBLTjgSM/c-1.png)
![Soal1Cb](https://i.postimg.cc/gjgJc9WT/c-2.png)
![Soal1Cc](https://i.postimg.cc/4yfyTfrc/c-3.png)

### Cara Pengerjaan ###

1. Setelah masing - masing file selesai didownload, lakukan fork pada parent process.
2. Pada child process, membuat array `char * argv[]` yang berisikan argumen untuk mengextract file zipnya yaitu `unzip` dan `namaFile.extensi`. 
3. Memanggil fungsi execv dengan argumen pertama `"/bin/unzip"` dan argumen kedua array `argv`.
4. Melakukan wait pada parent process.

### Kendala ###

Tidak ada kendala.

**(d)** **memindahkannnya** ke dalam folder yang telah dibuat (hanya file yang dimasukkan).

![Soal1Da](https://i.postimg.cc/KvYjqY7S/d-1.png)
![Soal1Db](https://i.postimg.cc/ryjzN4rN/d-2.png)
![Soal1Dc](https://i.postimg.cc/qvhRrZZ1/d-3.png)

### Cara Pengerjaan ###

1. Membuat variabel `dir` bertipe `DIR *` yang nanti digunakan untuk membaca direktori.
2. Membuat variabel `dirFile` bertipe `struct dirent` yang nanti digunakan untuk membaca file - file dalam direktori.
3. Untuk setiap folder yang ingin dipindahkan isinya, pertama melakukan `chdir` ke dalam folder tersebut.
4. Kemudian memanggil `dir = openDir(".");` untuk membaca isi dari folder tersebut.
5. `while ((dirFile = readdir(dir)) != NULL)` digunakan untuk membaca semua file yang ada dalam folder tersebut dan disimpan dalam variabel `dirFile`.
6. Untuk setiap file, melakukan fork pada parent process.
7. Pada child process, membuat array argumen `char * argv[]` yang berisi perintah `"mv"`, `dirFile->d_name` yang berisikan nama file yang ingin dipindahkan, serta `path ke folder barunya`.
8. Memanggil fungsi execv dengan argumen pertama `"/bin/mv"` untuk memindahkan file, dan argumen kedua array argumen `argv`.
9. Melakukan wait pada parent process.
10. Ulangi no. 6 - 9 sampai semua file telah dipindahkan ke folder barunya.
11. Menutup foler yang tadi dibuka dengan menggunakan perintah `closedir(dir);`.
12. Keluar dari folder tersebut dengan menggunakan perintah `chdir("../");`

### Kendala ###

Awalnya kami mencoba menggunakan perintah `mv FOTO/* Pyoto/` tetapi tidak bisa. Ternyata ketika memanggil fungsi execv argumen - argumen tersebut diubah menjadi `'mv' 'FOTO/*' 'Pyoto/'` sehingga dianggap ingin memindahkan file bernama `*` yang ada pada folder FOTO. Sehingga kami ubah menjadi kode yang diatas dengan menggunakan `opendir` dan `readdir` untuk membaca semua filenya.

**(e)** Untuk memudahkan Steven, ia ingin semua hal di atas berjalan **otomatis** 6 jam sebelum waktu ulang tahun Stevany.

![Soal1E](https://i.postimg.cc/ncwz6tTs/e.png)

### Cara Pengerjaan ###

1. Sebelum masuk ke dalam loop daemon, pertama kami memanggil fungsi `time(NULL)` yang hasilnya disimpan ke dalam variabel `t` yang bertipe `time_t`.
2. Membuat variabel `tm` dengan tipe `struct tm` yang nantinya digunakan untuk menyimpan informasi waktu seperti hari, bulan, jam, dan sebagainya.
3. Di dalam loop, kami memanggil fungsi `time(NULL)` dan menyimpan hasilnya ke dalam variabel `t` secara terus menerus untuk mendapatkan waktu sekarang.
4. Isi dari variabel `t` diubah menjadi format hari, bulan, jam, dan sebagainya dengan memanggil fungsi `*localtime(&t)` dan menyimpan hasilnya ke dalam variabel `tm`.
5. Variabel dapat digunakan isinya yaitu `tm_mon` (bulan), `tm_mday` (hari pada bulan tersebut), `tm_hour` (jam), `tm_min` (menit), dan `tm_sec` untuk melakukan pengecekan waktu.
6. Isi dari blok kode `if` - nya adalah kode untuk no. A, B, C, dan D.

### Kendala ###

Tidak ada kendala.

**(f)** Setelah itu pada **waktu** ulang tahunnya Stevany, semua folder akan di zip dengan nama **Lopyu_Stevany.zip** dan semua folder akan di delete (sehingga hanya menyisakan .zip).

![Soal1F](https://i.postimg.cc/XYRvYcR4/f.png)

### Cara Pengerjaan ###

1. Pertama melakukan pengecekan waktu dengan mengecek isi dari variabel `tm` yang berisikan informasi seperti hari, bulan, jam, dan sebagainya.
2. Jika kondisinya benar, eksekusi isi dari blok kode `if`.
3. Pertama membuat variabel `childId` dengan tipe `pid_t` untuk menyimpan ID dari child process yang akan dibuat.
4. Membuat variabel `status` yang digunakan untuk melakukan `wait` pada parent process.
5. Melakukan fork pada parent process untuk meng-zip folder Fylm, Musyik, dan Pyoto.
6. Dalam child process, membuat array argumen `char * argv[]` yang berisikan `"zip"` untuk meng-zip folder, `"-m"` yang berarti setelah folder dimasukkan ke dalam zip folder aslinya akan dihapus, `"Lopyu_Stevany.zip"` yaitu nama dari file zip yang akan dibuat, `"-r"` yang berarti rekursif untuk memindahkan folder beserta dengan isinya ke dalam zip, `"Fylm", "Musyik", "Pyoto"` yaitu nama - nama dari folder yang ingin dipindahkan, serta NULL.
7. Memanggil fungsi execv dengan argumen pertama `"/bin/zip"` untuk meng-zip folder - folder tersebut, dan argumen kedua array argumen `argv`.
8. Melakukan wait pada parent process.
9. Melakukan fork pada parent process untuk menghapus folder - folder FILM, FOTO, dan MUSIK.
10. Pada child process, membuat array argumen `char * argv[]` yang berisikan `"rmdir"` yaitu perintah untuk menghapus folder, `"FILM", "FOTO", "MUSIK"` yaitu nama - nama folder yang ingin dihapus, dan NULL.
11. Memanggil fungsi execv dengan argumen pertama `"/bin/rmdir"` untuk menghapus folder, dan argumen kedua yaitu array argumen `argv`.
12. Melakukan wait pada parent process.

### Kendala ###

Tidak ada kendala.

Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

## Soal 2 ##

Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

**(a)** Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

Jadi di soal ini kita diminta untuk mengekstrak zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop” dengan menggunakan fork dan execv.
```
pid_t nid;
    nid = fork();
    if(nid < 0) exit(0);
    if(nid == 0) {
        char *argu[] = {"unzip", "-o", "-q", "/home/sakti4869/modul2/pets.zip", "-d", "/home/sakti4869/modul2/petshop", NULL};
        execv("/usr/bin/unzip", argu);
    }
```
  
 Selanjutnya memakai program berikut ini, kita akan dapat membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan sesuai soal. Juga digunakan fungsi `wait()` untuk menunggu proses unzip hingga selesai terlebih dahulu.
 
 ``` while(wait(&stat) > 0);
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
```
**(b)** Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip. Contoh: Jenis peliharaan kucing akan disimpan dalam “`/petshop/cat`”, jenis peliharaan kura-kura akan disimpan dalam “`/petshop/turtle`”.

Sebelum membuat folder yang mengkategorikan hewan peliharaan, maka perlu diketahui jenis-jenis peliharaan yang nantinya  dijadikan nama folder yang akan dibuat. Jenis-jenis peliharaan disimpan dalam array of char 2 dimensi (seperti array of string pada C++) dengan nama variable `fldrnme[][]` dan integer zid sebagai bantuan indexing pada fldrnme.

```
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
```
Membuat folder sesuai dengan jenis hewan peliharaan.
```
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
```
**(c)** Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan. Contoh: “`/petshop/cat/joni.jpg`”.

Melihat setiap file dalam folder dan inisialisasi variabel yang akan digunakan nanti. `temp2` untuk hewan pertama dan `temp3` untuk hewan kedua.
```
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
```
Menyimpan jenis, nama, dan umur hewan peliharaan pertama dalam variabel temp2.

```
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
```
Menyalin foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.

```
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
```
**(d)** Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “`dog;baro;1_cat;joni;2.jpg`” dipindah ke folder “`/petshop/cat/joni.jpg`” dan “`/petshop/dog/baro.jpg`”.

Mengecek apakah dalam satu foto terdapat 2 jenis hewan peliharaan, jika ada maka akan disimpan jenis, nama, dan umur hewan yang kedua pada temp3.

```
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
```
Memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
```
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
```
**(e)** Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. Format harus sesuai contoh.

```
nama : joni
umur  : 3 tahun

nama : miko
umur  : 2 tahun
```
Menambahkan keterangan berupa nama dan umur hewan peliharaan sesuai didalam file "keterangan.txt" yang terdapat dalam setiap folder kategorinya.

```
 while(wait(&stat) > 0);
            char keter[300];
            sprintf(keter, "/home/sakti4869/modul2/petshop/%s/keterangan.txt", temp2_jenis);
            FILE *filez;
            filez = fopen(keter, "a+");
            fprintf(filez, "nama : %s\n", temp2_nama);
            fprintf(filez, "umur : %s tahun\n\n", temp2_umur);
            fclose(filez);
```
Hal yang sama juga dilakukan ketika ada dua jenis hewan peliharaan dalam satu foto.

```
    while(wait(&stat2) > 0);
                char keter[300];
                sprintf(keter, "/home/sakti4869/modul2/petshop/%s/keterangan.txt", temp3_jenis);
                FILE *filez;
                filez = fopen(keter, "a+");
                fprintf(filez, "nama : %s\n", temp3_nama);
                fprintf(filez, "umur : %s tahun\n\n", temp3_umur);
                fclose(filez);
```

### Kendala ###
saya merasa agak kesulitan dalam menentukan argumen apa saja yang ada dalam argu pada execv namun saya daat mengatasinya dengan search dan bekerja dengan kelompok saya. Saya juag mendapat pada saat membuat dan menambah data dalam suatu file sempat berjalan tidak sesuai keinginan karena adanya kesalahan penulisan sintaks. Sedikit ada kendala saat ingin mengerjakan soal e dan akhirnya teratasi dengan mengerjakannya bersamaan dengan soal c dan d. Sehingga saat iterasi menyalin gambar, sekaligus mengisi keterangan.txt.

## Soal 3 ##

Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

**(a)** Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].

Pertama, kita perlu import dulu library ```time.h``` untuk keperluan penggunaan timestamp.
```
#include <time.h>
```
Selanjutnya kita inisialisasi sebuah variabel ```time_t```. Deklarasi ```time(NULL)``` digunakan agar variabel menyimpan detik yang terhitung dalam Unix dari 1 Januari 1970.
```
time_t current;
current = time(NULL);
```
Kemudian, kita deklarasikan sebuah struct ```tm```. Fungsi ```localtime``` akan mengisi struct ```tm``` dengan nilai yang merepresentasikan waktu lokal dari Unix tersebut. 
```
struct tm * tLocal = localtime(&current);
```
Untuk membuat timestamp, kita bisa menggunakan fungsi ```strftime``` seperti berikut.
```
char buffer[20];
strftime(buffer, sizeof(buffer), "%Y-%m-%d_%T", tLocal);
```
```%Y-%m-%d``` menghasilkan 2021-04-25. Sedangkan ```%T``` menghasilkan format waktu standar 10:51:05. 

Selanjutnya, string timestamp digabung dengan string parent directory agar menjadi directory address yang akan dibuat folder.
```
char *tDate, *fAddress;
strcpy(tDate, buffer);
char *rDir = "/home/fortunela/seslab_sisop/asistensi2/";
strcpy(fAddress, rDir);
strcat(fAddress, tDate);
```
Kemudian, kita bisa panggil fungsi ```exec``` untuk menjalankan perintah pembuatan direktori.
```
char *argv[] = {"mkdir", "-p", fAddress, NULL};
execv("/bin/mkdir", argv);
```
```mkdir``` adalah perintah untuk membuat direktori. Dan ```-p``` adalah opsi yang digunakan agr jika parent directory pada ```fAddress``` belum ada, maka akan dibuatkan.

Karena pointer to char ```tDate``` dan ```fAddress``` nantinya digunakan oleh proses lain, perlu dilakukan attach memory agar kedua pointer tersebut dapat di share. Sebelum itu juga perlu ditambahkan library yang berisi fungsi-fungsi untuk implementasi shared memory.
```
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/stat.h>
```
```
if ((tDate = (char *) shmat(dfolderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
```
Ditambahkan juga pada main fungsi ```shmget``` untuk mengalokasikan segemen memori yang bisa dishare.
```
if ((folderId = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0666)) < 0) printf("smget returned -1\n");
if ((dfolderId = shmget(IPC_PRIVATE, 20, IPC_CREAT | 0666)) < 0) printf("smget returned -1\n");
```
Kemudian karena proses pembutan folder diharapkan berjalan setiap 40 detik, maka kita tambahkan fungsi ```sleep```. Selain itu kita tambahkan implementasi daemon agar program berjalan di background. 
```
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
	
	if ((tDate = (char *) shmat(dfolderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
   
	strcpy(tDate, buffer);
	char *rDir = "/home/fortunela/seslab_sisop/asistensi2/";
	strcpy(fAddress, rDir);
   strcat(fAddress, tDate);
	
	char *argv[] = {"mkdir", "-p", fAddress, NULL};
	execv("/bin/mkdir", argv);
}

int main(int argc, char* argv[]) {
   /*Awal dari implementasi daemon.*/
	pid_t sid, pid0 = fork();
	if(pid0 < 0) exit(EXIT_FAILURE);
	else if(pid0 > 0) exit(EXIT_SUCCESS);

	umask(0);
	if((sid = setsid()) < 0) exit(EXIT_FAILURE);
	
	if((chdir("/home/fortunela/seslab_sisop/asistensi2")) < 0) exit(EXIT_FAILURE);
	close(STDIN_FILENO);	
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	/*Akhir dari implementasi daemon.*/
	
	while(1) {
   /*shmget untuk memori fAddress dan tDate*/
	if ((folderId = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0666)) < 0) printf("smget returned -1\n");
	if ((dfolderId = shmget(IPC_PRIVATE, 20, IPC_CREAT | 0666)) < 0) printf("smget returned -1\n");
	
	pid_t pidn, pid1;
	pidn = fork();
	
	if(pidn == 0) {	
		pid1 = fork();
		if(pid1 == 0) makedir();
		else if(pidn == -1) exit(0);
	}
	else if(pidn == -1) exit(0);

	sleep(40);
	}
}
```

**(b)** Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.

Pertama, kita dapatkan dulu detik epoch unix lalu kita hitung dengan rumus (n%1000) + 50 dan gabungkan menjadi URL untuk pengunduhan file.
```
time_t current;
current = time(NULL);
char buffer2[30];
snprintf(buffer2, 30, "https://picsum.photos/%ld", (current % 1000) + 50);
```
Kemudian, kita download foto dari URL tersebut ke folder yang alamatnya ditunjuk ```fAddress```. Sebelumnya juga harus dilakukan attach memori ```fAddress```. Selanjutnya dipanggil fungsi exec untuk melakukan pengunduhan.
```
if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");

char *argv[] = {"/usr/bin/wget", "-q", buffer2, "-P", fAddress, NULL};
execvp("/usr/bin/wget", argv);	
```
```wget``` adalah perintah untuk melakukan pengunduhan.

```-P``` adalah opsi yang ditambahkan agar file tersimpan di direktori yang ditentukan ```fAddress```.

Karena nama file sekarang (hasil perhitungan untuk URL) dan nama file baru (timestamp saat mulai pengunduhan) dibutuhkan untuk penamaan file pada proses lain maka kita lakukan attach memory disini, dan juga kita lakukan set memory di main.
```
void download () {
	time_t current;
	current = time(NULL);
   
   /*attach shared memory*/
	if ((oldName = (char *) shmat(oldId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
	if ((newName = (char *) shmat(newId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
   
   /*modifikasi value pada memori oldName*/
   char buffer2[30];
	snprintf(buffer2, 10, "/%ld", (current % 1000) + 50);
	strcpy(oldName, buffer2);
   
   snprintf(buffer2, 30, "https://picsum.photos/%ld", (current % 1000) + 50);

   /*modifikasi value pada memori newName*/
	struct tm * tLocal = localtime(&current);
	char buffer4[30];
	strftime(buffer4, sizeof(buffer4), "/%Y-%m-%d_%H:%M:%S", tLocal);
	strcpy(newName, buffer4);

	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");

	char *argv[] = {"/usr/bin/wget", "-q", buffer2, "-P", fAddress, NULL};
	execvp("/usr/bin/wget", argv);	
}

int main(int argc, char* argv[]) {
   /*Awal dari implementasi daemon.*/
	
	/*Akhir dari implementasi daemon.*/
	
	while(1) {
   /*shmget untuk alokasi memori fAddress dan tDate*/
   
   /*shmget untuk alokasi memori oldName dan newName*/
   if ((oldId = shmget(IPC_PRIVATE, 10, IPC_CREAT | 0666)) < 0) printf("smget returned -1\n");
	if ((newId = shmget(IPC_PRIVATE, 20, IPC_CREAT | 0666)) < 0) printf("smget returned -1\n");
   
	pid_t pidn, pid1, pid2;
	pidn = fork();
	
	if(pidn == 0) {	
		/*fork makedir()*/
      
      while ((wait(&status)) >0); //menunggu proses pembuatan folder selesai
		for(int i=10; i>0; --i){
			pid2 = fork();
			if(pid2 == 0) {
				sleep(5);
				download();
			}
			else if(pidn == -1) exit(0);
	   }
	else if(pidn == -1) exit(0);

	sleep(40);
	}
}
```
Kemudian karena kita perlu melakukan proses penggantian nama file kita tambahkan fungsi ```renameFile()```` yang isinya sebagai berikut.
```
void renameFile () {
	if ((fAddress = (char *) shmat(folderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
	if ((oldName = (char *) shmat(oldId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
	if ((newName = (char *) shmat(newId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
   
	char *initName = (char*) malloc(100);	
	strcpy(initName, fAddress);
   strcat(initName, oldName);

	char *finalName = (char*) malloc(100);
	strcpy(finalName, fAddress);
   strcat(finalName, newName);

	char *argv[] = {"mv", initName, finalName, NULL};
	execvp("/bin/mv", argv);
}
```
```mv``` adalah perintah untuk penggantian nama dan pemindahan file atau folder.

Selanjutnya pada main kita tambahkan struktur fork seperti berikut.
```
pid_t pidn, pid1, pid2, pid3;
pidn = fork();

if(pidn == 0) {	
		/*fork makedir()*/

		while ((wait(&status)) >0);
		for(int i=10; i>0; --i){
			/*fork download()*/
         
			while ((wait(&status)) > 0); //menunggu pengunduhan oleh proses download() selesai
			
			pid3 = fork();
			if(pid3 == 0) {
				renameFile();
			}
			else if(pidn == -1) exit(0);
		}
}
else if(pidn == -1) exit(0);
```

**(c)** Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

Pertama, kita tuliskan algoritma untuk mengenkripsi dengan Caesar Cipher.
```
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
```
Selanjutnya, kita append teks yang terenkripsi ke ```status.txt```.
```
FILE *fStatus = fopen("status.txt", "a");
fprintf(fStatus, "%s\n", text);
fclose(fStatus);
```
Opsi ```"a"``` diatas menandakan append file, sehingga line baru ditambahkan di line baru dan tidak overwrite konten sebelumnya dari ```status.txt```.

Kita harus meng-zip folder yang dibuat kemudian folder tersebut dihapus. Dilakukan attach memory ```tDate``` karena dibutuhkan dalam spesifikasi folder yang akan dizip dan juga penamaan hasil zip.
```
if ((tDate = (char *) shmat(dfolderId, NULL, 0)) == (char *) -1) printf("Process shmat returned NULL\n");
	
char zipName[30];
sprintf(zipName, "%s.zip", tDate);
char *argv[] = {"zip", "-rm", zipName, tDate, NULL};
execvp("/usr/bin/zip", argv);
```
Opsi ```-rm``` meng-otomatiskan bahwa folder dihapus setelah di zip.

Sehingga terbentuklah fungsi ```appendStat()``` seperti berikut.
```
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
```
Kemudian fungsi ```appendStat()``` ditambahkan pada main sperti berikut ini.
```
pid_t pidn, pid1, pid2, pid3;
pidn = fork();

if(pidn == 0) {	
		/*fork makedir()*/

		while ((wait(&status)) >0);
		for(int i=10; i>0; --i){
			/*fork download()*/
         
			while ((wait(&status)) > 0); //menunggu pengunduhan oleh proses download() selesai
			
         /*fork renameFile()*/
		}
      while ((wait(&status2)) >0); //menunggu pengunduhan dan penamaan file selesai semua
		appendStat();
}
else if(pidn == -1) exit(0);
```

**(d)** Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.

Kita bisa membuat sebuah file bash menggunakan fungsi ```fopen()``` , ```fprintf()```, dan ```fclose()```.
```
void bashKiller() {

	FILE *fKiller = fopen("killer.sh", "w");
	fprintf(fKiller, "#!/bin/bash \n\n
                     killall -9 3a.o \n
                     echo \'Program is forcefully killed.\' \n
                     rm \"$0\" \n");
	fclose(fKiller);

	pid_t pid = fork();
    	if(pid == 0){
        	char *argv[] = {"chmod", "+x", "killer.sh", NULL};
        	execv("/bin/chmod", argv);
   }
}
```
```chmod``` adalah perintah untuk mengubah file permission. Digabung dengan opsi ```+x```, agar semua user bisa menjalankan program bash tersebut.

Dan fungsi diatas bisa dipanggil setelah dilakukannya implementasi daemon seperti berikut.
```
int main(int argc, char* argv[]) {

	/*implementasi daemon*/
	
	bashKiller();
	
	/*solusi soal a, b, c*/
}
```

**(e)** Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dsdengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

Untuk mendapatkan argumen (-z atau -x) pada saat program dijalankan, kita menggunakan parameter pointer to array of char ```argv``` yang berada di main.
```
int main(int argc, char* argv[]) {
   if(argc < 2) {                               //jika mode tidak dispesifikasi pada awal pemanggilan program, maka fungsi ```bashKiller()``` memiliki mode default -z
        	printf("Default option is -z.\n");
		   argv[1] = "-z";
   }
	else if(argv[1][1] != 'z' && argv[1][1] != 'x'){ // hanya ada mode -z atau -x
		   printf("Only option -z or -x is permitted.\n");
        	exit(0);
	}
   
	/*implementasi daemon*/
   
	bashKiller(argv[1]);
   
	/*solusi soal a, b, c*/
}
```
Kemudian fungsi ```bashKiller()``` kita modifikasi untuk memiliki parameter, dan kita tambahkan implementasi untuk mode -x dan -z.
```
void bashKiller(char option[]) {
	
	FILE *fKiller = fopen("killer.sh", "w");

	if(!(strcmp(option, "-x"))) 
		fprintf(fKiller, "#!/bin/bash \n\nkill %d \necho \'Program is successfully terminated.\' \nrm \"$0\" \n", getpid());
      
	if(!(strcmp(option, "-z"))) 
		fprintf(fKiller, "#!/bin/bash \n\nkillall -9 3a.o \necho \'Program is forcefully killed.\' \nrm \"$0\" \n");
	
	fclose(fKiller);

	pid_t pid = fork();
   if(pid == 0){
        char *argv[] = {"chmod", "+x", "killer.sh", NULL};
        execv("/bin/chmod", argv);
   }
}
```
# Kendala #
Pada saat implementasi mode -x, proses tidak bisa berhenti melakukan spawn meskipun parentnya telah di kill. Solusinya dengan menghapus fork saat appendStat(), sehingga exec pada appenStat() melakukan process switch, sehingga spawning berhenti. 


