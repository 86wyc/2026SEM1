#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("Cannot open the device file.");
		return -1;
	}

	char buf[256];
	int count = read(fd, buf, sizeof(buf)-1); 
	buf[count] = 0;
	printf("Content read out of %s:\n", argv[1]);
	printf("%s\n", buf);
	close(fd);
}
