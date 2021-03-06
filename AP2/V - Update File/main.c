#include <stdio.h>
#include <string.h>

int main()
{
    // deklarasi konten baris
    struct {
        char prodi[5];
        char nama[20];
        char nilai[10];
    }a,b,c;

    FILE *arsipMatkul;
    FILE *arsipMatkulUpdate;

    arsipMatkul = fopen("ArsipMatKulA.txt", "r");
    arsipMatkulUpdate = fopen("ArsipMatKulAUpdate.txt", "w");

    fscanf(arsipMatkul, "%s %s %s\n", &a.prodi, &a.nama, &a.nilai);

    // flag first line
    int is_first = 1;

    do {
        if(is_first == 1) {
            fscanf(arsipMatkul, "%s %s %s\n", &b.prodi, &b.nama, &b.nilai);
            fscanf(arsipMatkul, "%s %s %s\n", &c.prodi, &c.nama, &c.nilai);
            is_first = 0;
        }
        else {
            // jika menemukan nilai selain 75 diantara 75
            if((strcmp(a.nilai,"75") == 0) && (strcmp(b.nilai,"75") != 0) && (strcmp(c.nilai,"75") == 0)) {
                fprintf(arsipMatkulUpdate, "%s %s %s\n", a.prodi, a.nama, a.nilai);
                strcpy(b.nilai,"-> 80");
            }
            else {
                fprintf(arsipMatkulUpdate, "%s %s %s\n", a.prodi, a.nama, a.nilai);
            }
            // geser baris
            a = b;
            b = c;

            fscanf(arsipMatkul, "%s %s %s\n", &c.prodi, &c.nama, &c.nilai);
        }
    }
    while(!feof(arsipMatkul));
    // menambahkan sisa scan
    fprintf(arsipMatkulUpdate, "%s %s %s\n", a.prodi, a.nama, a.nilai);
    fprintf(arsipMatkulUpdate, "%s %s %s\n", b.prodi, b.nama, b.nilai);

    fclose(arsipMatkul);
    fclose(arsipMatkulUpdate);
}
