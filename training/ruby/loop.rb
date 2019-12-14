# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    loop.rb                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 15:29:00 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/14 18:49:36 by loiberti    ###    #+. /#+    ###.fr      #
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

# for x in xs do == xs.each do |x|

# for only one instruction
days.each {|day| puts day}

# to have access to index
days.each_with_index do |day, index|
	puts "The index for #{day} is #{i}"
end
