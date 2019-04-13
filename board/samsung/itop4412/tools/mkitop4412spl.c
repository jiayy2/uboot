#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BL2_SZ 14332
#define BAC_SZ 16384

static int checksum(char* fn_src,char* fn_dst)
{
    FILE *fp_src = NULL;
    FILE *fp_dst = NULL;

    unsigned char *bytes = NULL;
    int size = 0;
    int i = 0;

    fp_src = fopen(fn_src, "rb");
    if (NULL == fp_src)
    {
        printf("can't open file for read(%s)\n", fn_src);
        return -1;
    }

    fp_dst = fopen(fn_dst, "wb");
    if (NULL == fp_dst)
    {
        printf("can't open file for read(%s)\n", fn_dst);
        return -1;
    }

    fseek(fp_src, 0L, SEEK_END);
    size = ftell(fp_src);
    size = (size > BL2_SZ) ? BL2_SZ : size;

    bytes = (unsigned char *)calloc(BAC_SZ, 1);
    rewind(fp_src);
    fread(bytes, 1, size, fp_src);

    unsigned int sum = 0;
    for(i = 0;i < size;i++)
    {
        sum += bytes[i];
    }

    *(unsigned int*)(bytes+BL2_SZ) = sum;

    fwrite(bytes, 1, BAC_SZ, fp_dst);

    free(bytes);
    fclose(fp_src);
    fclose(fp_dst);

    return 0;
}


int main(int argc, char *argv[])
{
    if(argc == 3){
        return checksum(argv[1],argv[2]);
    }else{
        printf("Format: Program_Name Source_File Target_File\n");
    }
    return -1;
}
