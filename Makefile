
all:  asciiArt

#  Monday July 25, 2016
template: template.cpp
	g++ template.cpp -Wall -o template

add: add.cpp
	g++ add.cpp -Wall -o add

asciiArt: asciiArt.cpp
	g++ asciiArt.cpp -Wall -o asciiArt

clean:
	rm -f a.out template add asciiArt
