static size_t	intlen(long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*putitoa(size_t neg, size_t len, char *str, long long nb)
{
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	while (len > neg)
	{
		str[len - 1] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long long	nb;
	size_t		len;
	size_t		neg;
	char		*str;

	neg = 0;
	nb = n;
	len = intlen(nb);
	if (nb < 0)
		len += 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	putitoa(neg, len, str, nb);
	return (str);
}

bool isPalindrome(int x) {
    char *res = ft_itoa(x);
    int i = 0;
    int j = strlen(res) - 1;
    while(res[i] == res[j] && j > 0 && i < strlen(res))
    {
        i++;
        j--;
    }
    if(j == 0)
        return true;
    else 
        return false;
}