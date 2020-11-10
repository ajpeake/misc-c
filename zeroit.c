#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

//
// Adding a change to this file for testing purposes
//

int main(int argc, char *argv[])
{

	int fd;	   // File Descriptor
	clock_t t; // Variables for timing of code

	t = clock(); // Take the start time for timing.

	// Check to see if we have a file to work with. If not, then bail.

	if (argc < 2)
	{
		printf("\nPlease specify a file to truncate!\n\n");
		return -1;
	}

	// Open file specified on the command line
	// Open as read/write and truncate the file

	fd = open(argv[1], O_RDWR | O_TRUNC);

	// If for some reason the file open is in error, print a message and then bail.

	if (fd < 0)
	{
		printf("\nFile does not exist!\n");
		printf("\nFile Descriptor %d\n\n", fd);
		close(fd);
		return -1;
	}

	// Start to do work here since the file is open.

	printf("\n\nYour file has been truncated!!!\n\n");

	// We are done doing work now, so close up and return

	close(fd);

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	printf("This program took %f seconds to execute \n\n", time_taken);

	return 0;
}
