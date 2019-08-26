#include <iostream>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>
#include <thread>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
bool Terminated = false;
void tcp18666()
{
	int s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		perror("Error calling socket");
		
	}


	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(18666);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("Error calling bind");
	
	}

	if (listen(s, 5))
	{
		perror("Error calling listen");
		
	}

	int s1 = accept(s, NULL, NULL);
	if (s1 < 0)
	{
		perror("Error calling accept");
		
	}

	char buffer[18];
	int counter = 0;
	int out_file = open("/root/projects/telemetry.txt", O_WRONLY | O_CREAT);

	do
	{
		//memset(buffer, 0, sizeof(char) * 2);

		int rc = recv(s1, buffer, 19, 0);

		if (rc < 0)
		{
			if (errno == EINTR)
				continue;
		}
	
		write(out_file, buffer, 19);
		printf("%s/n", buffer);

		usleep(5000000);
	} while (!Terminated);

	close(out_file);
}

int main(int argc, char * argv)
{
	std::thread tcp = std::thread(tcp18666);
	while (getchar() != 's');
	Terminated = true;
	tcp.join();
}