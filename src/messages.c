#include "messages.h"
#include "arch.h"
#include "core.h"
#include "utils.h"


int handle_g(libgdbr_t* instance) {
	//int len = strlen(instance->data);
	//int i = 0;
	//while(len > 0) {
	//	printf("reg[%i] %s = ", i, x86_64[i].name);
	//	printf("%016lx\n", unpack_uint64_co ((instance->data + x86_64[i].offset * 2), x86_64[i].size * 2));
	//	len -= x86_64[i++].size * 2;
	//}
	instance->data_len = strlen(instance->data) / 2;
	unpack_hex(instance->data, strlen(instance->data), instance->data);
	return 0;
}


int handle_m(libgdbr_t* instance) {
	int len = strlen(instance->data);
	instance->data_len = strlen(instance->data) / 2;
	unpack_hex(instance->data, len, instance->data);
	//hexdump(instance->data, instance->data_len, 0);
	return 0;
}


int handle_cmd(libgdbr_t* instance) {
	unpack_hex(instance->data, strlen(instance->data), instance->data);
	//printf("Answer: %s\n", instance->data); 
	instance->data_len = strlen(instance->data) / 2;
	return 0;
}


int handle_connect(libgdbr_t* instance) {
	//printf("%s\n", instance->read_buff); // TODO handle the message correct and set all infos
	return 0;
}

