void p(void)
{
    void *eip;
    char buf[76];
    int32_t var_ch;

    fflush(stdout);
    gets(buf);

    if (((size_t)eip & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", eip);
        _exit(1);
    }
    puts(buf);
    strdup(buf);
}

int main(void)
{
    p();
    return 0;
}