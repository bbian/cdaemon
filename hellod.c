#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

extern "C" void test_cplusplus_11(void);

int main(void) 
{
	/* Our process ID and Session ID */
	pid_t pid, sid;
	
	/* First test C++11 environment */
	test_cplusplus_11();

	/* Fork off the parent process */
	pid = fork();
	if (pid < 0) {
		exit(EXIT_FAILURE);
	}
	/* If we got a good PID, then
	   we can exit the parent process. */
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	printf("Child is running!\n");

	/* Change the file mode mask */
	umask(0);
		
	/* Open any logs here */	
		
	/* Create a new SID for the child process */
	sid = setsid();
	if (sid < 0) {
		/* Log the failure */
		exit(EXIT_FAILURE);
	}
	
	/* Change the current working directory */
	if ((chdir("/tmp")) < 0) {
		/* Log the failure */
		exit(EXIT_FAILURE);
	}
	
	printf("Start syslog...\n");
	/* Close out the standard file descriptors */
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	/* Daemon-specific initialization goes here */
	
	/* The Big Loop */
	while (1) {
	   /* Do some task here ... */
		openlog("helloworldlog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
		syslog(LOG_INFO, "Hello world from hellod");
		closelog();	
	   
	   sleep(30); /* wait 30 seconds */
	}
   exit(EXIT_SUCCESS);
}

