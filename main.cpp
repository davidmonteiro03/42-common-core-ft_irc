/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:15:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/15 10:35:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_irc.hpp"

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
		Server *server = new Server(argc, argv);
		server->getInfo();
		server->execute();
		logs("server", LOG_SHUTDOWN);
		delete server;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
