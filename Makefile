#Makefile for personal virtual machine
SOURCE = main.cpp

LINKER_FLAGS = -w

APP_NAME = Virtual_Machine

COMPILER = g++

all:
	$(COMPILER) $(SOURCE) $(LINKER_FLAGS) -o $(APP_NAME)
