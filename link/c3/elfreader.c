#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/elf.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("/home/break/Projects/link/c3/SimpleSection.o", "r");
    if (NULL == fp)
    {
        printf("open file error\n");
        exit(0);
    }

    // check file size
    // fseek(fp, 0L, SEEK_END);
    // long size = ftell(fp);
    // printf("file size: %ld\n", size);

    // read ELF Header
    Elf64_Ehdr elf_header;
    fread(&elf_header, sizeof(Elf64_Ehdr), 1, fp);

    int shnum = elf_header.e_shnum;
    long shoff = elf_header.e_shoff;
    printf("section header number: %d, offset: 0x%lx\n", shnum, shoff);

    Elf64_Phdr elf_phdr;

    fclose(fp);
    return 0;
}