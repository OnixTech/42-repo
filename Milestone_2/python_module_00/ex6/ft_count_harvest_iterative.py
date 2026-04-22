# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 10:18:02 by luciano           #+#    #+#              #
#    Updated: 2026/04/22 10:37:54 by luciano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_count_harvest_iterative():
	days = int(input("Days untill harvest: "))
	i = 1
	while i <= days:
		print(f"Day {i}")
		i += 1
	print("Harvest time!")
