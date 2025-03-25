# Minitalk

## Overview
Minitalk is a communication program that allows sending messages between two processes using Unix signals.

## Features
- Send text messages between processes
- Uses only Unix signals for communication
- Lightweight and efficient

## Prerequisites
- C compiler
- Make
- Unix-like system

## Compilation
```bash
make
```

## Usage
1. Start the server:
```bash
./server
```
(The server will display its Process ID)

2. Send a message:
```bash
./client <server-pid> "Your message"
```

## Project Structure
```
minitalk/
├── server.c
├── client.c
└── Makefile
```

## How It Works
- Converts text to binary
- Transmits messages bit by bit using signals
- Handles communication between two processes

## Compilation Flags
- `-Wall`: Show all warnings
- `-Wextra`: Extra warnings
- `-Werror`: Warnings as errors
