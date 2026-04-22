# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 10:38:50 by luciano           #+#    #+#              #
#    Updated: 2026/04/22 13:30:55 by luciano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_count_harvest_recursive(i = 1, days = None):
	if days == None:
		days = int(input("Days until harverst: "))
	print(f"Day {i}")
	if i == days:
		print("Harvest time!")
		return
	return ft_count_harvest_recursive(i + 1, days)
