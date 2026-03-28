output = studentClass

compiler = g++
flags = -g -Wall -fsanitize=address -fsanitize=undefined -Wno-sign-compare
depflags = -MMD -MP

sourceFileExtension = cc

files = $(wildcard *.$(sourceFileExtension))
objects = $(patsubst %.$(sourceFileExtension),%.o,$(files))
deps = $(objects:.o=.d)

all: .gitignore $(output)

$(output): $(objects)
	$(compiler) $(flags) -o $@ $^

%.o: %.$(sourceFileExtension) Makefile
	$(compiler) $(flags) $(depflags) -c $< -o $@

.gitignore: Makefile
	echo "# Ignore generated files" > .gitignore
	echo "$(output)" >> .gitignore
	for obj in $(objects); do echo "$$obj" >> .gitignore; done
	for dep in $(deps); do echo "$$dep" >> .gitignore; done

clean:
	rm -f $(objects) $(deps) $(output)

-include $(deps)
