#ifndef TEST_H
# define TEST_H

# include "libft.h"
# include <unistd.h>

# define SEED 42
# define TRIALS 1000

# define PIPE_READ_END 0
# define PIPE_WRITE_END 1

char	*make_rand_str(void);
t_list	*make_rand_lst(int size);
int		*make_rand_int_arr(int size);

ssize_t	capture_begin(int fd, void *buf, size_t count);
size_t	capture_end(int fd);

#endif
