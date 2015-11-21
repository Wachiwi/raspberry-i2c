NAME=raspberry-i2c
CC=gcc
OPTS=
PWD=.
SOURCE=$(PWD)/$(NAME)
$(NAME)_INCLUDE=$(PWD)/include
# Set target device name (hostname)
TARGET=
# Set target install path
TARGET_PATH=

default: build

build: clean
	@mkdir -p $(PWD)/bin
	$(CC) $(OPTS) $(SOURCE)/*.c -I $($(NAME)_INCLUDE) -o $(PWD)/bin/$(NAME)

clean:
	@rm -rf $(PWD)/bin

sync:
	rsync -r $(PWD) $(TARGET):$(TARGET_PATH)

doc:
	cldoc generate -- --output ./doc/ $(NAME)
