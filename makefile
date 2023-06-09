############################# Makefile ##########################
CC=gcc
CFLAGS=-Wall

######Alterar Dependências e Objetos #####
DEPS = corrida.h  #ficheiros .h - Colocar todos
OBJ = main.o corrida.o #objetos. Um por ficheiro .c sempre com terminação .o
##########################################

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

#Mudar o nome de app para o nome da aplicação pretendido
corrida: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf corrida
