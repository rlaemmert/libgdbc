#ifndef CORE_H
#define CORE_H

#include <stdint.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "utils.h"
#include "arch.h"

#define CMD_CONTINUE "c"
#define CMD_READREG  "g"

typedef struct libgdbc_message_t
{
	ssize_t len;
	char* msg;
	uint8_t chk;
} libgdbc_message_t;


typedef struct libgdbc_message_stack_t
{
	int top;
	libgdbc_message_t message_stack[128];
} libgdbc_message_stack_t;


typedef struct libgdbc_t 
{
	char* send_buff; // defines a buffer for reading and sending stuff
	ssize_t max_send_len; // definses the maximal len for the given buffer

	char* read_buff;
	ssize_t max_read_len;

	libgdbc_message_stack_t message_stack; // keeps the unhandled messages
	// is already handled (i.e. already send or ...)
	int fd; // Filedescriptor // TODO add r_socket stuff from radare
	int connected;
	int acks;
	uint8_t* data;
	ssize_t data_len;
	register_t* architecture;
} libgdbc_t;

typedef struct x86_64_t {
	uint64_t rax;
} x86_64_t;


int send_command(libgdbc_t* instance, char* command);
int send_packet(libgdbc_t* instance);
int read_packet(libgdbc_t* instance);
int create_instance(libgdbc_t* instance);
int delete_instance(libgdbc_t* instance);
int connect_instance(libgdbc_t* instance, const char* host, int port);
int disconnect_instance(libgdbc_t* instance);
int dump_message_stack(libgdbc_t* instance);

int step_instance(libgdbc_t* instance);
int memread_instance(libgdbc_t* instance, uint64_t address, uint64_t len);
int regread_instance(libgdbc_t* instance);
int continue_instance(libgdbc_t* instance);

#endif
