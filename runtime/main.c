#include <stdlib.h>
#include <stdarg.h>

void error(const char* fmt, ...) {
	va_list arg;
	va_start(arg, fmt);
	vfprintf(stderr, fmt, arg);
	puts("");
	va_end(arg);
	exit(1);
}

int main(int argc, char* argv[]) {
	if (argc < 2)
		error("Need a filename");
	FILE* in = fopen(argv[1], "rb");
	if (!in) 
		error("File %s does not exist", argv[1]);
	fclose(in);
	return 0;
}
