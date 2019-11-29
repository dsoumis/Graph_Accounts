#
# In order to execute this "Makefile" just type "make"
#

OBJS    = main.o CyclesInGraph.o DeletionInGraph.o EndOfGraph.o InsertionInGraph.o ModificationInGraph.o PrintingOfGraph.o ReceivingInGraph.o SimpleCyclesInGraph.o StackImplementation.o Traceflow.o
SOURCE  = main.c CyclesInGraph.c DeletionInGraph.c EndOfGraph.c InsertionInGraph.c ModificationInGraph.c PrintingOfGraph.c ReceivingInGraph.c SimpleCyclesInGraph.c StackImplementation.c Traceflow.c
HEADER  = Graph.h GraphInterface.h Stack.h StackInterface.h 
OUT     = mygraph
CC      = gcc
FLAGS   = -g -c
# -g option enables debugging mode
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

# create/compile the individual files >>separately<<
main.o: main.c
	$(CC) $(FLAGS) main.c

CyclesInGraph.o: CyclesInGraph.c
	$(CC) $(FLAGS) CyclesInGraph.c

DeletionInGraph.o: DeletionInGraph.c
	$(CC) $(FLAGS) DeletionInGraph.c

EndOfGraph.o: EndOfGraph.c
	$(CC) $(FLAGS) EndOfGraph.c

InsertionInGraph.o: InsertionInGraph.c
	$(CC) $(FLAGS) InsertionInGraph.c

ModificationInGraph.o: ModificationInGraph.c
	$(CC) $(FLAGS) ModificationInGraph.c

PrintingOfGraph.o: PrintingOfGraph.c
	$(CC) $(FLAGS) PrintingOfGraph.c

ReceivingInGraph.o: ReceivingInGraph.c
	$(CC) $(FLAGS) ReceivingInGraph.c

SimpleCyclesInGraph.o: SimpleCyclesInGraph.c
	$(CC) $(FLAGS) SimpleCyclesInGraph.c

StackImplementation.o: StackImplementation.c
	$(CC) $(FLAGS) StackImplementation.c

Traceflow.o: Traceflow.c
	$(CC) $(FLAGS) Traceflow.c

# clean house
clean:
	rm -f $(OBJS) $(OUT)

# do a bit of accounting
count:
	wc $(SOURCE) $(HEADER)
