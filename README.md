# C stuff

Stuff I have written to use personally in C.

The source is C11, but the headers are targetted for C90 / ANSI C if that's
needed.

## `X_Array`

Extendable array, similar to `std::vector` from C++. Create an empty array with
`X_Array_alloc`, and extend with `X_Array_extend`:

```c
int *stuff = X_Array_alloc(sizeof (int));
stuff = X_Array_extend(stuff, 5);
for (size_t i = 0; i < 5; ++i) {
  stuff[i] = 20;
}
```

Cleanup with `X_Array_free`. Bear in mind the location of the array can change
during `X_Array_extend` (which is why we assign `stuff` again).
