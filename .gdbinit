# Show single stack
define pstack
  if $argc == 0
    printf "Usage: pstack <stack_pointer>\n"
  else
    set $current = $arg0
    set $index = 1
    printf "\n╔════════════════════╗\n"
    printf "║   STACK           ║\n"  
    printf "╠════════════════════╣\n"
    if $current == 0
      printf "║   (empty)         ║\n"
    end
    while $current != 0
      printf "║ [%d] -> %-10d ║\n", $index, *(int *)$current->content
      set $current = $current->next
      set $index = $index + 1
    end
    printf "╚════════════════╝\n\n"
  end
end

# Show both stacks
define pstacks
  if $argc != 2
    printf "Usage: pstacks <stack_a> <stack_b>\n"
  else
    printf "\n========== STACK A ==========\n"
    pstack $arg0
    printf "========== STACK B ==========\n"
    pstack $arg1
  end
end