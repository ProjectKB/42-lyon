void o(void)
{
    system("/bin/sh");
    exit(1);
}

void n(void)
{
    char *format;

    fgets(format, 512, stdin);
    printf(format);
    exit(1);
}

int main(void)
{
    n();
    return 0;
}
