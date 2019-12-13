# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    conditions.rb                                    .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 15:49:17 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/13 16:17:29 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

travel = [
	{ ville: "Paris", time: 10 },
	{ ville: "New York", time: 5 },
	{ ville: "Berlin", time: 2 },
	{ ville: "Montréal", time: 15 }
]

travel.each do |t|
	if not t[:time] == 5
		puts "I traveled to #{t[:ville]} for #{t[:time]} days"
	end
end
