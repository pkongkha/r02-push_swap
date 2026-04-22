SRCS :=\
	push_swap.c\
	$(addprefix chunk/,\
		chunk_find_max.c\
		chunk_find_min.c\
		chunk_split.c\
		chunk_split_get_next_memb.c\
		chunk_split_policy_init.c\
	)\
	$(addprefix circ_stack/,\
		circ_stack_destroy.c\
		circ_stack_init.c\
		circ_stack_pop.c\
		circ_stack_pop_bottom.c\
		circ_stack_print.c\
		circ_stack_print_dual.c\
		circ_stack_push.c\
		circ_stack_push_bottom.c\
		circ_stack_seek.c\
		circ_stack_seek_bottom.c\
		circ_stack_add_strsnums.c\
	)\
	$(addprefix op/,\
		op.c\
		op_many.c\
		op_obtain_enum_string.c\
		op_p.c\
		op_r.c\
		op_rr.c\
		op_s.c\
		op_transaction_destroy.c\
		op_transaction_opti.c\
		op_transaction_print.c\
		op_transaction_record.c\
		op_move.c\
	)\
	$(addprefix sort/,\
		sort.c\
		sort_dumb_five.c\
		sort_dumb_three.c\
		sort_one.c\
		sort_three.c\
		sort_three_flow_a_bottom.c\
		sort_three_flow_a_top.c\
		sort_three_flow_b_bottom.c\
		sort_three_flow_b_top.c\
		sort_three_flow_detect_scheme_bottom.c\
		sort_three_flow_detect_scheme_top.c\
		sort_two.c\
		sort_base_case.c\
	)\
	$(addprefix word_count/,\
		word_count.c\
		word_count_from_strsnums.c\
	)\
	$(addprefix validate/,\
		validate_duplicate.c\
		validate_sorted.c\
	)

BONUS_SRCS :=\
	checker_bonus.c\
	$(addprefix validate/,\
		validate_duplicate.c\
		validate_sorted.c\
	)\
	$(addprefix word_count/,\
		word_count.c\
		word_count_from_strsnums.c\
	)\
	$(addprefix op/,\
		op.c\
		op_many.c\
		op_obtain_enum_string.c\
		op_p.c\
		op_r.c\
		op_rr.c\
		op_s.c\
		op_transaction_destroy.c\
		op_transaction_opti.c\
		op_transaction_print.c\
		op_transaction_record.c\
		op_move.c\
	)\
	$(addprefix circ_stack/,\
		circ_stack_destroy.c\
		circ_stack_init.c\
		circ_stack_pop.c\
		circ_stack_pop_bottom.c\
		circ_stack_print.c\
		circ_stack_print_dual.c\
		circ_stack_push.c\
		circ_stack_push_bottom.c\
		circ_stack_seek.c\
		circ_stack_seek_bottom.c\
		circ_stack_add_strsnums.c\
	)

OBJDIR ?= .obj
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIRS := $(sort $(dir $(OBJS) $(dir $(BONUS_OBJS))))
DEPS := $(OBJS:.o=.d)

BONUS_OBJS := $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)
BONUS_DEPS := $(BONUS_OBJS:.o=.d)

ORIG_CFLAGS := $(CFLAGS)
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -MMD -MP
CFLAGS += -Ilibft -Iinclude
LDFLAGS += -Llibft -lft
unexport CFLAGS LDFLAGS

CC ?= cc

NAME := push_swap

BONUS_NAME := checker

.PHONY: all bonus clean fclean re libft
.NOTPARALLEL: re
all: $(NAME)
bonus: $(BONUS_NAME)
clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS)
	rmdir --ignore-fail-on-nonempty -p $(OBJDIR) 2>/dev/null | true
fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
re: fclean all
libft/libft.a:
	CFLAGS='$(ORIG_CFLAGS)' $(MAKE) -C libft all

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)/%.o: %.c | $(OBJDIRS)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS) | libft/libft.a
	$(CC) -o $@ $^ $(LDFLAGS)

$(BONUS_NAME): $(BONUS_OBJS) | libft/libft.a
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEPS) $(BONUS_DEPS)