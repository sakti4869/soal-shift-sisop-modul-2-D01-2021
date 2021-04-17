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



