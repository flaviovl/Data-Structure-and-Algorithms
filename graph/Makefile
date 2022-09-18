CC=clang

all: graph.o
	$(CC) -g -Wall main.c graph.o -o main

graph.o: graph_adj_matrix.c
	$(CC) -g -Wall -c graph_adj_matrix.c -o graph.o

clean:
	rm graph.o main graph.png graph.pdf graph.svg


graphpng:
	./main | dot -Tpng > graph.png

graphpdf:
	./main | dot -Tpdf > graph.pdf

graphsvg:
	./main | dot -Tsvg > graph.svg
