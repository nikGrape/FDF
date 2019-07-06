 # **LIBFT**
 
 ### **MAP**
 #### FIRST PART
 
 		1. ft_memset		11. ft_strncpy		21. ft_atoi
		2. ft_bzero		12. ft_strcat		22. ft_isalpha
		3. ft_memcpy		13. ft_strncat		23. ft_isdigit
 		4. ft_memccpy		14. ft_strlcat		24. ft_isalnum
 		5. ft_memmove		15. ft_strchr		25. ft_isascii
 		6. ft_memchr		16. ft_strrchr		26. ft_isprint
 		7. ft_memcmp		17. ft_strstr		27. ft_toupper
 		8. ft_strlen		18. ft_strnstr		28. ft_tolower
 		9. ft_strdup		19. ft_strcmp
		10. ft_strcpy		20. ft_strncmp
#### SECOND PART

		29. ft_memalloc		37. ft_strmapi		45. ft_putchar
		30. ft_memdel		38. ft_strequ		46. ft_putstr
		31. ft_strnew		39. ft_strnequ	 	47. ft_putendl
		32. ft_strdel		40. ft_strsub		48. ft_putnbr
		33. ft_strclr		41. ft_strjoin	 	49. ft_putchar_fd
		34. ft_striter		42. ft_strtrim		50. ft_putstr_fd
		35. ft_striteri		43. ft_strsplit		51. ft_putendl_fd
		36. ft_strmap		44. ft_itoa		52. ft_putnbr_fd

#### BONUS PART
		
		53. ft_lstnew		56. ft_lstadd
		45. ft_lstdelone	57. ft_lstiter
		55. ft_lstdel		58. ft_lstmap	

#### EXTRA FUNCTIONS
 
		59. ft_strindex
		60. ft_wdcounter
		61. ft_memdup.c

## 1. **FIRST PART**
<string.h>

###  1. FT_MEMSET
+ SYNOPSIS:

 		void	memset(void *b, int c, size_t len)
		
+ DESCRIPTION:

		The _memset()_ function writes len bytes of value c 
		(converted to an unsigned char) to the string b.
+ RETURN VALUES:

		The memset() function returns its first argument.

###  2. FT_BZERO
+ SYNOPSIS:

		void    bzero(void *s, size_t n)
+ DESCRIPTION:

		The bzero() function writes n zeroed bytes to the string s.  
		If n is zero, bzero() does nothing.

###  3. FT_MEMCPY
+ SYNOPSIS:

		void	*memcpy(void *restrict dst, const void *restrict src, size_t n)
+ DESCRIPTION:

		The memcpy() function copies n bytes from memory area src to memory area dst.  
		If dst and src overlap, behavior is undefined.
+ RETURN VALUES:

		The memcpy() function returns the original value of dst.

###  4. FT_MEMCCPY
+ SYNPSIS:

		void *
     		memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
+ DESCRIPTION:
   		
		The memccpy() function copies bytes from string src to string dst.  If
		the character c (as converted to an unsigned char) occurs in the string
		src, the copy stops and a pointer to the byte after the copy of c in the
		string dst is returned.  Otherwise, n bytes are copied, and a NULL
		pointer is returned.
		The source and destination strings should not overlap, as the behavior is
		undefined.
		
###  5. FT_MEMMOVE
+ SYNPSIS:

		void	*memmove(void *dst, const void *src, size_t len);
+ DESCRIPTION:

		The memmove() function copies len bytes from string src to string dst. 
		The two strings may overlap; the copy is always done in a non-destructive 
		manner.
+ RETURN VALUES:

		The memmove() function returns the original value of dst.
		
###  6. FT_MEMCHR
+ SYNPSIS:

		void	*memchr(const void *s, int c, size_t n);
+ DESCRIPTION:

		The memchr() function locates the first occurrence of c (converted to an
		unsigned char) in string s.
+ RETURN VALUES:

		The memchr() function returns a pointer to the byte located, or NULL if
     		no such byte exists within n bytes.
		
###  7. FT_MEMCMP
+ SYNPSIS:

		int	memcmp(const void *s1, const void *s2, size_t n);
+ DESCRIPTION:

     		The memcmp() function compares byte string s1 against byte string s2.
    		Both strings are assumed to be n bytes long.
+ RETURN VALUES:

		The memcmp() function returns zero if the two strings are identical, oth-
		erwise returns the difference between the first two differing bytes
		(treated as unsigned char values, so that `\200' is greater than `\0',
		for example).  Zero-length strings are always identical.  This behavior
		is not required by C and portable code should only depend on the sign of
		the returned value.

###  8. FT_STRLEN
+ SYNPSIS:
		
		size_t	strlen(const char *s);

+ DESCRIPTION:

		The strlen() function computes the length of the string s.
+ RETURN VALUES:
		
		The strlen() function returns the number of characters that precede the
		terminating NUL character

###  9. FT_STRDUP
+ SYNPSIS:
		
		char	*strdup(const char *s1);
+ DESCRIPTION:

		The strdup() function allocates sufficient memory for a copy of the
		string s1, does the copy, and returns a pointer to it.  The pointer may
		subsequently be used as an argument to the function free(3).
		If insufficient memory is available, NULL is returned and errno is set to
		ENOMEM.

###  10. FT_STRCPY
+ SYNPSIS:

		char	*strcpy(char * dst, const char * src);
+ DESCRIPTION:

		strcpy() functions copy the string src to dst (including
		the terminating `\0' character.)
+ RETURN VALUES:

		The strcpy() returns dst.
###  11. FT_STRNCPY
+ SYNPSIS:

		char	*strncpy(char * dst, const char * src, size_t len);
+ DESCRIPTION:

		The strncpy() function copy at most len characters from
		src into dst.  If src is less than len characters long, the remainder of
		dst is filled with `\0' characters.  Otherwise, dst is not terminated.
+ RETURN VALUES:

		The strncpy() returns dst.
###  12. FT_STRCAT
+ SYNPSIS:

		char	*strcat(char *restrict s1, const char *restrict s2);
+ DESCRIPTION:

		The strcat() and strncat() functions append a copy of the null-terminated
		string s2 to the end of the null-terminated string s1, then add a termi-
		nating `\0'.
+ RETURN VALUES:

		The strcat() and strncat() functions return the pointer s1.
###  13. FT_STRNCAT
+ SYNPSIS:

		char	*strncat(char *restrict s1, const char *restrict s2, size_t n);
+ DESCRIPTION:

		The strncat() function appends not more than n characters from s2, and
		then adds a terminating `\0'.
+ RETURN VALUES:
		
		The strcat() and strncat() functions return the pointer s1.
###  14. FT_STRLCAT
+ SYNPSIS:
		
		size_t
		strlcat(char * restrict dst, const char * restrict src, size_t dstsize);

+ DESCRIPTION:

		The strlcat() appends string src to the end of dst.  It will append at most
		dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
		dstsize is 0 or the original dst string was longer than dstsize (in prac-
		tice this should not happen as it means that either dstsize is incorrect
		or that dst is not a proper string).

+ RETURN VALUES:
		
		The strlcat() returns the initial length of dst plus
		the length of src.
###  15. FT_STRCHR
+ SYNPSIS:

		char	*strchr(const char *s, int c);
+ DESCRIPTION:

		The strchr() function locates the first occurrence of c (converted to a
		char) in the string pointed to by s.  The terminating null character is
		considered to be part of the string; therefore if c is `\0', the func-
		tions locate the terminating `\0'.
+ RETURN VALUES:

		The functions strchr() and strrchr() return a pointer to the located
		character, or NULL if the character does not appear in the string.
###  16. FT_STRRCHR
+ SYNPSIS:

		char	*strrchr(const char *s, int c);
+ DESCRIPTION:

		The strrchr() function is identical to strchr(), except it locates the
		last occurrence of c.

###  17. FT_STRSTR
+ SYNPSIS:

		char	*strstr(const char *haystack, const char *needle);
+ DESCRIPTION:

		The strstr() function locates the first occurrence of the null-terminated
		string needle in the null-terminated string haystack.
+ RETURN VALUES:

		If needle is an empty string, haystack is returned; if needle occurs
		nowhere in haystack, NULL is returned; otherwise a pointer to the first
		character of the first occurrence of needle is returned.
###  18. FT_STRNSTR
+ SYNPSIS:

		char	*strnstr(const char *haystack, const char *needle, size_t len);
+ DESCRIPTION:

		The strnstr() function locates the first occurrence of the null-termi-
		nated string needle in the string haystack, where not more than len char-
		acters are searched.  Characters that appear after a `\0' character are
		not searched.  Since the strnstr() function is a FreeBSD specific API, it
		should only be used when portability is not a concern.
+ RETURN VALUES:
		
		Look FT_STRSTR
		
###  19. FT_STRCMP
+ SYNPSIS:

		int	strcmp(const char *s1, const char *s2);
+ DESCRIPTION:

		The strcmp() and strncmp() functions lexicographically compare the null-
		terminated strings s1 and s2.
+ RETURN VALUES:

		The strcmp() and strncmp() functions return an integer greater than,
		equal to, or less than 0, according as the string s1 is greater than,
		equal to, or less than the string s2.  The comparison is done using
		unsigned characters, so that `\200' is greater than `\0'.
###  20. FT_STRNCMP
+ SYNPSIS:

		int	strncmp(const char *s1, const char *s2, size_t n);
+ DESCRIPTION:

		The strncmp() function compares not more than n characters
+ RETURN VALUES:

		Look FT_STRCMP
###  21. FT_ATOI
+ SYNPSIS:
		
		#include <stdlib.h>
		int	atoi(const char *str);
+ DESCRIPTION:

		The atoi() function converts the initial portion of the string pointed to
		by str to int representation
###  22. FT_ISALPHA
+ SYNPSIS:
		
		#include <ctype.h>
		int	isalpha(int c);
+ DESCRIPTION:

		The isalpha() function tests for any character for which isupper(3) or
		islower(3) is true
+ RETURN VALUES:
		
		The isalpha() function returns zero if the character tests false and
		returns non-zero if the character tests true
###  23. FT_ISDIGIT
+ SYNPSIS:
		
		#include <ctype.h>
		int	isdigit(int c);
+ DESCRIPTION:
		
		The isdigit() function tests for a decimal digit character.
+ RETURN VALUES:
		
		The isdigit() function returns zero if the character tests
		false and return non-zero if the character tests true.
###  24. FT_ISALNUM
+ SYNPSIS:

		#include <ctype.h>
		int	isalnum(int c);
+ DESCRIPTION:
		
		The isalnum() function tests for any character for which isalpha(3) or
		isdigit(3) is true.
+ RETURN VALUES:
		
		The isalnum() function returns zero if the character tests false and
		returns non-zero if the character tests true.
###  25. FT_ISASCII
+ SYNPSIS:

		#include <ctype.h>
		int	isascii(int c);
+ DESCRIPTION:
	
		The isascii() function tests for an ASCII character, which is any charac-
		ter between 0 and octal 0177 inclusive.

###  26. FT_ISPRINT
+ SYNPSIS:
		
		#include <ctype.h>
		int	isprint(int c);
+ DESCRIPTION:
		
		The isprint() function tests for any printing character, 
		including space(` ').
+ RETURN VALUES:
		
		The isprint() function returns zero if the character tests false and
		returns non-zero if the character tests true.
###  27. FT_TOUPPER
+ SYNPSIS:
		
		#include <ctype.h>
		int	toupper(int c);
+ DESCRIPTION:

		The toupper() function converts a lower-case letter to the corresponding
		upper-case letter.
+ RETURN VALUES:

		If the argument is a lower-case letter, the toupper() function returns
		the corresponding upper-case letter if there is one; otherwise, the argu-
		ment is returned unchanged.
###  28. FT_TOLOWER
+ SYNPSIS:

		#include <ctype.h>
		int	tolower(int c);
+ DESCRIPTION:

		The tolower() function converts an upper-case letter to the corresponding
		lower-case letter
+ RETURN VALUES
		
		If the argument is an upper-case letter, the tolower() function returns
		the corresponding lower-case letter if there is one; otherwise, the argu-
		ment is returned unchanged.
		

## 2. **SECOND PART**
