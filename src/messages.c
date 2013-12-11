#include "messages.h"
#include "arch.h"
#include "core.h"
#include "utils.h"


int handle_g(libgdbr_t* instance) {
	int index = instance->message_stack.count - 1;
	if (index < 0 ) {
		// theres no message that we could handle..
		return -1;
	}
	libgdbr_message_t* msg = &instance->message_stack.message_stack[index];
	//printf("Msg: %s with len: %i\n", msg->msg, msg->len);
	
	int len = msg->len;
	int i = 0;
	printf("Len: %i\n", len);
	while(len > 0) {
		printf("reg[%i] %s = ", i, x86_64[i].name);
		printf("%016llx\n", unpack_uint64_co ((msg->msg + x86_64[i].offset * 2), x86_64[i].size * 2));
		len -= x86_64[i++].size * 2;
	}
	// printf("Msg: %s with len: %i\n", msg->msg, msg->len); //TODO Debug...
	//instance->data = calloc((msg->len / 2), sizeof(char));
	instance->data_len = (msg->len / 2);
	
	unpack_hex(msg->msg, msg->len, instance->data);
	hexdump(instance->data, instance->data_len, 0);
	return 0;
}


int handle_m(libgdbr_t* instance) {
	int index = instance->message_stack.count - 1;
	if (index < 0 ) {
		// theres no message that we could handle..
		return -1;
	}
	libgdbr_message_t* msg = &instance->message_stack.message_stack[index];
	//printf("Msg: %s with len: %i\n", msg->msg, msg->len); //TODO add debug flag here?
	instance->data_len = (msg->len / 2);
	
	unpack_hex(msg->msg, msg->len, instance->data);
	hexdump(instance->data, instance->data_len, 0);
	instance->message_stack.count--; 

	return 0;
}
