# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_age.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 09:55:45 by luciano           #+#    #+#              #
#    Updated: 2026/04/22 09:57:59 by luciano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_plant_age():
	age = int(input("Enter plant age in days: "))
	if age > 60:
		print("Plant is ready to harvest!")
	else:
		print("Plant needs more time to grow.")
