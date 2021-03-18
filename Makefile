# Exe. file name
TARGET = run

CC=gcc
# compiling flags here
CFLAGS= -g -Wall

IDIR = ./sqlite/inc
# define any directories containing header file other then /usr/include
INCLUDES = -I $(IDIR)

# define any libraries to link into executable:
# if I want to link in libraries
# (libx.so or libx.a) I use the -llibname (-lx -lx) = (-lx)
# libfdr => -lfdr 
LIBS = -lsqlite3 -ldl #FATAL !!!! NEED -ldl

# define any directories containing implementation of the file in INCLUDES
# ../..lib means up 2 level then search for /lib
LDIR = sqlite/lib
LFLAGS = -L $(LDIR)

GTKFLAGS= -export-dynamic `pkg-config --cflags --libs gtk+-3.0`
#GTKFLAGS= -export -rdynamic `pkg-config --cflags --libs gtk+-3.0`

# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
# For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix

SRCS = $(wildcard *.c)
ODIR = obj
_OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(TARGET): $(OBJS)
	$(CC)  $(CFLAGS) $(INCLUDES) -g -rdynamic -o $@ $^ $(LFLAGS) $(LIBS) $(GTKFLAGS)
	@echo "Linking complete!"

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -rdynamic -c $< -o $@ $(LFLAGS) $(LIBS) $(GTKFLAGS)
	@echo "Compiled "$<" successfully!"

clean:
	rm -f $(ODIR)/*.o *~ $(TARGET)
	@echo "Cleanup complete!"
