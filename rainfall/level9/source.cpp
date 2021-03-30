
class N
{
public:
    int value;
    char *annotation;

    N(int value) : value(value)
    {}

    int operator+(N &rhs)
    {
        return value + rhs.value;
    }

    void setAnnotation(char *str)
    {
        memcpy(annotation, str, strlen(str));
    }
};

int main(int ac, char **av)
{
    if (ac < 2)
        exit(1);
    N *a = new N(5);
    N *b = new N(6);
    a->setAnnotation(av[1]);
    b->operator+(a);
    return 0;
}