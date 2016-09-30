#include <stdlib.h>
#include <stdio.h>
#include "instruction.h"

t_stacks *createStacks(int ac, char **av)
{
	t_pile *pile_a = createPile(ac, av);
	if (pile_a == NULL) {
		dprintf(2, "ERROR\n");
		exit(_EXIT_VALUE_);
	}
	t_pile *pile_b = createPile(ac, NULL);
	if (pile_b == NULL) {
		dprintf(2, "ERROR\n");
		exit(_EXIT_VALUE_);
	}
	t_stacks *stacks = malloc(sizeof(*stacks));
	if (stacks == NULL) {
		dprintf(2, "ERROR\n");
		exit(_EXIT_VALUE_);
	}
	stacks->stack[PILE_A] = pile_a;
	stacks->stack[PILE_B] = pile_b;
	return stacks;
}