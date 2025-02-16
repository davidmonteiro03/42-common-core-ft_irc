/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:17:19 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 10:09:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Client
{
private:
	int _fd;
	bool _logged, _status[3];
	t_string _user, _nick, _real;
	t_channels _channels;

public:
	Client(int);
	Client(t_string);
	~Client();
	int getFd(void) const;
	bool isLogged(void) const;
	bool getStatus(void) const;
	bool getStatus(int) const;
	t_string getNick(void) const;
	t_string getUser(void) const;
	t_string getClient(void) const;
	t_string getNickname(void) const;
	t_string getUsername(void) const;
	void login(void);
	void setstatus(int);
	void setUser(t_string, t_string);
	void setNick(t_string);
	void joinChannel(Channel *);
	void partChannel(Channel *);
	void partChannel(Channel *, t_string);
	void warnOtherUsers(t_string);
};
