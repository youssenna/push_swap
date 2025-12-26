def verify_push_swap():
    # --- 1. THE DATA ---
    # I pasted your exact numbers and operations here
    nums_str = """1 2 3 4 5 6 7 8 10 9"""

    ops_str = """pb
pb
pb
pb
pb
pb
pb
rra
sa
pa
pa
pa
pa
pa
pa
pa"""

    # --- 2. LOGIC ---
    a = [int(x) for x in nums_str.strip().split()]
    b = []
    ops = [x.strip() for x in ops_str.strip().split()]
    
    count = 0
    
    for op in ops:
        count += 1
        if op == "sa":
            if len(a) > 1: a[0], a[1] = a[1], a[0]
        elif op == "sb":
            if len(b) > 1: b[0], b[1] = b[1], b[0]
        elif op == "ss":
            if len(a) > 1: a[0], a[1] = a[1], a[0]
            if len(b) > 1: b[0], b[1] = b[1], b[0]
        elif op == "pa":
            if b: a.insert(0, b.pop(0))
        elif op == "pb":
            if a: b.insert(0, a.pop(0))
        elif op == "ra":
            if a: a.append(a.pop(0))
        elif op == "rb":
            if b: b.append(b.pop(0))
        elif op == "rr":
            if a: a.append(a.pop(0))
            if b: b.append(b.pop(0))
        elif op == "rra":
            if a: a.insert(0, a.pop())
        elif op == "rrb":
            if b: b.insert(0, b.pop())
        elif op == "rrr":
            if a: a.insert(0, a.pop())
            if b: b.insert(0, b.pop())
        else:
            print(f"Error: Unknown operation {op}")
            return

    # --- 3. RESULTS ---
    is_sorted = (a == sorted(a))
    is_empty_b = (len(b) == 0)
    
    print(f"Operations Count: {count}")
    print(f"Stack B Empty: {is_empty_b}")
    print(f"Stack A Sorted: {is_sorted}")
    
    if is_sorted and is_empty_b:
        print("\n✅ SUCCESS: The list is sorted correctly.")
        if count < 5500:
            print("🏆 SCORE: 5/5 (Excellent efficiency for 500 numbers!)")
        elif count < 7000:
            print("🥈 SCORE: 4/5 (Good efficiency)")
        else:
            print("🥉 SCORE: Passing but could be optimized.")
    else:
        print("\n❌ FAIL: The list is NOT sorted.")

verify_push_swap()