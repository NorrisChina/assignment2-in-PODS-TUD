#include <stdio.h>
#include <inttypes.h>
#include <string.h>

uint32_t adler32(unsigned char *data, size_t len) 
{
    uint32_t a = 1;
    uint32_t b = 0;
    size_t i;
    
    for (i = 0; i < len; i++)
    {
        a = (a + data[i]) % 65521;
        b = (b + a) % 65521;
    }
    
    return (b << 16) | a;
}


int main(int argc, char **argv) {
    char *str= "Hello World";
    if (argc > 1)
        str = argv[1];
    unsigned int h = adler32((unsigned char *)str, strlen(str));
    printf("Adler32 of `%s` is %u\n", str, h);
    return 0;
}
