#include "TEST.h"
#include "bsd_string.h"

t_capture	*capture_state(void)
{
	static t_capture	cap;

	return (&cap);
}

ssize_t	__wrap_write(int fd, const void *buf, size_t count)
{
	t_capture	*cap;
	void		*tmp;

	if (fd != 1)
		return (__real_write(fd, buf, count));
	cap = capture_state();
	if (!cap->buff)
		cap->size = 0;
	tmp = realloc(cap->buff, cap->size + count + 1);
	if (!tmp)
		// return (__real_write(fd, buf, count));
		return (count);
	cap->buff = tmp;
	memcpy(cap->buff + cap->size, buf, count);
	cap->size += count;
	return (count);
	// return (__real_write(fd, buf, count));
}

int	iseq_str(const char *testname, const char *result, const char *expected)
{
	int	iseq;

	if (result && expected)
		iseq = !strcmp(result, expected);
	else
		iseq = result == expected;
	if (iseq)
		printf("\033[32m[%s SUCCESS]\033[0m got \033[34m\"%s\"\033[0m as expected\n", testname, expected);
	else
		fprintf(stderr, "\033[31m[%s FAILED]\033[0m got \033[34m\"%s\"\033[0m instead of \033[34m\"%s\"\033[0m\n", testname, result, expected);
	return (iseq);
}

int	test_fd(const char *testname, const char *expected)
{
	t_capture	*cap;
	int			iseq;

	cap = capture_state();
	((char *)cap->buff)[cap->size] = 0;
	iseq = iseq_str(testname, cap->buff, expected);
	free(cap->buff);
	cap->buff = NULL;
	return (iseq);
}

int	iseq_int(const char *testname, int result, int expected)
{
	if (result == expected)
		printf("\033[32m[%s SUCCESS]\033[0m got \033[33m%d\033[0m as expected\n", testname, expected);
	else
		fprintf(stderr, "\033[31m[%s FAILED]\033[0m got \033[33m%d\033[0m instead of \033[33m%d\033[0m\n", testname, result, expected);
	return (result == expected);
}

int	main(void)
{
	return (0);
}
