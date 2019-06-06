ARRAY_SOURCES = arrays/*.[h,c] arrays/sum-array/*.[h,c] arrays/operations/*.[h,c]
SOURCES = $(ARRAY_SOURCES)

# Coding style and formatting
CLANG_FORMAT = clang-format
CLANG_FORMAT_SOURCES = utils/*.{h,c}
CLANG_FORMAT_ARGS = -i -style=file constants.h utils/*.[h,c] $(SOURCES)

all-checks: code-style

code-style:
	$(CLANG_FORMAT) $(CLANG_FORMAT_ARGS)
