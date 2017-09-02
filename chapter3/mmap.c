#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>


/* define RECORD structure */
typedef struct {
    int integer;
    char string[24];
} RECORD;

#define NRECORDS (100)

int main(void)
{
    RECORD record, *mapped;
    int i, f;
    FILE *fp;

    // fulfill the records.dat 
    fp = fopen("records.dat", "w+");
    for (i=0; i<NRECORDS; i++) {
        record.integer = i;
        sprintf(record.string, "RECORD-%d", i);
        fwrite(&record, sizeof(record), 1, fp);
    }
    fclose(fp);
    
    fp = fopen("records.dat","r+");
    fseek(fp,43*sizeof(record),SEEK_SET);
    fread(&record,sizeof(record),1,fp);

    record.integer = 144;
    sprintf(record.string,"RECORD-%d", record.integer);
    fseek(fp,43*sizeof(record),SEEK_SET);
    fwrite(&record,sizeof(record),1,fp);
    fclose(fp);

    /* Now map the records into memory and access the 43rd record in order to change the integer to
     * 243 (and update the record string), again using memory mapping */

    f = open("records.dat", O_RDWR);
    mapped = (RECORD *)mmap(0, NRECORDS*sizeof(record), PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);
    mapped[43].integer = 243;
    sprintf(mapped[43].string, "RECORD-%d", mapped[43].integer);
    printf("%d, %s\n", mapped[43].integer, mapped[43].string);
    sleep(100);
    msync((void *)mapped, NRECORDS*sizeof(record), MS_ASYNC);
    munmap((void *)mapped, NRECORDS*sizeof(record));
    close(f);

    exit(0);
}
