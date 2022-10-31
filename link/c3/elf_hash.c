#include <stdio.h>
#include <stdint.h>
uint32_t elf_hash(const uint8_t *name) {

	uint32_t h = 0, g;
	for(; *name; name++) {
	
		h = (h << 4) + *name;
		if(g = h & 0xf0000000) {
	
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h;
}

int main(int argc, char *argv[]) {
	uint32_t hash = elf_hash((const uint8_t *)argv[1]);
	printf("0x%08x\n", hash);
}
