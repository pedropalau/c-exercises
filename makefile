# Exercises source files
ARRAY_SOURCES = arrays/sum-array arrays/operations
SOURCES = $(ARRAY_SOURCES)
ARRAY_SOURCES_FILES = arrays/*.[h,c] arrays/sum-array/*.[h,c] arrays/operations/*.[h,c]
SOURCES_FILES = $(ARRAY_SOURCES_FILES)

# Builders
CC = gcc
CC_ARGS = -Wall

BUILD_SOURCE = main.c
BUILD_TARGET = build

# Statically checking C programs for security vulnerabilities and coding mistakes
SPLINT = splint
SPLINT_ARGS = $(SOURCES_FILES)

# Coding style and formatting
CLANG_FORMAT = clang-format
CLANG_FORMAT_SOURCES = utils/*.{h,c}
CLANG_FORMAT_ARGS = -i -style=file constants.h utils/*.[h,c] $(SOURCES_FILES)

# Valgrind memory checker
VALGRIND = valgrind
VALGRIND_ARGS = --track-origins=yes --quiet --error-exitcode=2 --leak-check=full --read-var-info=yes

build: all-checks
	for folder in ${SOURCES} ; \
	do \
		echo "> Building $$folder" ; \
		if [ -f $(wildcard "$$folder/$(BUILD_SOURCE)") ] ; then \
			$(CC) $(CC_ARGS) "$$folder/$(BUILD_SOURCE)" -o "$$folder/$(BUILD_TARGET)" ; \
		fi \
	done

all-checks: code-style splint

splint:
	$(SPLINT) $(SPLINT_ARGS)

code-style:
	$(CLANG_FORMAT) $(CLANG_FORMAT_ARGS)

memory-check: build
	for folder in ${SOURCES} ; \
	do \
		echo "> Executing Valgrind on $$folder" ; \
		if [ -f $(wildcard "$$folder/$(BUILD_TARGET)") ] ; then \
			$(VALGRIND) $(VALGRIND_ARGS) "$$folder/$(BUILD_TARGET)" ; \
		fi \
	done

clean:
	for folder in ${SOURCES} ; \
	do \
		echo "> Cleanning source $$folder" ; \
		if [ -f $(wildcard "$$folder/$(BUILD_TARGET)") ] ; then \
			$(RM) -f "$$folder/$(BUILD_TARGET)" ; \
		fi \
	done
