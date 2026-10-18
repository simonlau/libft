#ifndef TEST_H
#define TEST_H

#include "libft.h"

#define SEED 42
#define TRIALS 2000

#define PIPE_READ_END 0
#define PIPE_WRITE_END 1

char	*make_rand_str(void);
t_list	*make_rand_lst(int size);
int		*make_rand_int_arr(int size);

#endif
