/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:15:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/14 23:56:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_irc.hpp"

Server *server = NULL;
char hostname[256], *ip;
bool running = true;

void signal_handler(int sig)
{
	if (sig == SIGINT)
		running = false;
}

int main(int argc, char **argv)
{
	signal(SIGINT, signal_handler);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	try
	{
		server = new Server(argc, argv);
		server->getInfo();
		server->execute();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	if (server != NULL)
		delete server;
	logs("server", LOG_SHUTDOWN);
	return (void)argc, (void)argv, EXIT_SUCCESS;
}
