#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE	10
# define MAX_SIZE_BUFFER 8000000

//# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		get_next_line(int const fd, char **line);

#endif
