INC=  
LIB=

CC=gcc
CC_FLAG=-g -Wall  

TARGET=segfault
OBJ=segfault.o

$(TARGET):$(OBJ)  
	$(CC) $(INC) $(LIB) -o $@ $(OBJ)  
  
.SUFFIXES: .c .o .cpp  

.cpp.o:  
	$(CC) $(CC_FLAG) $(INC) -c $*.cpp -o $*.o  

.c.o:  
	$(CC) $(CC_FLAG) $(INC) -c $*.c -o $*.o  

test:
	./$(TARGET)

.PRONY:clean  
clean:  
	@echo "Removing linked and compiled files......"  
	rm -f $(OBJ) $(TARGET) core
