output = studentClass

compiler = g++

flags = -g -Wall -fsanitize=address -fsanitize=undefined -Wno-sign-compare

sourceFileExtension = cc

files = $(wildcard *.$(sourceFileExtension))

objects = $(patsubst %.$(sourceFileExtension), %.o, $(files))

$(output): $(objects)
	$(compiler) $(flags) -o $@ $^

$(objects): $(files)
	$(compiler) $(flags) -c $^

clean:
	rm -f $(objects) $(output)

ignore:
	echo "# Ignore generated files" > .gitignore
	echo "$(output) $(objects)" >> .gitignore
