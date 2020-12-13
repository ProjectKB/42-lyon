#include "ft_ssl.h"

static void	write_output_b64(t_hash *h)
{
	int fd;
	int len;

	if (test_bit(&h->flag, FLAG_D))
		len = h->base64.rest_len ? (h->base64.turn - 1) * 3 + h->base64.rest_len : h->base64.turn * 3; 
	else
		len = h->base64.turn * 4;
	if ((fd = open((const char *)h->base64.output_file_name, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		freexit(h, "Congrats, you broke malloc.\n", 2);
    write(fd, h->base64.output, len);
	if (!test_bit(&h->flag, FLAG_D))
    	write(fd, "\n", 1);
	close(fd);
}

void print_base64(t_hash *h, int mod)
{
	if (test_bit2(&h->action, PRINT))
	{
		if (test_bit(&h->flag, FLAG_O))
			write_output_b64(h);
		else if (test_bit(&h->flag, FLAG_D))
			ft_printf ("%s", h->base64.output);
		else
			ft_printf ("%s\n", h->base64.output);
	}
}
