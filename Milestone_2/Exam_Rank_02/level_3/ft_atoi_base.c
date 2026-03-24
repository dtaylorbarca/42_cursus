/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/


int	base_index(char c, int str_base)
{
	char	*base= "0123456789abcdef";
	int		i = 0;

	if ('A' <= c && c <= 'Z')
		c += 32;
	while (base[i])
	{
		if (c == base[i] && i < str_base)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		sign = 1;
	unsigned int		result = 0;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while(*str)
	{
		if (base_index(*str, str_base) == -1)
			break;
		result = result * str_base + base_index(*str, str_base);
		str ++;
	}
	return (result * sign);
}
