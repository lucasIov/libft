#ifndef TEST_H
# define TEST_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "bsd_string.h"

typedef struct s_capture
{
	void	*buff;
	size_t	size;
}	t_capture;

t_capture	*capture_state(void);
ssize_t		__real_write(int fd, const void *buf, size_t count);
ssize_t		__wrap_write(int fd, const void *buf, size_t count);
int			iseq_str(const char *testname, const char *result, const char *expected);
int			test_fd(const char *testname, const char *expected);
void		test_flush();
int			iseq_int(const char *testname, int result, int expected);
#endif
