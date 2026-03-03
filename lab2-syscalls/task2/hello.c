int my_write(int fd, const void* buf, int count) {
    int result;
    asm (
        "\tmovq $1, %%rax\n"		/* 1 (write) -> rax.  */
        "\tmovq %%rsi, %%rdi\n"		/* shift arg1 - arg3.  */
        "\tmovq %%rdx, %%rsi\n"
        "\tmovq %%rcx, %%rdx\n"
        "\tsyscall\n"			/* Do the system call.  */
    : "=a"(result)
    );

    if (-4095 <= result && result <= -1) {
        return -1;
    }
    return 0;
}
