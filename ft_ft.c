#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

double	ft_atof(const char *str)
{
	double	result;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	result = ft_atoi(str);
	if (*str == '-')
	{
		result = -result;
		sign = -1;
	}
	while (*str != '.' && *str != ',')
		str++;
	str++;
	while ((*str >= '0' && *str <= '9'))
	{
		result = result * 10 + *str - '0';
		str++;
		i++;
	}
	result = (result) / powerof(i + 1) * sign;
	return (result);
}
