# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 13:32:40 by luciano           #+#    #+#              #
#    Updated: 2026/04/22 14:00:38 by luciano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
	seed_type = seed_type.capitalize()

	if unit == "packets":
		print(f"{seed_type} seeds: {quantity} packets available")
	elif unit == "grams":
		print(f"{seed_type} seeds: {quantity} grams total")
	elif unit == "area":
		print(f"{seed_type} seeds: covers {quantity} square meters")
	else:
		print("Unknown unit type")
