#ifdef TEST
# define TEST_ATOI
# define TEST_ITOA
# define TEST_LSTADD_BACK
# define TEST_LSTADD_FRONT
# define TEST_LSTCLEAR
# define TEST_LSTDELONE
# define TEST_LSTITER
# define TEST_LSTLAST
# define TEST_LSTMAP
# define TEST_LSTNEW
# define TEST_LSTSIZE
# define TEST_MEMSET
# define TEST_BZERO
# define TEST_CALLOC
# define TEST_MEMCHR
# define TEST_MEMCMP
# define TEST_MEMCPY
# define TEST_MEMMOVE
# define TEST_MEMSET
# define TEST_PUTCHAR_FD
# define TEST_PUTENDL_FD
# define TEST_PUTNBR_FD
# define TEST_PUTSTR_FD
# define TEST_STRCHR
# define TEST_STRDUP
# define TEST_STRITERI
# define TEST_STRJOIN
# define TEST_STRLCAT
# define TEST_STRLCPY
# define TEST_STRLEN
# define TEST_STRMAPI
# define TEST_STRNCMP
# define TEST_STRNSTR
# define TEST_STRRCHR
# define TEST_STRTRIM
# define TEST_SUBSTR
# define TEST_ISALNUM
# define TEST_ISALPHA
# define TEST_ISASCII
# define TEST_ISDIGIT
# define TEST_ISSPACE
# define TEST_ISPRINT
# define TEST_ISLOWER
# define TEST_ISUPPER
# define TEST_TOLOWER
# define TEST_TOUPPER
# define TEST_SPLIT
#endif

/* #if defined(TEST_ATOI) ||\
	defined(TEST_ITOA) ||\
	defined(TEST_LSTADD_BACK) ||\
	defined(TEST_LSTADD_FRONT) ||\
	defined(TEST_LSTCLEAR) ||\
	defined(TEST_LSTDELONE) ||\
	defined(TEST_LSTITER) ||\
	defined(TEST_LSTLAST) ||\
	defined(TEST_LSTMAP) ||\
	defined(TEST_LSTNEW) ||\
	defined(TEST_LSTSIZE) ||\
	defined(TEST_MEMSET) ||\
	defined(TEST_BZERO) ||\
	defined(TEST_CALLOC) ||\
	defined(TEST_MEMCHR) ||\
	defined(TEST_MEMCMP) ||\
	defined(TEST_MEMCPY) ||\
	defined(TEST_MEMMOVE) ||\
	defined(TEST_MEMSET) ||\
	defined(TEST_PUTCHAR_FD) ||\
	defined(TEST_PUTENDL_FD) ||\
	defined(TEST_PUTNBR_FD) ||\
	defined(TEST_PUTSTR_FD) ||\
	defined(TEST_STRCHR) ||\
	defined(TEST_STRDUP) ||\
	defined(TEST_STRITERI) ||\
	defined(TEST_STRJOIN) ||\
	defined(TEST_STRLCAT) ||\
	defined(TEST_STRLCPY) ||\
	defined(TEST_STRLEN) ||\
	defined(TEST_STRMAPI) ||\
	defined(TEST_STRNCMP) ||\
	defined(TEST_STRNSTR) ||\
	defined(TEST_STRRCHR) ||\
	defined(TEST_STRTRIM) ||\
	defined(TEST_SUBSTR) ||\
	defined(TEST_ISALNUM) ||\
	defined(TEST_ISALPHA) ||\
	defined(TEST_ISASCII) ||\
	defined(TEST_ISDIGIT) ||\
	defined(TEST_ISSPACE) ||\
	defined(TEST_ISPRINT) ||\
	defined(TEST_ISLOWER) ||\
	defined(TEST_ISUPPER) ||\
	defined(TEST_TOLOWER) ||\
	defined(TEST_TOUPPER) ||\
	defined(TEST_SPLIT)*/
#include "lib/TEST.h"
#include "../libft.h"
// #endif



#ifdef TEST_ATOI

void	atoi_test_helper(const char *name, const char *str)
{
	iseq_int(name, ft_atoi(str), atoi(str));
}

__attribute__((constructor))
void	atoi_test(void)
{
	atoi_test_helper("atoi 0", "0");
	atoi_test_helper("atoi positive", "42");
	atoi_test_helper("atoi positive noted", "+42");
	atoi_test_helper("atoi negative", "-10");
	atoi_test_helper("atoi MAX_INT", "2147483647");
	atoi_test_helper("atoi MIN_INT", "-2147483648");
	atoi_test_helper("atoi positive space and garbage", "   \t\n+42a");
	atoi_test_helper("atoi garbage", "   \t\n+4w2a");
	atoi_test_helper("atoi null", "   \t\n++42a");
	atoi_test_helper("atoi null", "   \t\n--42a");
	atoi_test_helper("atoi null", "   z\t\n++42a");
	atoi_test_helper("atoi empty", "");
}
#endif

#ifdef TEST_ITOA

__attribute__((constructor))
void	itoa_test(void)
{
	iseq_str("itoa 0", "0", ft_itoa(0));
	iseq_str("itoa positive", "42", ft_itoa(42));
	iseq_str("itoa negative", "-10", ft_itoa(-10));
	iseq_str("itoa MAX_INT", "2147483647", ft_itoa(2147483647));
	iseq_str("itoa MIN_INT", "-2147483648", ft_itoa(-2147483648));
}
#endif

// === LIST TEST ===

#ifdef TEST_LSTADD_BACK
// TODO: test
__attribute__((constructor))
void	lstadd_back_test(void) {
}
#endif

#ifdef TEST_LSTADD_FRONT

__attribute__((constructor))
void	lstadd_front_test(void)
{
	t_list	*l;

	l = ft_lstnew("a");
	ft_lstadd_front(&l, ft_lstnew("b"));
	iseq_str("lstadd_front 1st char", l->content, "b");
	iseq_str("lstadd_front 2nd char", l->next->content, "a");
}
#endif

#ifdef TEST_LSTCLEAR
// TODO: test
__attribute__((constructor))
void	lstclear_test(void) {
}
#endif

#ifdef TEST_LSTDELONE
// TODO: test
__attribute__((constructor))
void	lstdelone_test(void) {
}
#endif

#ifdef TEST_LSTITER
// TODO: test
__attribute__((constructor))
void	lstiter_test(void) {
}
#endif

#ifdef TEST_LSTLAST
// TODO: test
__attribute__((constructor))
void	lstlast_test(void)
{
	t_list	*l;

	l = ft_lstnew("a");
	iseq_str("lstlast 1 elem", ft_lstlast(l)->content, "a");
	ft_lstadd_front(&l, ft_lstnew("b"));
	iseq_str("lstlast 2 elems", ft_lstlast(l)->content, "a");
}
#endif

#ifdef TEST_LSTMAP
// TODO: test
__attribute__((constructor))
void	lstmap_test(void) {
}
#endif

#ifdef TEST_LSTNEW

__attribute__((constructor))
void	lstnew_test(void)
{
	t_list	*l;

	l = ft_lstnew("a");
	iseq_str("lstnew", l->content, "a");
}
#endif

#ifdef TEST_LSTSIZE

__attribute__((constructor))
void	lstsize_test(void) {
	t_list	*l;

	l = ft_lstnew("a");
	iseq_int("lstsize 1 elem", ft_lstsize(l), 1);
	ft_lstadd_front(&l, ft_lstnew("b"));
	iseq_int("lstsize 2 elems", ft_lstsize(l), 2);
}
#endif

// === MEM DEF TEST ===

#ifdef TEST_MEMSET

__attribute__((constructor))
void	test_memset(void)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * 6);
	ft_memset(p, '=', 5);
	p[5] = 0;
	iseq_str("memset", "=====", p);
	free(p);
}
#endif

#ifdef TEST_BZERO
// TODO
#endif

#ifdef TEST_CALLOC
// TODO
#endif

#ifdef TEST_MEMCHR
// TODO
#endif

#ifdef TEST_MEMCMP
// TODO
#endif

#ifdef TEST_MEMCPY
// TODO
#endif

#ifdef TEST_MEMMOVE
// TODO
#endif

#ifdef TEST_MEMSET
// TODO
#endif



// === FD WRITE TEST ===

#ifdef TEST_PUTCHAR_FD

__attribute__((constructor))
void	ft_putchar_fd_test(void)
{
	ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);
	test_fd("putchar_fd", "c\n");
}
#endif

#ifdef TEST_PUTENDL_FD

__attribute__((constructor))
void	ft_putendl_fd_test(void)
{
	ft_putendl_fd("hello, world", 1);
	test_fd("putendl_fd", "hello, world\n");
}
#endif

#ifdef TEST_PUTNBR_FD

__attribute__((constructor))
void	ft_putnbr_fd_test(void)
{
	ft_putnbr_fd(0, 1);
	test_fd("putnbr_fd 0", "0");
	ft_putnbr_fd(42, 1);
	test_fd("putnbr_fd positive", "42");
	ft_putnbr_fd(-10, 1);
	test_fd("putnbr_fd negative", "-10");
	ft_putnbr_fd(2147483647, 1);
	test_fd("putnbr_fd MAX_INT", "2147483647");
	ft_putnbr_fd(-2147483648, 1);
	test_fd("putnbr_fd MIN_INT", "-2147483648");
}
#endif

#ifdef TEST_PUTSTR_FD

__attribute__((constructor))
void	ft_putstr_fd_test(void)
{
	ft_putstr_fd("hello", 1);
	ft_putstr_fd(", world", 1);
	test_fd("putstr_fd", "hello, world");
}
#endif


// ===================
// === STRING TEST ===
// ===================

#ifdef TEST_STRCHR

void	test_strchr_help(char *name, char *str, int c)
{
	char	*a;
	char	*b;

	a = ft_strchr(str, c);
	b = strchr(str, c);
	iseq_str(name, a, b);
}

__attribute__((constructor))
void	ft_strchr_test(void)
{
	test_strchr_help("strchr 'c' in empty", "", 'c');
	test_strchr_help("strchr ',' in \"hello, world\"", "hello, world", ',');
	test_strchr_help("strchr '!' in \"hello, world\"", "hello, world", '!');
	test_strchr_help("strchr 'h' in \"hello, world\"", "hello, world", 'h');
	test_strchr_help("strchr 'h' + 256 in \"hello, world\"", "hello, world", 'h' + 256);
	test_strchr_help("strchr 'x80' in \"h\\x80llo, world\"", "h\x81llo, world", 0x80);
}
#endif

#ifdef TEST_STRDUP

void	test_strdup_help(char *name, char *str)
{
	char	*a;
	char	*b;

	a = ft_strdup(str);
	b = strdup(str);
	iseq_str(name, a, b);
	free(a);
	free(b);
}

__attribute__((constructor))
void	ft_strdup_test(void)
{
	test_strdup_help("strdup empty", "");
	test_strdup_help("strdup \"hello, world\"", "hello, world");
}
#endif

#ifdef TEST_STRITERI
// TODO: test
__attribute__((constructor))
void	striteri_test(void)
{
}
#endif

#ifdef TEST_STRJOIN
// TODO: test
__attribute__((constructor))
void	strjoin_test(void)
{
}
#endif

#ifdef TEST_STRLCAT
void	strlcat_test_helper(const char *name, char *dst, char *str, size_t dsize)
{
	char	*dst_1;
	char	*dst_2;
	size_t	r1;
	size_t	r2;

	dst_1 = calloc(dsize, sizeof(char));
	dst_2 = calloc(dsize, sizeof(char));
	strcpy(dst_1, dst);
	strcpy(dst_2, dst);
	r1 = ft_strlcat(dst_1, str, dsize);
	r2 = strlcat(dst_2, str, dsize);
	iseq_str(name, dst_1, dst_2);
	iseq_int(name, r1, r2);
	free(dst_1);
	free(dst_2);
}

__attribute__((constructor))
void	strlcat_test()
{
	strlcat_test_helper("strlcat normal", "bon", "jour", 8);
	strlcat_test_helper("strlcat normal src mt", "bon", "", 3);
	strlcat_test_helper("strlcat shorter", "bon", "jour", 7);
	strlcat_test_helper("strlcat shorter than dst", "bon", "jour", 2);
	strlcat_test_helper("strlcat longer", "bon", "", 10);
	strlcat_test_helper("strlcat longer dst mt", "", "jour", 10);
	strlcat_test_helper("strlcat 0", "bon", "jour", 0);
	strlcat_test_helper("strlcat src empty", "bon", "", 5);
	strlcat_test_helper("strlcat dst empty", "", "jour", 5);
	strlcat_test_helper("strlcat empty", "", "", 5);
	strlcat_test_helper("strlcat empty & 0", "", "", 0);
}
#endif

#ifdef TEST_STRLCPY
void	strlcpy_test_helper(const char *name, char *str, size_t dsize)
{
	char	*dst;
	char	*dst_2;
	size_t	r1;
	size_t	r2;

	dst = calloc(dsize, sizeof(char));
	dst_2 = calloc(dsize, sizeof(char));
	r1 = ft_strlcpy(dst, str, dsize);
	r2 = strlcpy(dst_2, str, dsize);
	iseq_str(name, dst, dst_2);
	iseq_int(name, r1, r2);
	free(dst);
	free(dst_2);
}

__attribute__((constructor))
void	strlcpy_test(void)
{
	strlcpy_test_helper("strlcpy normal", "bonjour", 8);
	strlcpy_test_helper("strlcpy shorter", "42", 2);
	strlcpy_test_helper("strlcpy longer", "lorem ?", 12);
	strlcpy_test_helper("strlcpy 0", "sit ame !!", 0);
	strlcpy_test_helper("strlcpy empty", "", 10);
	strlcpy_test_helper("strlcpy empty & 0", "", 0);
}
#endif

#ifdef TEST_STRLEN

void	test_strlen_help(char *name, char *str)
{
	iseq_int(name, ft_strlen(str), strlen(str));
}

__attribute__((constructor))
void	ft_strlen_test(void)
{
	test_strlen_help("strlen empty", "");
	test_strlen_help("strlen \"hello, world\"", "hello, world");
}
#endif

#ifdef TEST_STRMAPI
// TODO: test
__attribute__((constructor))
void	strmapi_test(void)
{
}
#endif

#ifdef TEST_STRNCMP

int	test_strncmp_sign(int x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

void	test_strncmp_help(char *name, char *str1, char *str2, size_t n)
{
	iseq_int(name, test_strncmp_sign(ft_strncmp(str1, str2, n)),
		test_strncmp_sign(strncmp(str1, str2, n)));
}

__attribute__((constructor))
void	ft_strncmp_test(void)
{
	test_strncmp_help("strncmp empty", "", "", 10);
	test_strncmp_help("strncmp same", "bonjour", "bonjour", 5);
	test_strncmp_help("strncmp differ content", "bonjour", "bonbon", 5);
	test_strncmp_help("strncmp differ size", "bonjour", "bon", 5);
	test_strncmp_help("strncmp differ content n short", "bonjour", "bonbon", 2);
	test_strncmp_help("strncmp differ size n shorter", "bonjour", "bon", 2);
	test_strncmp_help("strncmp negative char", "bon\x80our", "bon", 7);
}
#endif

#ifdef TEST_STRNSTR

__attribute__((constructor))
void	strnstr_test(void)
{
	iseq_str("strnstr find",
		ft_strnstr("bonjour le monde!", "le", 17), "le monde!");
	iseq_str("strnstr search end out of reach",
		ft_strnstr("bonjour le monde!", "le", 9), NULL);
	iseq_str("strnstr find at end more len",
		ft_strnstr("bonjour le monde!", "!", 200), "!");
	iseq_str("strnstr find in loopback",
		ft_strnstr("aaabcabcd", "aabc", 9), "aabcabcd");
	iseq_str("strnstr find at end",
		ft_strnstr("aaabcabcd", "abcd", 9), "abcd");
}
#endif

#ifdef TEST_STRRCHR

void	test_strrchr_help(char *name, char *str, int c)
{
	char	*a;
	char	*b;

	a = ft_strrchr(str, c);
	b = strrchr(str, c);
	iseq_str(name, a, b);
}

__attribute__((constructor))
void	ft_strrchr_test(void)
{
	test_strrchr_help("strrchr 'c' in empty", "", 'c');
	test_strrchr_help("strrchr ',' in \"he,llo, world\"", "he,llo, world", ',');
	test_strrchr_help("strrchr '!' in \"hello, world\"", "hello, world", '!');
}
#endif

#ifdef TEST_STRTRIM
void	test_strtrim_help(char *name, char *oldstr, char *trimset, char *newstr)
{
	char	*r;

	r = ft_strtrim(oldstr, trimset);
	iseq_str(name, r, newstr);
	free(r);
}

__attribute__((constructor))
void	strtrim_test(void)
{
	test_strtrim_help("strtrim none", "bonjour le monde", " ", "bonjour le monde");
	test_strtrim_help("strtrim normal start", "   bonjour le monde", " ", "bonjour le monde");
	test_strtrim_help("strtrim normal end", "bonjour le monde     ", " ", "bonjour le monde");
	test_strtrim_help("strtrim normal start, end", "   bonjour le monde     ", " ", "bonjour le monde");
	test_strtrim_help("strtrim all in set", " abcde ", " abcde", "");
	test_strtrim_help("strtrim empty s1", "", " abcde", "");
	test_strtrim_help("strtrim empty set", " abcde ", "", " abcde ");
	test_strtrim_help("strtrim empty s1 & set", "", "", "");
}
#endif

#ifdef TEST_SUBSTR

__attribute__((constructor))
void	substr_test(void)
{
	iseq_str("substr normal", ft_substr("abcde", 1, 3), "bcd");
	iseq_str("substr to much normal", ft_substr("abcde", 1, 100), "bcde");
}
#endif

// === CHAR TEST ===

#ifdef TEST_ISALNUM
// TODO
#endif

#ifdef TEST_ISALPHA
// TODO
#endif

#ifdef TEST_ISASCII
// TODO
#endif

#ifdef TEST_ISDIGIT
// TODO
#endif

#ifdef TEST_ISSPACE
// TODO
#endif

#ifdef TEST_ISPRINT
// TODO
#endif

#ifdef TEST_ISLOWER
// TODO
#endif

#ifdef TEST_ISUPPER
// TODO
#endif

#ifdef TEST_TOLOWER
// TODO
#endif

#ifdef TEST_TOUPPER
// TODO
#endif

// ==================
// === SPLIT TEST ===
// ==================

#ifdef TEST_SPLIT

void	print_split_res(char *name, const char *str, char c, int rn)
{
	char	**strs;
	int		i;

	puts("\n==========================");
	printf("'%c' / '%s'\n", c, str);
	puts("--------------------------");
	strs = ft_split(str, c);
	i = 0;
	while (strs[i])
	{
		printf("[%d] = '%s'\n", i, strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
	iseq_int(name, i, rn);
}

__attribute__((constructor))
void	split_test(void)
{
	char	*str;

	str = "bbonjour   le monde!!";
	print_split_res("split multi in mid", str, ' ', 3);
	print_split_res("split multi at end", str, '!', 1);
	print_split_res("split multi at start", str, 'b', 1);
	print_split_res("split not present", str, '-', 1);
	print_split_res("split only present", "   ", ' ', 0);
	print_split_res("split empty", "", ' ', 0);
	print_split_res("split tripouille", "--1-2--3---4----5-----42", '-', 6);
}
#endif
