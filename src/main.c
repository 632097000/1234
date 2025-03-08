#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "用法：%s <进程ID> <十六进制地址> <长度> <权限>\n", argv[0]);
        return 1;
    }
    
    pid_t pid = atoi(argv[1]);
    unsigned long addr = strtoul(argv[2], NULL, 16);
    size_t length = strtoul(argv[3], NULL, 10);
    int prot = atoi(argv[4]);
    
    if (mprotect((void*)addr, length, prot) == -1) {
        perror("[-] 内存保护修改失败");
        return 2;
    }
    return 0;
}
