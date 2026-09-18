# C Data Types — How to Choose the Right One

*Reading material — Computer Programming 1. Use this page alongside lecture and lab sessions; it will be used as reference material for quizzes and exams.*

---

## 1. Ask: What Kind of Value Am I Storing?

| Data | Suitable Type | Example |
| --- | --- | --- |
| Whole number | `int` | `int age = 20;` |
| Positive whole number / bit patterns | `unsigned int` | `unsigned int count = 100;` |
| Character | `char` | `char grade = 'A';` |
| Decimal number | `float` / `double` | `double price = 19.99;` |
| True / False | `_Bool` | `_Bool passed = 1;` |
| Very large integer | `long long` | `long long population = 8000000000LL;` |

> `_Bool` is a keyword since C99 and does **not** require an extra header. If you prefer the more readable `bool`, `true`, and `false` spellings, `#include <stdbool.h>` — it just defines those as aliases for `_Bool`/`1`/`0`.

## 2. Then Ask: What RANGE of Values Do I Need?

Choose the smallest type that can safely represent all required values.

```c
int age = 21;             // -2,147,483,648 to 2,147,483,647 on most systems
                           // 'int' is the simple, conventional choice
unsigned int count = 50;  // 0 to 4,294,967,295 on most systems
```

⚠️ **Important:** Exact ranges depend on the C implementation (compiler + platform). The C standard only *guarantees minimum* ranges — `int` is not guaranteed to be exactly 32 bits everywhere. Never hard-code a range from memory; check it.

Use `<limits.h>` to check at compile/run time:

- `sizeof(int)` — size in bytes
- `INT_MIN`, `INT_MAX` — signed range
- `UINT_MAX` — unsigned range

## 3. Do I Need Negative Values?

If **YES** → use a signed type.

```c
int temperature = -5;
```

If **NO** and the larger non-negative range is genuinely useful → consider `unsigned`.

```c
unsigned int students = 50;
```

**Rule:** Do not use `unsigned` just because a value "should normally be positive." Use it when the non-negative range or bit-level representation is actually useful. Mixing signed and unsigned values in the same expression can produce surprising results (the signed value is silently converted to unsigned), so use `unsigned` deliberately, not by default.

## 4. Do I Need a Fractional Value?

```c
double average = 87.5;
```

- `float` → less precision, smaller storage.
- `double` → generally the preferred floating-point type unless memory, performance, hardware, or precision requirements dictate otherwise.

**Default choice for decimal calculations: `double`.**

```c
double price = 19.99;
```

## 5. Do I Need Exactly 8 Bits?

For an 8-bit value, distinguish between:

**Character**

```c
char letter = 'A';
```

Use `char` when the value represents a character.

**8-bit integer / raw byte**

```c
#include <stdint.h>

uint8_t value = 255;
```

Use `uint8_t` when you specifically need an unsigned integer of exactly 8 bits — e.g., a microcontroller register, a byte, or binary data.

```c
uint8_t sensorValue = 200;
```

⚠️ `char` is **not** guaranteed to be signed or unsigned — its signedness is implementation-defined. Never assume `char` behaves like `signed char` or `unsigned char` without checking, especially if you plan to use it for small arithmetic instead of representing a character.

---

## Quick Decision Guide

**What am I storing?**

- Character → `char`
- True/False → `_Bool` (or `bool` with `<stdbool.h>`)
- Whole number → `int`
- Whole number with a smaller range → `short`
- Whole number with a larger range → `long` / `long long`
- Non-negative integer where the unsigned range is useful → `unsigned ...`
- Decimal → `double`
- Exactly 8 bits → `uint8_t` / `int8_t`
- Exactly 16/32/64 bits → `uint16_t`, `uint32_t`, `uint64_t`, etc. (`#include <stdint.h>`)

---

## Exam / Problem-Solving Rule

When a question asks you to choose a data type:

1. Identify the data.
2. Determine the required range.
3. Check whether negative values are possible.
4. Check whether fractional values are needed.
5. Check whether an exact number of bits is required.
6. Choose the simplest type that safely satisfies the requirements.

**Question:** Store the age of a person.
Whole number? YES. Fraction? NO. Negative? NO. Very large? NO.
→ `int`

**Question:** Store a temperature that can be −20.5 °C.
Whole number? NO. Fraction? YES. Negative? YES.
→ `double`

**Question:** Store an 8-bit sensor reading from 0–255.
Whole number? YES. Negative? NO. Exactly 8 bits? YES.
→ `uint8_t`

---

## Key Idea

Choose the type based on the **requirements**, not simply on the value you happen to have today.

```c
int x = 5;
unsigned int x = 5;
short x = 5;
uint8_t x = 5;
```

All four can legally store `5` today, but they have different ranges, sizes, and intended uses. Choosing a data type is not only about "what value am I storing?" For more complex data, also ask: *am I storing one value, multiple values, or a collection of related values?*

---

## 6. Do I Need to Store MULTIPLE VALUES of the Same Type?

If you need several values of the same type, an **array** is usually appropriate.

```c
int scores[5] = {85, 90, 78, 92, 88};
```

Instead of:

```c
int score1 = 85;
int score2 = 90;
int score3 = 78;
int score4 = 92;
int score5 = 88;
```

An array stores multiple values under one variable name.

| One value | Many values of the same type |
| --- | --- |
| `int age;` | `int ages[30];` |

**How to choose an array?** Ask:

- Do I need multiple values?
- Are all values the same type?
- Do I know the maximum/fixed number of elements?
- Do I need to access elements by position/index?

If **YES** to these → consider an array.

**Example — Store the grades of 50 students.**
Multiple values? YES. Same type? YES. Grades are numerical → `double`/`float`. Number of students known? YES.
→ `double grades[50];`

## 7. Do I Need a TWO-DIMENSIONAL Collection?

If the data naturally has rows and columns, use a multidimensional array.

```c
int matrix[3][4];
```

```
       Column
       0   1   2   3
     +---+---+---+---+
Row 0|   |   |   |   |
     +---+---+---+---+
Row 1|   |   |   |   |
     +---+---+---+---+
Row 2|   |   |   |   |
     +---+---+---+---+
```

**Example** — a classroom seating arrangement:

```c
int seats[5][10];
```

A 5 × 10 matrix: 5 rows, 10 columns, 50 integer elements.

**Decision rule**

- One-dimensional data → `int scores[50];`
- Two-dimensional data → `int matrix[10][10];`
- More dimensions → `int data[3][4][5];`

Use multidimensional arrays when the structure of the data naturally maps to dimensions.

## 8. Do I Need to Store TEXT?

C does not have a built-in string data type. A string is represented as an array of `char` terminated by the null character `'\0'`.

```c
char name[] = "Anas";
```

Conceptually, memory contains:

```
'A'  'n'  'a'  's'  '\0'
```

Therefore `char name[] = "Anas";` requires **5** characters, not 4 — the compiler automatically sizes the array to fit the text plus the terminator.

**Sizing the array explicitly**

```c
char name[5] = "Anas";
```

is valid: the array has exactly enough room for `A n a s \0`.

```c
char name[4] = "Anas";
```

⚠️ **This is a subtle case, worth knowing precisely for exams.** The C standard allows a string literal to initialize a char array of *exactly* the literal's length (without the terminator) — so `char name[4] = "Anas";` actually **compiles without error or warning** (verified with gcc/clang, `-Wall -Wextra -pedantic`). What it produces, however, is an array holding `'A','n','a','s'` with **no** `'\0'` — it is *not* a valid C string. Passing `name` to `printf("%s", name)`, `strlen(name)`, `strcpy`, or any function that expects a null-terminated string is undefined behavior (it will keep reading past the array until it happens to find a zero byte in memory). Rule of thumb: when sizing a char array explicitly to hold text, always allocate at least `strlen(text) + 1` bytes so there is room for `'\0'`.

## 9. Array or String?

Ask what the elements represent.

**Numeric data**

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

**Characters**

```c
char letters[5] = {'A', 'B', 'C', 'D', 'E'};
```

**Text/string**

```c
char name[] = "Anas";
```

The important distinction:

- **char array** → a collection of characters.
- **C string** → a character array **+** `'\0'`.

## 10. Do I Need to Store DIFFERENT TYPES Together?

An array requires all elements to have the same type. But sometimes one object needs to contain different kinds of information. For example, a student may have:

- ID → integer
- Name → string
- GPA → decimal
- Passed → true/false

An array is not appropriate because these values have different types. Use a **struct**.

```c
struct Student {
    int id;
    char name[50];
    double gpa;
    _Bool passed;
};
```

Now we can create:

```c
struct Student student1;
```

and access its members:

```c
student1.id
student1.name
student1.gpa
student1.passed
```

*(Structures — and the `typedef` shorthand that lets you write `Student` instead of `struct Student` — are covered in depth in Session 7.)*

## 11. Array vs Struct

This is an important exam distinction.

**Array** — use when you have many values of the **SAME** type:

```c
int scores[5];
```

Think: `int + int + int + int + int`.

**Struct** — use when you have different pieces of information describing **ONE** entity:

```c
struct Student {
    int id;
    char name[50];
    double gpa;
};
```

Think:

```
Student
 ├── id
 ├── name
 └── gpa
```

**Quick rule:** Array → a fixed-size sequence of elements of the same type. Struct → different information belonging together.

## 12. Do I Need MANY STRUCT OBJECTS?

You can combine arrays and structures. For example, to store 100 students:

```c
struct Student students[100];
```

`struct Student` describes one student; `students[100]` stores 100 of them.

```
students
   │
   ├── students[0]  { id, name, gpa }
   ├── students[1]  { id, name, gpa }
   └── ...
```

This is a very common C programming pattern.

## 13. Do I Need a Collection That Can GROW OR SHRINK?

C does not provide a built-in growable list type like Java's `ArrayList<Integer>` or Python's `numbers = []`. Dynamic arrays, linked lists, trees, etc. are different choices depending on the requirement.

```c
int *numbers = malloc(10 * sizeof(int));
if (numbers == NULL) {
    // allocation failed — handle it before using numbers
}
```

⚠️ **Always check the return value of `malloc`/`calloc`/`realloc` for `NULL`** before dereferencing the pointer. On failure they return `NULL` and set `errno`; using the pointer anyway is undefined behavior.

If the collection needs to grow, `realloc()` can be used — but **never assign the result directly back to the original pointer**:

```c
// UNSAFE — if realloc fails and returns NULL, this overwrites the only
// pointer to the original block, leaking that memory permanently.
numbers = realloc(numbers, 20 * sizeof(int));

// SAFE PATTERN — use a temporary pointer, check it, then commit.
int *temp = realloc(numbers, 20 * sizeof(int));
if (temp == NULL) {
    // allocation failed — 'numbers' is still valid and still points
    // to the original, unmodified block; decide how to recover
} else {
    numbers = temp;
}
```

Remember to release dynamically allocated memory when you're done with it:

```c
free(numbers);
```

*(Dynamic memory allocation with `malloc`, `calloc`, `realloc`, and `free` is covered in depth in Session 6.)*

## 14. Do I Need a LINKED LIST?

If the problem requires a collection whose elements can be dynamically connected, a linked list may be appropriate. A linked list is normally built using a struct and a pointer.

```c
struct Node {
    int data;
    struct Node *next;
};
```

```
+-------+-------+     +-------+-------+     +-------+-------+
| data  | next  | --> | data  | next  | --> | data  | NULL  |
+-------+-------+     +-------+-------+     +-------+-------+
```

Each node contains the stored data and a pointer to the next node.

**Important:** A linked list is not a built-in C data type — it is typically implemented using structures and pointers, with dynamic allocation commonly (but not necessarily) used to create nodes. *(Linked lists are covered in depth in Session 13.)*

## 15. Array vs Linked List

Another important problem-solving distinction.

| Requirement | Array | Linked List |
| --- | --- | --- |
| Same type of elements | ✓ | ✓ |
| Fixed-size collection | Excellent | Possible |
| Dynamic size | Limited / requires resizing | ✓ |
| Direct access by index | ✓ | ✗ |
| Easy insertion in the middle | Usually expensive | Can be efficient with a pointer to position |
| Contiguous memory | ✓ | Not required |
| Requires pointers | No | Yes |
| Requires dynamic allocation | Not necessarily | Commonly |

**Simple rule:** Use an array when you know the size or need fast indexed access. Consider a linked list when the collection changes dynamically and insertion/removal is an important operation.

## 16. Do I Need to Store an ADDRESS?

If you need to store the memory address of another object, use a **pointer**.

```c
int age = 21;
int *p = &age;
```

```
age
┌─────────┐
│   21    │
└─────────┘
    ↑
    │
    p
```

`p` stores the address of `age`.

**Decision rule:** if the question involves memory addresses, dynamically allocated memory, linked lists, trees, modifying a variable through another variable, or passing data by address → you probably need a pointer. *(Pointers are covered in depth in Session 5.)*

## 17. Do I Need a Set of Named CONSTANT VALUES?

If a variable should represent one value from a predefined set of named choices, consider an `enum`.

```c
enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};
```

```c
enum Day today = WEDNESDAY;
```

Instead of using unexplained numbers:

```c
int today = 2;
```

`enum` makes the meaning clearer (by default, `MONDAY` is 0, `TUESDAY` is 1, and so on, unless you assign values explicitly).

**Use `enum` when:** the variable represents one choice from a small, predefined set of named options — e.g., days, directions, states, menu options, error categories. *(Enumerations, along with `typedef`, are covered in depth in Session 12.)*

## 18. Do I Need DIFFERENT VIEWS OF THE SAME MEMORY?

Union members occupy overlapping storage; at most one member's stored value should generally be treated as the active value at a time, subject to C's rules.

```c
union Data {
    int i;
    float f;
    char c;
};
```

Unlike a struct, the members share storage.

**Struct** — members have separate storage:

```
struct
┌──────────┐
│ int      │
├──────────┤
│ float    │
├──────────┤
│ char     │
└──────────┘
```

**Union** — shared storage:

```
union
┌────────────────────┐
│ int / float / char  │
└────────────────────┘
       shared storage
```

A union is useful in situations involving memory-efficient representations, low-level programming, hardware interfaces, and data that can have one of several representations. *(Unions are covered together with structures in Session 7.)*

---

## 19. A Complete Decision Guide

When choosing a C type or data representation, ask these questions in order.

**Step 1 — How many values?**

- One value → continue to Step 2.
- Many values of the same type → consider an array: `int scores[50];`
- Many values that may grow/shrink dynamically → consider dynamic memory and an appropriate data structure.

**Step 2 — What kind of value?**

- Character → `char`
- True/False → `_Bool`
- Whole number → `int`, `long`, `long long`, etc.
- Decimal/fractional number → `double` or `float`
- Memory address → pointer

**Step 3 — Do I need an exact width?**

- Exactly 8 bits → `uint8_t` / `int8_t`
- Exactly 16 bits → `uint16_t` / `int16_t`
- Exactly 32 bits → `uint32_t` / `int32_t`
- Exactly 64 bits → `uint64_t` / `int64_t`

```c
#include <stdint.h>
```

**Step 4 — Do I need TEXT?** → use a char array representing a C string: `char name[50];` Remember: C string = characters + `'\0'`.

**Step 5 — Do I need different types belonging to ONE object?** → `struct`

```c
struct Student {
    int id;
    char name[50];
    double gpa;
};
```

**Step 6 — Do I need a predefined set of named choices?** → `enum`

```c
enum Status {
    SUCCESS,
    FAILURE,
    PENDING
};
```

**Step 7 — Do I need dynamic relationships between objects?** → consider pointers and data structures such as linked lists.

> Trees and graphs are mentioned below only to show the *bigger picture* of where data representation choices eventually lead in computer science. They are **not** part of this course's syllabus and will not appear on quizzes or exams unless your instructor explicitly says otherwise.

### Master Decision Tree

```
                    What am I storing?
                           │
          ┌────────────────┼────────────────┐
          │                │                │
       ONE VALUE       MANY VALUES      RELATED DATA
          │                │                │
          │                │             Different
          │                │              types?
          │                │                │
          │                │          ┌─────┴─────┐
          │                │         YES          NO
          │                │          │            │
          │                │       struct        array
          │                │
          │          Same type?
          │                │
          │          ┌─────┴─────┐
          │         YES          NO
          │          │            │
          │        array       consider
          │                   struct / other
          │                   data structure
          │
          ▼
     What kind of value?
          │
    ┌─────┼────────┬─────────┬─────────┐
    │     │        │         │         │
 char  integer  decimal   Boolean   address
    │     │        │         │         │
   char  int/    double    _Bool    pointer
         long/
         long long
```

---

## Exam / Problem-Solving Extension

When a question asks you to choose a C data representation, use this process:

1. What am I storing?
2. How many values do I need?
3. Are the values the same type?
4. What range of values is required?
5. Can the value be negative?
6. Is a fractional value required?
7. Is an exact number of bits required?
8. Is the data text?
9. Do several different values describe one object?
10. Does the collection need to grow or shrink?
11. Do I need memory addresses or relationships between objects?
12. Choose the simplest representation that safely satisfies the requirements.

### Exam Examples

**Example 1 — Student grades.** Store the grades of 30 students.
Multiple values? YES. Same type? YES. Numeric? YES. Fixed number? YES.
→ `double grades[30];`

**Example 2 — Student information.** Store the ID, name, GPA, and enrollment status of one student.
Multiple pieces of information? YES. Same type? NO. Describe one entity? YES.
→ `struct`

**Example 3 — Product name.** Store the name `"Laptop"`.
Text? YES. C has no built-in string type? YES.
→ `char productName[] = "Laptop";`

**Example 4 — Sensor value.** A sensor produces values from 0 to 255, and the value must occupy exactly 8 bits.
Integer? YES. Negative? NO. Exact width? YES. 8 bits? YES.
→ `uint8_t`

**Example 5 — Student records with a variable number of students.** Store student records when the number of students is not known at compile time.
Multiple values? YES. Different fields per student? YES. Number can change? YES.
→ `struct Student` + dynamic memory.

```c
struct Student *students;
students = malloc(n * sizeof(struct Student));
if (students == NULL) {
    // allocation failed — handle before use
}
```

**Example 6 — Linked list.** Implement a list where elements can be dynamically inserted and removed.
Collection? YES. Dynamic structure? YES. Need nodes connected to one another? YES.
→ `struct` + pointers, forming a linked list.

---

## The Big Picture

It is useful to think of C data representation in layers:

```
                    C DATA REPRESENTATION
                            │
          ┌─────────────────┴─────────────────┐
          │                                   │
      Basic values                       Collections
          │                                   │
    ┌─────┼─────┐                    ┌────────┼────────┐
    │     │     │                    │        │        │
 integer decimal char               array   dynamic   linked
    │      │     │                           data      list
    │      │     │                           │
    └──────┴─────┘                       pointers
                                             │
                                      data structures
                                       (beyond this course:
                                        trees, graphs, ...)
```

And for records / related information:

```
                    STRUCT
                      │
          ┌───────────┼───────────┐
          │           │           │
         int         char       double
         id          name         gpa
```

### Final Principle

Choose the representation based on the **structure of the problem**, not just the value currently stored.

A value such as `5` could legally be stored in many ways:

```c
int x = 5;
unsigned int x = 5;
short x = 5;
uint8_t x = 5;
```

The correct choice depends on range, precision, required size, number of values, relationships between values, and how the data will be used.
