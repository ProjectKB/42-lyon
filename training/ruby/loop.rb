# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    loop.rb                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 15:29:00 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/13 15:49:08 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

days = ["monday", "tuesday", "wednesday", "thursday", "friday"]

i = 5
days.each do |day|
	if day == "friday"
		puts day + " : Have a good weekend !"
	elsif day == "monday"
		puts day + " : Be Brave !"
	else
		puts day + " : Weekend in #{i} days !"
	end
	i-=1
end

7.times do
	puts "Turn your tong"
end
puts "... and speak !"
