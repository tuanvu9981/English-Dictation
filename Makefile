# Exe. file name
TARGET = run

CC=gcc
# compiling flags here
CFLAGS= -g -Wall

GTK_FLAGS= -export -rdynamic `pkg-config --cflags --libs gtk+-3.0`

SRCS = $(wildcard *.c)
ODIR = obj
_OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -rdynamic -o $@ $^ $(GTK_FLAGS)
	@echo "Linking complete!"

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -rdynamic -c $< -o $@ $(GTK_FLAGS)
	@echo "Compiled "$<" successfully!"

clean:
	rm -f $(ODIR)/*.o *~ $(TARGET)
	@echo "Cleanup complete!"
