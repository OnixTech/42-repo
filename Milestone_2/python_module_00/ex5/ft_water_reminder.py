# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 10:00:02 by luciano           #+#    #+#              #
#    Updated: 2026/04/22 10:14:39 by luciano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_water_reminder():
	days = int(input("Days since last watering: "))
	if days > 2:
		print("Water the plants!")
	else:
		print("Plants are fine")
