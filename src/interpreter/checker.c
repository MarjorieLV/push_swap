#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "interpreter.h"
#include "instruction.h"

void displayStacks(t_stacks *stacks)
{
	printf("pile_a\n");
	printPile(stacks->stack[PILE_A]);
	printf("pile_b\n");
	printPile(stacks->stack[PILE_B]);
	return;
}

void printPile(t_pile *pile)
{
	t_element *current_elem = pile->first_element;
	while (current_elem){
		printf("%d\n", current_elem->current_int);
		current_elem = current_elem->next;
	}
	return;
}
void checker(int ac, char **av)
{
	size_t size_max = _SIZE_MAX_;
	bool status = true;
	t_stacks * stacks = createStacks(ac, av);
	displayStacks(stacks);
	while (status){
		int ret = 0;
		char *buff = NULL;
		ret = getline(&buff, &size_max, stdin);
		buff[ret] = '\0';
		if (ret == 0){
			//ckeckResult(stacks); //////////TO_DO////////////////
			status = false;
		}
		else 
			applyCmd(buff, stacks);
		free(buff);
	}
	displayStacks(stacks);
	freeStacks(&stacks);
	return;
} 