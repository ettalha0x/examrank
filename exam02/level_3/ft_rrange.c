#include<unistd.h>
#include<stdlib.h>


int	*ft_rrange(int start, int end)
{
	int i = 0;
	int n = start;
	while(n <= end)
	{
		i++;
		n++;
	}
	int *arr = malloc(sizeof(int) * i + 1);
	if (!arr)
		return 0;
	i = 0;
	while (end >= start)
	{
		arr[i++] = end;
		end--;
	}
	arr[i] = '\0';
	return arr;
}
