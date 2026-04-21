SRCS := $(wildcard *.c $(addsuffix /*.c,chunk circ_stack op sort word_count validate))
OBJDIR ?= .obj
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIRS := $(sort $(dir $(OBJS)))
DEPS := $(OBJS:.o=.d)

ORIG_CFLAGS := $(CFLAGS)
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -MMD -MP
CFLAGS += -Ilibft -Iinclude
LDFLAGS += -Llibft -lft
unexport CFLAGS LDFLAGS

CC ?= cc

NAME := push_swap

.PHONY: all libft
.NOTPARALLEL: re
all: $(NAME)
clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJS) $(DEPS)
	rmdir --ignore-fail-on-nonempty -p $(OBJDIR) 2>/dev/null | true
fclean: clean
	$(RM) $(NAME)
re: fclean all
libft/libft.a:
	CFLAGS='$(ORIG_CFLAGS)' $(MAKE) -C libft all

$(OBJDIRS):
	mkdir -p $@
$(OBJDIR)/%.o: %.c | $(OBJDIRS)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS) | libft/libft.a
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEPS)