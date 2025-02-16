/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:39:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 10:09:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Bot
{
private:
	t_string _name;
	t_stats _stats;
	Channel *_channel;
	t_args _levels;

public:
	Bot(t_string, Channel *);
	~Bot();

	void addStats(Client *);
	void updateStats(Client *);
	void checkStats(Client *, t_string, bool);
	void removeClient(Client *);
	size_t getClientLevel(t_string);
	t_string getName();
};
