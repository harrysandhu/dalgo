# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

TODO

## According to its man page, what does `getrusage` do?

returns the information describing the resources utilized bt the currenmt process or all its terminated child processes. The who parameter is either RUSAGE_SELF, or RUSAGE_CHILDRES. The buffer to which r_usage points will be filled in with the following structure.



## Per that same man page, how many members are in a variable of type `struct rusage`?

17

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?
issa large struct


## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODO