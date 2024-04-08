#include <stdio.h>
#include <stdlib.h>

long long int _atoi(char *s)
{
	int i, d, len, f, digit;
	long long int n;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}


int main(int argc, char **argv) 
{
	int flag;
	long long int n, div, rem, rest;
	size_t len = 0;
	ssize_t line_read = 0;
	char *buffer = NULL;
	FILE *file;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((line_read = getline(&buffer, &len, file)) != -1) 
    {
	    flag = 1, div = 2;
	    n = _atoi(buffer);
	    while (flag)
	    {
		    rest = n % div;
		    if (!rest)
		    {
			    rem = n / div;
			    printf("%lld=%lld*%lld\n", n, rem, div);
			    flag = 0;
		    }
		    div++;
	    }
    }
    free(buffer);
    fclose(file);
    exit(EXIT_SUCCESS);
}
