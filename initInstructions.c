#include "monty.h"

/**
 * initInstructions -  Initializes an array of instruction_t with
 * the available opcodes and their functions.
 * @instructions: an array of instructions
 */
void initInstructions(instruction_t instructions[7])
{
	instructions[0].opcode = "pall";
	instructions[0].f = stack_pall;
	instructions[1].opcode = "pint";
	instructions[1].f = stack_pint;
	instructions[2].opcode = "pop";
	instructions[2].f = stack_pop;
	instructions[3].opcode = "swap";
	instructions[3].f = stack_swap;
	instructions[4].opcode = "add";
	instructions[4].f = stack_add;
	instructions[5].opcode = "nop";
	instructions[5].f = stack_nop;
	instructions[6].opcode = "sub";
	instructions[6].f = stack_sub;
	instructions[7].opcode = "div";
	instructions[7].f = stack_div;
	instructions[8].opcode = "mul";
	instructions[8].f = stack_mul;
	instructions[9].opcode = "mod";
	instructions[9].f = stack_mod;
	instructions[10].opcode = "pchar";
	instructions[10].f = stack_pchar;
	instructions[11].opcode = "pstr";
	instructions[11].f = stack_pstr;
	instructions[12].opcode = "rotl";
	instructions[12].f = stack_rotl;
	instructions[13].opcode = "rotr";
	instructions[13].f = stack_rotr;
}
