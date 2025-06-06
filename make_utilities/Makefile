SRC=$(shell find -name '*.c')

# SRC=./src/file.c ./src/file2.c
#  INC=./inc
#********************************************** 
# SRC=$(shell find ./src/ -name '*.c')  //using shell command to add if src folder not in current directory
# INC=$(shell find ./inc/ -name '*.h')
#
#**********************************************
#
#SRC=p1.c main.c
all:
	gcc $(SRC) -o app
	#gcc $(SRC) -I$(INC) -o mainapp
	
clean:
	rm -f app
