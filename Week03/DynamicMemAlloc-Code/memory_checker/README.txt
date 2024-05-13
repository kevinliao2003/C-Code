1. To compile with CMSC216 memory tool:

   gcc -DMY_DEBUG example_detecting_mem_probs.c my_memory_checker_216.c 

2. Compilation to run with valgrind

   gcc example_detecting_mem_probs.c my_memory_checker_216.c 

3. Compilation using gcc's -fsanitize=address option 

   gcc -fsanitize=address example_detecting_mem_probs.c my_memory_checker_216.c

4. Do not use more that one tool (CMSC216 memory checker, valgrind
   or -fsanitize=address compiler option) at a time.

