
DSA Suggestions — BCA 1st Year (C Language)
============================================

This folder contains study material for Data Structures & Algorithms
organized into 3 topics. All programs are in C.

FOLDER STRUCTURE
----------------
DSA_Suggestions/
│
├── Polynomials/           (20 programs)
│   01_polynomial_addition.c               Add two polynomials (basic)
│   02_polynomial_subtraction.c            Subtract two polynomials
│   03_polynomial_multiplication.c         Multiply two polynomials
│   04_polynomial_evaluation.c             Evaluate at x (Direct + Horner's)
│   05_polynomial_division.c               Long division of polynomials
│   06_addition_three_polynomials.c        Add 3 high-degree polynomials
│   07_subtraction_negative_coefficients.c Subtract with negative terms
│   08_multiplication_high_degree.c        Multiply degree-3 × degree-3
│   09_evaluate_multiple_points.c          Evaluate at multiple x values
│   10_check_root.c                        Check if x is a root (P(x)=0)
│   11_add_and_subtract_combined.c         (P1+P2)-P3 combined operation
│   12_multiply_then_evaluate.c            Multiply then evaluate (verify)
│   13_addition_different_degrees.c        Add degree-6 and degree-2
│   14_addition_then_multiply.c            (P1+P2)*P3 + Distributive law
│   15_polynomial_square.c                 Square a polynomial P^2
│   16_quadratic_roots.c                   Solve ax²+bx+c=0 (all 3 cases)
│   17_subtraction_then_evaluate.c         Subtract then evaluate
│   18_exact_division.c                    Division with remainder 0
│   19_polynomial_calculator_menu.c        Menu-driven calculator (+,-,*)
│   20_hard_multiply_add.c                 P1*P2 + P1*P3 (hardest)
│
├── Linked_Lists/          (10 programs)
│   01_insertion_at_beginning.c            Singly LL - insert at front (O1)
│   02_insertion_at_end.c                  Singly LL - insert at end (On)
│   03_insertion_at_position.c             Singly LL - insert at position p
│   04_deletion_from_beginning.c           Singly LL - delete first node
│   05_deletion_from_end.c                 Singly LL - delete last node
│   06_deletion_at_position.c              Singly LL - delete node at pos p
│   07_traversal_operations.c              Traversal: display, count, search, sum
│   08_complete_singly_linked_list.c       Menu-driven: ALL singly LL ops
│   09_doubly_linked_list.c               Doubly LL: prev+next, bidirectional
│   10_circular_linked_list.c             Circular LL: last->next = head
│
└── Sortings/              (10 programs)
    01_bubble_sort.c                       Compare adjacent, swap if wrong
    02_selection_sort.c                    Select min, place at front
    03_insertion_sort.c                    Pick each element, insert in place
    04_merge_sort.c                        Divide & conquer, O(n log n)
    05_quick_sort.c                        Pivot partition, O(n log n) avg
    06_shell_sort.c                        Improved insertion with gaps
    07_counting_sort.c                     Count frequencies, non-comparison
    08_radix_sort.c                        Sort digit by digit (LSD)
    09_heap_sort.c                         Max-heap based, O(n log n) guaranteed
    10_all_sorts_comparison.c              All 9 sorts + comparison table


HOW TO COMPILE AND RUN (Terminal)
----------------------------------
For any single file (example: bubble sort):
  gcc 01_bubble_sort.c -o bubble && ./bubble

For programs using math.h (polynomial evaluation, roots):
  gcc 04_polynomial_evaluation.c -o eval -lm && ./eval

The -lm flag links the math library (needed for pow(), sqrt(), fabs()).


READING ORDER SUGGESTION
-------------------------
Polynomials:
  Start -> 01 (add) -> 02 (sub) -> 03 (mult) -> 04 (eval) -> 05 (div)
  Then harder: 06, 07, 08, 09, 10 ...
  Review/capstone: 19 (menu), 20 (hardest)

Linked Lists:
  Start -> 01 (insert begin) -> 02 (insert end) -> 03 (insert pos)
  Then deletion: 04, 05, 06
  Then traversal: 07
  Capstone: 08 (complete menu)
  Advanced: 09 (doubly), 10 (circular)

Sortings:
  Start -> 01 (bubble) -> 02 (selection) -> 03 (insertion)
  Efficient: 04 (merge) -> 05 (quick) -> 09 (heap)
  Special: 06 (shell) -> 07 (counting) -> 08 (radix)
  Summary: 10 (comparison of all)


KEY CONCEPTS PER TOPIC
-----------------------
Polynomials:
  - Represent polynomial as an array: poly[i] = coefficient of x^i
  - Addition/Subtraction: add/subtract same-index coefficients
  - Multiplication: result[i+j] += poly1[i] * poly2[j]
  - Division: long division algorithm
  - Evaluation: Horner's Method is O(n), Direct Method is O(n^2)

Linked Lists:
  - Node has: data + next pointer (singly) or prev+next (doubly)
  - malloc() allocates memory; free() releases it (prevent memory leaks)
  - Traversal: current = head; while(current != NULL) current = current->next
  - Insert at beginning: O(1) | Insert at end: O(n)
  - Circular: last->next = head (not NULL)

Sortings:
  - O(n^2): Bubble, Selection, Insertion (slow for large arrays)
  - O(n log n): Merge, Quick, Heap (fast, good for large arrays)
  - O(n+k): Counting, Radix (fastest when k is small)
  - Stable sort: preserves order of equal elements
  - In-place: sorts without extra arrays (O(1) space)
