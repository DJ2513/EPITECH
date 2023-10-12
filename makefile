all:
	@echo "build, run, clean"
build: main.o
	@gcc main.o -o boggle
main.o: main.c
	@gcc -c main.c
run:
	@./boggle -g "lqnelooelbtelqte"
clean:
	@rm -f boogle main.o
.PHONY: all build run clean