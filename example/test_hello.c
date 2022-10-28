#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <assert.h>

int main()
{
    // int fd = open("./test_hello_mount/test", O_RDONLY, 00777);
    // char * p_file = (char*)mmap(NULL, 1024, PROT_READ, MAP_SHARED, fd, 0);

    int fd = open("./test_hello_mount/home/lx/libfuse_learning/example/test", O_RDWR, 00777);
    if (fd < 0) {
        fprintf(stderr, "fail to open file: %s\n", strerror(errno));
        return 0;
    }
    // char buf[] = "test mmap.";

    // write(fd, buf, strlen(buf));
    
    char * p_file = (char*)mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (p_file == (void *)-1) {
        fprintf(stderr, "mmap: %s\n", strerror(errno));
        return 0;
    }
    printf("file: %s\n", p_file);

    sprintf(p_file, "modified the files.");
    printf("file: %s\n", p_file);


    char input[10];
    scanf("input:%s", input);

    munmap(p_file, 1024);

    close(fd);
    return 0;
}