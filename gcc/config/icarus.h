#undef TARGET_ICARUS
#define TARGET_ICARUS 1

/* Link against the C library by default. */
#undef LIB_SPEC
#define LIB_SPEC "-lc"

/* Files linked before and after your program (looked up in the sysroot's lib directory). */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"

/* Force 4 KB page alignment (ld defaults to 2 MB on x86_64). */
#undef LINK_SPEC
#define LINK_SPEC "-z max-page-size=4096"

/* Predefined macros, so code can use #ifdef __icarus__ */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()          \
  do {                                    \
    builtin_define ("__icarus__");        \
    builtin_define ("__unix__");          \
    builtin_assert ("system=icarus");     \
    builtin_assert ("system=unix");       \
    builtin_assert ("system=posix");      \
  } while (0)