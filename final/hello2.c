extern int printf(char *fmt, int num);

int print(char *fmt, int num)
{
	int k1 = printf(fmt, num);
	char *fmt2 ;
	fmt2 = "k is %d\n";
	int k = 4;
	if((k > 1))
	{
		int k = 5;
		if(((k + 5) == 10))
		{
			int k = 10;
			k = ((k * k) + (k <= 12));
			printf(fmt2, k);
			return (k + 1);
		}
		else
		{
			
			int k = 20;
			k = printf(fmt2, k);
			return k;
		}
	}
	else
	{
		int k = 30;
		k = printf(fmt2, k);
		return k;
	}
	
}

int add(int l, int r)
{
	int k = l;
	k = (k + r);
	if((k < 10))
	{
		int m = add(r, k);
		return m;
	}
	return k;
}

int sum(int max, int min)
{
	int sum = 0;
	while((max >= min))
	{
		sum = (sum + max);
		max = (max - 1);
	}
	return sum;
}

int for_test(int max)
{
	int sum = 0;
	for(int i = 0; (i < max); i = (i + 2);)
	{
		sum = (sum + i);
	}
	return sum;
}

int main()
{
	char *fmt;
	char *ret;
	char *s;
	char *sqrt;
	char *fc;
	char *ftc;

	int num = 10;
	float p = 10.23;

	ret = "The peibolaqi is %d\n";
	fmt = "hello %d\n";
	s = "sum is %d\n";
	sqrt = "The sqrt is %d\n";
	fc = "float p is %f\n";
	ftc = "for test result is %d\n";


	num = (2 <= 3);
	num = print(fmt, num);
	num = print(fmt, num);

	num = add(1, 1);
	printf(ret, num);

	num = sum(10, 5);
	printf(s, num);

	num = 0;
	while((num < 10))
	{
		int k = 0;
		k = (num * num);
		printf(sqrt, k);
		num = (num + 1);
	}

	num = for_test(10);
	printf(ftc, num);

	return 0;
}
